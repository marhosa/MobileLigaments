// volcano_avatar.cpp
// Volcano mini-game with user-provided avatar pixel map, rescaled to match in-game avatar size.
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
int ticks = 0; // timeline ticks

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

// Avatar target on-screen size (keeps same scale as previous build)
const float PIXEL_UNIT = 0.025f;            // size of one pixel cell in previous avatar
const float AVATAR_WIDTH = 8 * PIXEL_UNIT;  // ~0.20
const float AVATAR_HEIGHT = 8 * PIXEL_UNIT; // ~0.20

// Player
float playerX = 0.0f;
const float PLAYER_Y = -0.75f;
const float PLAYER_SPEED = 1.8f;
bool leftPressed = false;
bool rightPressed = false;

// Debris struct and pool (unchanged)
struct Debris {
    float x, y;
    float vy;
    float radius;
    bool active;
};
const int MAX_DEBRIS = 40;
vector<Debris> debrisPool;
float debrisSpawnTimer = 0.0f;
float debrisSpawnInterval = 0.35f;

bool gameOver = false;
bool initializedVolcano = false;
float timeSinceStart = 0.0f;

// ------------------------------------------------------------------
// The user's avatar pixel data (parsed from their drawPixel calls).
// We'll put it into a grid (minX..maxX, minY..maxY).
// ------------------------------------------------------------------
struct Pixel {
    float r, g, b;
    bool opaque;
};
int gridMinX = 1000, gridMinY = 1000, gridMaxX = -1000, gridMaxY = -1000;
vector<vector<Pixel>> avatarGrid; // avatarGrid[col][row] where col = x-minX, row = y-minY
int gridW = 0, gridH = 0;

// Helper: convert small triplets (0/1) or 0..255 to normalized RGB
void setPixelColorFromTriplet(Pixel& p, int r, int g, int b) {
    // If any component > 1 treat as 0..255 ints; else treat as flags (0 or 1)
    if (r > 1 || g > 1 || b > 1) {
        p.r = r / 255.0f;
        p.g = g / 255.0f;
        p.b = b / 255.0f;
        p.opaque = true;
        return;
    }
    // Interpret small values as palette flags
    // (1,0,0) -> red, (0,1,0)->green, (0,0,1)->blue, (1,1,0)->yellow, (0,1,1)->cyan,
    // (1,1,1)->white, (0,0,0)->black
    if (r == 1 && g == 0 && b == 0) { p.r = 1; p.g = 0; p.b = 0; p.opaque = true; return; }
    if (r == 0 && g == 1 && b == 0) { p.r = 0; p.g = 1; p.b = 0; p.opaque = true; return; }
    if (r == 0 && g == 0 && b == 1) { p.r = 0; p.g = 0; p.b = 1; p.opaque = true; return; }
    if (r == 1 && g == 1 && b == 0) { p.r = 1; p.g = 1; p.b = 0; p.opaque = true; return; }
    if (r == 0 && g == 1 && b == 1) { p.r = 0; p.g = 1; p.b = 1; p.opaque = true; return; }
    if (r == 1 && g == 1 && b == 1) { p.r = 1; p.g = 1; p.b = 1; p.opaque = true; return; }
    if (r == 0 && g == 0 && b == 0) { p.r = 0; p.g = 0; p.b = 0; p.opaque = true; return; }
    // fallback: transparent
    p.opaque = false;
}

// Add a pixel at canvas coordinates (x,y) with color triplet
vector<tuple<int, int, int, int>> rawPixelEntries; // store temporarily: x,y,r,g,b
void addRawPixel(int x, int y, int r, int g, int b) {
    rawPixelEntries.emplace_back(x, y, r, g, b);
    gridMinX = min(gridMinX, x);
    gridMaxX = max(gridMaxX, x);
    gridMinY = min(gridMinY, y);
    gridMaxY = max(gridMaxY, y);
}

