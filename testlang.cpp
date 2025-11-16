// volcano_game.cpp
// Complete Chapter 4: Volcanic Eruption scene with avatar, falling debris, and volcano
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// ------------------------------------------------------------------
// Configuration / Globals
// ------------------------------------------------------------------
int ticks = 12000; // timeline ticks (do not modify manually)

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

// Avatar pixel-art (8x8). 0 = transparent
int pixelArt[8][8] = {
    {0,0,2,2,2,0,0,0},
    {0,2,1,1,1,2,0,0},
    {0,2,3,3,3,2,0,0},
    {0,0,3,3,3,0,0,0},
    {0,0,4,4,4,0,0,0},
    {0,4,4,4,4,4,0,0},
    {0,0,5,0,0,5,0,0},
    {0,0,0,0,0,0,0,0}
};

// avatar size (in normalized coordinates); 8 * PIXEL_UNIT = avatar width
const float PIXEL_UNIT = 0.025f; // 8 * 0.025 = 0.2 width
const float AVATAR_WIDTH = 8 * PIXEL_UNIT;   // ~0.20
const float AVATAR_HEIGHT = 8 * PIXEL_UNIT;  // ~0.20

// Player
float playerX = 0.0f;            // normalized coords (-1..1)
const float PLAYER_Y = -0.75f;   // fixed vertical position
const float PLAYER_SPEED = 1.8f; // units/sec (normalized)
bool leftPressed = false;
bool rightPressed = false;

// Debris
struct Debris {
    float x, y;
    float vy;    // vertical speed (normalized units/sec)
    float radius;
    bool active;
};
const int MAX_DEBRIS = 40;
vector<Debris> debrisPool;
float debrisSpawnTimer = 0.0f;
float debrisSpawnInterval = 0.35f; // seconds

// Volcano / visuals
bool gameOver = false;
bool initializedVolcano = false;
float timeSinceStart = 0.0f; // seconds

// Utility: draw text
void drawText(float x, float y, const string& s) {
    glRasterPos2f(x, y);
    for (char c : s) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// Color mapping for pixel art
void setColorFromPixel(int p) {
    switch (p) {
    case 1: glColor3f(1.0f, 0.9f, 0.6f); break; // skin
    case 2: glColor3f(0.35f, 0.2f, 0.05f); break; // hair
    case 3: glColor3f(1.0f, 1.0f, 1.0f); break; // shirt
    case 4: glColor3f(1.0f, 0.45f, 0.0f); break; // pants
    case 5: glColor3f(0.05f, 0.05f, 0.05f); break; // shoes
    default: glColor3f(0.0f, 0.0f, 0.0f); break;
    }
}

// ------------------------------------------------------------------
// Initialization and helpers
// ------------------------------------------------------------------
void initDebrisPool() {
    debrisPool.clear();
    debrisPool.resize(MAX_DEBRIS);
    for (auto& d : debrisPool) d.active = false;
}

void spawnDebrisOne() {
    for (auto& d : debrisPool) {
        if (!d.active) {
            // spawn randomly across volcano top region (x near center)
            float spread = 0.6f; // normalized width
            d.x = (float(rand()) / RAND_MAX - 0.5f) * spread;
            d.y = 1.05f + (float(rand()) / RAND_MAX) * 0.25f; // slightly above top
            d.vy = 0.35f + (float(rand()) / RAND_MAX) * 0.45f; // normalized units/sec
            d.radius = 0.018f + (float(rand()) / RAND_MAX) * 0.03f;
            d.active = true;
            break;
        }
    }
}

void Start_Volcano() {
    srand((unsigned)time(0));
    initDebrisPool();
    // Pre-spawn a few
    for (int i = 0; i < 6; ++i) spawnDebrisOne();
    playerX = 0.0f;
    leftPressed = rightPressed = false;
    gameOver = false;
    initializedVolcano = true;
    timeSinceStart = 0.0f;
    debrisSpawnTimer = 0.0f;
}

// ------------------------------------------------------------------
// Drawing
// ------------------------------------------------------------------
void drawCircleFilled(float cx, float cy, float r, int segments = 20) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; ++i) {
        float a = (2.0f * M_PI * i) / segments;
        glVertex2f(cx + cosf(a) * r, cy + sinf(a) * r);
    }
    glEnd();
}

