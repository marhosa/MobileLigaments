
// ! Debugging purposes why its on top
// ! ALSO this runs the code, do not remove
int ticks = 3300;

/*
Use Better Comments Extension para ez readability
*/

#include <GL/glut.h>
#include <functional>
#include <iostream>

using namespace std;

// * YUNG MGA POSITIONS NG CHARACTERS ANDITO
// * -----------------------------------------------

int drawMark_XPOS = 0;
int drawMark_YPOS = 4;

int breadOnTable_XPOS = 0;
int breadOnTable_YPOS = 6;

int window_XPOS = 8;
int window_YPOS = 0;

int introFloor_XPOS = 0;
int introFloor_YPOS = 3;

int tornado_XPOS = 5;
int tornado_YPOS = -3;

int nameBarNew_XPOS = 0;
int nameBarNew_YPOS = 0;

int brokenWindow_XPOS = 2;
int brokenWindow_YPOS = -1;

int introWall_XPOS = 0;
int introWall_YPOS = 0;

int oneLastBite_XPOS = 0;
int oneLastBite_YPOS = 0;

int chapter1TornadoBackground_XPOS = 0;
int chapter1TornadoBackground_YPOS = 0;

int sharkBackground_XPOS = 0;
int sharkBackground_YPOS = 0;

// * Asset Declarations:
void drawMark();
void smallMark();
void breadOnTable();
void window();
void nameBarNew();
void introFloor();
void brokenWindow();
void tornadoNew();
void introWall();
void oneLastBite();
void chapter1TornadoBackground();
void sharkBackground();

// ! ---------------------------------------
// ! DO NOT GALAW GALAW ALSO WAG NIYO MANUALLY PALITAN VARIABLES

// Pixel canvas size
const int PIXEL_WIDTH = 64;
const int PIXEL_HEIGHT = 36;

// Window size
const int WIN_WIDTH = 1920;
const int WIN_HEIGHT = 1080;

// * HELPER FUNCTIONS OR VARIABLES STUFF
// TODO: INTRO (wala)

// TODO: Chapter 1:
//  Small Mark movement
int smallMark_XPOS = 0;
int smallMark_YPOS = 0;

// Which lane tornado is using (0 = top lane, 1 = bottom lane)
int tornadoLane = 0;

// 1 = tornado is moving left, -1 = moving right
int tornadoDirection = -1;

// For one-time init per scene
bool chapter1_initialized = false;

// ! ---------------------------------------

// *===========================================
// *  Scene Timeline Reference (60 ticks = 1 sec)
// *===========================================
//*   TICKS        SECOND      SCENE
//   0–2999   →  0–50s   → Intro Scene
//  3000–5999 → 50–100s  → Chapter 1: Tornado
//  6000–8999 → 100–150s → Chapter 2: Flood
//  9000–11999 → 150–200s → Chapter 3: Earthquake
//  12000–14999 → 200–250s → Chapter 4: Volcanic Eruption
//  15000–17999 → 250–300s → Ending Scene
//  ≥18000 → Post-ending / Restart

// ===========================================

// * ---------------------------------------
// * functions na gagamitin niyo most likely
// Declarations rin to kaya wag delete lol

// Draws Text, params: (x-position, y-position, stringMessage)
void drawText(float x, float y, const std::string &text);

// Start and End Changer
// Basically sets the ticks to kung ano ang starting ticks ng mga to
// Refer kayo sa scene timeline reference comment block
void Start_Intro();
void Start_Tornado();
void Start_Flood();
void Start_Earthquake();
void Start_Volcano();
void Start_Ending();
/*
Pwede rin if matalo sa halimbawa sa tornado game si player,
icall niyo si "Start_Tornado()"
para balik sa simula

also 1,2,3,4,5,6 sa keyboard pupunta ka sa ibat ibang scene

*/

// gagawa ng pixel sa x and y location (1920 x 1080 reference)
// tapos may r g b color values
void drawPixel(int x, int y, int r, int g, int b);
/*
Example Use Case:
drawPixel(32, 18, 255, 0, 0);   // red pixel in center
drawPixel(0, 0, 0, 255, 0);     // green pixel at top-left
drawPixel(63, 35, 0, 0, 255);   // blue pixel at bottom-right
*/

// Message Box, start tick, end tick, message
void messageBox(int tickCountStart, int tickCountEnd, string msg);

// run certain function between tickstart and tickend
void appearAt(int tickstart, int tickend, function<void()> func);

// * ---------------------------------------

// * ---------------------------------------
// * DISPLAY CONTROLLERS PER SCENE:

// Intro Scene (Tutorial + Breakfast)
void Display_Intro() {
  // TODO: Show title, controls, and Mark eating breakfast
  // glColor3f(0.0f, 0.0f, 0.0f);
  // drawText(0, 0, "MARK INTRO SCENE SCANDAL");

  introWall();
  appearAt(0, 2400, window);
  drawMark();
  breadOnTable();
  introFloor();
  appearAt(2400, 3000, brokenWindow);
  appearAt(2500, 3000, tornadoNew);

  messageBox(200, 580,
             "MARK: sarap buhay gagi lods angas naman sheesh pare lods 67");
  messageBox(
      780, 1080,
      "MARK: Gagi may tinapay, makain nga yan sarap naman wow duterte moment");
  messageBox(1300, 1680,
             "MARK: sheesh sarap nung pandesal bagong luto mainit init pa");
  messageBox(
      1800, 2100,
      "MARK: kainin ko na to bago lumamig, bread taste better than key ehh");
  messageBox(2450, 2650, "MARK: GAGI ANO YUN TORNADO SI YOLANDA");
  messageBox(2750, 3000, "TORNADO: TAKBO TITIRAHIN KITA WAHAHAHA");
}

// Chapter 1: Tornado

void helper_chapter1_updateTornado() {
  tornado_XPOS += tornadoDirection;

  // When tornado leaves screen, reset it
  if (tornado_XPOS < -60) {
    tornadoDirection = 1; //  move right
    tornadoLane = rand() % 2;
    tornado_YPOS = (tornadoLane == 0 ? 6 : -4);
  }

  if (tornado_XPOS > 50) {
    tornadoDirection = -1; // move left
    tornadoLane = rand() % 2;
    tornado_YPOS = (tornadoLane == 0 ? 6 : -4);
  }
}

void helper_chapter1_updateMark(unsigned char key) {
  switch (key) {
  case 's':
  case 'S':
    smallMark_YPOS += 2; // slide up
    break;

  case 'w':
  case 'W':
    smallMark_YPOS -= 2; // slide down
    break;

  case 'a':
  case 'A':
    smallMark_XPOS -= 1; // optional movement
    break;

  case 'd':
  case 'D':
    smallMark_XPOS += 1;
    break;
  }
}

// Chapter 1: Tornado
void Display_Chapter_1() {

  // Tornado movement update (runs every frame)
  helper_chapter1_updateTornado();

  // Timeline events
  appearAt(3000, 3300, oneLastBite);
  appearAt(3300, 6000, chapter1TornadoBackground);

  // Small Mark & Tornado
  appearAt(3300, 6000, smallMark);
  appearAt(3300, 6000, tornadoNew);

  // Messages
  messageBox(3400, 3700,
             "TORNADO: Trip lang pre ah hahuiuwh penge ng tinapay (mo)");
  messageBox(3800, 4100,
             "MARK: Di nakakatuwa pre gusto ko lng kainin tong tinapay ko sah");
  messageBox(4500, 4800,
             "TORNADO: Di ka napapagod eh no, well at least sweaty :>");
  messageBox(5000, 5300, "MARK: Umay sah... Lomayo ka. de keta mahal");
  messageBox(5600, 5800, "TORNADO: UGHHH PAGOD NA AKO, LAPIT NAAA!");
  messageBox(5850, 6000, "MARK: LEZZGO!");
}

// Chapter 2: Flood

// Helper to move shark background infinitely
void helper_sharkBackground_update() {
  // Move background left by 1 pixel per frame
  sharkBackground_XPOS -= 1;

  // Reset when fully offscreen to create infinite loop
  if (sharkBackground_XPOS <= -PIXEL_WIDTH) {
    sharkBackground_XPOS = 0;
  }

  // Draw two copies: original and mirrored for seamless loop
  sharkBackground(); // main copy
  // draw mirrored copy
  int tempX = sharkBackground_XPOS + PIXEL_WIDTH;
  // temporarily shift the background position
  sharkBackground_XPOS = tempX;
  sharkBackground();
  sharkBackground_XPOS = tempX - PIXEL_WIDTH; // restore
}

void Display_Chapter_2() {
  // Move & draw the scrolling background
  helper_sharkBackground_update();
  drawMark();
}

// Chapter 3: Earthquake
void Display_Chapter_3() {
  // TODO: Mark jumps across cracks safely
  glColor3f(0.0f, 0.0f, 0.0f);
  drawText(0, 0, "MARK TALON SA SKY");
}

// Chapter 4: Volcanic Eruption
void Display_Chapter_4() {
  // TODO: Mark dodges falling volcanic debris
  glColor3f(0.0f, 0.0f, 0.0f);
  drawText(0, 0, "MARK IWAS HULOG ROCKY ROADS");
}

// Ending Scene (Resolution / Credits)
void Display_Ending() {
  // TODO: Mark finds expired bread, humorous credits roll
  glColor3f(0.0f, 0.0f, 0.0f);
  drawText(0, 0, "MARK NAMATAY THANK YOU FOR PLAYING MLBB");
}

// Basically  Access to all scenes andito
void Display_Whole_Scene() {
  // Show Ticks Sa Taas
  glColor3f(0.0f, 0.0f, 0.0f);
  drawText(-0.9, 0.9, ("Ticks: " + to_string(ticks)));

  // TODO: LAgyan nyo nalang baba neto etc if may trip kayo idisplay na wala sa
  // scope niyo.
}

// * ---------------------------------------

// * ---------------------------------------
// * KEYBOARD CONTROLLERS PER SCENE:

// unsigned char key, yung key is yung keyboard hex
// example: key = 32 is space bar ganun eyy

// Intro Scene (Tutorial + Breakfast)
void KB_Intro(unsigned char key) {
  // TODO: Show title, controls, and Mark eating breakfast

  // * Control Mark
  switch (key) {
  case 'a': // move left
  case 'A':
    drawMark_XPOS -= 1;
    break;
  case 'd': // move right
  case 'D':
    drawMark_XPOS += 1;
    break;
  }
}

// Chapter 1: Tornado Controls
void KB_Chapter_1(unsigned char key) { helper_chapter1_updateMark(key); }

// Chapter 2: Flood
void KB_Chapter_2(unsigned char key) {
  switch (key) {
  case 'w':
  case 'W':
    drawMark_YPOS -= 1;
    break; // move up
  case 's':
  case 'S':
    drawMark_YPOS += 1;
    break; // move down
  case 'a':
  case 'A':
    drawMark_XPOS -= 1;
    break; // move left
  case 'd':
  case 'D':
    drawMark_XPOS += 1;
    break; // move right
  }
}

// Chapter 3: Earthquake
void KB_Chapter_3(unsigned char key) {
  // TODO: Mark jumps across cracks safely
}

// Chapter 4: Volcanic Eruption
void KB_Chapter_4(unsigned char key) {
  // TODO: Mark dodges falling volcanic debris
}

// Ending Scene (Resolution / Credits)
void KB_Ending(unsigned char key) {
  // TODO: Mark finds expired bread, humorous credits roll
}

void KB_Whole_Scene(unsigned char key) {

  // ? Controlls The Scene With Keyboard
  switch (key) {
  case '1':        // Key 1 → Jump sa Intro
    Start_Intro(); // ticks = 0
    break;
  case '2':          // Key 2 → Jump sa Tornado
    Start_Tornado(); // ticks = 3000
    break;
  case '3':        // Key 3 → Jump sa Flood
    Start_Flood(); // ticks = 6000
    break;
  case '4':             // Key 4 → Jump sa Earthquake
    Start_Earthquake(); // ticks = 9000
    break;
  case '5':          // Key 5 → Jump sa Volcano
    Start_Volcano(); // ticks = 12000
    break;
  case '6':         // Key 6 → Jump sa Ending
    Start_Ending(); // ticks = 15000
    break;
  case 'r': // Key R → Reset/Restart
  case 'R':
    Start_Intro();
    break;
  default:
    break;
  }

  /*
  TODO: Add nalang kayo sa baba netong function
  TODO: if may trip kayo gawin or lagyan keyboard func etc idk
  TODO: Exit ganun type shii
  */
}

// * ---------------------------------------

// * ---------------------------------------
// * HELPER FUNCTIONS
// pwede niyo dagdagan to

void appearAt(int tickstart, int tickend, function<void()> func) {
  if (ticks >= tickstart && ticks <= tickend) {
    func(); // run the function
  }
}

void messageBox(int tickCountStart, int tickCountEnd, std::string msg) {
  if (ticks > tickCountStart && ticks < tickCountEnd) {
    nameBarNew();
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(-0.7, -0.7, msg);
  }
}

// ? Draw Text Function
// ? doc hadji draw a text function
void drawText(float x, float y, const std::string &text) {
  glRasterPos2f(x, y);
  for (char c : text)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// ? Draw a single pixel on the 64x36 pixel canvas
// ? x, y are in canvas coordinates (0..Pixel_width, 0..pixel_height)
void drawPixel(int x, int y, int r, int g, int b) {
  // Size of each pixel in screen space
  float pixelWidth = WIN_WIDTH / (float)PIXEL_WIDTH;
  float pixelHeight = WIN_HEIGHT / (float)PIXEL_HEIGHT;

  // Convert canvas coordinates to screen coordinates
  float screenX = x * pixelWidth;
  float screenY = y * pixelHeight;

  // Convert screen coordinates to normalized OpenGL coordinates (-1 to 1)
  float nx = (screenX / WIN_WIDTH) * 2.0f - 1.0f;
  float ny = 1.0f - (screenY / WIN_HEIGHT) * 2.0f;

  float halfSizeX = (pixelWidth / WIN_WIDTH);
  float halfSizeY = (pixelHeight / WIN_HEIGHT);

  // Draw a quad
  glBegin(GL_QUADS);
  glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
  glVertex2f(nx - halfSizeX, ny - halfSizeY);
  glVertex2f(nx + halfSizeX, ny - halfSizeY);
  glVertex2f(nx + halfSizeX, ny + halfSizeY);
  glVertex2f(nx - halfSizeX, ny + halfSizeY);
  glEnd();
}

// ? Starter Ticks Function para basic
void Start_Intro() {
  ticks = 0; // Intro starts at tick 0
}

void Start_Tornado() {
  ticks = 3000; // Chapter 1: Tornado starts at tick 3000
}

void Start_Flood() {
  ticks = 6000; // Chapter 2: Flood starts at tick 6000
}

void Start_Earthquake() {
  ticks = 9000; // Chapter 3: Earthquake starts at tick 9000
}

void Start_Volcano() {
  ticks = 12000; // Chapter 4: Volcanic Eruption starts at tick 12000
}

void Start_Ending() {
  ticks = 15000; // Ending Scene starts at tick 15000
}

// * ---------------------------------------

// * ---------------------------------------
// * MAIN DISPLAY
// ! Galawin lang if needed
void display() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  Display_Whole_Scene();

  if (ticks < 3000) { // Intro Scene (Tutorial + Breakfast)
    Display_Intro();
  } else if (ticks < 6000) { // Chapter 1: Tornado
    Display_Chapter_1();
  } else if (ticks < 9000) { // Chapter 2: Flood
    Display_Chapter_2();
  } else if (ticks < 12000) { // Chapter 3: Earthquake
    Display_Chapter_3();
  } else if (ticks < 15000) { // Chapter 4: Volcanic Eruption
    Display_Chapter_4();
  } else if (ticks < 18000) { // Ending Scene (Credits)
    Display_Ending();
  } else { // Post-ending / Restart
    drawText(-0.3f, 0.0f, "THE END - Press W to Restart");
  }

  glFlush();
}
// * ---------------------------------------

// ! ---------------------------------------
// ! WAG GALAWIN IF PWEDE, MODIFY KB_WHOLE_SCENE INSTEAD

// UPDATER FUNCTION
void update(int value) {
  ticks += 1;

  glutPostRedisplay();
  glutTimerFunc(16, update, 0);
}

// KEYBOARD CONTROLS FUNCTION
void keyboard(unsigned char key, int x, int y) {

  // Triggers anyways any scene
  KB_Whole_Scene(key);

  if (ticks < 3000) { // Intro Scene (Tutorial + Breakfast)
    KB_Intro(key);
  } else if (ticks < 6000) { // Chapter 1: Tornado
    KB_Chapter_1(key);
  } else if (ticks < 9000) { // Chapter 2: Flood
    KB_Chapter_2(key);
  } else if (ticks < 12000) { // Chapter 3: Earthquake
    KB_Chapter_3(key);
  } else if (ticks < 15000) { // Chapter 4: Volcanic Eruption
    KB_Chapter_4(key);
  } else if (ticks < 18000) { // Ending Scene (Credits)
    KB_Ending(key);
  }
}
// ! ---------------------------------------

// * ---------------------------------------
// * MAIN
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("Mobile Ligaments");
  glutFullScreen();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}
// * ---------------------------------------