// Parse the user's drawPixel inputs (copied from their message)
void populateRawPixelData() {
    // The following calls are transcribed from the user's drawPixel list.
    // Format: addRawPixel(x, y, r, g, b)
    addRawPixel(14, 7, 1, 0, 0);
    addRawPixel(19, 7, 1, 0, 0);
    addRawPixel(20, 7, 0, 0, 0);
    addRawPixel(21, 7, 0, 0, 0);
    addRawPixel(22, 7, 0, 0, 1);
    addRawPixel(23, 7, 1, 0, 0);
    addRawPixel(14, 8, 0, 1, 0);
    addRawPixel(15, 8, 0, 0, 1);
    addRawPixel(18, 8, 0, 0, 1);
    addRawPixel(19, 8, 157, 90, 60);
    addRawPixel(20, 8, 156, 91, 60);
    addRawPixel(21, 8, 156, 90, 61);
    addRawPixel(22, 8, 1, 0, 0);
    addRawPixel(14, 9, 0, 1, 0);
    addRawPixel(15, 9, 156, 90, 61);
    addRawPixel(16, 9, 1, 1, 0);
    addRawPixel(17, 9, 0, 1, 1);
    addRawPixel(18, 9, 1, 0, 0);
    addRawPixel(19, 9, 157, 90, 60);
    addRawPixel(20, 9, 156, 90, 61);
    addRawPixel(21, 9, 0, 0, 0);
    addRawPixel(22, 9, 0, 1, 0);
    addRawPixel(12, 10, 0, 1, 1);
    addRawPixel(14, 10, 1, 1, 0);
    addRawPixel(15, 10, 156, 91, 60);
    addRawPixel(16, 10, 157, 90, 61);
    addRawPixel(17, 10, 157, 90, 60);
    addRawPixel(18, 10, 156, 90, 60);
    addRawPixel(19, 10, 156, 90, 61);
    addRawPixel(20, 10, 157, 90, 60);
    addRawPixel(21, 10, 0, 0, 0);
    addRawPixel(11, 11, 0, 1, 0);
    addRawPixel(12, 11, 156, 90, 60);
    addRawPixel(13, 11, 1, 0, 0);
    addRawPixel(14, 11, 0, 1, 0);
    addRawPixel(15, 11, 156, 90, 60);
    addRawPixel(16, 11, 1, 0, 0);
    addRawPixel(17, 11, 0, 0, 0);
    addRawPixel(18, 11, 0, 0, 1);
    addRawPixel(19, 11, 156, 90, 60);
    addRawPixel(20, 11, 0, 0, 0);
    addRawPixel(11, 12, 0, 0, 0);
    addRawPixel(12, 12, 156, 90, 60);
    addRawPixel(13, 12, 157, 90, 60);
    addRawPixel(14, 12, 156, 90, 60);
    addRawPixel(15, 12, 0, 0, 0);
    addRawPixel(16, 12, 255, 249, 189);
    addRawPixel(17, 12, 255, 249, 188);
    addRawPixel(18, 12, 255, 249, 189);
    addRawPixel(19, 12, 0, 1, 0);
    addRawPixel(12, 13, 0, 1, 0);
    addRawPixel(13, 13, 156, 90, 60);
    addRawPixel(14, 13, 157, 91, 60);
    addRawPixel(15, 13, 0, 0, 0);
    addRawPixel(16, 13, 255, 249, 188);
    addRawPixel(17, 13, 255, 249, 189);
    addRawPixel(18, 13, 255, 248, 188);
    addRawPixel(19, 13, 1, 0, 0);
    addRawPixel(13, 14, 0, 0, 0);
    addRawPixel(14, 14, 0, 0, 0);
    addRawPixel(15, 14, 0, 0, 0);
    addRawPixel(16, 14, 254, 249, 189);
    addRawPixel(17, 14, 255, 249, 189);
    addRawPixel(18, 14, 255, 249, 188);
    addRawPixel(19, 14, 1, 0, 0);
    addRawPixel(16, 15, 0, 1, 0);
    addRawPixel(17, 15, 0, 1, 1);
    addRawPixel(18, 15, 1, 0, 0);
    addRawPixel(17, 16, 1, 0, 0);
    addRawPixel(15, 17, 0, 0, 0);
    addRawPixel(16, 17, 1, 0, 0);
    addRawPixel(17, 17, 0, 0, 0);
    addRawPixel(18, 17, 0, 0, 0);
    addRawPixel(19, 17, 1, 0, 0);
    addRawPixel(14, 18, 0, 1, 1);
    addRawPixel(17, 18, 0, 0, 1);
    addRawPixel(20, 18, 0, 0, 1);
    addRawPixel(14, 19, 1, 1, 0);
    addRawPixel(17, 19, 0, 1, 0);
    addRawPixel(20, 19, 1, 0, 0);
    addRawPixel(16, 20, 0, 0, 0);
    addRawPixel(17, 20, 0, 1, 0);
    addRawPixel(18, 20, 0, 0, 1);
    addRawPixel(15, 21, 0, 0, 0);
    addRawPixel(16, 21, 254, 127, 0);
    addRawPixel(17, 21, 255, 126, 0);
    addRawPixel(18, 21, 255, 126, 1);
    addRawPixel(19, 21, 0, 0, 0);
    addRawPixel(14, 22, 0, 0, 0);
    addRawPixel(15, 22, 0, 0, 0);
    addRawPixel(16, 22, 254, 126, 0);
    addRawPixel(17, 22, 254, 126, 0);
    addRawPixel(18, 22, 255, 126, 1);
    addRawPixel(19, 22, 0, 0, 0);
    addRawPixel(20, 22, 0, 0, 0);
    addRawPixel(13, 23, 1, 0, 0);
    addRawPixel(14, 23, 255, 127, 0);
    addRawPixel(15, 23, 255, 126, 1);
    addRawPixel(16, 23, 255, 126, 0);
    addRawPixel(17, 23, 0, 0, 0);
    addRawPixel(18, 23, 255, 126, 1);
    addRawPixel(19, 23, 254, 126, 0);
    addRawPixel(20, 23, 255, 127, 0);
    addRawPixel(21, 23, 0, 0, 1);
    addRawPixel(13, 24, 1, 1, 0);
    addRawPixel(14, 24, 255, 127, 1);
    addRawPixel(15, 24, 255, 126, 1);
    addRawPixel(16, 24, 0, 0, 0);
    addRawPixel(18, 24, 1, 0, 1);
    addRawPixel(19, 24, 255, 126, 0);
    addRawPixel(20, 24, 255, 126, 0);
    addRawPixel(21, 24, 1, 0, 0);
    addRawPixel(13, 25, 1, 0, 0);
    addRawPixel(14, 25, 0, 1, 0);
    addRawPixel(15, 25, 0, 0, 0);
    addRawPixel(16, 25, 1, 0, 0);
    addRawPixel(18, 25, 0, 1, 0);
    addRawPixel(19, 25, 0, 0, 1);
    addRawPixel(20, 25, 1, 1, 0);
    addRawPixel(21, 25, 0, 0, 1);
    addRawPixel(15, 26, 0, 0, 0);
    addRawPixel(19, 26, 1, 0, 0);
    addRawPixel(14, 27, 0, 1, 0);
    addRawPixel(15, 27, 0, 0, 1);
    addRawPixel(19, 27, 1, 1, 0);
    addRawPixel(20, 27, 0, 1, 1);
}