void drawVolcano() {
    // mountain shape
    glColor3f(0.2f, 0.11f, 0.05f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.65f, -1.0f);
    glVertex2f(0.65f, -1.0f);
    glVertex2f(0.0f, 0.45f);
    glEnd();

    // crater interior darker
    glColor3f(0.07f, 0.04f, 0.02f);
    drawCircleFilled(0.0f, 0.45f, 0.06f, 24);
    // some rocks near mouth
    drawCircleFilled(0.12f, 0.42f, 0.02f, 16);
    drawCircleFilled(-0.12f, 0.40f, 0.016f, 16);
}

void drawLavaRivers(float t) {
    // simple wavy lava stripes below volcano
    for (int i = 0; i < 3; ++i) {
        float y = -0.9f + i * 0.12f;
        glBegin(GL_QUADS);
        float offset = sinf(t * (0.9f + i * 0.6f)) * 0.03f;
        glColor3f(0.8f, 0.18f, 0.02f);
        glVertex2f(-1.0f, y + offset);
        glVertex2f(1.0f, y + offset + 0.02f);
        glVertex2f(1.0f, y + offset - 0.01f);
        glVertex2f(-1.0f, y + offset - 0.02f);
        glEnd();
    }
}

void drawAvatar(float cx, float cy) {
    // Draw pixelArt as little quads centered at (cx, cy).
    float baseLeft = cx - AVATAR_WIDTH * 0.5f;
    float baseBottom = cy - AVATAR_HEIGHT * 0.5f;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            int p = pixelArt[row][col];
            if (p == 0) continue;
            float px = baseLeft + col * PIXEL_UNIT;
            float py = baseBottom + (7 - row) * PIXEL_UNIT; // invert row
            setColorFromPixel(p);
            glBegin(GL_QUADS);
            glVertex2f(px, py);
            glVertex2f(px + PIXEL_UNIT, py);
            glVertex2f(px + PIXEL_UNIT, py + PIXEL_UNIT);
            glVertex2f(px, py + PIXEL_UNIT);
            glEnd();
        }
    }
}

// ------------------------------------------------------------------
// Update (game loop) — deltaSeconds provided by timer
// ------------------------------------------------------------------
void updateScene(float deltaSeconds) {
    if (!initializedVolcano) Start_Volcano();

    if (gameOver) return;

    timeSinceStart += deltaSeconds;
    debrisSpawnTimer += deltaSeconds;

    // spawn debris periodically
    if (debrisSpawnTimer >= debrisSpawnInterval) {
        spawnDebrisOne();
        debrisSpawnTimer = 0.0f;
        // gradually shorten spawn interval to increase difficulty
        if (debrisSpawnInterval > 0.12f && (int)timeSinceStart % 8 == 0) {
            debrisSpawnInterval *= 0.995f;
        }
    }

    // move player by key state
    if (leftPressed && !rightPressed) playerX -= PLAYER_SPEED * deltaSeconds;
    if (rightPressed && !leftPressed) playerX += PLAYER_SPEED * deltaSeconds;
    // clamp
    float half = AVATAR_WIDTH * 0.5f;
    playerX = max(playerX, -1.0f + half);
    playerX = min(playerX, 1.0f - half);

    // update debris
    for (auto& d : debrisPool) {
        if (!d.active) continue;
        d.y -= d.vy * deltaSeconds;
        // collision: avatar bounding box vs debris circle
        float avatarLeft = playerX - AVATAR_WIDTH * 0.5f;
        float avatarRight = playerX + AVATAR_WIDTH * 0.5f;
        float avatarTop = PLAYER_Y + AVATAR_HEIGHT * 0.5f;
        float avatarBot = PLAYER_Y - AVATAR_HEIGHT * 0.5f;

        // find closest point on avatar rect to debris center
        float nearestX = max(avatarLeft, min(d.x, avatarRight));
        float nearestY = max(avatarBot, min(d.y, avatarTop));
        float dx = d.x - nearestX;
        float dy = d.y - nearestY;
        float dist2 = dx * dx + dy * dy;
        if (dist2 <= d.radius * d.radius) {
            gameOver = true;
        }

        // recycle if off-screen bottom
        if (d.y < -1.2f) {
            d.active = false;
        }
    }
}