void drawMark() {
  drawPixel(14 + drawMark_XPOS, 7 + drawMark_YPOS, 1, 0, 0);
  drawPixel(19 + drawMark_XPOS, 7 + drawMark_YPOS, 1, 0, 0);
  drawPixel(20 + drawMark_XPOS, 7 + drawMark_YPOS, 0, 0, 0);
  drawPixel(21 + drawMark_XPOS, 7 + drawMark_YPOS, 0, 0, 0);
  drawPixel(22 + drawMark_XPOS, 7 + drawMark_YPOS, 0, 0, 1);
  drawPixel(23 + drawMark_XPOS, 7 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 8 + drawMark_YPOS, 0, 1, 0);
  drawPixel(15 + drawMark_XPOS, 8 + drawMark_YPOS, 0, 0, 1);
  drawPixel(18 + drawMark_XPOS, 8 + drawMark_YPOS, 0, 0, 1);
  drawPixel(19 + drawMark_XPOS, 8 + drawMark_YPOS, 157, 90, 60);
  drawPixel(20 + drawMark_XPOS, 8 + drawMark_YPOS, 156, 91, 60);
  drawPixel(21 + drawMark_XPOS, 8 + drawMark_YPOS, 156, 90, 61);
  drawPixel(22 + drawMark_XPOS, 8 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 9 + drawMark_YPOS, 0, 1, 0);
  drawPixel(15 + drawMark_XPOS, 9 + drawMark_YPOS, 156, 90, 61);
  drawPixel(16 + drawMark_XPOS, 9 + drawMark_YPOS, 1, 1, 0);
  drawPixel(17 + drawMark_XPOS, 9 + drawMark_YPOS, 0, 1, 1);
  drawPixel(18 + drawMark_XPOS, 9 + drawMark_YPOS, 1, 0, 0);
  drawPixel(19 + drawMark_XPOS, 9 + drawMark_YPOS, 157, 90, 60);
  drawPixel(20 + drawMark_XPOS, 9 + drawMark_YPOS, 156, 90, 61);
  drawPixel(21 + drawMark_XPOS, 9 + drawMark_YPOS, 0, 0, 0);
  drawPixel(22 + drawMark_XPOS, 9 + drawMark_YPOS, 0, 1, 0);
  drawPixel(12 + drawMark_XPOS, 10 + drawMark_YPOS, 0, 1, 1);
  drawPixel(14 + drawMark_XPOS, 10 + drawMark_YPOS, 1, 1, 0);
  drawPixel(15 + drawMark_XPOS, 10 + drawMark_YPOS, 156, 91, 60);
  drawPixel(16 + drawMark_XPOS, 10 + drawMark_YPOS, 157, 90, 61);
  drawPixel(17 + drawMark_XPOS, 10 + drawMark_YPOS, 157, 90, 60);
  drawPixel(18 + drawMark_XPOS, 10 + drawMark_YPOS, 156, 90, 60);
  drawPixel(19 + drawMark_XPOS, 10 + drawMark_YPOS, 156, 90, 61);
  drawPixel(20 + drawMark_XPOS, 10 + drawMark_YPOS, 157, 90, 60);
  drawPixel(21 + drawMark_XPOS, 10 + drawMark_YPOS, 0, 0, 0);
  drawPixel(11 + drawMark_XPOS, 11 + drawMark_YPOS, 0, 1, 0);
  drawPixel(12 + drawMark_XPOS, 11 + drawMark_YPOS, 156, 90, 60);
  drawPixel(13 + drawMark_XPOS, 11 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 11 + drawMark_YPOS, 0, 1, 0);
  drawPixel(15 + drawMark_XPOS, 11 + drawMark_YPOS, 156, 90, 60);
  drawPixel(16 + drawMark_XPOS, 11 + drawMark_YPOS, 1, 0, 0);
  drawPixel(17 + drawMark_XPOS, 11 + drawMark_YPOS, 0, 0, 0);
  drawPixel(18 + drawMark_XPOS, 11 + drawMark_YPOS, 0, 0, 1);
  drawPixel(19 + drawMark_XPOS, 11 + drawMark_YPOS, 156, 90, 60);
  drawPixel(20 + drawMark_XPOS, 11 + drawMark_YPOS, 0, 0, 0);
  drawPixel(11 + drawMark_XPOS, 12 + drawMark_YPOS, 0, 0, 0);
  drawPixel(12 + drawMark_XPOS, 12 + drawMark_YPOS, 156, 90, 60);
  drawPixel(13 + drawMark_XPOS, 12 + drawMark_YPOS, 157, 90, 60);
  drawPixel(14 + drawMark_XPOS, 12 + drawMark_YPOS, 156, 90, 60);
  drawPixel(15 + drawMark_XPOS, 12 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 12 + drawMark_YPOS, 255, 249, 189);
  drawPixel(17 + drawMark_XPOS, 12 + drawMark_YPOS, 255, 249, 188);
  drawPixel(18 + drawMark_XPOS, 12 + drawMark_YPOS, 255, 249, 189);
  drawPixel(19 + drawMark_XPOS, 12 + drawMark_YPOS, 0, 1, 0);
  drawPixel(12 + drawMark_XPOS, 13 + drawMark_YPOS, 0, 1, 0);
  drawPixel(13 + drawMark_XPOS, 13 + drawMark_YPOS, 156, 90, 60);
  drawPixel(14 + drawMark_XPOS, 13 + drawMark_YPOS, 157, 91, 60);
  drawPixel(15 + drawMark_XPOS, 13 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 13 + drawMark_YPOS, 255, 249, 188);
  drawPixel(17 + drawMark_XPOS, 13 + drawMark_YPOS, 255, 249, 189);
  drawPixel(18 + drawMark_XPOS, 13 + drawMark_YPOS, 255, 248, 188);
  drawPixel(19 + drawMark_XPOS, 13 + drawMark_YPOS, 1, 0, 0);
  drawPixel(13 + drawMark_XPOS, 14 + drawMark_YPOS, 0, 0, 0);
  drawPixel(14 + drawMark_XPOS, 14 + drawMark_YPOS, 0, 0, 0);
  drawPixel(15 + drawMark_XPOS, 14 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 14 + drawMark_YPOS, 254, 249, 189);
  drawPixel(17 + drawMark_XPOS, 14 + drawMark_YPOS, 255, 249, 189);
  drawPixel(18 + drawMark_XPOS, 14 + drawMark_YPOS, 255, 249, 188);
  drawPixel(19 + drawMark_XPOS, 14 + drawMark_YPOS, 1, 0, 0);
  drawPixel(16 + drawMark_XPOS, 15 + drawMark_YPOS, 0, 1, 0);
  drawPixel(17 + drawMark_XPOS, 15 + drawMark_YPOS, 0, 1, 1);
  drawPixel(18 + drawMark_XPOS, 15 + drawMark_YPOS, 1, 0, 0);
  drawPixel(17 + drawMark_XPOS, 16 + drawMark_YPOS, 1, 0, 0);
  drawPixel(15 + drawMark_XPOS, 17 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 17 + drawMark_YPOS, 1, 0, 0);
  drawPixel(17 + drawMark_XPOS, 17 + drawMark_YPOS, 0, 0, 0);
  drawPixel(18 + drawMark_XPOS, 17 + drawMark_YPOS, 0, 0, 0);
  drawPixel(19 + drawMark_XPOS, 17 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 18 + drawMark_YPOS, 0, 1, 1);
  drawPixel(17 + drawMark_XPOS, 18 + drawMark_YPOS, 0, 0, 1);
  drawPixel(20 + drawMark_XPOS, 18 + drawMark_YPOS, 0, 0, 1);
  drawPixel(14 + drawMark_XPOS, 19 + drawMark_YPOS, 1, 1, 0);
  drawPixel(17 + drawMark_XPOS, 19 + drawMark_YPOS, 0, 1, 0);
  drawPixel(20 + drawMark_XPOS, 19 + drawMark_YPOS, 1, 0, 0);
  drawPixel(16 + drawMark_XPOS, 20 + drawMark_YPOS, 0, 0, 0);
  drawPixel(17 + drawMark_XPOS, 20 + drawMark_YPOS, 0, 1, 0);
  drawPixel(18 + drawMark_XPOS, 20 + drawMark_YPOS, 0, 0, 1);
  drawPixel(15 + drawMark_XPOS, 21 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 21 + drawMark_YPOS, 254, 127, 0);
  drawPixel(17 + drawMark_XPOS, 21 + drawMark_YPOS, 255, 126, 0);
  drawPixel(18 + drawMark_XPOS, 21 + drawMark_YPOS, 255, 126, 1);
  drawPixel(19 + drawMark_XPOS, 21 + drawMark_YPOS, 0, 0, 0);
  drawPixel(14 + drawMark_XPOS, 22 + drawMark_YPOS, 0, 0, 0);
  drawPixel(15 + drawMark_XPOS, 22 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 22 + drawMark_YPOS, 254, 126, 0);
  drawPixel(17 + drawMark_XPOS, 22 + drawMark_YPOS, 254, 126, 0);
  drawPixel(18 + drawMark_XPOS, 22 + drawMark_YPOS, 255, 126, 1);
  drawPixel(19 + drawMark_XPOS, 22 + drawMark_YPOS, 0, 0, 0);
  drawPixel(20 + drawMark_XPOS, 22 + drawMark_YPOS, 0, 0, 0);
  drawPixel(13 + drawMark_XPOS, 23 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 23 + drawMark_YPOS, 255, 127, 0);
  drawPixel(15 + drawMark_XPOS, 23 + drawMark_YPOS, 255, 126, 1);
  drawPixel(16 + drawMark_XPOS, 23 + drawMark_YPOS, 255, 126, 0);
  drawPixel(17 + drawMark_XPOS, 23 + drawMark_YPOS, 0, 0, 0);
  drawPixel(18 + drawMark_XPOS, 23 + drawMark_YPOS, 255, 126, 1);
  drawPixel(19 + drawMark_XPOS, 23 + drawMark_YPOS, 254, 126, 0);
  drawPixel(20 + drawMark_XPOS, 23 + drawMark_YPOS, 255, 127, 0);
  drawPixel(21 + drawMark_XPOS, 23 + drawMark_YPOS, 0, 0, 1);
  drawPixel(13 + drawMark_XPOS, 24 + drawMark_YPOS, 1, 1, 0);
  drawPixel(14 + drawMark_XPOS, 24 + drawMark_YPOS, 255, 127, 1);
  drawPixel(15 + drawMark_XPOS, 24 + drawMark_YPOS, 255, 126, 1);
  drawPixel(16 + drawMark_XPOS, 24 + drawMark_YPOS, 0, 0, 0);
  drawPixel(18 + drawMark_XPOS, 24 + drawMark_YPOS, 1, 0, 1);
  drawPixel(19 + drawMark_XPOS, 24 + drawMark_YPOS, 255, 126, 0);
  drawPixel(20 + drawMark_XPOS, 24 + drawMark_YPOS, 255, 126, 0);
  drawPixel(21 + drawMark_XPOS, 24 + drawMark_YPOS, 1, 0, 0);
  drawPixel(13 + drawMark_XPOS, 25 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 25 + drawMark_YPOS, 0, 1, 0);
  drawPixel(15 + drawMark_XPOS, 25 + drawMark_YPOS, 0, 0, 0);
  drawPixel(16 + drawMark_XPOS, 25 + drawMark_YPOS, 1, 0, 0);
  drawPixel(18 + drawMark_XPOS, 25 + drawMark_YPOS, 0, 1, 0);
  drawPixel(19 + drawMark_XPOS, 25 + drawMark_YPOS, 0, 0, 1);
  drawPixel(20 + drawMark_XPOS, 25 + drawMark_YPOS, 1, 1, 0);
  drawPixel(21 + drawMark_XPOS, 25 + drawMark_YPOS, 0, 0, 1);
  drawPixel(15 + drawMark_XPOS, 26 + drawMark_YPOS, 0, 0, 0);
  drawPixel(19 + drawMark_XPOS, 26 + drawMark_YPOS, 1, 0, 0);
  drawPixel(14 + drawMark_XPOS, 27 + drawMark_YPOS, 0, 1, 0);
  drawPixel(15 + drawMark_XPOS, 27 + drawMark_YPOS, 0, 0, 1);
  drawPixel(19 + drawMark_XPOS, 27 + drawMark_YPOS, 1, 1, 0);
  drawPixel(20 + drawMark_XPOS, 27 + drawMark_YPOS, 0, 1, 1);
}

void smallMark() {
  drawPixel(37 + smallMark_XPOS, 11 + smallMark_YPOS, 157, 91, 60);
  drawPixel(38 + smallMark_XPOS, 11 + smallMark_YPOS, 156, 91, 60);
  drawPixel(36 + smallMark_XPOS, 12 + smallMark_YPOS, 156, 90, 61);
  drawPixel(37 + smallMark_XPOS, 12 + smallMark_YPOS, 156, 90, 60);
  drawPixel(38 + smallMark_XPOS, 12 + smallMark_YPOS, 157, 91, 61);
  drawPixel(39 + smallMark_XPOS, 12 + smallMark_YPOS, 157, 90, 60);
  drawPixel(40 + smallMark_XPOS, 12 + smallMark_YPOS, 157, 91, 60);
  drawPixel(41 + smallMark_XPOS, 12 + smallMark_YPOS, 157, 90, 60);
  drawPixel(35 + smallMark_XPOS, 13 + smallMark_YPOS, 156, 91, 60);
  drawPixel(36 + smallMark_XPOS, 13 + smallMark_YPOS, 156, 91, 61);
  drawPixel(37 + smallMark_XPOS, 13 + smallMark_YPOS, 157, 90, 60);
  drawPixel(38 + smallMark_XPOS, 13 + smallMark_YPOS, 156, 90, 60);
  drawPixel(39 + smallMark_XPOS, 13 + smallMark_YPOS, 156, 91, 60);
  drawPixel(40 + smallMark_XPOS, 13 + smallMark_YPOS, 156, 90, 60);
  drawPixel(36 + smallMark_XPOS, 14 + smallMark_YPOS, 156, 90, 60);
  drawPixel(37 + smallMark_XPOS, 14 + smallMark_YPOS, 0, 1, 0);
  drawPixel(38 + smallMark_XPOS, 14 + smallMark_YPOS, 0, 0, 0);
  drawPixel(39 + smallMark_XPOS, 14 + smallMark_YPOS, 1, 0, 1);
  drawPixel(37 + smallMark_XPOS, 15 + smallMark_YPOS, 1, 0, 0);
  drawPixel(38 + smallMark_XPOS, 15 + smallMark_YPOS, 0, 0, 0);
  drawPixel(39 + smallMark_XPOS, 15 + smallMark_YPOS, 0, 1, 0);
  drawPixel(38 + smallMark_XPOS, 16 + smallMark_YPOS, 1, 0, 0);
  drawPixel(36 + smallMark_XPOS, 17 + smallMark_YPOS, 0, 0, 1);
  drawPixel(37 + smallMark_XPOS, 17 + smallMark_YPOS, 0, 1, 0);
  drawPixel(38 + smallMark_XPOS, 17 + smallMark_YPOS, 0, 1, 1);
  drawPixel(39 + smallMark_XPOS, 17 + smallMark_YPOS, 1, 0, 1);
  drawPixel(40 + smallMark_XPOS, 17 + smallMark_YPOS, 0, 1, 0);
  drawPixel(38 + smallMark_XPOS, 18 + smallMark_YPOS, 1, 0, 1);
  drawPixel(37 + smallMark_XPOS, 19 + smallMark_YPOS, 254, 126, 1);
  drawPixel(38 + smallMark_XPOS, 19 + smallMark_YPOS, 255, 127, 0);
  drawPixel(39 + smallMark_XPOS, 19 + smallMark_YPOS, 255, 126, 1);
  drawPixel(36 + smallMark_XPOS, 20 + smallMark_YPOS, 255, 126, 1);
  drawPixel(37 + smallMark_XPOS, 20 + smallMark_YPOS, 255, 126, 0);
  drawPixel(38 + smallMark_XPOS, 20 + smallMark_YPOS, 255, 127, 0);
  drawPixel(39 + smallMark_XPOS, 20 + smallMark_YPOS, 255, 126, 0);
  drawPixel(40 + smallMark_XPOS, 20 + smallMark_YPOS, 254, 126, 0);
  drawPixel(36 + smallMark_XPOS, 21 + smallMark_YPOS, 255, 126, 0);
  drawPixel(37 + smallMark_XPOS, 21 + smallMark_YPOS, 255, 126, 1);
  drawPixel(39 + smallMark_XPOS, 21 + smallMark_YPOS, 254, 126, 0);
  drawPixel(40 + smallMark_XPOS, 21 + smallMark_YPOS, 255, 126, 0);
  drawPixel(36 + smallMark_XPOS, 22 + smallMark_YPOS, 0, 1, 0);
  drawPixel(40 + smallMark_XPOS, 22 + smallMark_YPOS, 0, 0, 0);
}