// Build the 2D avatarGrid from raw entries
void buildAvatarGrid() {
    populateRawPixelData();
    if (gridMaxX < gridMinX || gridMaxY < gridMinY) return; // nothing
    gridW = gridMaxX - gridMinX + 1;
    gridH = gridMaxY - gridMinY + 1;
    avatarGrid.assign(gridW, vector<Pixel>(gridH));
    // initialize transparent
    for (int x = 0; x < gridW; ++x)
        for (int y = 0; y < gridH; ++y) avatarGrid[x][y].opaque = false;

    for (auto& t : rawPixelEntries) {
        int x, y, r, g, b;
        tie(x, y, r, g, b) = t;
        int ix = x - gridMinX;
        int iy = y - gridMinY;
        if (ix < 0 || ix >= gridW || iy < 0 || iy >= gridH) continue;
        setPixelColorFromTriplet(avatarGrid[ix][iy], r, g, b);
    }
}

// ------------------------------------------------------------------
// Game code (mostly same as previous working version)
// ------------------------------------------------------------------
void drawText(float x, float y, const string& s) {
    glRasterPos2f(x, y);
    for (char c : s) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void initDebrisPool() {
    debrisPool.clear();
    debrisPool.resize(MAX_DEBRIS);
    for (auto& d : debrisPool) d.active = false;
}

void spawnDebrisOne() {
    for (auto& d : debrisPool) {
        if (!d.active) {
            float spread = 0.6f;
            d.x = (float(rand()) / RAND_MAX - 0.5f) * spread;
            d.y = 1.05f + (float(rand()) / RAND_MAX) * 0.25f;
            d.vy = 0.35f + (float(rand()) / RAND_MAX) * 0.45f;
            d.radius = 0.018f + (float(rand()) / RAND_MAX) * 0.03f;
            d.active = true;
            break;
        }
    }
}

void Start_Volcano() {
    srand((unsigned)time(0));
    initDebrisPool();
    for (int i = 0; i < 6; ++i) spawnDebrisOne();
    playerX = 0.0f;
    leftPressed = rightPressed = false;
    gameOver = false;
    initializedVolcano = true;
    timeSinceStart = 0.0f;
    debrisSpawnTimer = 0.0f;
}

// Drawing helpers
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
    glColor3f(0.2f, 0.11f, 0.05f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.65f, -1.0f);
    glVertex2f(0.65f, -1.0f);
    glVertex2f(0.0f, 0.45f);
    glEnd();
    glColor3f(0.07f, 0.04f, 0.02f);
    drawCircleFilled(0.0f, 0.45f, 0.06f, 24);
    drawCircleFilled(0.12f, 0.42f, 0.02f, 16);
    drawCircleFilled(-0.12f, 0.40f, 0.016f, 16);
}