// ------------------------------------------------------------------
// Display callback (selects Chapter 4 view when ticks in range)
// ------------------------------------------------------------------
void displayChapter4() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // background sky gradient - simple solid for compatibility
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.18f, 0.28f); glVertex2f(-1.0f, -1.0f);
    glColor3f(0.22f, 0.35f, 0.60f); glVertex2f(1.0f, -1.0f);
    glColor3f(0.03f, 0.06f, 0.18f); glVertex2f(1.0f, 1.0f);
    glColor3f(0.09f, 0.12f, 0.25f); glVertex2f(-1.0f, 1.0f);
    glEnd();

    float t = timeSinceStart;
    drawLavaRivers(t);

    // volcano & crater
    drawVolcano();

    // draw falling debris (as circles)
    for (auto& d : debrisPool) {
        if (!d.active) continue;
        // outer glow
        glColor3f(1.0f, 0.6f, 0.12f);
        drawCircleFilled(d.x, d.y, d.radius + d.radius * 0.35f, 18);
        // inner rock
        glColor3f(0.18f, 0.06f, 0.02f);
        drawCircleFilled(d.x, d.y, d.radius, 20);
    }

    // draw avatar
    drawAvatar(playerX, PLAYER_Y);

    // UI text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.98f, 0.92f, "Volcanic Eruption: Dodge the falling debris!");
    drawText(-0.98f, 0.86f, "Move: A / D or Left / Right arrows. R to restart. Q to quit.");

    if (gameOver) {
        glColor3f(1.0f, 0.22f, 0.22f);
        drawText(-0.08f, 0.06f, "GAME OVER!");
        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(-0.18f, -0.02f, "Press R to try again.");
    }

    glutSwapBuffers();
}

void display() {
    if (ticks >= 12000 && ticks < 15000) {
        displayChapter4();
    }
    else {
        // blank screen for other chapters
        glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSwapBuffers();
    }
}
// ------------------------------------------------------------------
// GLUT callbacks and input
// ------------------------------------------------------------------
void keyboardDown(unsigned char key, int x, int y) {
    // Global hotkeys
    if (key == 'q' || key == 'Q') exit(0);
    if (key == 'r' || key == 'R') {
        Start_Volcano();
        gameOver = false;
        return;
    }

    // Only respond if in chapter 4 by ticks
    if (!(ticks >= 12000 && ticks < 15000)) return;
    if (gameOver) return;

    if (key == 'a' || key == 'A') leftPressed = true;
    if (key == 'd' || key == 'D') rightPressed = true;
}

void keyboardUp(unsigned char key, int x, int y) {
    if (!(ticks >= 12000 && ticks < 15000)) return;
    if (key == 'a' || key == 'A') leftPressed = false;
    if (key == 'd' || key == 'D') rightPressed = false;
}

void specialDown(int key, int x, int y) {
    if (!(ticks >= 12000 && ticks < 15000)) return;
    if (key == GLUT_KEY_LEFT) leftPressed = true;
    if (key == GLUT_KEY_RIGHT) rightPressed = true;
}
void specialUp(int key, int x, int y) {
    if (!(ticks >= 12000 && ticks < 15000)) return;
    if (key == GLUT_KEY_LEFT) leftPressed = false;
    if (key == GLUT_KEY_RIGHT) rightPressed = false;
}

// Timer-based update (approx 60fps)
void timerFunc(int value) {
    const float dt = 1.0f / 60.0f; // seconds
    // increment ticks: 60 ticks == 1 second according to your mapping
    ticks += 1; // called every ~16ms -> ~60 per second

    // Only update gameplay when chapter 4 active
    if (ticks >= 12000 && ticks < 15000) {
        updateScene(dt);
    }

    glutPostRedisplay();
    glutTimerFunc(16, timerFunc, 0);
}

// ------------------------------------------------------------------
// main
// ------------------------------------------------------------------
int main(int argc, char** argv) {
    srand((unsigned)time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Chapter 4 - Volcanic Eruption");

    // set orthographic projection matching normalized coords (-1..1)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // initialize
    Start_Volcano();

    // callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialDown);
    glutSpecialUpFunc(specialUp);
    glutTimerFunc(16, timerFunc, 0);

    glutMainLoop();
    return 0;
}