void breadOnTable() {
  drawPixel(32 + breadOnTable_XPOS, 9 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(33 + breadOnTable_XPOS, 9 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(34 + breadOnTable_XPOS, 9 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(35 + breadOnTable_XPOS, 9 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(31 + breadOnTable_XPOS, 10 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(32 + breadOnTable_XPOS, 10 + breadOnTable_YPOS, 254, 126, 0);
  drawPixel(33 + breadOnTable_XPOS, 10 + breadOnTable_YPOS, 254, 126, 0);
  drawPixel(34 + breadOnTable_XPOS, 10 + breadOnTable_YPOS, 184, 89, 0);
  drawPixel(35 + breadOnTable_XPOS, 10 + breadOnTable_YPOS, 185, 89, 1);
  drawPixel(36 + breadOnTable_XPOS, 10 + breadOnTable_YPOS, 1, 1, 0);
  drawPixel(30 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(31 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 185, 89, 0);
  drawPixel(32 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 244, 229, 156);
  drawPixel(33 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 245, 228, 156);
  drawPixel(34 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 255, 126, 1);
  drawPixel(35 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 184, 88, 0);
  drawPixel(36 + breadOnTable_XPOS, 11 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(29 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(30 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 254, 126, 1);
  drawPixel(31 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 254, 127, 0);
  drawPixel(32 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 255, 126, 0);
  drawPixel(33 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 245, 228, 156);
  drawPixel(34 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 254, 127, 0);
  drawPixel(35 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 184, 89, 1);
  drawPixel(36 + breadOnTable_XPOS, 12 + breadOnTable_YPOS, 1, 0, 0);
  drawPixel(28 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(29 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 185, 89, 0);
  drawPixel(30 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 245, 228, 156);
  drawPixel(31 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 245, 228, 156);
  drawPixel(32 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 255, 126, 0);
  drawPixel(33 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 244, 228, 156);
  drawPixel(34 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 255, 126, 0);
  drawPixel(35 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 185, 89, 1);
  drawPixel(36 + breadOnTable_XPOS, 13 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(27 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(28 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 184, 89, 0);
  drawPixel(29 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 254, 126, 0);
  drawPixel(30 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 255, 126, 1);
  drawPixel(31 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 245, 228, 156);
  drawPixel(32 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 254, 126, 0);
  drawPixel(33 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 255, 127, 1);
  drawPixel(34 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 185, 89, 0);
  drawPixel(35 + breadOnTable_XPOS, 14 + breadOnTable_YPOS, 1, 1, 0);
  drawPixel(27 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(28 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 185, 89, 0);
  drawPixel(29 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 255, 126, 0);
  drawPixel(30 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 254, 126, 0);
  drawPixel(31 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 245, 229, 156);
  drawPixel(32 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 255, 127, 0);
  drawPixel(33 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 184, 89, 0);
  drawPixel(34 + breadOnTable_XPOS, 15 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(27 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(28 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 255, 126, 1);
  drawPixel(29 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 255, 126, 1);
  drawPixel(30 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 255, 127, 0);
  drawPixel(31 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 255, 126, 0);
  drawPixel(32 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 185, 89, 0);
  drawPixel(33 + breadOnTable_XPOS, 16 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(27 + breadOnTable_XPOS, 17 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(28 + breadOnTable_XPOS, 17 + breadOnTable_YPOS, 184, 89, 1);
  drawPixel(29 + breadOnTable_XPOS, 17 + breadOnTable_YPOS, 184, 88, 0);
  drawPixel(30 + breadOnTable_XPOS, 17 + breadOnTable_YPOS, 184, 89, 1);
  drawPixel(31 + breadOnTable_XPOS, 17 + breadOnTable_YPOS, 184, 89, 1);
  drawPixel(32 + breadOnTable_XPOS, 17 + breadOnTable_YPOS, 1, 0, 0);
  drawPixel(28 + breadOnTable_XPOS, 18 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(29 + breadOnTable_XPOS, 18 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(30 + breadOnTable_XPOS, 18 + breadOnTable_YPOS, 1, 0, 1);
  drawPixel(31 + breadOnTable_XPOS, 18 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(25 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(26 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(27 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(28 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(29 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 1, 0, 0);
  drawPixel(30 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 1, 1, 0);
  drawPixel(31 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(32 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(33 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 1, 1, 0);
  drawPixel(34 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(35 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(36 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 1, 0, 0);
  drawPixel(37 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(38 + breadOnTable_XPOS, 19 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(24 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(25 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(26 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(27 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(28 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 157, 90, 61);
  drawPixel(29 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(30 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 91, 60);
  drawPixel(31 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 61);
  drawPixel(32 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 157, 91, 60);
  drawPixel(33 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 61);
  drawPixel(34 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(35 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 91, 60);
  drawPixel(36 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 91, 61);
  drawPixel(37 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(38 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(39 + breadOnTable_XPOS, 20 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(25 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 1, 0, 0);
  drawPixel(26 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 156, 91, 60);
  drawPixel(27 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(28 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(29 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(30 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(31 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 1, 1, 0);
  drawPixel(32 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(33 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(34 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(35 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(36 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(37 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 157, 91, 60);
  drawPixel(38 + breadOnTable_XPOS, 21 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(25 + breadOnTable_XPOS, 22 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(26 + breadOnTable_XPOS, 22 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(27 + breadOnTable_XPOS, 22 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(36 + breadOnTable_XPOS, 22 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(37 + breadOnTable_XPOS, 22 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(38 + breadOnTable_XPOS, 22 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(25 + breadOnTable_XPOS, 23 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(26 + breadOnTable_XPOS, 23 + breadOnTable_YPOS, 157, 90, 60);
  drawPixel(27 + breadOnTable_XPOS, 23 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(36 + breadOnTable_XPOS, 23 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(37 + breadOnTable_XPOS, 23 + breadOnTable_YPOS, 157, 90, 60);
  drawPixel(38 + breadOnTable_XPOS, 23 + breadOnTable_YPOS, 1, 0, 0);
  drawPixel(25 + breadOnTable_XPOS, 24 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(26 + breadOnTable_XPOS, 24 + breadOnTable_YPOS, 156, 90, 60);
  drawPixel(27 + breadOnTable_XPOS, 24 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(36 + breadOnTable_XPOS, 24 + breadOnTable_YPOS, 0, 0, 1);
  drawPixel(37 + breadOnTable_XPOS, 24 + breadOnTable_YPOS, 156, 91, 60);
  drawPixel(38 + breadOnTable_XPOS, 24 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(25 + breadOnTable_XPOS, 25 + breadOnTable_YPOS, 0, 1, 1);
  drawPixel(26 + breadOnTable_XPOS, 25 + breadOnTable_YPOS, 157, 90, 60);
  drawPixel(27 + breadOnTable_XPOS, 25 + breadOnTable_YPOS, 0, 0, 0);
  drawPixel(36 + breadOnTable_XPOS, 25 + breadOnTable_YPOS, 0, 1, 0);
  drawPixel(37 + breadOnTable_XPOS, 25 + breadOnTable_YPOS, 156, 91, 60);
  drawPixel(38 + breadOnTable_XPOS, 25 + breadOnTable_YPOS, 1, 0, 1);
  drawPixel(26 + breadOnTable_XPOS, 26 + breadOnTable_YPOS, 1, 1, 0);
  drawPixel(37 + breadOnTable_XPOS, 26 + breadOnTable_YPOS, 0, 0, 1);
}

void window() {
  drawPixel(37 + window_XPOS, 7 + window_YPOS, 0, 0, 1);
  drawPixel(38 + window_XPOS, 7 + window_YPOS, 1, 0, 0);
  drawPixel(39 + window_XPOS, 7 + window_YPOS, 0, 1, 0);
  drawPixel(40 + window_XPOS, 7 + window_YPOS, 0, 0, 1);
  drawPixel(41 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(42 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(43 + window_XPOS, 7 + window_YPOS, 0, 0, 1);
  drawPixel(44 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(45 + window_XPOS, 7 + window_YPOS, 0, 1, 0);
  drawPixel(46 + window_XPOS, 7 + window_YPOS, 0, 0, 1);
  drawPixel(47 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(48 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(49 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(50 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(51 + window_XPOS, 7 + window_YPOS, 0, 1, 0);
  drawPixel(52 + window_XPOS, 7 + window_YPOS, 0, 0, 1);
  drawPixel(53 + window_XPOS, 7 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 8 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 8 + window_YPOS, 229, 171, 122);
  drawPixel(39 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(40 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(41 + window_XPOS, 8 + window_YPOS, 229, 171, 122);
  drawPixel(42 + window_XPOS, 8 + window_YPOS, 229, 170, 123);
  drawPixel(43 + window_XPOS, 8 + window_YPOS, 228, 170, 122);
  drawPixel(44 + window_XPOS, 8 + window_YPOS, 229, 171, 122);
  drawPixel(45 + window_XPOS, 8 + window_YPOS, 229, 170, 123);
  drawPixel(46 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(47 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(48 + window_XPOS, 8 + window_YPOS, 229, 170, 123);
  drawPixel(49 + window_XPOS, 8 + window_YPOS, 228, 170, 122);
  drawPixel(50 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(51 + window_XPOS, 8 + window_YPOS, 229, 170, 123);
  drawPixel(52 + window_XPOS, 8 + window_YPOS, 229, 170, 122);
  drawPixel(53 + window_XPOS, 8 + window_YPOS, 229, 171, 122);
  drawPixel(54 + window_XPOS, 8 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 9 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 9 + window_YPOS, 0, 0, 1);
  drawPixel(39 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(40 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(41 + window_XPOS, 9 + window_YPOS, 0, 0, 1);
  drawPixel(42 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(43 + window_XPOS, 9 + window_YPOS, 0, 1, 0);
  drawPixel(44 + window_XPOS, 9 + window_YPOS, 0, 0, 1);
  drawPixel(45 + window_XPOS, 9 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(48 + window_XPOS, 9 + window_YPOS, 1, 0, 0);
  drawPixel(49 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(50 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(51 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(52 + window_XPOS, 9 + window_YPOS, 0, 1, 0);
  drawPixel(53 + window_XPOS, 9 + window_YPOS, 229, 170, 123);
  drawPixel(54 + window_XPOS, 9 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 10 + window_YPOS, 0, 1, 0);
  drawPixel(37 + window_XPOS, 10 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 10 + window_YPOS, 1, 0, 0);
  drawPixel(39 + window_XPOS, 10 + window_YPOS, 0, 182, 239);
  drawPixel(40 + window_XPOS, 10 + window_YPOS, 0, 183, 239);
  drawPixel(41 + window_XPOS, 10 + window_YPOS, 1, 183, 239);
  drawPixel(42 + window_XPOS, 10 + window_YPOS, 0, 183, 239);
  drawPixel(43 + window_XPOS, 10 + window_YPOS, 0, 183, 239);
  drawPixel(44 + window_XPOS, 10 + window_YPOS, 0, 0, 0);
  drawPixel(45 + window_XPOS, 10 + window_YPOS, 229, 171, 122);
  drawPixel(46 + window_XPOS, 10 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 10 + window_YPOS, 1, 183, 239);
  drawPixel(48 + window_XPOS, 10 + window_YPOS, 0, 182, 239);
  drawPixel(49 + window_XPOS, 10 + window_YPOS, 0, 183, 238);
  drawPixel(50 + window_XPOS, 10 + window_YPOS, 0, 183, 239);
  drawPixel(51 + window_XPOS, 10 + window_YPOS, 0, 183, 239);
  drawPixel(52 + window_XPOS, 10 + window_YPOS, 0, 0, 0);
  drawPixel(53 + window_XPOS, 10 + window_YPOS, 228, 170, 122);
  drawPixel(54 + window_XPOS, 10 + window_YPOS, 0, 1, 0);
  drawPixel(36 + window_XPOS, 11 + window_YPOS, 0, 0, 1);
  drawPixel(37 + window_XPOS, 11 + window_YPOS, 228, 170, 122);
  drawPixel(38 + window_XPOS, 11 + window_YPOS, 0, 1, 0);
  drawPixel(39 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(40 + window_XPOS, 11 + window_YPOS, 1, 183, 239);
  drawPixel(41 + window_XPOS, 11 + window_YPOS, 0, 182, 239);
  drawPixel(42 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(43 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(44 + window_XPOS, 11 + window_YPOS, 0, 1, 0);
  drawPixel(45 + window_XPOS, 11 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 11 + window_YPOS, 1, 0, 0);
  drawPixel(47 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(48 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(49 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(50 + window_XPOS, 11 + window_YPOS, 0, 182, 239);
  drawPixel(51 + window_XPOS, 11 + window_YPOS, 0, 183, 239);
  drawPixel(52 + window_XPOS, 11 + window_YPOS, 1, 0, 0);
  drawPixel(53 + window_XPOS, 11 + window_YPOS, 229, 170, 122);
  drawPixel(54 + window_XPOS, 11 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 12 + window_YPOS, 1, 0, 0);
  drawPixel(37 + window_XPOS, 12 + window_YPOS, 229, 171, 122);
  drawPixel(38 + window_XPOS, 12 + window_YPOS, 0, 0, 1);
  drawPixel(39 + window_XPOS, 12 + window_YPOS, 0, 183, 239);
  drawPixel(40 + window_XPOS, 12 + window_YPOS, 0, 182, 239);
  drawPixel(41 + window_XPOS, 12 + window_YPOS, 0, 183, 238);
  drawPixel(42 + window_XPOS, 12 + window_YPOS, 0, 183, 239);
  drawPixel(43 + window_XPOS, 12 + window_YPOS, 0, 182, 239);
  drawPixel(44 + window_XPOS, 12 + window_YPOS, 0, 0, 1);
  drawPixel(45 + window_XPOS, 12 + window_YPOS, 228, 170, 122);
  drawPixel(46 + window_XPOS, 12 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 12 + window_YPOS, 0, 183, 239);
  drawPixel(48 + window_XPOS, 12 + window_YPOS, 1, 183, 239);
  drawPixel(49 + window_XPOS, 12 + window_YPOS, 0, 182, 239);
  drawPixel(50 + window_XPOS, 12 + window_YPOS, 0, 183, 239);
  drawPixel(51 + window_XPOS, 12 + window_YPOS, 1, 183, 239);
  drawPixel(52 + window_XPOS, 12 + window_YPOS, 0, 1, 0);
  drawPixel(53 + window_XPOS, 12 + window_YPOS, 229, 170, 123);
  drawPixel(54 + window_XPOS, 12 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 13 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 13 + window_YPOS, 229, 170, 123);
  drawPixel(38 + window_XPOS, 13 + window_YPOS, 1, 0, 0);
  drawPixel(39 + window_XPOS, 13 + window_YPOS, 0, 183, 239);
  drawPixel(40 + window_XPOS, 13 + window_YPOS, 0, 183, 238);
  drawPixel(41 + window_XPOS, 13 + window_YPOS, 0, 183, 239);
  drawPixel(42 + window_XPOS, 13 + window_YPOS, 0, 182, 239);
  drawPixel(43 + window_XPOS, 13 + window_YPOS, 0, 183, 239);
  drawPixel(44 + window_XPOS, 13 + window_YPOS, 0, 0, 0);
  drawPixel(45 + window_XPOS, 13 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 13 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 13 + window_YPOS, 1, 183, 239);
  drawPixel(48 + window_XPOS, 13 + window_YPOS, 0, 182, 239);
  drawPixel(49 + window_XPOS, 13 + window_YPOS, 0, 183, 239);
  drawPixel(50 + window_XPOS, 13 + window_YPOS, 0, 183, 239);
  drawPixel(51 + window_XPOS, 13 + window_YPOS, 0, 182, 239);
  drawPixel(52 + window_XPOS, 13 + window_YPOS, 0, 0, 0);
  drawPixel(53 + window_XPOS, 13 + window_YPOS, 229, 170, 122);
  drawPixel(54 + window_XPOS, 13 + window_YPOS, 0, 1, 0);
  drawPixel(36 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 14 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 14 + window_YPOS, 0, 1, 0);
  drawPixel(39 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(40 + window_XPOS, 14 + window_YPOS, 1, 0, 0);
  drawPixel(41 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(42 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(43 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(44 + window_XPOS, 14 + window_YPOS, 0, 1, 0);
  drawPixel(45 + window_XPOS, 14 + window_YPOS, 229, 170, 123);
  drawPixel(46 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(48 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(49 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(50 + window_XPOS, 14 + window_YPOS, 0, 1, 0);
  drawPixel(51 + window_XPOS, 14 + window_YPOS, 0, 0, 0);
  drawPixel(52 + window_XPOS, 14 + window_YPOS, 1, 0, 0);
  drawPixel(53 + window_XPOS, 14 + window_YPOS, 229, 171, 122);
  drawPixel(54 + window_XPOS, 14 + window_YPOS, 0, 0, 1);
  drawPixel(36 + window_XPOS, 15 + window_YPOS, 1, 0, 0);
  drawPixel(37 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(39 + window_XPOS, 15 + window_YPOS, 228, 170, 122);
  drawPixel(40 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(41 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(42 + window_XPOS, 15 + window_YPOS, 228, 170, 122);
  drawPixel(43 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(44 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(45 + window_XPOS, 15 + window_YPOS, 228, 170, 122);
  drawPixel(46 + window_XPOS, 15 + window_YPOS, 229, 171, 122);
  drawPixel(47 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(48 + window_XPOS, 15 + window_YPOS, 228, 170, 122);
  drawPixel(49 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(50 + window_XPOS, 15 + window_YPOS, 229, 170, 123);
  drawPixel(51 + window_XPOS, 15 + window_YPOS, 228, 170, 122);
  drawPixel(52 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(53 + window_XPOS, 15 + window_YPOS, 229, 170, 122);
  drawPixel(54 + window_XPOS, 15 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 16 + window_YPOS, 229, 170, 123);
  drawPixel(38 + window_XPOS, 16 + window_YPOS, 1, 0, 0);
  drawPixel(39 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(40 + window_XPOS, 16 + window_YPOS, 0, 0, 1);
  drawPixel(41 + window_XPOS, 16 + window_YPOS, 1, 0, 0);
  drawPixel(42 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(43 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(44 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(45 + window_XPOS, 16 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(48 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(49 + window_XPOS, 16 + window_YPOS, 0, 0, 1);
  drawPixel(50 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(51 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(52 + window_XPOS, 16 + window_YPOS, 0, 0, 1);
  drawPixel(53 + window_XPOS, 16 + window_YPOS, 228, 170, 122);
  drawPixel(54 + window_XPOS, 16 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 17 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 17 + window_YPOS, 228, 170, 122);
  drawPixel(38 + window_XPOS, 17 + window_YPOS, 0, 0, 0);
  drawPixel(39 + window_XPOS, 17 + window_YPOS, 0, 183, 239);
  drawPixel(40 + window_XPOS, 17 + window_YPOS, 1, 183, 239);
  drawPixel(41 + window_XPOS, 17 + window_YPOS, 0, 182, 239);
  drawPixel(42 + window_XPOS, 17 + window_YPOS, 0, 183, 238);
  drawPixel(43 + window_XPOS, 17 + window_YPOS, 1, 183, 239);
  drawPixel(44 + window_XPOS, 17 + window_YPOS, 0, 1, 0);
  drawPixel(45 + window_XPOS, 17 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 17 + window_YPOS, 1, 0, 0);
  drawPixel(47 + window_XPOS, 17 + window_YPOS, 0, 182, 239);
  drawPixel(48 + window_XPOS, 17 + window_YPOS, 0, 183, 238);
  drawPixel(49 + window_XPOS, 17 + window_YPOS, 0, 183, 239);
  drawPixel(50 + window_XPOS, 17 + window_YPOS, 0, 183, 239);
  drawPixel(51 + window_XPOS, 17 + window_YPOS, 0, 183, 238);
  drawPixel(52 + window_XPOS, 17 + window_YPOS, 0, 0, 0);
  drawPixel(53 + window_XPOS, 17 + window_YPOS, 229, 170, 122);
  drawPixel(54 + window_XPOS, 17 + window_YPOS, 0, 0, 1);
  drawPixel(36 + window_XPOS, 18 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 18 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 18 + window_YPOS, 0, 0, 1);
  drawPixel(39 + window_XPOS, 18 + window_YPOS, 1, 183, 239);
  drawPixel(40 + window_XPOS, 18 + window_YPOS, 0, 183, 239);
  drawPixel(41 + window_XPOS, 18 + window_YPOS, 0, 183, 238);
  drawPixel(42 + window_XPOS, 18 + window_YPOS, 1, 183, 239);
  drawPixel(43 + window_XPOS, 18 + window_YPOS, 0, 183, 239);
  drawPixel(44 + window_XPOS, 18 + window_YPOS, 0, 0, 0);
  drawPixel(45 + window_XPOS, 18 + window_YPOS, 228, 170, 122);
  drawPixel(46 + window_XPOS, 18 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 18 + window_YPOS, 0, 183, 239);
  drawPixel(48 + window_XPOS, 18 + window_YPOS, 0, 183, 239);
  drawPixel(49 + window_XPOS, 18 + window_YPOS, 0, 183, 239);
  drawPixel(50 + window_XPOS, 18 + window_YPOS, 0, 183, 238);
  drawPixel(51 + window_XPOS, 18 + window_YPOS, 1, 183, 239);
  drawPixel(52 + window_XPOS, 18 + window_YPOS, 0, 0, 0);
  drawPixel(53 + window_XPOS, 18 + window_YPOS, 229, 170, 122);
  drawPixel(54 + window_XPOS, 18 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 19 + window_YPOS, 0, 1, 0);
  drawPixel(37 + window_XPOS, 19 + window_YPOS, 229, 170, 122);
  drawPixel(38 + window_XPOS, 19 + window_YPOS, 0, 0, 0);
  drawPixel(39 + window_XPOS, 19 + window_YPOS, 0, 183, 239);
  drawPixel(40 + window_XPOS, 19 + window_YPOS, 0, 183, 238);
  drawPixel(41 + window_XPOS, 19 + window_YPOS, 1, 183, 239);
  drawPixel(42 + window_XPOS, 19 + window_YPOS, 0, 183, 239);
  drawPixel(43 + window_XPOS, 19 + window_YPOS, 0, 183, 238);
  drawPixel(44 + window_XPOS, 19 + window_YPOS, 1, 0, 0);
  drawPixel(45 + window_XPOS, 19 + window_YPOS, 229, 171, 122);
  drawPixel(46 + window_XPOS, 19 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 19 + window_YPOS, 1, 183, 239);
  drawPixel(48 + window_XPOS, 19 + window_YPOS, 0, 182, 239);
  drawPixel(49 + window_XPOS, 19 + window_YPOS, 0, 183, 239);
  drawPixel(50 + window_XPOS, 19 + window_YPOS, 1, 183, 239);
  drawPixel(51 + window_XPOS, 19 + window_YPOS, 0, 183, 239);
  drawPixel(52 + window_XPOS, 19 + window_YPOS, 0, 0, 0);
  drawPixel(53 + window_XPOS, 19 + window_YPOS, 228, 170, 122);
  drawPixel(54 + window_XPOS, 19 + window_YPOS, 0, 1, 0);
  drawPixel(36 + window_XPOS, 20 + window_YPOS, 0, 0, 1);
  drawPixel(37 + window_XPOS, 20 + window_YPOS, 228, 170, 122);
  drawPixel(38 + window_XPOS, 20 + window_YPOS, 0, 0, 0);
  drawPixel(39 + window_XPOS, 20 + window_YPOS, 0, 183, 238);
  drawPixel(40 + window_XPOS, 20 + window_YPOS, 1, 183, 239);
  drawPixel(41 + window_XPOS, 20 + window_YPOS, 0, 183, 239);
  drawPixel(42 + window_XPOS, 20 + window_YPOS, 0, 183, 238);
  drawPixel(43 + window_XPOS, 20 + window_YPOS, 0, 183, 239);
  drawPixel(44 + window_XPOS, 20 + window_YPOS, 0, 1, 0);
  drawPixel(45 + window_XPOS, 20 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 20 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 20 + window_YPOS, 0, 182, 239);
  drawPixel(48 + window_XPOS, 20 + window_YPOS, 0, 183, 238);
  drawPixel(49 + window_XPOS, 20 + window_YPOS, 1, 183, 239);
  drawPixel(50 + window_XPOS, 20 + window_YPOS, 0, 182, 239);
  drawPixel(51 + window_XPOS, 20 + window_YPOS, 0, 183, 239);
  drawPixel(52 + window_XPOS, 20 + window_YPOS, 1, 0, 0);
  drawPixel(53 + window_XPOS, 20 + window_YPOS, 229, 171, 122);
  drawPixel(54 + window_XPOS, 20 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 21 + window_YPOS, 1, 0, 0);
  drawPixel(37 + window_XPOS, 21 + window_YPOS, 229, 171, 122);
  drawPixel(38 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(39 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(40 + window_XPOS, 21 + window_YPOS, 0, 1, 0);
  drawPixel(41 + window_XPOS, 21 + window_YPOS, 0, 0, 1);
  drawPixel(42 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(43 + window_XPOS, 21 + window_YPOS, 0, 1, 0);
  drawPixel(44 + window_XPOS, 21 + window_YPOS, 0, 0, 1);
  drawPixel(45 + window_XPOS, 21 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(47 + window_XPOS, 21 + window_YPOS, 0, 0, 1);
  drawPixel(48 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(49 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(50 + window_XPOS, 21 + window_YPOS, 0, 0, 1);
  drawPixel(51 + window_XPOS, 21 + window_YPOS, 1, 0, 0);
  drawPixel(52 + window_XPOS, 21 + window_YPOS, 0, 1, 0);
  drawPixel(53 + window_XPOS, 21 + window_YPOS, 229, 170, 123);
  drawPixel(54 + window_XPOS, 21 + window_YPOS, 0, 0, 0);
  drawPixel(36 + window_XPOS, 22 + window_YPOS, 0, 0, 0);
  drawPixel(37 + window_XPOS, 22 + window_YPOS, 229, 170, 123);
  drawPixel(38 + window_XPOS, 22 + window_YPOS, 228, 170, 122);
  drawPixel(39 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(40 + window_XPOS, 22 + window_YPOS, 229, 170, 123);
  drawPixel(41 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(42 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(43 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(44 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(45 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(46 + window_XPOS, 22 + window_YPOS, 229, 170, 123);
  drawPixel(47 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(48 + window_XPOS, 22 + window_YPOS, 229, 171, 122);
  drawPixel(49 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(50 + window_XPOS, 22 + window_YPOS, 228, 170, 122);
  drawPixel(51 + window_XPOS, 22 + window_YPOS, 229, 171, 122);
  drawPixel(52 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(53 + window_XPOS, 22 + window_YPOS, 229, 170, 122);
  drawPixel(54 + window_XPOS, 22 + window_YPOS, 0, 1, 0);
  drawPixel(37 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(38 + window_XPOS, 23 + window_YPOS, 0, 1, 0);
  drawPixel(39 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(40 + window_XPOS, 23 + window_YPOS, 1, 0, 0);
  drawPixel(41 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(42 + window_XPOS, 23 + window_YPOS, 0, 0, 1);
  drawPixel(43 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(44 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(45 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(46 + window_XPOS, 23 + window_YPOS, 1, 0, 0);
  drawPixel(47 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(48 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(49 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(50 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(51 + window_XPOS, 23 + window_YPOS, 0, 0, 0);
  drawPixel(52 + window_XPOS, 23 + window_YPOS, 1, 0, 0);
  drawPixel(53 + window_XPOS, 23 + window_YPOS, 0, 1, 0);
}

void introFloor() {
  drawPixel(0 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(1 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(2 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(3 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(4 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(5 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(6 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(7 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(8 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(9 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(10 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(11 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(12 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(13 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(14 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(15 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(16 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(17 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(18 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(19 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(20 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(21 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(22 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(23 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(24 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(25 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(26 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(27 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(28 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(29 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(30 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(31 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(32 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(33 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(34 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(35 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(36 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(37 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(38 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(39 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(40 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(41 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(42 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(43 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(44 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(45 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(46 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(47 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(48 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(49 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(50 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(51 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(52 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(53 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(54 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(55 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(56 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(57 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(58 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(59 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(60 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 18);
  drawPixel(61 + introFloor_XPOS, 29 + introFloor_YPOS, 67, 30, 19);
  drawPixel(62 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 31, 19);
  drawPixel(63 + introFloor_XPOS, 29 + introFloor_YPOS, 66, 30, 19);
  drawPixel(0 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(1 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(2 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(3 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(4 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 31, 19);
  drawPixel(5 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(6 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(7 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(8 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(9 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(10 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 31, 19);
  drawPixel(11 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(12 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(13 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(14 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(15 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(16 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(17 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 30, 18);
  drawPixel(18 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(19 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(20 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(21 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(22 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(23 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(24 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 30, 19);
  drawPixel(25 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(26 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(27 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(28 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(29 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(30 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(31 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(32 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 30, 18);
  drawPixel(33 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(34 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(35 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(36 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(37 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(38 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(39 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 30, 19);
  drawPixel(40 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(41 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(42 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(43 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(44 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(45 + introFloor_XPOS, 30 + introFloor_YPOS, 123, 58, 37);
  drawPixel(46 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 30, 19);
  drawPixel(47 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(48 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(49 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(50 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(51 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(52 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(53 + introFloor_XPOS, 30 + introFloor_YPOS, 66, 30, 18);
  drawPixel(54 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(55 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(56 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(57 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(58 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(59 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(60 + introFloor_XPOS, 30 + introFloor_YPOS, 67, 30, 19);
  drawPixel(61 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 59, 37);
  drawPixel(62 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 36);
  drawPixel(63 + introFloor_XPOS, 30 + introFloor_YPOS, 122, 58, 37);
  drawPixel(0 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(1 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(2 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(3 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(4 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 18);
  drawPixel(5 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(6 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(7 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(8 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(9 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(10 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 19);
  drawPixel(11 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(12 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(13 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(14 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(15 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(16 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(17 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 19);
  drawPixel(18 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(19 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(20 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(21 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(22 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(23 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(24 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 19);
  drawPixel(25 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(26 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(27 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(28 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(29 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(30 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(31 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(32 + introFloor_XPOS, 31 + introFloor_YPOS, 67, 30, 19);
  drawPixel(33 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(34 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(35 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(36 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(37 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(38 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(39 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 19);
  drawPixel(40 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(41 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(42 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(43 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(44 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(45 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(46 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 19);
  drawPixel(47 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(48 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(49 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(50 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(51 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(52 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(53 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 30, 19);
  drawPixel(54 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(55 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(56 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(57 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(58 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 37);
  drawPixel(59 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(60 + introFloor_XPOS, 31 + introFloor_YPOS, 66, 31, 19);
  drawPixel(61 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 58, 36);
  drawPixel(62 + introFloor_XPOS, 31 + introFloor_YPOS, 123, 58, 37);
  drawPixel(63 + introFloor_XPOS, 31 + introFloor_YPOS, 122, 59, 37);
  drawPixel(0 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(1 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(2 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(3 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(4 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(5 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(6 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(7 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(8 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(9 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(10 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(11 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(12 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(13 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(14 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(15 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(16 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(17 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(18 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(19 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(20 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(21 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(22 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(23 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(24 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(25 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(26 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(27 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(28 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(29 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(30 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(31 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(32 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(33 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(34 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(35 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(36 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(37 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(38 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(39 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(40 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(41 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(42 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(43 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(44 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(45 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(46 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(47 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(48 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(49 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(50 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(51 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(52 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(53 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(54 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(55 + introFloor_XPOS, 32 + introFloor_YPOS, 67, 30, 19);
  drawPixel(56 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(57 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(58 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(59 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 31, 19);
  drawPixel(60 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(61 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(62 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 19);
  drawPixel(63 + introFloor_XPOS, 32 + introFloor_YPOS, 66, 30, 18);
  drawPixel(0 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(1 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(2 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(3 + introFloor_XPOS, 33 + introFloor_YPOS, 123, 58, 37);
  drawPixel(4 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(5 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(6 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(7 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 31, 19);
  drawPixel(8 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(9 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(10 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 59, 37);
  drawPixel(11 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(12 + introFloor_XPOS, 33 + introFloor_YPOS, 123, 58, 37);
  drawPixel(13 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 59, 37);
  drawPixel(14 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 30, 18);
  drawPixel(15 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(16 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(17 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(18 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(19 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(20 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(21 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 30, 19);
  drawPixel(22 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(23 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(24 + introFloor_XPOS, 33 + introFloor_YPOS, 123, 58, 37);
  drawPixel(25 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(26 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(27 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(28 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 30, 19);
  drawPixel(29 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(30 + introFloor_XPOS, 33 + introFloor_YPOS, 123, 58, 37);
  drawPixel(31 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 59, 37);
  drawPixel(32 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(33 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(34 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(35 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(36 + introFloor_XPOS, 33 + introFloor_YPOS, 67, 30, 19);
  drawPixel(37 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 59, 37);
  drawPixel(38 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(39 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(40 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(41 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(42 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(43 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 31, 19);
  drawPixel(44 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(45 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(46 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(47 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(48 + introFloor_XPOS, 33 + introFloor_YPOS, 123, 58, 37);
  drawPixel(49 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 59, 37);
  drawPixel(50 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 30, 19);
  drawPixel(51 + introFloor_XPOS, 33 + introFloor_YPOS, 123, 58, 37);
  drawPixel(52 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(53 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(54 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(55 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(56 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 36);
  drawPixel(57 + introFloor_XPOS, 33 + introFloor_YPOS, 66, 30, 19);
  drawPixel(58 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(59 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(60 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(61 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(62 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(63 + introFloor_XPOS, 33 + introFloor_YPOS, 122, 58, 37);
  drawPixel(0 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(1 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(2 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(3 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(4 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(5 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(6 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(7 + introFloor_XPOS, 34 + introFloor_YPOS, 66, 30, 18);
  drawPixel(8 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(9 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(10 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(11 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(12 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(13 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(14 + introFloor_XPOS, 34 + introFloor_YPOS, 67, 30, 19);
  drawPixel(15 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(16 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(17 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(18 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(19 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(20 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(21 + introFloor_XPOS, 34 + introFloor_YPOS, 66, 31, 19);
  drawPixel(22 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(23 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(24 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(25 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(26 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(27 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(28 + introFloor_XPOS, 34 + introFloor_YPOS, 66, 30, 18);
  drawPixel(29 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(30 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(31 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(32 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(33 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(34 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(35 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(36 + introFloor_XPOS, 34 + introFloor_YPOS, 66, 30, 19);
  drawPixel(37 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(38 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(39 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(40 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(41 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(42 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(43 + introFloor_XPOS, 34 + introFloor_YPOS, 66, 30, 19);
  drawPixel(44 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(45 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(46 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(47 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(48 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(49 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(50 + introFloor_XPOS, 34 + introFloor_YPOS, 67, 30, 19);
  drawPixel(51 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(52 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(53 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(54 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(55 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 36);
  drawPixel(56 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(57 + introFloor_XPOS, 34 + introFloor_YPOS, 66, 30, 19);
  drawPixel(58 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(59 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(60 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(61 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 58, 37);
  drawPixel(62 + introFloor_XPOS, 34 + introFloor_YPOS, 123, 58, 37);
  drawPixel(63 + introFloor_XPOS, 34 + introFloor_YPOS, 122, 59, 37);
  drawPixel(0 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(1 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(2 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(3 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(4 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(5 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(6 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(7 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(8 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(9 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(10 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(11 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(12 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(13 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(14 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(15 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(16 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(17 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(18 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(19 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(20 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(21 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(22 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(23 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(24 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(25 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(26 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(27 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(28 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(29 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(30 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(31 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(32 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(33 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(34 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(35 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(36 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(37 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(38 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(39 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(40 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(41 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(42 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(43 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(44 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(45 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(46 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(47 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(48 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(49 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(50 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(51 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(52 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(53 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(54 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 18);
  drawPixel(55 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(56 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(57 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(58 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(59 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(60 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
  drawPixel(61 + introFloor_XPOS, 35 + introFloor_YPOS, 67, 30, 19);
  drawPixel(62 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 31, 19);
  drawPixel(63 + introFloor_XPOS, 35 + introFloor_YPOS, 66, 30, 19);
}

void nameBarNew() {
  drawPixel(9 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(10 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(11 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(12 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(13 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(14 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(15 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(16 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 1, 0);
  drawPixel(17 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(18 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(19 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(20 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 1, 0);
  drawPixel(21 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(22 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(23 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(24 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(25 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(26 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(27 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(28 + nameBarNew_XPOS, 25 + nameBarNew_YPOS, 1, 0, 1);
  drawPixel(7 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(8 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(9 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 255, 194, 14);
  drawPixel(10 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 255, 195, 14);
  drawPixel(11 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(12 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(13 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(14 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 20, 12);
  drawPixel(15 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(16 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(17 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(18 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(19 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 20, 12);
  drawPixel(20 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 21, 12);
  drawPixel(21 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(22 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 21, 13);
  drawPixel(23 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(24 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 21, 12);
  drawPixel(25 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(26 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 36, 21, 13);
  drawPixel(27 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 254, 194, 15);
  drawPixel(28 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 254, 194, 14);
  drawPixel(29 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(30 + nameBarNew_XPOS, 26 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(4 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(5 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(6 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 1);
  drawPixel(7 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 255, 194, 15);
  drawPixel(8 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 254, 195, 15);
  drawPixel(9 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 254, 194, 14);
  drawPixel(10 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(11 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(12 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(13 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 20, 12);
  drawPixel(14 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(15 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 20, 12);
  drawPixel(16 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 21, 13);
  drawPixel(17 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(18 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 20, 13);
  drawPixel(19 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(20 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(21 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 20, 13);
  drawPixel(22 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(23 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 20, 13);
  drawPixel(24 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 21, 13);
  drawPixel(25 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(26 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(27 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(28 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 254, 194, 15);
  drawPixel(29 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 255, 195, 15);
  drawPixel(30 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 255, 195, 14);
  drawPixel(31 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 1);
  drawPixel(32 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(33 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(34 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(35 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(36 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(37 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(38 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(39 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(40 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(41 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(42 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(43 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(44 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(45 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(46 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(47 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(48 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(49 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(50 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(51 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(52 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(53 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(54 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(55 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(56 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(57 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 1, 1, 0);
  drawPixel(58 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(59 + nameBarNew_XPOS, 27 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(3 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(4 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(5 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(6 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(7 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(8 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 1, 1, 1);
  drawPixel(9 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 15);
  drawPixel(10 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 14);
  drawPixel(11 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 21, 12);
  drawPixel(12 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 21, 13);
  drawPixel(13 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 20, 13);
  drawPixel(14 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 21, 12);
  drawPixel(15 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 21, 12);
  drawPixel(16 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 37, 21, 13);
  drawPixel(17 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 20, 13);
  drawPixel(18 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 37, 21, 12);
  drawPixel(19 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 37, 20, 13);
  drawPixel(20 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(21 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 21, 13);
  drawPixel(22 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 37, 21, 13);
  drawPixel(23 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(24 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 20, 13);
  drawPixel(25 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 37, 20, 12);
  drawPixel(26 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 36, 20, 12);
  drawPixel(27 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 15);
  drawPixel(28 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 14);
  drawPixel(29 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(30 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(31 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(32 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(33 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(34 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(35 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(36 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(37 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(38 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(39 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(40 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(41 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(42 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(43 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(44 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(45 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(46 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(47 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(48 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(49 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(50 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(51 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(52 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(53 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(54 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(55 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(56 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(57 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(58 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(59 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(60 + nameBarNew_XPOS, 28 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(2 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(3 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(4 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(5 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(6 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(7 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(8 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(9 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(10 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(11 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(12 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(13 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(14 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(15 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(16 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(17 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(18 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(19 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(20 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(21 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(22 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(23 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(24 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(25 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(26 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(27 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(28 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(29 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(30 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(31 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(32 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(33 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(34 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(35 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(36 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(37 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(38 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(39 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(40 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(41 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(42 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(43 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(44 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(45 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(46 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(47 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(48 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(49 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(50 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(51 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(52 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(53 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(54 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(55 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(56 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(57 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(58 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(59 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(60 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(61 + nameBarNew_XPOS, 29 + nameBarNew_YPOS, 0, 1, 1);
  drawPixel(1 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(2 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(3 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(4 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(5 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(6 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(7 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(8 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(9 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(10 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(11 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(12 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(13 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(14 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(15 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(16 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(17 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(18 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(19 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(20 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(21 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(22 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(23 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(24 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(25 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(26 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(27 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(28 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(29 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(30 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(31 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(32 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(33 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(34 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(35 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(36 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(37 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(38 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(39 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(40 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(41 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(42 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(43 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(44 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(45 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(46 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(47 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(48 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(49 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(50 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(51 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(52 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(53 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(54 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(55 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(56 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(57 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(58 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(59 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(60 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(61 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(62 + nameBarNew_XPOS, 30 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(1 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 1, 1, 1);
  drawPixel(2 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(3 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(4 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(5 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(6 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(7 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(8 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(9 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(10 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(11 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(12 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(13 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(14 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(15 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(16 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(17 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(18 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(19 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(20 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(21 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(22 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(23 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(24 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(25 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(26 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(27 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(28 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(29 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(30 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(31 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(32 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(33 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(34 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(35 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(36 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(37 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(38 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(39 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(40 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(41 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(42 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(43 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(44 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(45 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(46 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(47 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(48 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(49 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(50 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(51 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(52 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(53 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(54 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(55 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(56 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(57 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(58 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(59 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(60 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(61 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(62 + nameBarNew_XPOS, 31 + nameBarNew_YPOS, 1, 1, 0);
  drawPixel(2 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(3 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(4 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(5 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(6 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(7 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(8 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(9 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(10 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(11 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(12 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(13 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(14 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(15 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(16 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(17 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(18 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(19 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(20 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(21 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(22 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(23 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(24 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(25 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(26 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(27 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(28 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(29 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(30 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(31 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(32 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(33 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(34 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(35 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(36 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(37 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(38 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(39 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(40 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(41 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(42 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(43 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(44 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(45 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(46 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(47 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(48 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(49 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(50 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(51 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(52 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(53 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(54 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(55 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(56 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(57 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(58 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(59 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(60 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(61 + nameBarNew_XPOS, 32 + nameBarNew_YPOS, 1, 1, 0);
  drawPixel(3 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(4 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(5 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(6 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(7 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(8 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(9 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(10 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(11 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(12 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(13 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(14 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(15 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(16 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(17 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(18 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(19 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(20 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(21 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(22 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(23 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(24 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(25 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(26 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(27 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(28 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(29 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(30 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(31 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(32 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(33 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(34 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(35 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(36 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(37 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 149);
  drawPixel(38 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(39 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(40 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(41 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(42 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(43 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(44 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(45 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 149);
  drawPixel(46 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(47 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(48 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(49 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 195, 148);
  drawPixel(50 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(51 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(52 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(53 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 148);
  drawPixel(54 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 148);
  drawPixel(55 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(56 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 194, 149);
  drawPixel(57 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 255, 195, 149);
  drawPixel(58 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(59 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 254, 194, 148);
  drawPixel(60 + nameBarNew_XPOS, 33 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(4 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(5 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(6 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(7 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(8 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(9 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(10 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(11 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(12 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(13 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(14 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(15 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(16 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(17 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(18 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(19 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(20 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(21 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(22 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(23 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(24 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(25 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(26 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(27 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(28 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(29 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(30 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(31 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(32 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(33 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(34 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(35 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(36 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(37 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(38 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(39 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(40 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(41 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(42 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(43 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(44 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 1, 0, 0);
  drawPixel(45 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(46 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(47 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(48 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(49 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 1);
  drawPixel(50 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(51 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(52 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(53 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(54 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(55 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(56 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(57 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 1, 0);
  drawPixel(58 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
  drawPixel(59 + nameBarNew_XPOS, 34 + nameBarNew_YPOS, 0, 0, 0);
}

void brokenWindow() {
  drawPixel(43 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(44 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(45 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(46 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(47 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(48 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(49 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(50 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(51 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(52 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(53 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(54 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(55 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(56 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(57 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(58 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(59 + brokenWindow_XPOS, 8 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(42 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(44 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(45 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 228, 171, 123);
  drawPixel(46 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(47 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(48 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(49 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(50 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(51 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(52 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(53 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(54 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(55 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(56 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(57 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(58 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(59 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(60 + brokenWindow_XPOS, 9 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(42 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(43 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(44 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(45 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(46 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(47 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(48 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(49 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(50 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(51 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(52 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(53 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(54 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(55 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(56 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(57 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(58 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(59 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(60 + brokenWindow_XPOS, 10 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(42 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(43 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(44 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(45 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(46 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(47 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 9, 55, 66);
  drawPixel(48 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 8, 55, 67);
  drawPixel(49 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 9, 54, 66);
  drawPixel(50 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(51 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 228, 171, 123);
  drawPixel(52 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(53 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 9, 55, 67);
  drawPixel(54 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(55 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 254, 254, 255);
  drawPixel(56 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(57 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 8, 55, 67);
  drawPixel(58 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(59 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(60 + brokenWindow_XPOS, 11 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(42 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(43 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(44 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(45 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 9, 55, 67);
  drawPixel(46 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(47 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 254, 255, 254);
  drawPixel(48 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(50 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(51 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(52 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(53 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(54 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(55 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 255, 255, 254);
  drawPixel(56 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(57 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(58 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(59 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(60 + brokenWindow_XPOS, 12 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(42 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(43 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(44 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(45 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(46 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(47 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 254, 255, 254);
  drawPixel(48 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 9, 54, 66);
  drawPixel(49 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(50 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(51 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(52 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(53 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(54 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 254, 254, 255);
  drawPixel(55 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(56 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 255, 255, 254);
  drawPixel(57 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(58 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(59 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(60 + brokenWindow_XPOS, 13 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(42 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(43 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(44 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(45 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 9, 54, 66);
  drawPixel(46 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(47 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(48 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(50 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(51 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(52 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(53 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 255, 254, 255);
  drawPixel(54 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 9, 55, 66);
  drawPixel(55 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 8, 55, 67);
  drawPixel(56 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 8, 55, 66);
  drawPixel(57 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 9, 55, 67);
  drawPixel(58 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(59 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(60 + brokenWindow_XPOS, 14 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(42 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(43 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(44 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(45 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(46 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(47 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(48 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(49 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(50 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(51 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 228, 171, 123);
  drawPixel(52 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(53 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(54 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(55 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(56 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(57 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(58 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(59 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(60 + brokenWindow_XPOS, 15 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(42 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(44 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(45 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(46 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(47 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(48 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(49 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(50 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(51 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(52 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(53 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(54 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(55 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(56 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(57 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(58 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(59 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(60 + brokenWindow_XPOS, 16 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(42 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(43 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(44 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(45 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(46 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(47 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(48 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(49 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(50 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(51 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(52 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(53 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(54 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(55 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(56 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(57 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(58 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(59 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(60 + brokenWindow_XPOS, 17 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(42 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(44 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(45 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(46 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(47 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(48 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(49 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 9, 55, 67);
  drawPixel(50 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(51 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(52 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(53 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(54 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 255, 255, 254);
  drawPixel(55 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 8, 55, 67);
  drawPixel(56 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 9, 55, 66);
  drawPixel(57 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(58 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(59 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(60 + brokenWindow_XPOS, 18 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(42 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(43 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(44 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(45 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(46 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(47 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 255, 255, 254);
  drawPixel(48 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(49 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(50 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(51 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(52 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(53 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(54 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 254, 254, 255);
  drawPixel(55 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 254, 254, 255);
  drawPixel(56 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 254, 255, 254);
  drawPixel(57 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(58 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(59 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(60 + brokenWindow_XPOS, 19 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(42 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(44 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(45 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(46 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 254, 254, 255);
  drawPixel(47 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(48 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(49 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 8, 54, 67);
  drawPixel(50 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(51 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(52 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(53 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 8, 55, 66);
  drawPixel(54 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(55 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 8, 55, 66);
  drawPixel(56 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 254, 255, 254);
  drawPixel(57 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 8, 55, 66);
  drawPixel(58 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(59 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(60 + brokenWindow_XPOS, 20 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(42 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(44 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(45 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 255, 254, 254);
  drawPixel(46 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(47 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(48 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 9, 54, 66);
  drawPixel(49 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 9, 54, 67);
  drawPixel(50 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(51 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(52 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 0, 1, 0);
  drawPixel(53 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 8, 54, 66);
  drawPixel(54 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 254, 255, 255);
  drawPixel(55 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 9, 55, 67);
  drawPixel(56 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(57 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 254, 254, 254);
  drawPixel(58 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(59 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(60 + brokenWindow_XPOS, 21 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(42 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(44 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(45 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(46 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(47 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(48 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(49 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(50 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(51 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 229, 170, 123);
  drawPixel(52 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(53 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(54 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(55 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(56 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(57 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(58 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(59 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(60 + brokenWindow_XPOS, 22 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(42 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(43 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(44 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(45 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(46 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(47 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(48 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(49 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(50 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(51 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(52 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 123);
  drawPixel(53 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(54 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 170, 122);
  drawPixel(55 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(56 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 228, 171, 122);
  drawPixel(57 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 171, 123);
  drawPixel(58 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 171, 122);
  drawPixel(59 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 229, 170, 122);
  drawPixel(60 + brokenWindow_XPOS, 23 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(43 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(44 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(45 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(46 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(47 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(48 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(49 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 0, 1);
  drawPixel(50 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(51 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(52 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 1, 1);
  drawPixel(53 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(54 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 0, 0);
  drawPixel(55 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 1, 1);
  drawPixel(56 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 1, 1, 0);
  drawPixel(57 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 1);
  drawPixel(58 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 0, 0);
  drawPixel(59 + brokenWindow_XPOS, 24 + brokenWindow_YPOS, 0, 1, 1);
}

void tornadoNew() {
  drawPixel(37 + tornado_XPOS, 7 + tornado_YPOS, 84, 85, 111);
  drawPixel(38 + tornado_XPOS, 7 + tornado_YPOS, 85, 84, 110);
  drawPixel(39 + tornado_XPOS, 7 + tornado_YPOS, 85, 84, 110);
  drawPixel(40 + tornado_XPOS, 7 + tornado_YPOS, 85, 85, 110);
  drawPixel(41 + tornado_XPOS, 7 + tornado_YPOS, 85, 84, 111);
  drawPixel(42 + tornado_XPOS, 7 + tornado_YPOS, 85, 84, 110);
  drawPixel(43 + tornado_XPOS, 7 + tornado_YPOS, 84, 84, 111);
  drawPixel(44 + tornado_XPOS, 7 + tornado_YPOS, 85, 85, 110);
  drawPixel(34 + tornado_XPOS, 8 + tornado_YPOS, 85, 85, 111);
  drawPixel(35 + tornado_XPOS, 8 + tornado_YPOS, 84, 84, 110);
  drawPixel(36 + tornado_XPOS, 8 + tornado_YPOS, 85, 84, 111);
  drawPixel(37 + tornado_XPOS, 8 + tornado_YPOS, 145, 154, 176);
  drawPixel(38 + tornado_XPOS, 8 + tornado_YPOS, 144, 155, 176);
  drawPixel(39 + tornado_XPOS, 8 + tornado_YPOS, 144, 154, 176);
  drawPixel(40 + tornado_XPOS, 8 + tornado_YPOS, 144, 155, 176);
  drawPixel(41 + tornado_XPOS, 8 + tornado_YPOS, 144, 155, 176);
  drawPixel(42 + tornado_XPOS, 8 + tornado_YPOS, 145, 154, 177);
  drawPixel(43 + tornado_XPOS, 8 + tornado_YPOS, 145, 155, 177);
  drawPixel(44 + tornado_XPOS, 8 + tornado_YPOS, 144, 154, 177);
  drawPixel(45 + tornado_XPOS, 8 + tornado_YPOS, 85, 84, 110);
  drawPixel(46 + tornado_XPOS, 8 + tornado_YPOS, 85, 85, 110);
  drawPixel(47 + tornado_XPOS, 8 + tornado_YPOS, 85, 84, 111);
  drawPixel(48 + tornado_XPOS, 8 + tornado_YPOS, 84, 84, 111);
  drawPixel(33 + tornado_XPOS, 9 + tornado_YPOS, 85, 85, 110);
  drawPixel(34 + tornado_XPOS, 9 + tornado_YPOS, 145, 154, 177);
  drawPixel(35 + tornado_XPOS, 9 + tornado_YPOS, 145, 155, 177);
  drawPixel(36 + tornado_XPOS, 9 + tornado_YPOS, 144, 155, 177);
  drawPixel(37 + tornado_XPOS, 9 + tornado_YPOS, 195, 211, 230);
  drawPixel(38 + tornado_XPOS, 9 + tornado_YPOS, 247, 251, 251);
  drawPixel(39 + tornado_XPOS, 9 + tornado_YPOS, 247, 250, 250);
  drawPixel(40 + tornado_XPOS, 9 + tornado_YPOS, 194, 211, 231);
  drawPixel(41 + tornado_XPOS, 9 + tornado_YPOS, 195, 210, 230);
  drawPixel(42 + tornado_XPOS, 9 + tornado_YPOS, 144, 155, 177);
  drawPixel(43 + tornado_XPOS, 9 + tornado_YPOS, 145, 155, 176);
  drawPixel(44 + tornado_XPOS, 9 + tornado_YPOS, 145, 154, 177);
  drawPixel(45 + tornado_XPOS, 9 + tornado_YPOS, 114, 125, 141);
  drawPixel(46 + tornado_XPOS, 9 + tornado_YPOS, 115, 125, 141);
  drawPixel(47 + tornado_XPOS, 9 + tornado_YPOS, 87, 94, 110);
  drawPixel(48 + tornado_XPOS, 9 + tornado_YPOS, 86, 94, 111);
  drawPixel(49 + tornado_XPOS, 9 + tornado_YPOS, 85, 84, 111);
  drawPixel(33 + tornado_XPOS, 10 + tornado_YPOS, 85, 84, 110);
  drawPixel(34 + tornado_XPOS, 10 + tornado_YPOS, 114, 125, 140);
  drawPixel(35 + tornado_XPOS, 10 + tornado_YPOS, 185, 210, 239);
  drawPixel(36 + tornado_XPOS, 10 + tornado_YPOS, 185, 210, 239);
  drawPixel(37 + tornado_XPOS, 10 + tornado_YPOS, 247, 251, 250);
  drawPixel(38 + tornado_XPOS, 10 + tornado_YPOS, 246, 251, 250);
  drawPixel(39 + tornado_XPOS, 10 + tornado_YPOS, 194, 210, 231);
  drawPixel(40 + tornado_XPOS, 10 + tornado_YPOS, 195, 210, 230);
  drawPixel(41 + tornado_XPOS, 10 + tornado_YPOS, 195, 210, 231);
  drawPixel(42 + tornado_XPOS, 10 + tornado_YPOS, 144, 154, 177);
  drawPixel(43 + tornado_XPOS, 10 + tornado_YPOS, 144, 155, 177);
  drawPixel(44 + tornado_XPOS, 10 + tornado_YPOS, 114, 125, 140);
  drawPixel(45 + tornado_XPOS, 10 + tornado_YPOS, 114, 125, 140);
  drawPixel(46 + tornado_XPOS, 10 + tornado_YPOS, 115, 125, 141);
  drawPixel(47 + tornado_XPOS, 10 + tornado_YPOS, 114, 124, 141);
  drawPixel(48 + tornado_XPOS, 10 + tornado_YPOS, 87, 95, 111);
  drawPixel(49 + tornado_XPOS, 10 + tornado_YPOS, 87, 95, 110);
  drawPixel(50 + tornado_XPOS, 10 + tornado_YPOS, 84, 84, 110);
  drawPixel(33 + tornado_XPOS, 11 + tornado_YPOS, 84, 85, 110);
  drawPixel(34 + tornado_XPOS, 11 + tornado_YPOS, 115, 124, 141);
  drawPixel(35 + tornado_XPOS, 11 + tornado_YPOS, 185, 210, 239);
  drawPixel(36 + tornado_XPOS, 11 + tornado_YPOS, 246, 251, 251);
  drawPixel(37 + tornado_XPOS, 11 + tornado_YPOS, 246, 250, 251);
  drawPixel(38 + tornado_XPOS, 11 + tornado_YPOS, 195, 210, 230);
  drawPixel(39 + tornado_XPOS, 11 + tornado_YPOS, 195, 211, 230);
  drawPixel(40 + tornado_XPOS, 11 + tornado_YPOS, 195, 210, 230);
  drawPixel(41 + tornado_XPOS, 11 + tornado_YPOS, 185, 211, 238);
  drawPixel(42 + tornado_XPOS, 11 + tornado_YPOS, 185, 211, 239);
  drawPixel(43 + tornado_XPOS, 11 + tornado_YPOS, 185, 211, 238);
  drawPixel(44 + tornado_XPOS, 11 + tornado_YPOS, 145, 154, 176);
  drawPixel(45 + tornado_XPOS, 11 + tornado_YPOS, 114, 124, 141);
  drawPixel(46 + tornado_XPOS, 11 + tornado_YPOS, 114, 124, 141);
  drawPixel(47 + tornado_XPOS, 11 + tornado_YPOS, 115, 124, 140);
  drawPixel(48 + tornado_XPOS, 11 + tornado_YPOS, 115, 124, 141);
  drawPixel(49 + tornado_XPOS, 11 + tornado_YPOS, 115, 125, 140);
  drawPixel(50 + tornado_XPOS, 11 + tornado_YPOS, 84, 84, 110);
  drawPixel(33 + tornado_XPOS, 12 + tornado_YPOS, 84, 84, 110);
  drawPixel(34 + tornado_XPOS, 12 + tornado_YPOS, 115, 125, 140);
  drawPixel(35 + tornado_XPOS, 12 + tornado_YPOS, 115, 124, 140);
  drawPixel(36 + tornado_XPOS, 12 + tornado_YPOS, 246, 251, 250);
  drawPixel(37 + tornado_XPOS, 12 + tornado_YPOS, 247, 250, 250);
  drawPixel(38 + tornado_XPOS, 12 + tornado_YPOS, 194, 210, 230);
  drawPixel(39 + tornado_XPOS, 12 + tornado_YPOS, 195, 210, 231);
  drawPixel(40 + tornado_XPOS, 12 + tornado_YPOS, 185, 211, 239);
  drawPixel(41 + tornado_XPOS, 12 + tornado_YPOS, 184, 211, 238);
  drawPixel(42 + tornado_XPOS, 12 + tornado_YPOS, 144, 154, 177);
  drawPixel(43 + tornado_XPOS, 12 + tornado_YPOS, 144, 154, 177);
  drawPixel(44 + tornado_XPOS, 12 + tornado_YPOS, 145, 155, 177);
  drawPixel(45 + tornado_XPOS, 12 + tornado_YPOS, 144, 155, 176);
  drawPixel(46 + tornado_XPOS, 12 + tornado_YPOS, 114, 124, 140);
  drawPixel(47 + tornado_XPOS, 12 + tornado_YPOS, 86, 95, 110);
  drawPixel(48 + tornado_XPOS, 12 + tornado_YPOS, 86, 95, 110);
  drawPixel(49 + tornado_XPOS, 12 + tornado_YPOS, 114, 125, 140);
  drawPixel(50 + tornado_XPOS, 12 + tornado_YPOS, 85, 84, 111);
  drawPixel(33 + tornado_XPOS, 13 + tornado_YPOS, 84, 84, 110);
  drawPixel(34 + tornado_XPOS, 13 + tornado_YPOS, 87, 94, 110);
  drawPixel(35 + tornado_XPOS, 13 + tornado_YPOS, 87, 94, 110);
  drawPixel(36 + tornado_XPOS, 13 + tornado_YPOS, 246, 251, 250);
  drawPixel(37 + tornado_XPOS, 13 + tornado_YPOS, 246, 250, 250);
  drawPixel(38 + tornado_XPOS, 13 + tornado_YPOS, 246, 250, 251);
  drawPixel(39 + tornado_XPOS, 13 + tornado_YPOS, 194, 210, 231);
  drawPixel(40 + tornado_XPOS, 13 + tornado_YPOS, 144, 154, 176);
  drawPixel(41 + tornado_XPOS, 13 + tornado_YPOS, 145, 155, 176);
  drawPixel(42 + tornado_XPOS, 13 + tornado_YPOS, 145, 155, 176);
  drawPixel(43 + tornado_XPOS, 13 + tornado_YPOS, 144, 155, 177);
  drawPixel(44 + tornado_XPOS, 13 + tornado_YPOS, 144, 154, 176);
  drawPixel(45 + tornado_XPOS, 13 + tornado_YPOS, 144, 154, 177);
  drawPixel(46 + tornado_XPOS, 13 + tornado_YPOS, 114, 125, 141);
  drawPixel(47 + tornado_XPOS, 13 + tornado_YPOS, 115, 125, 141);
  drawPixel(48 + tornado_XPOS, 13 + tornado_YPOS, 87, 95, 111);
  drawPixel(49 + tornado_XPOS, 13 + tornado_YPOS, 87, 95, 111);
  drawPixel(50 + tornado_XPOS, 13 + tornado_YPOS, 84, 84, 110);
  drawPixel(33 + tornado_XPOS, 14 + tornado_YPOS, 85, 85, 110);
  drawPixel(34 + tornado_XPOS, 14 + tornado_YPOS, 87, 95, 110);
  drawPixel(35 + tornado_XPOS, 14 + tornado_YPOS, 184, 211, 239);
  drawPixel(36 + tornado_XPOS, 14 + tornado_YPOS, 194, 211, 231);
  drawPixel(37 + tornado_XPOS, 14 + tornado_YPOS, 246, 250, 250);
  drawPixel(38 + tornado_XPOS, 14 + tornado_YPOS, 246, 251, 251);
  drawPixel(39 + tornado_XPOS, 14 + tornado_YPOS, 194, 211, 231);
  drawPixel(40 + tornado_XPOS, 14 + tornado_YPOS, 184, 210, 238);
  drawPixel(41 + tornado_XPOS, 14 + tornado_YPOS, 185, 210, 238);
  drawPixel(42 + tornado_XPOS, 14 + tornado_YPOS, 184, 211, 239);
  drawPixel(43 + tornado_XPOS, 14 + tornado_YPOS, 145, 154, 176);
  drawPixel(44 + tornado_XPOS, 14 + tornado_YPOS, 145, 155, 177);
  drawPixel(45 + tornado_XPOS, 14 + tornado_YPOS, 87, 94, 110);
  drawPixel(46 + tornado_XPOS, 14 + tornado_YPOS, 86, 95, 110);
  drawPixel(47 + tornado_XPOS, 14 + tornado_YPOS, 115, 124, 140);
  drawPixel(48 + tornado_XPOS, 14 + tornado_YPOS, 115, 125, 141);
  drawPixel(49 + tornado_XPOS, 14 + tornado_YPOS, 84, 84, 110);
  drawPixel(34 + tornado_XPOS, 15 + tornado_YPOS, 84, 84, 110);
  drawPixel(35 + tornado_XPOS, 15 + tornado_YPOS, 144, 154, 177);
  drawPixel(36 + tornado_XPOS, 15 + tornado_YPOS, 185, 211, 238);
  drawPixel(37 + tornado_XPOS, 15 + tornado_YPOS, 246, 251, 251);
  drawPixel(38 + tornado_XPOS, 15 + tornado_YPOS, 246, 251, 250);
  drawPixel(39 + tornado_XPOS, 15 + tornado_YPOS, 195, 210, 231);
  drawPixel(40 + tornado_XPOS, 15 + tornado_YPOS, 184, 210, 238);
  drawPixel(41 + tornado_XPOS, 15 + tornado_YPOS, 145, 155, 177);
  drawPixel(42 + tornado_XPOS, 15 + tornado_YPOS, 145, 155, 177);
  drawPixel(43 + tornado_XPOS, 15 + tornado_YPOS, 144, 154, 176);
  drawPixel(44 + tornado_XPOS, 15 + tornado_YPOS, 145, 154, 177);
  drawPixel(45 + tornado_XPOS, 15 + tornado_YPOS, 115, 125, 140);
  drawPixel(46 + tornado_XPOS, 15 + tornado_YPOS, 87, 94, 110);
  drawPixel(47 + tornado_XPOS, 15 + tornado_YPOS, 87, 94, 110);
  drawPixel(48 + tornado_XPOS, 15 + tornado_YPOS, 85, 84, 110);
  drawPixel(34 + tornado_XPOS, 16 + tornado_YPOS, 85, 84, 111);
  drawPixel(35 + tornado_XPOS, 16 + tornado_YPOS, 87, 94, 110);
  drawPixel(36 + tornado_XPOS, 16 + tornado_YPOS, 86, 95, 110);
  drawPixel(37 + tornado_XPOS, 16 + tornado_YPOS, 195, 211, 230);
  drawPixel(38 + tornado_XPOS, 16 + tornado_YPOS, 246, 251, 250);
  drawPixel(39 + tornado_XPOS, 16 + tornado_YPOS, 246, 251, 250);
  drawPixel(40 + tornado_XPOS, 16 + tornado_YPOS, 247, 251, 250);
  drawPixel(41 + tornado_XPOS, 16 + tornado_YPOS, 145, 154, 177);
  drawPixel(42 + tornado_XPOS, 16 + tornado_YPOS, 145, 155, 176);
  drawPixel(43 + tornado_XPOS, 16 + tornado_YPOS, 144, 155, 176);
  drawPixel(44 + tornado_XPOS, 16 + tornado_YPOS, 144, 155, 176);
  drawPixel(45 + tornado_XPOS, 16 + tornado_YPOS, 114, 124, 141);
  drawPixel(46 + tornado_XPOS, 16 + tornado_YPOS, 114, 125, 141);
  drawPixel(47 + tornado_XPOS, 16 + tornado_YPOS, 114, 124, 141);
  drawPixel(48 + tornado_XPOS, 16 + tornado_YPOS, 85, 84, 111);
  drawPixel(35 + tornado_XPOS, 17 + tornado_YPOS, 84, 84, 111);
  drawPixel(36 + tornado_XPOS, 17 + tornado_YPOS, 86, 94, 111);
  drawPixel(37 + tornado_XPOS, 17 + tornado_YPOS, 145, 155, 177);
  drawPixel(38 + tornado_XPOS, 17 + tornado_YPOS, 194, 210, 230);
  drawPixel(39 + tornado_XPOS, 17 + tornado_YPOS, 194, 211, 231);
  drawPixel(40 + tornado_XPOS, 17 + tornado_YPOS, 247, 250, 250);
  drawPixel(41 + tornado_XPOS, 17 + tornado_YPOS, 246, 250, 250);
  drawPixel(42 + tornado_XPOS, 17 + tornado_YPOS, 145, 155, 177);
  drawPixel(43 + tornado_XPOS, 17 + tornado_YPOS, 144, 155, 177);
  drawPixel(44 + tornado_XPOS, 17 + tornado_YPOS, 144, 155, 176);
  drawPixel(45 + tornado_XPOS, 17 + tornado_YPOS, 114, 124, 140);
  drawPixel(46 + tornado_XPOS, 17 + tornado_YPOS, 115, 124, 140);
  drawPixel(47 + tornado_XPOS, 17 + tornado_YPOS, 85, 85, 110);
  drawPixel(36 + tornado_XPOS, 18 + tornado_YPOS, 85, 84, 111);
  drawPixel(37 + tornado_XPOS, 18 + tornado_YPOS, 144, 155, 176);
  drawPixel(38 + tornado_XPOS, 18 + tornado_YPOS, 144, 154, 177);
  drawPixel(39 + tornado_XPOS, 18 + tornado_YPOS, 195, 210, 231);
  drawPixel(40 + tornado_XPOS, 18 + tornado_YPOS, 194, 211, 231);
  drawPixel(41 + tornado_XPOS, 18 + tornado_YPOS, 247, 251, 251);
  drawPixel(42 + tornado_XPOS, 18 + tornado_YPOS, 247, 251, 251);
  drawPixel(43 + tornado_XPOS, 18 + tornado_YPOS, 195, 211, 231);
  drawPixel(44 + tornado_XPOS, 18 + tornado_YPOS, 144, 155, 176);
  drawPixel(45 + tornado_XPOS, 18 + tornado_YPOS, 114, 124, 141);
  drawPixel(46 + tornado_XPOS, 18 + tornado_YPOS, 87, 94, 111);
  drawPixel(47 + tornado_XPOS, 18 + tornado_YPOS, 84, 84, 111);
  drawPixel(37 + tornado_XPOS, 19 + tornado_YPOS, 84, 84, 110);
  drawPixel(38 + tornado_XPOS, 19 + tornado_YPOS, 87, 95, 111);
  drawPixel(39 + tornado_XPOS, 19 + tornado_YPOS, 144, 154, 177);
  drawPixel(40 + tornado_XPOS, 19 + tornado_YPOS, 195, 210, 230);
  drawPixel(41 + tornado_XPOS, 19 + tornado_YPOS, 195, 210, 230);
  drawPixel(42 + tornado_XPOS, 19 + tornado_YPOS, 247, 251, 251);
  drawPixel(43 + tornado_XPOS, 19 + tornado_YPOS, 247, 251, 250);
  drawPixel(44 + tornado_XPOS, 19 + tornado_YPOS, 194, 210, 231);
  drawPixel(45 + tornado_XPOS, 19 + tornado_YPOS, 115, 124, 141);
  drawPixel(46 + tornado_XPOS, 19 + tornado_YPOS, 114, 124, 140);
  drawPixel(47 + tornado_XPOS, 19 + tornado_YPOS, 85, 84, 111);
  drawPixel(38 + tornado_XPOS, 20 + tornado_YPOS, 84, 84, 110);
  drawPixel(39 + tornado_XPOS, 20 + tornado_YPOS, 87, 94, 111);
  drawPixel(40 + tornado_XPOS, 20 + tornado_YPOS, 144, 155, 177);
  drawPixel(41 + tornado_XPOS, 20 + tornado_YPOS, 144, 155, 177);
  drawPixel(42 + tornado_XPOS, 20 + tornado_YPOS, 195, 210, 230);
  drawPixel(44 + tornado_XPOS, 20 + tornado_YPOS, 195, 210, 231);
  drawPixel(45 + tornado_XPOS, 20 + tornado_YPOS, 115, 124, 141);
  drawPixel(46 + tornado_XPOS, 20 + tornado_YPOS, 115, 125, 141);
  drawPixel(47 + tornado_XPOS, 20 + tornado_YPOS, 115, 125, 140);
  drawPixel(48 + tornado_XPOS, 20 + tornado_YPOS, 84, 85, 111);
  drawPixel(39 + tornado_XPOS, 21 + tornado_YPOS, 85, 85, 110);
  drawPixel(40 + tornado_XPOS, 21 + tornado_YPOS, 84, 85, 111);
  drawPixel(41 + tornado_XPOS, 21 + tornado_YPOS, 86, 95, 111);
  drawPixel(42 + tornado_XPOS, 21 + tornado_YPOS, 144, 154, 177);
  drawPixel(43 + tornado_XPOS, 21 + tornado_YPOS, 194, 210, 231);
  drawPixel(44 + tornado_XPOS, 21 + tornado_YPOS, 195, 211, 230);
  drawPixel(45 + tornado_XPOS, 21 + tornado_YPOS, 115, 125, 141);
  drawPixel(46 + tornado_XPOS, 21 + tornado_YPOS, 115, 125, 141);
  drawPixel(47 + tornado_XPOS, 21 + tornado_YPOS, 114, 125, 141);
  drawPixel(48 + tornado_XPOS, 21 + tornado_YPOS, 115, 125, 140);
  drawPixel(49 + tornado_XPOS, 21 + tornado_YPOS, 85, 84, 111);
  drawPixel(41 + tornado_XPOS, 22 + tornado_YPOS, 84, 84, 110);
  drawPixel(42 + tornado_XPOS, 22 + tornado_YPOS, 86, 95, 110);
  drawPixel(43 + tornado_XPOS, 22 + tornado_YPOS, 145, 155, 176);
  drawPixel(44 + tornado_XPOS, 22 + tornado_YPOS, 195, 210, 230);
  drawPixel(45 + tornado_XPOS, 22 + tornado_YPOS, 194, 210, 230);
  drawPixel(46 + tornado_XPOS, 22 + tornado_YPOS, 195, 211, 230);
  drawPixel(47 + tornado_XPOS, 22 + tornado_YPOS, 115, 124, 140);
  drawPixel(48 + tornado_XPOS, 22 + tornado_YPOS, 114, 125, 141);
  drawPixel(49 + tornado_XPOS, 22 + tornado_YPOS, 84, 85, 111);
  drawPixel(42 + tornado_XPOS, 23 + tornado_YPOS, 85, 85, 110);
  drawPixel(43 + tornado_XPOS, 23 + tornado_YPOS, 85, 85, 111);
  drawPixel(44 + tornado_XPOS, 23 + tornado_YPOS, 145, 155, 177);
  drawPixel(45 + tornado_XPOS, 23 + tornado_YPOS, 194, 211, 230);
  drawPixel(46 + tornado_XPOS, 23 + tornado_YPOS, 145, 154, 176);
  drawPixel(47 + tornado_XPOS, 23 + tornado_YPOS, 114, 125, 141);
  drawPixel(48 + tornado_XPOS, 23 + tornado_YPOS, 115, 124, 141);
  drawPixel(49 + tornado_XPOS, 23 + tornado_YPOS, 84, 85, 111);
  drawPixel(44 + tornado_XPOS, 24 + tornado_YPOS, 85, 84, 111);
  drawPixel(45 + tornado_XPOS, 24 + tornado_YPOS, 144, 155, 177);
  drawPixel(46 + tornado_XPOS, 24 + tornado_YPOS, 144, 155, 177);
  drawPixel(47 + tornado_XPOS, 24 + tornado_YPOS, 115, 125, 141);
  drawPixel(48 + tornado_XPOS, 24 + tornado_YPOS, 85, 85, 110);
  drawPixel(45 + tornado_XPOS, 25 + tornado_YPOS, 85, 84, 110);
  drawPixel(46 + tornado_XPOS, 25 + tornado_YPOS, 144, 155, 177);
  drawPixel(47 + tornado_XPOS, 25 + tornado_YPOS, 84, 84, 110);
  drawPixel(46 + tornado_XPOS, 26 + tornado_YPOS, 85, 85, 111);
}

void introWall() {
  drawPixel(0 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(3 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(5 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(6 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(8 + introWall_XPOS, 0 + introWall_YPOS, 255, 243, 226);
  drawPixel(9 + introWall_XPOS, 0 + introWall_YPOS, 231, 136, 104);
  drawPixel(10 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(11 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 0 + introWall_YPOS, 231, 136, 104);
  drawPixel(16 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(17 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(18 + introWall_XPOS, 0 + introWall_YPOS, 231, 136, 104);
  drawPixel(19 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 0 + introWall_YPOS, 255, 243, 227);
  drawPixel(21 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(27 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(29 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(33 + introWall_XPOS, 0 + introWall_YPOS, 254, 243, 226);
  drawPixel(34 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 105);
  drawPixel(42 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(44 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 0 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 0 + introWall_YPOS, 231, 136, 104);
  drawPixel(49 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(53 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 0 + introWall_YPOS, 231, 136, 104);
  drawPixel(55 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(59 + introWall_XPOS, 0 + introWall_YPOS, 255, 243, 226);
  drawPixel(60 + introWall_XPOS, 0 + introWall_YPOS, 231, 136, 104);
  drawPixel(61 + introWall_XPOS, 0 + introWall_YPOS, 230, 137, 104);
  drawPixel(62 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 0 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(5 + introWall_XPOS, 1 + introWall_YPOS, 231, 136, 104);
  drawPixel(6 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(7 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(8 + introWall_XPOS, 1 + introWall_YPOS, 254, 243, 226);
  drawPixel(9 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(10 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 1 + introWall_YPOS, 231, 136, 104);
  drawPixel(12 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(14 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(19 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(20 + introWall_XPOS, 1 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(22 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(26 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(27 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(28 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(31 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 1 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(35 + introWall_XPOS, 1 + introWall_YPOS, 231, 136, 104);
  drawPixel(36 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(37 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(38 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(40 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 1 + introWall_YPOS, 231, 136, 104);
  drawPixel(42 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(43 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 1 + introWall_YPOS, 255, 242, 226);
  drawPixel(46 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(50 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 1 + introWall_YPOS, 231, 136, 104);
  drawPixel(54 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(55 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(58 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 1 + introWall_YPOS, 255, 243, 226);
  drawPixel(60 + introWall_XPOS, 1 + introWall_YPOS, 230, 137, 104);
  drawPixel(61 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 105);
  drawPixel(62 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 1 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(1 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(3 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(4 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(5 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(7 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(8 + introWall_XPOS, 2 + introWall_YPOS, 255, 243, 226);
  drawPixel(9 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(14 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(15 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(17 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 2 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(23 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(24 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(27 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(28 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 2 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(35 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(36 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(38 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(41 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(45 + introWall_XPOS, 2 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(47 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(51 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(52 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(55 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(56 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 2 + introWall_YPOS, 255, 242, 226);
  drawPixel(60 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 105);
  drawPixel(61 + introWall_XPOS, 2 + introWall_YPOS, 231, 136, 104);
  drawPixel(62 + introWall_XPOS, 2 + introWall_YPOS, 230, 137, 104);
  drawPixel(63 + introWall_XPOS, 2 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 3 + introWall_YPOS, 231, 136, 104);
  drawPixel(1 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(2 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(3 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(8 + introWall_XPOS, 3 + introWall_YPOS, 255, 243, 226);
  drawPixel(9 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(14 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(15 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(17 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 3 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 3 + introWall_YPOS, 231, 136, 104);
  drawPixel(22 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(26 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(27 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(30 + introWall_XPOS, 3 + introWall_YPOS, 231, 136, 104);
  drawPixel(31 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(32 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 3 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(35 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 3 + introWall_YPOS, 231, 136, 104);
  drawPixel(37 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(39 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 3 + introWall_YPOS, 231, 136, 104);
  drawPixel(43 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(45 + introWall_XPOS, 3 + introWall_YPOS, 254, 243, 226);
  drawPixel(46 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(50 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(53 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 3 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 105);
  drawPixel(57 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 3 + introWall_YPOS, 255, 243, 226);
  drawPixel(60 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 3 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 3 + introWall_YPOS, 231, 136, 104);
  drawPixel(0 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(1 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(2 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(3 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(5 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(6 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(7 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(8 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(9 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(10 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(11 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(12 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(13 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(14 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(15 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(16 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(17 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(18 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(19 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(20 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(22 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(23 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(24 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(25 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(26 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(28 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(29 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(30 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(31 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(32 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(33 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(35 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(36 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(37 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(38 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(39 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(40 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(41 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(42 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(43 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(45 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(46 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(47 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(48 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(49 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(50 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(51 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(52 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(53 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(54 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(55 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(56 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(57 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 227);
  drawPixel(59 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(60 + introWall_XPOS, 4 + introWall_YPOS, 255, 242, 226);
  drawPixel(61 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(62 + introWall_XPOS, 4 + introWall_YPOS, 254, 243, 226);
  drawPixel(63 + introWall_XPOS, 4 + introWall_YPOS, 255, 243, 226);
  drawPixel(0 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(1 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(3 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(4 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(6 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(8 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(10 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(12 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(13 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 5 + introWall_YPOS, 255, 243, 226);
  drawPixel(15 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(19 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(21 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(23 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 5 + introWall_YPOS, 255, 242, 226);
  drawPixel(27 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(28 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(29 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(33 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(34 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(35 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(38 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(39 + introWall_XPOS, 5 + introWall_YPOS, 255, 243, 226);
  drawPixel(40 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(42 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(44 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(47 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(50 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(51 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 5 + introWall_YPOS, 255, 243, 226);
  drawPixel(53 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(55 + introWall_XPOS, 5 + introWall_YPOS, 231, 136, 104);
  drawPixel(56 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(57 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(58 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 5 + introWall_YPOS, 230, 137, 104);
  drawPixel(63 + introWall_XPOS, 5 + introWall_YPOS, 230, 136, 105);
  drawPixel(0 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(2 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(4 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(5 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(6 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(7 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(10 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(11 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(13 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 6 + introWall_YPOS, 255, 243, 226);
  drawPixel(15 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(18 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(21 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(25 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 6 + introWall_YPOS, 255, 243, 227);
  drawPixel(27 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(28 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(29 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(30 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(33 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(37 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 6 + introWall_YPOS, 254, 243, 226);
  drawPixel(40 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(42 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(46 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(48 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(50 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(52 + introWall_XPOS, 6 + introWall_YPOS, 255, 242, 226);
  drawPixel(53 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(54 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(55 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 6 + introWall_YPOS, 230, 137, 104);
  drawPixel(59 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(60 + introWall_XPOS, 6 + introWall_YPOS, 231, 136, 104);
  drawPixel(61 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 105);
  drawPixel(63 + introWall_XPOS, 6 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(1 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(2 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(3 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(4 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(5 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(10 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(12 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(13 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(14 + introWall_XPOS, 7 + introWall_YPOS, 254, 243, 226);
  drawPixel(15 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(19 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(20 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(21 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(22 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(26 + introWall_XPOS, 7 + introWall_YPOS, 254, 243, 226);
  drawPixel(27 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(30 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(31 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(35 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(36 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(38 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(39 + introWall_XPOS, 7 + introWall_YPOS, 255, 243, 226);
  drawPixel(40 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(41 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(42 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(47 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 7 + introWall_YPOS, 255, 243, 227);
  drawPixel(53 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 105);
  drawPixel(56 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(57 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(58 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 7 + introWall_YPOS, 231, 136, 104);
  drawPixel(60 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(61 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 7 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 7 + introWall_YPOS, 230, 137, 104);
  drawPixel(0 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(5 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(7 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(8 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(12 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(13 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(14 + introWall_XPOS, 8 + introWall_YPOS, 255, 243, 226);
  drawPixel(15 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(21 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(22 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(24 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 8 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(29 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(31 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(33 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(37 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(38 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(39 + introWall_XPOS, 8 + introWall_YPOS, 255, 243, 227);
  drawPixel(40 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(43 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(46 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(50 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 8 + introWall_YPOS, 254, 243, 226);
  drawPixel(53 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(55 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(58 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(60 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(61 + introWall_XPOS, 8 + introWall_YPOS, 231, 136, 104);
  drawPixel(62 + introWall_XPOS, 8 + introWall_YPOS, 230, 137, 104);
  drawPixel(63 + introWall_XPOS, 8 + introWall_YPOS, 230, 136, 105);
  drawPixel(0 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(1 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(2 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(3 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(5 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(6 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(7 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(8 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(9 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(11 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(12 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(13 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(14 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(15 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(16 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(17 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(18 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(19 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(20 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(21 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(22 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(23 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(24 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(25 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(26 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(28 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(29 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(30 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(31 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(32 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(33 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(34 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(35 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(36 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(37 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(38 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(39 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(40 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(41 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(42 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(43 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(45 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(47 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(48 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(49 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(50 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(51 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(52 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(53 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(54 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(55 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(56 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(57 + introWall_XPOS, 9 + introWall_YPOS, 254, 243, 226);
  drawPixel(58 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(59 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(60 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(61 + introWall_XPOS, 9 + introWall_YPOS, 255, 242, 226);
  drawPixel(62 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 227);
  drawPixel(63 + introWall_XPOS, 9 + introWall_YPOS, 255, 243, 226);
  drawPixel(0 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(1 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 10 + introWall_YPOS, 255, 243, 226);
  drawPixel(3 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(7 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(9 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(10 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(12 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(14 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(15 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(18 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(19 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(20 + introWall_XPOS, 10 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(22 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(25 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(27 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(29 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(30 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 10 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(35 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(38 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(39 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(40 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(42 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 10 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(47 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(50 + introWall_XPOS, 10 + introWall_YPOS, 231, 136, 104);
  drawPixel(51 + introWall_XPOS, 10 + introWall_YPOS, 230, 137, 104);
  drawPixel(52 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(56 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(59 + introWall_XPOS, 10 + introWall_YPOS, 254, 243, 226);
  drawPixel(60 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 105);
  drawPixel(62 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 10 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(1 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(2 + introWall_XPOS, 11 + introWall_YPOS, 255, 243, 226);
  drawPixel(3 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(8 + introWall_XPOS, 11 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 11 + introWall_YPOS, 230, 137, 104);
  drawPixel(12 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(13 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(14 + introWall_XPOS, 11 + introWall_YPOS, 230, 137, 104);
  drawPixel(15 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(16 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 11 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(19 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 11 + introWall_YPOS, 255, 242, 226);
  drawPixel(21 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(22 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(27 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(28 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(31 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 11 + introWall_YPOS, 230, 137, 104);
  drawPixel(33 + introWall_XPOS, 11 + introWall_YPOS, 255, 243, 227);
  drawPixel(34 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(37 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(38 + introWall_XPOS, 11 + introWall_YPOS, 230, 137, 104);
  drawPixel(39 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(40 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(43 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(44 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 11 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(47 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(55 + introWall_XPOS, 11 + introWall_YPOS, 231, 136, 104);
  drawPixel(56 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 11 + introWall_YPOS, 255, 243, 226);
  drawPixel(60 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(61 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 11 + introWall_YPOS, 230, 136, 105);
  drawPixel(0 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(2 + introWall_XPOS, 12 + introWall_YPOS, 255, 243, 227);
  drawPixel(3 + introWall_XPOS, 12 + introWall_YPOS, 231, 136, 104);
  drawPixel(4 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(11 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(14 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 105);
  drawPixel(15 + introWall_XPOS, 12 + introWall_YPOS, 231, 136, 104);
  drawPixel(16 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 12 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(26 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 105);
  drawPixel(27 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(32 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 105);
  drawPixel(33 + introWall_XPOS, 12 + introWall_YPOS, 254, 243, 226);
  drawPixel(34 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 12 + introWall_YPOS, 231, 136, 104);
  drawPixel(40 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(44 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 105);
  drawPixel(45 + introWall_XPOS, 12 + introWall_YPOS, 254, 243, 226);
  drawPixel(46 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 105);
  drawPixel(48 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(50 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(53 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 12 + introWall_YPOS, 231, 136, 104);
  drawPixel(55 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 12 + introWall_YPOS, 231, 136, 104);
  drawPixel(58 + introWall_XPOS, 12 + introWall_YPOS, 230, 137, 104);
  drawPixel(59 + introWall_XPOS, 12 + introWall_YPOS, 255, 243, 226);
  drawPixel(60 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 12 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(1 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 13 + introWall_YPOS, 254, 243, 226);
  drawPixel(3 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(4 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(5 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(6 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(7 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(8 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(12 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(16 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(20 + introWall_XPOS, 13 + introWall_YPOS, 254, 243, 226);
  drawPixel(21 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(22 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(26 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(27 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(31 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(33 + introWall_XPOS, 13 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(36 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(37 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(38 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(40 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(41 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(42 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(43 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 13 + introWall_YPOS, 255, 242, 226);
  drawPixel(46 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(47 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(48 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(49 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(50 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(52 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(53 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 13 + introWall_YPOS, 231, 136, 104);
  drawPixel(57 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(58 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 105);
  drawPixel(59 + introWall_XPOS, 13 + introWall_YPOS, 254, 243, 226);
  drawPixel(60 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 13 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 13 + introWall_YPOS, 230, 137, 104);
  drawPixel(0 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(1 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(2 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(3 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(5 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(6 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(7 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(8 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(9 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(11 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(12 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(13 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(14 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(15 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(16 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(17 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(18 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(19 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(20 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(21 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(22 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(23 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(24 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(25 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(26 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(28 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(29 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(30 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(31 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(32 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(33 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(35 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(36 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(37 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(38 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(39 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(40 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(41 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(42 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(43 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(45 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(47 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(48 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(49 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(50 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(51 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(52 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(53 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(54 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(55 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(56 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(57 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(58 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(59 + introWall_XPOS, 14 + introWall_YPOS, 255, 242, 226);
  drawPixel(60 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(61 + introWall_XPOS, 14 + introWall_YPOS, 254, 243, 226);
  drawPixel(62 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 226);
  drawPixel(63 + introWall_XPOS, 14 + introWall_YPOS, 255, 243, 227);
  drawPixel(0 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(2 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(7 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 15 + introWall_YPOS, 254, 243, 226);
  drawPixel(10 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(11 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(12 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(13 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(14 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(15 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(17 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(19 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(21 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(22 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(26 + introWall_XPOS, 15 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(28 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(29 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(31 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(37 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(39 + introWall_XPOS, 15 + introWall_YPOS, 255, 243, 226);
  drawPixel(40 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(42 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(43 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(47 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(49 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(51 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(52 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 15 + introWall_YPOS, 254, 243, 226);
  drawPixel(55 + introWall_XPOS, 15 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 105);
  drawPixel(60 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 15 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 15 + introWall_YPOS, 231, 136, 104);
  drawPixel(0 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(2 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(3 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(5 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(6 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(7 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 16 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(11 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(13 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(14 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(15 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(16 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(19 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(20 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(21 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(22 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 16 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(28 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(29 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(30 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(31 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(32 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(33 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(36 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(39 + introWall_XPOS, 16 + introWall_YPOS, 255, 242, 226);
  drawPixel(40 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(41 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(42 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(50 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(51 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 16 + introWall_YPOS, 255, 242, 226);
  drawPixel(55 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(57 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(58 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 16 + introWall_YPOS, 230, 137, 104);
  drawPixel(61 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 105);
  drawPixel(62 + introWall_XPOS, 16 + introWall_YPOS, 231, 136, 104);
  drawPixel(63 + introWall_XPOS, 16 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(3 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(4 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(7 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 17 + introWall_YPOS, 255, 243, 227);
  drawPixel(10 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(12 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(13 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(16 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(19 + introWall_XPOS, 17 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(21 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(25 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 17 + introWall_YPOS, 255, 242, 226);
  drawPixel(27 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 17 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(33 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(39 + introWall_XPOS, 17 + introWall_YPOS, 255, 243, 227);
  drawPixel(40 + introWall_XPOS, 17 + introWall_YPOS, 231, 136, 104);
  drawPixel(41 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(43 + introWall_XPOS, 17 + introWall_YPOS, 231, 136, 104);
  drawPixel(44 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(46 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(48 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(52 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 17 + introWall_YPOS, 230, 137, 104);
  drawPixel(54 + introWall_XPOS, 17 + introWall_YPOS, 255, 243, 227);
  drawPixel(55 + introWall_XPOS, 17 + introWall_YPOS, 231, 136, 104);
  drawPixel(56 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(58 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(61 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 17 + introWall_YPOS, 230, 136, 105);
  drawPixel(0 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(1 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(2 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(7 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 18 + introWall_YPOS, 254, 243, 226);
  drawPixel(10 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(12 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(17 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(19 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(21 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 18 + introWall_YPOS, 255, 243, 227);
  drawPixel(27 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(29 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(30 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(31 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(33 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(35 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(38 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 18 + introWall_YPOS, 254, 243, 226);
  drawPixel(40 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(42 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(45 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(49 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(50 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(51 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 18 + introWall_YPOS, 255, 243, 226);
  drawPixel(55 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 105);
  drawPixel(57 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(58 + introWall_XPOS, 18 + introWall_YPOS, 230, 137, 104);
  drawPixel(59 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 18 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 18 + introWall_YPOS, 231, 136, 104);
  drawPixel(0 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(1 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(2 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(3 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(5 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(6 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(7 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(8 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(9 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(11 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(12 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(13 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(14 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(15 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(16 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(17 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(18 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(19 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(20 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(22 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(23 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(24 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(25 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 227);
  drawPixel(26 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(27 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(28 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(29 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(30 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(31 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 227);
  drawPixel(32 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(33 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(35 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(36 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(37 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 227);
  drawPixel(38 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(39 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(40 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(41 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(42 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(43 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(45 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(46 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(47 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(48 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(49 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 227);
  drawPixel(50 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(51 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(52 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(53 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(54 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(55 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(56 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(57 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(58 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 227);
  drawPixel(59 + introWall_XPOS, 19 + introWall_YPOS, 254, 243, 226);
  drawPixel(60 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(61 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(62 + introWall_XPOS, 19 + introWall_YPOS, 255, 243, 226);
  drawPixel(63 + introWall_XPOS, 19 + introWall_YPOS, 255, 242, 226);
  drawPixel(0 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(3 + introWall_XPOS, 20 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(12 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(16 + introWall_XPOS, 20 + introWall_YPOS, 255, 243, 226);
  drawPixel(17 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(19 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(21 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(22 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(23 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(24 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(25 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(26 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(27 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(29 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(30 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(31 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 20 + introWall_YPOS, 255, 243, 227);
  drawPixel(34 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(36 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(40 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(41 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(42 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(43 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(44 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(46 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(47 + introWall_XPOS, 20 + introWall_YPOS, 255, 243, 226);
  drawPixel(48 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(50 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(51 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 20 + introWall_YPOS, 231, 136, 104);
  drawPixel(53 + introWall_XPOS, 20 + introWall_YPOS, 230, 137, 104);
  drawPixel(54 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(58 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 105);
  drawPixel(61 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 20 + introWall_YPOS, 255, 243, 226);
  drawPixel(63 + introWall_XPOS, 20 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(1 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 21 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(5 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(12 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 21 + introWall_YPOS, 255, 243, 226);
  drawPixel(17 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(19 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(21 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(22 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(26 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(27 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(31 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(33 + introWall_XPOS, 21 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(35 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(37 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(42 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(44 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(46 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 21 + introWall_YPOS, 255, 243, 226);
  drawPixel(48 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(50 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(51 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(54 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(55 + introWall_XPOS, 21 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 105);
  drawPixel(57 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 21 + introWall_YPOS, 231, 136, 104);
  drawPixel(61 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 21 + introWall_YPOS, 255, 243, 226);
  drawPixel(63 + introWall_XPOS, 21 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(1 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(2 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(3 + introWall_XPOS, 22 + introWall_YPOS, 255, 243, 226);
  drawPixel(4 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(11 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 22 + introWall_YPOS, 255, 243, 227);
  drawPixel(17 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(20 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(21 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(25 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(27 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(28 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(30 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(31 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(33 + introWall_XPOS, 22 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(35 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(36 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(37 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(38 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(39 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(42 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(44 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 22 + introWall_YPOS, 255, 243, 226);
  drawPixel(48 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(51 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(52 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(54 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(55 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(57 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(59 + introWall_XPOS, 22 + introWall_YPOS, 231, 136, 104);
  drawPixel(60 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 22 + introWall_YPOS, 230, 136, 105);
  drawPixel(62 + introWall_XPOS, 22 + introWall_YPOS, 254, 243, 226);
  drawPixel(63 + introWall_XPOS, 22 + introWall_YPOS, 230, 137, 104);
  drawPixel(0 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(1 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(2 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 23 + introWall_YPOS, 255, 243, 227);
  drawPixel(4 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(5 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(6 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(7 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(10 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 23 + introWall_YPOS, 254, 243, 226);
  drawPixel(17 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(20 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(21 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(22 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(23 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(27 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(28 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(29 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(30 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(31 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(33 + introWall_XPOS, 23 + introWall_YPOS, 255, 243, 227);
  drawPixel(34 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(35 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(36 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(37 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(40 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(41 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(44 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(45 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(46 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(47 + introWall_XPOS, 23 + introWall_YPOS, 255, 242, 226);
  drawPixel(48 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(51 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(52 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(53 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(54 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 23 + introWall_YPOS, 230, 137, 104);
  drawPixel(57 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(58 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(59 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 23 + introWall_YPOS, 231, 136, 104);
  drawPixel(62 + introWall_XPOS, 23 + introWall_YPOS, 255, 243, 226);
  drawPixel(63 + introWall_XPOS, 23 + introWall_YPOS, 230, 136, 105);
  drawPixel(0 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(1 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(2 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(3 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(4 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(5 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(6 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(7 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(8 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(9 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(10 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(11 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(12 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(13 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(14 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(15 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(16 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(17 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(18 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(19 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(20 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(21 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(22 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(23 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(24 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(25 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(26 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(27 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(28 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(29 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(30 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(31 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(32 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(33 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(34 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(35 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(36 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(37 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(38 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(39 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(40 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(41 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(42 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(43 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(45 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(46 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(47 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(48 + introWall_XPOS, 24 + introWall_YPOS, 254, 243, 226);
  drawPixel(49 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(50 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(51 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(52 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(53 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(54 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(55 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(56 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(57 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(59 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 227);
  drawPixel(60 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(61 + introWall_XPOS, 24 + introWall_YPOS, 255, 242, 226);
  drawPixel(62 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(63 + introWall_XPOS, 24 + introWall_YPOS, 255, 243, 226);
  drawPixel(0 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(1 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(2 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(4 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(6 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(8 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(9 + introWall_XPOS, 25 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(14 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(16 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(17 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(20 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(21 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(22 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(24 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(25 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(26 + introWall_XPOS, 25 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(29 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(30 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(33 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(34 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(39 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(41 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 25 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(47 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(48 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(50 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(51 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(52 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 105);
  drawPixel(53 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(57 + introWall_XPOS, 25 + introWall_YPOS, 255, 242, 226);
  drawPixel(58 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 25 + introWall_YPOS, 231, 136, 104);
  drawPixel(60 + introWall_XPOS, 25 + introWall_YPOS, 230, 137, 104);
  drawPixel(61 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 25 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(1 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(3 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(4 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 26 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(12 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(14 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(15 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(16 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(19 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(21 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(22 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(23 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 26 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(30 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(35 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(36 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(37 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(38 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(41 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(42 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 26 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(51 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 105);
  drawPixel(52 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(56 + introWall_XPOS, 26 + introWall_YPOS, 230, 137, 104);
  drawPixel(57 + introWall_XPOS, 26 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(59 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 26 + introWall_YPOS, 231, 136, 104);
  drawPixel(62 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 26 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(1 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(2 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(4 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(6 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(8 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(9 + introWall_XPOS, 27 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(12 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(14 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(15 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(16 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(17 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(18 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(20 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(21 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(22 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(24 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(25 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 27 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(28 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(30 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(32 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(34 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(39 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(43 + introWall_XPOS, 27 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(46 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(48 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(49 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(50 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(51 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 27 + introWall_YPOS, 230, 137, 104);
  drawPixel(53 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(54 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(55 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 105);
  drawPixel(57 + introWall_XPOS, 27 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(60 + introWall_XPOS, 27 + introWall_YPOS, 231, 136, 104);
  drawPixel(61 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 27 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(2 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(3 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(4 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(5 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(8 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(9 + introWall_XPOS, 28 + introWall_YPOS, 255, 242, 226);
  drawPixel(10 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(11 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(12 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(14 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(17 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(18 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(20 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(21 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(23 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(24 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(25 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 28 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(30 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(32 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(33 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(34 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(35 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(36 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(38 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 28 + introWall_YPOS, 255, 243, 227);
  drawPixel(44 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(45 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(46 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(47 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(49 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(51 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(52 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(53 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(55 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(57 + introWall_XPOS, 28 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(60 + introWall_XPOS, 28 + introWall_YPOS, 230, 137, 104);
  drawPixel(61 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 105);
  drawPixel(62 + introWall_XPOS, 28 + introWall_YPOS, 231, 136, 104);
  drawPixel(63 + introWall_XPOS, 28 + introWall_YPOS, 230, 136, 104);
  drawPixel(0 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(2 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(3 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(5 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(6 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(7 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(8 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(9 + introWall_XPOS, 29 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(11 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(12 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(15 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(16 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(17 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(18 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(19 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(20 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(21 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(22 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(23 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(24 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(26 + introWall_XPOS, 29 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(28 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(29 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(30 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(31 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(32 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(33 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(34 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(36 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(39 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(41 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(42 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(43 + introWall_XPOS, 29 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(45 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(46 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(47 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(48 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(49 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(50 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(51 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(53 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(54 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(55 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(56 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(57 + introWall_XPOS, 29 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(59 + introWall_XPOS, 29 + introWall_YPOS, 230, 137, 104);
  drawPixel(60 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 29 + introWall_YPOS, 231, 136, 104);
  drawPixel(62 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 29 + introWall_YPOS, 230, 136, 105);
  drawPixel(0 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(1 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(2 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(3 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(4 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(5 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(6 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(7 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(8 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(9 + introWall_XPOS, 30 + introWall_YPOS, 255, 243, 226);
  drawPixel(10 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(11 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(12 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(13 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(14 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(15 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(16 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(17 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(18 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
  drawPixel(19 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(20 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(21 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
  drawPixel(22 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(23 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(24 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(25 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(26 + introWall_XPOS, 30 + introWall_YPOS, 255, 243, 226);
  drawPixel(27 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(28 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(29 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(30 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
  drawPixel(31 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(32 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(33 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
  drawPixel(34 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(35 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(36 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(37 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(38 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(39 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(40 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(41 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(42 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(43 + introWall_XPOS, 30 + introWall_YPOS, 255, 243, 226);
  drawPixel(44 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(45 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(46 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(47 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(48 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
  drawPixel(49 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(50 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(51 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(52 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(53 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(54 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
  drawPixel(55 + introWall_XPOS, 30 + introWall_YPOS, 230, 137, 104);
  drawPixel(56 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(57 + introWall_XPOS, 30 + introWall_YPOS, 255, 243, 226);
  drawPixel(58 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(59 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 105);
  drawPixel(60 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(61 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(62 + introWall_XPOS, 30 + introWall_YPOS, 230, 136, 104);
  drawPixel(63 + introWall_XPOS, 30 + introWall_YPOS, 231, 136, 104);
}

void oneLastBite() {
  drawPixel(19 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(20 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(21 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(22 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(23 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(24 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(25 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(26 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(27 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(28 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(29 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(30 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(31 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(32 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 1, 1);
  drawPixel(33 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(34 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(35 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(36 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(37 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(38 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(39 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(40 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(41 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(42 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(43 + oneLastBite_XPOS, 2 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(18 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(20 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(21 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(22 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(23 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(24 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(25 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(26 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(27 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(28 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(29 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(31 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(33 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(34 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(36 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(38 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(39 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(40 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(41 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(42 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(44 + oneLastBite_XPOS, 3 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(19 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(20 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 66, 67);
  drawPixel(21 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(22 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 67, 67);
  drawPixel(23 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 66, 66);
  drawPixel(24 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(25 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(26 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(27 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(28 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(29 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(30 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 67, 67);
  drawPixel(32 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 66, 66, 66);
  drawPixel(33 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 66, 67);
  drawPixel(34 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 66, 67);
  drawPixel(35 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(36 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(37 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(39 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(40 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(41 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(42 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(44 + oneLastBite_XPOS, 4 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(20 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(21 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(22 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(23 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(24 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 67, 66, 67);
  drawPixel(25 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(26 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(28 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(29 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(30 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 66, 66, 66);
  drawPixel(31 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(32 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(33 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(35 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(36 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 66, 66, 67);
  drawPixel(37 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(38 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(39 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(40 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 229, 170, 122);
  drawPixel(41 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 229, 170, 122);
  drawPixel(42 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 127, 1);
  drawPixel(43 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(44 + oneLastBite_XPOS, 5 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(18 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(20 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 66, 67, 67);
  drawPixel(22 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(23 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(24 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(26 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 66, 66, 66);
  drawPixel(27 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(28 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(29 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(30 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 66, 66, 66);
  drawPixel(31 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(32 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(33 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 67, 66, 67);
  drawPixel(34 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(35 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 67, 66, 67);
  drawPixel(36 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 66, 66, 67);
  drawPixel(38 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(39 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(40 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(41 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 229, 170, 122);
  drawPixel(42 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 254, 127, 0);
  drawPixel(43 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(44 + oneLastBite_XPOS, 6 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(20 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(21 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(22 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(24 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(25 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(26 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 67, 66, 67);
  drawPixel(27 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(28 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(29 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(30 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(31 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(32 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(33 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(34 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(37 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(39 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(40 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(41 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(42 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(43 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(44 + oneLastBite_XPOS, 7 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(18 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(19 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(20 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(21 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 66, 66);
  drawPixel(22 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(23 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(24 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 66, 67);
  drawPixel(25 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(26 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(27 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(28 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(29 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(30 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 66, 67);
  drawPixel(31 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(32 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(33 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(34 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 67, 66, 66);
  drawPixel(35 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 67, 67, 66);
  drawPixel(36 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 66, 67, 66);
  drawPixel(37 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(39 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(40 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 254, 126, 1);
  drawPixel(41 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(42 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(44 + oneLastBite_XPOS, 8 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(19 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(20 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(24 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(25 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(27 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(29 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(30 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(31 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(32 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(33 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(35 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(36 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(37 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(39 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(40 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(41 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(42 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(44 + oneLastBite_XPOS, 9 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(18 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(20 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(21 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(22 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(23 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(24 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(25 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(26 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 37, 36, 37);
  drawPixel(27 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(28 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(29 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(30 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(32 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(33 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(34 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(35 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 37, 37, 37);
  drawPixel(36 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 37, 37);
  drawPixel(38 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(39 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 37, 37, 36);
  drawPixel(40 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(41 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 37, 36, 37);
  drawPixel(42 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(43 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(44 + oneLastBite_XPOS, 10 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(18 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(19 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(20 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(21 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(22 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(23 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(26 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(27 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(28 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(29 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(30 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(32 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(33 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(34 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(35 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(36 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(37 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(39 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(40 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(42 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(43 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(44 + oneLastBite_XPOS, 11 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(18 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(19 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(20 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 37, 37);
  drawPixel(22 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(24 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(25 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(26 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(27 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(28 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(29 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(30 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 37, 37, 37);
  drawPixel(31 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(32 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(33 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(34 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(35 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 37, 37, 37);
  drawPixel(36 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(37 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(39 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(40 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 37, 37, 37);
  drawPixel(41 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(42 + oneLastBite_XPOS, 12 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(18 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(20 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 37, 36, 37);
  drawPixel(22 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(23 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(24 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(25 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(26 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(27 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(28 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(29 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(30 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(31 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(32 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(34 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(35 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(36 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(37 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(38 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(40 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 36, 37, 37);
  drawPixel(41 + oneLastBite_XPOS, 13 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(18 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(19 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(20 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(21 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 36, 37);
  drawPixel(22 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(23 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(24 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 37, 37);
  drawPixel(25 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(26 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(27 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(29 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(30 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 37, 36, 36);
  drawPixel(31 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(32 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(33 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 37, 36);
  drawPixel(34 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 37, 36, 37);
  drawPixel(35 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 37, 37, 36);
  drawPixel(36 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(37 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(40 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 36, 36, 36);
  drawPixel(42 + oneLastBite_XPOS, 14 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(18 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(20 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(21 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(22 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(23 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(24 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(25 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(28 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(29 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(30 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(32 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(34 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(35 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(36 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(37 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(38 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(40 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(41 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(42 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(44 + oneLastBite_XPOS, 15 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(20 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(21 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(22 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(23 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(24 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(25 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(26 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(27 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(28 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(29 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(30 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(31 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(32 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(33 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(34 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(35 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(36 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(37 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(39 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(40 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(41 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(42 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(44 + oneLastBite_XPOS, 16 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(19 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(20 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(21 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(22 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(24 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(25 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(26 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(28 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(29 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(30 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(31 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(32 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(33 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(34 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(35 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(36 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(38 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(39 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(41 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(42 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(43 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(44 + oneLastBite_XPOS, 17 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(18 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(19 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(20 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(21 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(22 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(23 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(25 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(26 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(28 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(29 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(31 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(32 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(34 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(35 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(36 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(38 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 1, 1, 1);
  drawPixel(39 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(40 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(41 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(42 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(43 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(44 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(45 + oneLastBite_XPOS, 18 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(18 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(20 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(21 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(22 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(23 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(24 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(25 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(26 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(27 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(28 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(31 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(32 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(33 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(34 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(35 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(38 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(39 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(40 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(41 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(42 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(43 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(44 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(46 + oneLastBite_XPOS, 19 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(18 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(20 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(21 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(22 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(23 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(24 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(26 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(27 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(28 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(29 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(30 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(31 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(32 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(34 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(35 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(38 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(39 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(40 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(41 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(42 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(43 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(44 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(45 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(46 + oneLastBite_XPOS, 20 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(18 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(20 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(21 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(22 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(23 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(25 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(26 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(27 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(28 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(29 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(30 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(32 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(33 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(34 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(35 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 254);
  drawPixel(36 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(38 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(39 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 254, 254);
  drawPixel(40 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 254, 255);
  drawPixel(41 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(42 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 255, 255);
  drawPixel(43 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 254, 255);
  drawPixel(45 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 254, 255, 254);
  drawPixel(46 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(50 + oneLastBite_XPOS, 21 + oneLastBite_YPOS, 255, 255, 254);
  drawPixel(19 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(20 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(21 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(22 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(23 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(24 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(25 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(26 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 1, 1);
  drawPixel(27 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(28 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(29 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(30 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(31 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(32 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(33 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(34 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(35 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(36 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(37 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(38 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(39 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(40 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(41 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(42 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 1, 0);
  drawPixel(43 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(44 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(45 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(48 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(49 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(50 + oneLastBite_XPOS, 22 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(19 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(25 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(26 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(27 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(33 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(34 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(35 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(41 + oneLastBite_XPOS, 24 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(19 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(21 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(23 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(25 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(26 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(29 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(30 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(31 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(33 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(34 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(35 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(37 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(38 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(39 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(43 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(44 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(45 + oneLastBite_XPOS, 25 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(19 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(21 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(23 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(26 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(27 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(30 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(33 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(37 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(41 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(43 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(45 + oneLastBite_XPOS, 26 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(19 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(21 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(22 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(23 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(25 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(26 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(27 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(30 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(33 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(34 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(35 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 1);
  drawPixel(37 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(41 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(43 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 127, 0);
  drawPixel(44 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 255, 126, 0);
  drawPixel(45 + oneLastBite_XPOS, 27 + oneLastBite_YPOS, 254, 126, 0);
  drawPixel(22 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(23 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(24 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(26 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(27 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(34 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(35 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(36 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(38 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(39 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(40 + oneLastBite_XPOS, 29 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(22 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(23 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(24 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(26 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(28 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(30 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(31 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(34 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(35 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(36 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(38 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(39 + oneLastBite_XPOS, 30 + oneLastBite_YPOS, 1, 0, 0);
  drawPixel(24 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(26 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(27 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(28 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(30 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(31 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(32 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(34 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(39 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 0, 0, 1);
  drawPixel(40 + oneLastBite_XPOS, 31 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(23 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(24 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(28 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(30 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(32 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 0, 0);
  drawPixel(34 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 1, 0);
  drawPixel(35 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(36 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(38 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 1, 1);
  drawPixel(39 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 1, 0, 1);
  drawPixel(40 + oneLastBite_XPOS, 32 + oneLastBite_YPOS, 0, 1, 0);
}

void chapter1TornadoBackground() {
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            0 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            1 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            2 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            3 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            4 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 158, 169, 183);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 158, 168, 182);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 159, 168, 183);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 158, 168, 183);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            5 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            6 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 195, 194, 201);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 194, 195, 201);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 195, 195, 200);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 195, 195, 201);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            7 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            8 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            9 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            10 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            11 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            12 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            13 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            14 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            15 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            16 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            17 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            18 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 60, 95, 130);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 61, 95, 130);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 60, 94, 130);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            19 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 60, 95, 131);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            20 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            21 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 84, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            22 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 12, 85, 120);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 13, 85, 120);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            23 + chapter1TornadoBackground_YPOS, 13, 85, 121);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            24 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 106);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 73, 107);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 34, 72, 107);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            25 + chapter1TornadoBackground_YPOS, 35, 72, 107);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            26 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            27 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            28 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            29 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            30 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            31 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 164, 165, 165);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 165);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 164, 165);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 165, 165, 164);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            32 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            33 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            34 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(0 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(1 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(2 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(3 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(4 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(5 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(6 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(7 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(8 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(9 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(10 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(11 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(12 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(13 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(14 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(15 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(16 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(17 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(18 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(19 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(20 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(21 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(22 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(23 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(24 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(25 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(26 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(27 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(28 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(29 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(30 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(31 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(32 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(33 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(34 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(35 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(36 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(37 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(38 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(39 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(40 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(41 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(42 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(43 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(44 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(45 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(46 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(47 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(48 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(49 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(50 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(51 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(52 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(53 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(54 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(55 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(56 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 75, 81);
  drawPixel(57 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
  drawPixel(58 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 71, 74, 81);
  drawPixel(59 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(60 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(61 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(62 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 81);
  drawPixel(63 + chapter1TornadoBackground_XPOS,
            35 + chapter1TornadoBackground_YPOS, 70, 74, 80);
}

void sharkBackground() {
  drawPixel(0 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(3 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(4 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(5 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(6 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(7 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(8 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(9 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(11 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(12 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(13 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(14 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(15 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(16 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(17 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(18 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(19 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(20 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(21 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(23 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(24 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(25 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(26 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(27 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(28 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(29 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(30 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(31 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(32 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(33 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(34 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(35 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(36 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(37 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(38 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(39 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(40 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(41 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(42 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(43 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(44 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(45 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(46 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(47 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(48 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(49 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(50 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(51 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(52 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(53 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(54 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(55 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(56 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(57 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(58 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(59 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(60 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(61 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(62 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(63 + sharkBackground_XPOS, 0 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(0 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(2 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(3 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(5 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(6 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(7 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(9 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(11 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(12 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(13 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(14 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(15 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(16 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(17 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(18 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(19 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(20 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(21 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(23 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(24 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(25 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(26 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(27 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(28 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(29 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(30 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(31 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(32 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(33 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(34 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(35 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(36 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(37 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(38 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(39 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(40 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(41 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(42 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(43 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(44 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(45 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(46 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(47 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(48 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(49 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(50 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(51 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(52 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(53 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(54 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(55 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(56 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(57 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(58 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(59 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(60 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(61 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(62 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(63 + sharkBackground_XPOS, 1 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(0 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(3 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(4 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(5 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(6 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(7 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(9 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(10 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(11 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(12 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(13 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(14 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(15 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(16 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(17 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(18 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(19 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(20 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(21 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(23 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(24 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(25 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(26 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(27 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(28 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(29 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(30 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(31 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(32 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(33 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(34 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(35 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(36 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(37 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(38 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(39 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(40 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(41 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(42 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(43 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(44 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(45 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(46 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(47 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(48 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(49 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(50 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(51 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(52 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(53 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(54 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(55 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(56 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(57 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(58 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(59 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(60 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(61 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(62 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(63 + sharkBackground_XPOS, 2 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(0 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(2 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(3 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(5 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(6 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(7 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(9 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(11 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(12 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(13 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(14 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(15 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(16 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(17 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(18 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(19 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(20 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(21 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(23 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(24 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(25 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(26 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(27 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(28 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(29 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(30 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(31 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 176, 226, 251);
  drawPixel(33 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(34 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(35 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(36 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(37 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(38 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(39 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(40 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(41 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(42 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(43 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(44 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(45 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(46 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(47 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(48 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(49 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(50 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(51 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(52 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(53 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(54 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(55 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(56 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(57 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(58 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(59 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(60 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(61 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(62 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(63 + sharkBackground_XPOS, 3 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(0 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(3 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(5 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(7 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(9 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(11 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(12 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(13 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(14 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(15 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(16 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(17 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(18 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(19 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(20 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(21 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(23 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(24 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(25 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(26 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(27 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(28 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(29 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(30 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(31 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(33 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(34 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(35 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(36 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(37 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(38 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(39 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(40 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(41 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(42 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(43 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(44 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(45 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(46 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(47 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(48 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(49 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(50 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(51 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(52 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(53 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(54 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(55 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(56 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(57 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(58 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(59 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(60 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(61 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(62 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(63 + sharkBackground_XPOS, 4 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(0 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(2 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(3 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(4 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(5 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(9 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(10 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(11 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(12 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(13 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(14 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(15 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(16 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(17 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(18 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(19 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(20 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(21 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(23 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(24 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(25 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(26 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(27 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(28 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(29 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(30 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(31 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(33 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(34 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(35 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(36 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(37 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(38 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(39 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(40 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(41 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(42 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(43 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(44 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(45 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(46 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(47 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(48 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(49 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(50 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(51 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(52 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(53 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(54 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(55 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(56 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(57 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 176, 226, 251);
  drawPixel(58 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(59 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(60 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(61 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(62 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(63 + sharkBackground_XPOS, 5 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(0 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(1 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(2 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(5 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(6 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(9 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(11 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(12 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(13 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(14 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(15 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(16 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(17 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(18 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(19 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(20 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(21 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(23 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(24 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(25 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(26 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(27 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(28 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(29 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(30 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(31 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(34 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(35 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(36 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(37 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(38 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(39 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(40 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(41 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(42 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(43 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(44 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(45 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(46 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(47 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(48 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(49 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(50 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(51 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(52 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(53 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(54 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(55 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(56 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(57 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(58 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(59 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(60 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(61 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(62 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(63 + sharkBackground_XPOS, 6 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(0 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(2 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(4 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(5 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(8 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(9 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(11 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(12 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(13 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(14 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(15 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(16 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(17 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(18 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(19 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(20 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(21 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(22 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(23 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(24 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(25 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(26 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(27 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(28 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(29 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(30 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(31 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(33 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(34 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(35 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(36 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(37 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(38 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(39 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(40 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(41 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(42 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(43 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(44 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(45 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(46 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(47 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(48 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(49 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(50 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(51 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(52 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(53 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(54 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(55 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(56 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(57 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(58 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(59 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(60 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(61 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(62 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(63 + sharkBackground_XPOS, 7 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(0 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(1 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(5 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(6 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(9 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(10 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(11 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(12 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(13 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(14 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(15 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(16 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(17 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(18 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(19 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(20 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(21 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(22 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(23 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(24 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(25 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(26 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(27 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(28 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(29 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(30 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 226, 251);
  drawPixel(31 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(33 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(34 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(35 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(36 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(37 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(38 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(39 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 226, 251);
  drawPixel(40 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(41 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(42 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 251, 251);
  drawPixel(43 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(44 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(45 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(46 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(47 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(48 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(49 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(50 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(51 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(52 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(53 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(54 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(55 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(56 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 251, 251, 251);
  drawPixel(57 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(58 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 176, 226, 251);
  drawPixel(59 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(60 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 226, 251);
  drawPixel(61 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(62 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(63 + sharkBackground_XPOS, 8 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(0 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 227, 251);
  drawPixel(4 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(5 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(6 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(9 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(10 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(11 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(12 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(13 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(14 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(15 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(16 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(17 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(18 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(19 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(20 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(21 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(22 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(23 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(24 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(25 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(26 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(27 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(28 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(29 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 251);
  drawPixel(30 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(31 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(32 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(33 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(34 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(35 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(36 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(37 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(38 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(39 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(40 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(41 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 251, 250);
  drawPixel(42 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(43 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(44 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(45 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(46 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(47 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 226, 250);
  drawPixel(48 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(49 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(50 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(51 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(52 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(53 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(54 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(55 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(56 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(57 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(58 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(59 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 226, 251);
  drawPixel(60 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(61 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(62 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(63 + sharkBackground_XPOS, 9 + sharkBackground_YPOS, 251, 250, 250);
  drawPixel(0 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(1 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(2 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(3 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(4 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(5 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(7 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(8 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(9 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(10 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(11 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(12 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(13 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(14 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(15 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(16 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(17 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(18 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(19 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(20 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(21 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 251,
            250);
  drawPixel(22 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(23 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(24 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(25 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(26 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(27 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(28 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(29 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(30 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(31 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 226,
            250);
  drawPixel(32 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 226,
            251);
  drawPixel(33 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(34 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 251, 251,
            250);
  drawPixel(35 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(36 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(37 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(38 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 227,
            250);
  drawPixel(39 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(40 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(41 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(42 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 251, 250,
            250);
  drawPixel(43 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 251, 251,
            251);
  drawPixel(44 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(45 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 183, 223);
  drawPixel(46 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(47 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(48 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 70, 182, 223);
  drawPixel(49 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(50 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(51 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(52 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 70, 182, 223);
  drawPixel(53 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(54 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(55 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 251, 250,
            250);
  drawPixel(56 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(57 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(58 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(59 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(60 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(61 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(62 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(63 + sharkBackground_XPOS, 10 + sharkBackground_YPOS, 251, 250,
            251);
  drawPixel(0 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(1 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(5 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(8 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(9 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(10 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(11 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(12 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(13 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(15 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(16 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(17 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(18 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(19 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(20 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(21 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(22 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(23 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(24 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(25 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(26 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(27 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 251, 250,
            251);
  drawPixel(28 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 251, 250,
            250);
  drawPixel(29 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 251,
            250);
  drawPixel(30 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(31 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(32 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(33 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 176, 226,
            250);
  drawPixel(34 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 251, 250,
            250);
  drawPixel(35 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(36 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 251, 251,
            251);
  drawPixel(37 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(38 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(39 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(40 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(41 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(42 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(43 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(44 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 70, 183, 223);
  drawPixel(45 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(46 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(47 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(48 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(49 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(50 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(51 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(52 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(53 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 70, 182, 223);
  drawPixel(54 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(55 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 251, 250,
            251);
  drawPixel(56 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(57 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(58 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(59 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(60 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(61 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 176, 227,
            250);
  drawPixel(62 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(63 + sharkBackground_XPOS, 11 + sharkBackground_YPOS, 250, 251,
            251);
  drawPixel(0 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(1 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(2 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(5 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(6 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(7 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 251, 250);
  drawPixel(8 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250, 250);
  drawPixel(9 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(10 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(11 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(12 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(13 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(15 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(16 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(17 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(18 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(19 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(20 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(21 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(22 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(23 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(24 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(25 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(26 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(27 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(28 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 251,
            250);
  drawPixel(29 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(30 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(31 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(32 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(33 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(34 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(35 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 251,
            250);
  drawPixel(36 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 251,
            250);
  drawPixel(37 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(38 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(39 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 70, 183, 222);
  drawPixel(40 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 71, 183, 223);
  drawPixel(41 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(42 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(43 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(44 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(45 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(46 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(47 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(48 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(49 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(50 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(51 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(52 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(53 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(54 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 70, 182, 223);
  drawPixel(55 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(56 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(57 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227,
            250);
  drawPixel(58 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227,
            250);
  drawPixel(59 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(60 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 176, 227,
            250);
  drawPixel(61 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(62 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 250, 251,
            250);
  drawPixel(63 + sharkBackground_XPOS, 12 + sharkBackground_YPOS, 70, 183, 223);
  drawPixel(0 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(1 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(2 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(3 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(4 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(5 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 176, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 226, 250);
  drawPixel(7 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 250, 250, 251);
  drawPixel(8 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(9 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(10 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(12 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(13 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(15 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(16 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(17 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(18 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(19 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(20 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(21 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(22 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(23 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(24 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(25 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(26 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(27 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 250, 250,
            250);
  drawPixel(28 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 250, 250,
            251);
  drawPixel(29 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 251, 250,
            250);
  drawPixel(30 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(31 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(32 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(33 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(34 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 250, 251,
            251);
  drawPixel(35 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 251, 250,
            251);
  drawPixel(36 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 251, 250,
            250);
  drawPixel(37 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(38 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(39 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(40 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(41 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(42 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(43 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(44 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(45 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(46 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(47 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(48 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(49 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(50 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(51 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(52 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(53 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(54 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(55 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 70, 183, 223);
  drawPixel(56 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 251, 250,
            251);
  drawPixel(57 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(58 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 176, 227,
            250);
  drawPixel(59 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(60 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(61 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 177, 227,
            250);
  drawPixel(62 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(63 + sharkBackground_XPOS, 13 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(0 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(1 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(2 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(3 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(4 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(5 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 227, 250);
  drawPixel(6 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 227, 251);
  drawPixel(7 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(8 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(9 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(10 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(12 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(13 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(15 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(16 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(17 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(18 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(19 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(20 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(21 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(22 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(23 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(24 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(25 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(26 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(27 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(28 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(29 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(30 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(31 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(32 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 226,
            250);
  drawPixel(33 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(34 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(35 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 70, 183, 222);
  drawPixel(36 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(37 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 70, 182, 223);
  drawPixel(38 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(39 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(40 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(41 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(42 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(43 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(44 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(45 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(46 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(47 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(48 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(49 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(50 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(51 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(52 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(53 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(54 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(55 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(56 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(57 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 227,
            251);
  drawPixel(58 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 177, 226,
            251);
  drawPixel(59 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 176, 227,
            251);
  drawPixel(60 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 176, 226,
            250);
  drawPixel(61 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 70, 183, 223);
  drawPixel(62 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(63 + sharkBackground_XPOS, 14 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(0 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(1 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(2 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(3 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(4 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(5 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(6 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(7 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(8 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(9 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(10 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(12 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(13 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(14 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(15 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(16 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(17 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(18 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(19 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(20 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(21 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(22 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(23 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(24 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(25 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(26 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(27 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(28 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(29 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(30 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 182, 222);
  drawPixel(31 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(32 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(33 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(34 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(35 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(36 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(37 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(38 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(39 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(40 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(41 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(42 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(43 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(44 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(45 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(46 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(47 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(48 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(49 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(50 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(51 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(52 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(53 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(54 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(55 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(56 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(57 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 70, 182, 222);
  drawPixel(58 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 183, 223);
  drawPixel(59 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 183, 222);
  drawPixel(60 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 71, 182, 223);
  drawPixel(61 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(62 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(63 + sharkBackground_XPOS, 15 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(0 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(1 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(2 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(3 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(4 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(5 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(6 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(7 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(8 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(9 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(10 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(12 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(13 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(15 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(16 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(17 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(18 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(19 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(20 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(21 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(22 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(23 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(24 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(25 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(26 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(27 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(28 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(29 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(30 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(31 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(32 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(33 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(34 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(35 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(36 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(37 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(38 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(39 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(40 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(41 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(42 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(43 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(44 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(45 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(46 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(47 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(48 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(49 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(50 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(51 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(52 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(53 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(54 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(55 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(56 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(57 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(58 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(59 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(60 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(61 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(62 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(63 + sharkBackground_XPOS, 16 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(0 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(1 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(2 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(3 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(4 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(5 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(6 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(7 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(8 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(9 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(10 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(11 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(12 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(13 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(15 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(16 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(17 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(18 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(19 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(20 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(21 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(22 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(23 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(24 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(25 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(26 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(27 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(28 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(29 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(30 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(31 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(32 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(33 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(34 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(35 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(36 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(37 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(38 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(39 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(40 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(41 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(42 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 1, 157, 205);
  drawPixel(43 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 1, 156, 205);
  drawPixel(44 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 0, 157, 205);
  drawPixel(45 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(46 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(47 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(48 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(49 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(50 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(51 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(52 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(53 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(54 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(55 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(56 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(57 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(58 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(59 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(60 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(61 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(62 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(63 + sharkBackground_XPOS, 17 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(0 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(1 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(2 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(3 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(4 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(5 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(6 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(7 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(8 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(9 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(10 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(12 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(13 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(15 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(16 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(17 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(18 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(19 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(22 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(23 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(24 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(25 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(26 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(27 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(28 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(29 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(30 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(31 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(32 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(33 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(34 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(35 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(36 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(37 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(38 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(39 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(40 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(41 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(42 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(43 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(44 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(45 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(46 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(47 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(48 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(49 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(50 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(51 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(52 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(53 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(54 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(55 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(56 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(57 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(58 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(59 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(60 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(61 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(62 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(63 + sharkBackground_XPOS, 18 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(0 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(1 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(2 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(3 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(4 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(5 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(6 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(7 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(8 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(9 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(10 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(11 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(12 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(13 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(14 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(15 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(16 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(17 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(20 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(26 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(27 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(28 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(29 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(30 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(31 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(32 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(33 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(34 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(35 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(36 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 1, 157, 205);
  drawPixel(37 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(38 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(39 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(41 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(42 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(43 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(46 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(48 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(49 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(50 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(51 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(52 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(53 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(54 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(55 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(56 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(57 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(58 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(59 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(60 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(61 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(62 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(63 + sharkBackground_XPOS, 19 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(0 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(1 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(2 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(3 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(4 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(5 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(6 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(7 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(8 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(9 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(10 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(12 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(13 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(14 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(16 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(20 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(22 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(28 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(29 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(30 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(31 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(32 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(33 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(34 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(35 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(36 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(37 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(38 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(40 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(41 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(43 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(45 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(46 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(48 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(51 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(52 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(53 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(54 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(55 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(56 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(57 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(58 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(59 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(60 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(61 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(62 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(63 + sharkBackground_XPOS, 20 + sharkBackground_YPOS, 1, 156, 205);
  drawPixel(0 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(1 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(2 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(3 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(4 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(5 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(6 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(7 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(8 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(9 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(10 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(11 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(12 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(13 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(14 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(18 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(21 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(22 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(23 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(24 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(25 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(28 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(30 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(31 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(32 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(33 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 79, 200, 245);
  drawPixel(34 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(35 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(36 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(38 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(39 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(41 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(42 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(44 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(48 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(51 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(52 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(53 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(54 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(55 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(56 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(57 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(58 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(59 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(60 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(61 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(62 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(63 + sharkBackground_XPOS, 21 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(0 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(1 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(3 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(4 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(5 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(6 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(7 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(8 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 79, 201, 245);
  drawPixel(9 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(10 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 156, 205);
  drawPixel(11 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(12 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(13 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(14 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(20 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(23 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(26 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(27 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(28 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(29 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(31 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 79, 201, 244);
  drawPixel(32 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(33 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(34 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(35 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(37 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(40 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(43 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(45 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(46 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(47 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(48 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(49 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(50 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(52 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(53 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 1, 156, 205);
  drawPixel(54 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(55 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(56 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(57 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(58 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 244);
  drawPixel(59 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 201, 245);
  drawPixel(60 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 78, 200, 244);
  drawPixel(61 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(62 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(63 + sharkBackground_XPOS, 22 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(0 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(1 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(3 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 156, 205);
  drawPixel(4 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(5 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 78, 200, 245);
  drawPixel(6 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(7 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(8 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(9 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(10 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(13 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(18 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(19 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(25 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(28 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(30 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(31 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(32 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(33 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(34 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(35 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(37 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(38 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(41 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(42 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(45 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(46 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(48 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(49 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(52 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(53 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(54 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(55 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 157, 204);
  drawPixel(56 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 157, 204);
  drawPixel(57 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 157, 205);
  drawPixel(58 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 79, 200, 244);
  drawPixel(59 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 157, 205);
  drawPixel(60 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 1, 156, 204);
  drawPixel(61 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(62 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(63 + sharkBackground_XPOS, 23 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(0 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(1 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(2 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(3 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(5 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(6 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(7 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(14 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(18 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(21 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(26 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(27 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(28 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(31 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(32 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(33 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(34 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(35 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(38 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(39 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(40 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(43 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(44 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(45 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(46 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(47 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(48 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(50 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(51 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(52 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(53 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(54 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(55 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(56 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(57 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(58 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 156, 204);
  drawPixel(59 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(60 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(61 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(62 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(63 + sharkBackground_XPOS, 24 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(0 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(1 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(4 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(5 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(6 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(8 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(10 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(16 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(20 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(21 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(25 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(28 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(31 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(32 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(33 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(34 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(35 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(36 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(37 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(38 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(42 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(43 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(44 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(46 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(47 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(49 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(51 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(52 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(53 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(54 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(55 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(56 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(58 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(59 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(60 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(61 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(62 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(63 + sharkBackground_XPOS, 25 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(0 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(1 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(5 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(6 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(7 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(8 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(10 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(19 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(21 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(25 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(27 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(28 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(31 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(33 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(34 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(35 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(36 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(39 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(40 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(43 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(44 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(49 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(50 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(52 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(53 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(54 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(55 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(56 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(58 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(59 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(60 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(61 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(62 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(63 + sharkBackground_XPOS, 26 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(0 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(1 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(5 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(6 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(11 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(12 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(16 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(17 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(18 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(21 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(28 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(30 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(31 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(33 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(34 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(35 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(36 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(41 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(44 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(45 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(46 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(47 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(52 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(53 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(54 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(55 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(56 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(58 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(59 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(60 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(61 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(62 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(63 + sharkBackground_XPOS, 27 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(0 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(1 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(2 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(5 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(6 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(11 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(13 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(14 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(16 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(17 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(22 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(23 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(25 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(28 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(31 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(33 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(34 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(35 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(39 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(40 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(41 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(42 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(45 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(48 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(49 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(51 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(52 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(53 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(54 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(55 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(56 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(58 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(59 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(60 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(61 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(62 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(63 + sharkBackground_XPOS, 28 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(0 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(1 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(5 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(6 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(8 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(9 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(14 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(15 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(18 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(19 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(24 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(27 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(28 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(31 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(33 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(34 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(35 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(37 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(38 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(40 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(44 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(45 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(46 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(49 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(51 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(52 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(53 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(54 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(55 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(56 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(58 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(59 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(60 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(61 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(62 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(63 + sharkBackground_XPOS, 29 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(0 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(1 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(2 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(5 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(6 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(7 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(8 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(9 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(11 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(15 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(16 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(17 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(18 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(20 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(23 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(24 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(25 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(27 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(28 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(29 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(30 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(31 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(33 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(34 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(35 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(36 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(39 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(40 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(41 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(42 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(44 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(45 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(47 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(48 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(50 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(51 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(52 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(53 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(54 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(55 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(56 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(57 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(58 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(59 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(60 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(61 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(62 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(63 + sharkBackground_XPOS, 30 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(0 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(1 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(4 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(5 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(6 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(16 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(18 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(19 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(20 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(21 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(22 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(23 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(25 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(27 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(28 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(29 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(31 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(32 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(33 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(34 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(35 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(36 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(37 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(39 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(40 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(42 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(44 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(49 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(50 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(51 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(52 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(53 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(54 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(55 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(56 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(58 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(59 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(60 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(61 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(62 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(63 + sharkBackground_XPOS, 31 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(0 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(1 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(4 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(5 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(6 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(7 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(9 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(10 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(11 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(12 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(13 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(14 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(16 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(18 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(21 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(22 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(25 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(28 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(30 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(31 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(33 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(34 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(35 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(37 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(38 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(39 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(42 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(43 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(45 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(47 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(48 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(50 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(52 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(53 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(54 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(55 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(56 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(57 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(58 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(59 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(60 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(61 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(62 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(63 + sharkBackground_XPOS, 32 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(0 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(1 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(2 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(3 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(5 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(6 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(9 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(11 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(12 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(14 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(16 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(18 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(20 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(21 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(23 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(26 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(27 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(28 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(31 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(33 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(34 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(35 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(36 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(37 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(38 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(39 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(40 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(41 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(42 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(44 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(47 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(52 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(53 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(54 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(55 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(56 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(58 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(59 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(60 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(61 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(62 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(63 + sharkBackground_XPOS, 33 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(0 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(1 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(5 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(6 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(8 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(10 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(11 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(12 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(13 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(14 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(16 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(19 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(20 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(22 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(23 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(28 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(29 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(31 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(32 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(33 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(34 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(35 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(36 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(37 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(39 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(40 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(43 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(44 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(45 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(46 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(47 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(48 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(49 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(51 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(52 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(53 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(54 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(55 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(56 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(57 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(58 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(59 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(60 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(61 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(62 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(63 + sharkBackground_XPOS, 34 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(0 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(1 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(2 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(3 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(4 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(5 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(6 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(7 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(8 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(9 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(10 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(11 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(12 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(13 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(14 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(15 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(16 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(17 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(18 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(19 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(20 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(21 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(22 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(23 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(24 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(25 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(26 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(27 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(28 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(29 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(30 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(31 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(32 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(33 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(34 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(35 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(36 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(37 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(38 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(39 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(40 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(41 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(42 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(43 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(44 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(45 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(46 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(47 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 241);
  drawPixel(48 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(49 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(50 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 185, 240);
  drawPixel(51 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(52 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(53 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 184, 240);
  drawPixel(54 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(55 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 1, 185, 241);
  drawPixel(56 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 241);
  drawPixel(57 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(58 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 185, 240);
  drawPixel(59 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 241);
  drawPixel(60 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(61 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(62 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
  drawPixel(63 + sharkBackground_XPOS, 35 + sharkBackground_YPOS, 0, 184, 240);
}