void drawLavaRivers(float t) {
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

// New: draw avatar using avatarGrid, rescaled to AVATAR_WIDTH x AVATAR_HEIGHT
void drawAvatarFromGrid(float centerX, float centerY) {
    if (gridW == 0 || gridH == 0) return; // nothing
    float pxW = AVATAR_WIDTH / float(gridW);
    float pxH = AVATAR_HEIGHT / float(gridH);
    // draw each grid cell; origin: left-bottom = center - halfWidth/height
    float left = centerX - (pxW * gridW) * 0.5f;
    float bottom = centerY - (pxH * gridH) * 0.5f;
    for (int gx = 0; gx < gridW; ++gx) {
        for (int gy = 0; gy < gridH; ++gy) {
            Pixel& pc = avatarGrid[gx][gy];
            if (!pc.opaque) continue;
            float x0 = left + gx * pxW;
            float y0 = bottom + gy * pxH;
            glColor3f(pc.r, pc.g, pc.b);
            glBegin(GL_QUADS);
            glVertex2f(x0, y0);
            glVertex2f(x0 + pxW, y0);
            glVertex2f(x0 + pxW, y0 + pxH);
            glVertex2f(x0, y0 + pxH);
            glEnd();
        }
    }
}

// Update loop
void updateScene(float deltaSeconds) {
    if (!initializedVolcano) Start_Volcano();
    if (gameOver) return;
    timeSinceStart += deltaSeconds;
    debrisSpawnTimer += deltaSeconds;
    if (debrisSpawnTimer >= debrisSpawnInterval) {
        spawnDebrisOne();
        debrisSpawnTimer = 0.0f;
    }
    if (leftPressed && !rightPressed) playerX -= PLAYER_SPEED * deltaSeconds;
    if (rightPressed && !leftPressed) playerX += PLAYER_SPEED * deltaSeconds;
    float half = AVATAR_WIDTH * 0.5f;
    playerX = max(playerX, -1.0f + half);
    playerX = min(playerX, 1.0f - half);
    for (auto& d : debrisPool) {
        if (!d.active) continue;
        d.y -= d.vy * deltaSeconds;
        float avatarLeft = playerX - AVATAR_WIDTH * 0.5f;
        float avatarRight = playerX + AVATAR_WIDTH * 0.5f;
        float avatarTop = PLAYER_Y + AVATAR_HEIGHT * 0.5f;
        float avatarBot = PLAYER_Y - AVATAR_HEIGHT * 0.5f;
        float nearestX = max(avatarLeft, min(d.x, avatarRight));
        float nearestY = max(avatarBot, min(d.y, avatarTop));
        float dx = d.x - nearestX;
        float dy = d.y - nearestY;
        float dist2 = dx * dx + dy * dy;
        if (dist2 <= d.radius * d.radius) gameOver = true;
        if (d.y < -1.2f) d.active = false;
    }
}

// Display for chapter 4
void displayChapter4() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float t = timeSinceStart;
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.18f, 0.28f); glVertex2f(-1.0f, -1.0f);
    glColor3f(0.22f, 0.35f, 0.60f); glVertex2f(1.0f, -1.0f);
    glColor3f(0.03f, 0.06f, 0.18f); glVertex2f(1.0f, 1.0f);
    glColor3f(0.09f, 0.12f, 0.25f); glVertex2f(-1.0f, 1.0f);
    glEnd();
    drawLavaRivers(t);
    drawVolcano();
    for (auto& d : debrisPool) {
        if (!d.active) continue;
        glColor3f(1.0f, 0.6f, 0.12f);
        drawCircleFilled(d.x, d.y, d.radius + d.radius * 0.35f, 18);
        glColor3f(0.18f, 0.06f, 0.02f);
        drawCircleFilled(d.x, d.y, d.radius, 20);
    }
    // draw new avatar rescaled from user pixel map
    drawAvatarFromGrid(playerX, PLAYER_Y);
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
    // Force chapter 4 rendering for immediate play
    displayChapter4();
}

// Input
void keyboardDown(unsigned char key, int x, int y) {
    if (key == 'q' || key == 'Q') exit(0);
    if (key == 'r' || key == 'R') {
        Start_Volcano();
        gameOver = false;
        return;
    }
    if (gameOver) return;
    if (key == 'a' || key == 'A') leftPressed = true;
    if (key == 'd' || key == 'D') rightPressed = true;
}

void keyboardUp(unsigned char key, int x, int y) {
    if (key == 'a' || key == 'A') leftPressed = false;
    if (key == 'd' || key == 'D') rightPressed = false;
}
void specialDown(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) leftPressed = true;
    if (key == GLUT_KEY_RIGHT) rightPressed = true;
}
void specialUp(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) leftPressed = false;
    if (key == GLUT_KEY_RIGHT) rightPressed = false;
}

// Timer
void timerFunc(int value) {
    const float dt = 1.0f / 60.0f;
    // Set ticks to chapter 4 immediately for convenience
    if (ticks < 12000) ticks = 12000;
    ticks += 1;
    updateScene(dt);
    glutPostRedisplay();
    glutTimerFunc(16, timerFunc, 0);
}

// ------------------------------------------------------------------
// main
// ------------------------------------------------------------------
int main(int argc, char** argv) {
    // Build avatar grid from user's drawPixel data
    buildAvatarGrid();

    srand((unsigned)time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Chapter 4 - Volcanic Eruption (Avatar integrated)");

    // Set clear color
    glClearColor(0.08f, 0.08f, 0.12f, 1.0f);

    // Orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Start_Volcano();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialDown);
    glutSpecialUpFunc(specialUp);
    glutTimerFunc(16, timerFunc, 0);

    glutMainLoop();
    return 0;
}
