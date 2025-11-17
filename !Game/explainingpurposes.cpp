
// ! Debugging purposes why its on top
// ! ALSO this runs the code, do not remove
int ticks = 17000;

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

int sharksBigPosAdjusterMain = -5;

int bigShark_XPOS = 0 + sharksBigPosAdjusterMain;
int bigShark_YPOS = 0;

int bigSharkMouthClosed_XPOS = -13 + sharksBigPosAdjusterMain;
int bigSharkMouthClosed_YPOS = 0;

int smallShark_XPOS = 0;
int smallShark_YPOS = 0;

int volcanoBackground_XPOS = 0;
int volcanoBackground_YPOS = 0;

int meteorBig_XPOS = 0;
int meteorBig_YPOS = 0;

int meteorSmall_XPOS = 0;
int meteorSmall_YPOS = 0;


int buildingDir = 1;   // 1 = right, -1 = left
int crackDir = 1;


int earthquakeBackground_XPOS = 0;
int earthquakeBackground_YPOS = 0;

int earthquakeBuildingsBackgrounds_XPOS = 0;
int earthquakeBuildingsBackgrounds_YPOS = 0;


int earthquakeGroundCracked_XPOS = 0;
int earthquakeGroundCracked_YPOS = 0;

int mrGolem_XPOS = 0;
int mrGolem_YPOS = -30;

int golemTick = 0;



int markPeacefulHome_XPOS = 0;
int markPeacefulHome_YPOS = 0;

int markBiteBread_XPOS = 0;
int markBiteBread_YPOS = 0;

int markDead_XPOS = 0;
int markDead_YPOS = 0;

int ripMarkBreadHeaven_XPOS = 0;
int ripMarkBreadHeaven_YPOS = 0;


int theEnd_XPOS = 0;
int theEnd_YPOS = 0;



















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
void bigShark();
void bigSharkMouthClosed();
void smallShark();
void volcanoBackground();
void meteorBig();
void meteorSmall();
void earthquakeBackground();
void earthquakeBuildingsBackgrounds();
void earthquakeGroundCracked();
void mrGolem();
void markPeacefulHome();
void markBiteBread();
void markDead();
void ripMarkBreadHeaven();
void theEnd();


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
void drawText(float x, float y, const std::string& text);

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

void SharkChomper(int malayKO = 10) {
  if ((ticks) % malayKO < malayKO / 2) {
    bigShark();
  }
  else {
    bigSharkMouthClosed();
  }
}



// Moves shark from left → right then loops
void helper_moveSmallShark(
  int startX,      // starting X position
  int endX,        // maximum X before wrapping
  int speed        // pixels moved per frame
) {
  // Initialize only once
  static bool initialized = false;
  if (!initialized) {
    smallShark_XPOS = startX;
    initialized = true;
  }

  // Move shark
  smallShark_XPOS += speed;

  // Loop back to start once it reaches end
  if (smallShark_XPOS >= endX) {
    smallShark_XPOS = startX;
  }
}

void Display_Chapter_2() {

  //initialize mark pos
  if (ticks == 6001) {
    drawMark_XPOS = 35;
  }
  // Move & draw the scrolling background
  int bitespeed = 30;
  int talkingSpeed = 5;

  string messageShark = "";
  int startSharkMessage = 1;
  int endSharkMessage = 1;
  helper_sharkBackground_update();
  drawMark();
  SharkChomper(bitespeed);


  messageShark = "SHARK: Nom Nom Inom, wahahaha Shork 67 tau";
  startSharkMessage = 6200;
  endSharkMessage = 6400;
  if (ticks >= startSharkMessage && ticks <= endSharkMessage) {
    SharkChomper(talkingSpeed);
  }
  messageBox(startSharkMessage, endSharkMessage, messageShark);

  messageBox(6500, 6600, "MARK: W T F ");


  messageBox(6800, 7000, "MARK: LUHH sah, bat ka andito pala yah.");


  messageShark = "SHARK: Ako yung rason kasi kinuha ko flood control projects, kaya ayun d2 ako.";
  startSharkMessage = 7300;
  endSharkMessage = 7600;
  if (ticks >= startSharkMessage && ticks <= endSharkMessage) {
    SharkChomper(talkingSpeed);
  }
  messageBox(startSharkMessage, endSharkMessage, messageShark);

  messageShark = "SHARK: Ito Lods ano, mga anak ko tatagosin ka";
  startSharkMessage = 7750;
  endSharkMessage = 7950;
  if (ticks >= startSharkMessage && ticks <= endSharkMessage) {
    SharkChomper(talkingSpeed);
  }
  messageBox(startSharkMessage, endSharkMessage, messageShark);



  helper_moveSmallShark(-70, 30, 1);
  appearAt(7800, 8300, smallShark);

  messageBox(8050, 8200, "MARK: ARAY GAGI naneto ahh gagstoinks ka sah.");
  messageBox(8250, 8400, "MARK: AWTS HAHAHWA NAHULI NG MANGINGISDA SILA.");

  messageShark = "SHARK: OY LODS UMAY NAMAN BOUNCE NAKO";
  startSharkMessage = 8500;
  endSharkMessage = 8650;
  if (ticks >= startSharkMessage && ticks <= endSharkMessage) {
    SharkChomper(talkingSpeed);
  }
  messageBox(startSharkMessage, endSharkMessage, messageShark);

  messageBox(8780, 8900, "MARK: GE lods ingat wahahaha naging sushi sila lods.");


}

// Moves meteor vertically down, spawns randomly within X range
void helper_fallMeteor(
  int xStartRange,  // min X spawn
  int xEndRange,    // max X spawn
  int speed         // pixels per frame downward
) {
  // Initialize meteor only once per "fall"
  static bool initialized = false;
  if (!initialized) {
    meteorSmall_XPOS = xStartRange + rand() % (xEndRange - xStartRange + 1);
    meteorSmall_YPOS = -20;  // Start at top of screen
    initialized = true;
  }

  // Move meteor down
  meteorSmall_YPOS += speed;  // Y increases going down

  // Reset if it falls below screen
  if (meteorSmall_YPOS > PIXEL_HEIGHT) {
    meteorSmall_XPOS = xStartRange + rand() % (xEndRange - xStartRange + 1);
    meteorSmall_YPOS = -20;  // restart at top
  }
}


// Moves big meteor vertically down, spawns randomly within X range
void helper_fallMeteorBig(
  int xStartRange,  // min X spawn
  int xEndRange,    // max X spawn
  int speed         // pixels per frame downward
) {
  // Initialize meteor only once per "fall"
  static bool initialized = false;
  if (!initialized) {
    meteorBig_XPOS = xStartRange + rand() % (xEndRange - xStartRange + 1);
    meteorBig_YPOS = -40;  // Start higher since it's big
    initialized = true;
  }

  // Move meteor down
  meteorBig_YPOS += speed;  // Y increases going down

  // Reset if it falls below screen
  if (meteorBig_YPOS > PIXEL_HEIGHT) {
    meteorBig_XPOS = xStartRange + rand() % (xEndRange - xStartRange + 1);
    meteorBig_YPOS = -40;  // restart at top
  }
}



// Chapter 3: Earthquake
void Display_Chapter_3() {


  //initialize mark pos
  if (ticks == 9001) {
    drawMark_XPOS = 0;
    drawMark_YPOS = -1;
  }

  volcanoBackground();

  drawMark();
  

  helper_fallMeteor(-40, 40, 1.5);
  appearAt(9300, 999999, meteorSmall);
  appearAt(11650, 99999, meteorBig);
  helper_fallMeteorBig(-40, 40, 3);


  // Mark dito ka mag add messages

  messageBox(9070, 9160, "MARK: Wher da hail am I");
  messageBox(9200, 9350, "MARK: ANG INIT MGA YAH");
  messageBox(9400, 9550, "MARK: bat ang init naman ng bundok na to");
  messageBox(9600, 9750, "VOLCANO: engot mo di ako bundok, isa akong volcano");
  messageBox(9800, 9950, "MARK: eee ganun ba sorry boss gusto ko lang kumain ng bread");
  // smol meteor fall
  messageBox(10000, 10200, "VOLCANO: Walang bread bread dito ito na kamatayan mo");
  messageBox(10300, 10500, "MARK: Di moko mapipigilan dahil gutom ako");
  messageBox(10600, 10800, "VOLCANO: Hahaha try mo nga");
  messageBox(11000, 11200, "MARK: DI MOKO MAPIPIGILAN MOSKOV USER AKO");
  messageBox(11400, 11600, "VOLCANO: Ganyanan pala gegegege");
  //big meteor fall
  messageBox(11800, 99999, "VOLCANO: Naknapmocha bohay ka pa...");
}






void earthquakeShake() {

    // ---- BUILDINGS (slow) ----
    earthquakeBuildingsBackgrounds_XPOS += buildingDir;

    // if it hits the limits, flip direction
    if (earthquakeBuildingsBackgrounds_XPOS > 5) buildingDir = -1;
    if (earthquakeBuildingsBackgrounds_XPOS < -5) buildingDir = 1;



    // ---- GROUND CRACK (faster) ----
    earthquakeGroundCracked_XPOS += crackDir * 2;   // moves 2 steps = faster

    if (earthquakeGroundCracked_XPOS > 8) crackDir = -1;
    if (earthquakeGroundCracked_XPOS < -8) crackDir = 1;
}


void golemHulog() {
    if (golemTick < 60) {
        // linear drop from -30 -> 2 over 60 ticks
        mrGolem_YPOS = -30 + (golemTick * (32 / 60.0f));
        golemTick++;
    }
    else {
        mrGolem_YPOS = 2; // lock at the ground after 60 ticks
    }
}





// Chapter 4: Volcanic Eruption wasdwasd
void Display_Chapter_4() {

    //initialize mark pos
if (ticks == 12001) {
    drawMark_XPOS = 0;
    drawMark_YPOS = -1;
    golemTick = 0;        // reset counter
    mrGolem_YPOS = -30;   // reset start position
}


  
  earthquakeBackground();
  earthquakeBuildingsBackgrounds();
  earthquakeGroundCracked();
  drawMark();
  mrGolem();
  








  // TODO: Mark dodges falling volcanic debris
  messageBox(12070, 12160, "MARK: HUH? Panibagong lebel???");
  appearAt(12150, 999999, earthquakeShake);
  messageBox(12200, 12350, "MARK: bakit gumagalaw ang ploor??");
  messageBox(12400, 12550, "MARK: may tumatalon ba??");
  messageBox(12600, 12750, "EARTHQUAKE: balew walang tumatalon, ako lang to");
  appearAt(12550, 13000,golemHulog);
  messageBox(12800, 12950, "MARK: boss baka pwede timeout muna? kain lang ako saglit ng bread tapos papansinin na kita");
  messageBox(13000, 13200, "EARTQUAKE: Anong timeout?? wala timeout timeout dito, uulti na si Minotaur");
  messageBox(13300, 13500, "MARK: teka ulti? whut ip talon din ako? shake + talon = minus effect ");
  messageBox(13600, 13800, "EARTHQUAKE: hahahahah ano pinagsasabi mo dyan??");
  messageBox(14000, 14200, "MARK: Hulaan mo hahahdahdw ");
  messageBox(14400, 14600, "EARTHQUAKE: Ganyanan ahh");
  messageBox(14850, 10029999, "MARK: Im in dangerrr");

}

// Ending Scene (Resolution / Credits)
void Display_Ending() {

  if (ticks == 15001) {
    drawMark_XPOS = 0;
    drawMark_YPOS = 3;
}

  markPeacefulHome();
  breadOnTable();


  appearAt(16000, 16700, markBiteBread);
  appearAt(16700, 9999999, markDead);
  appearAt(17150, 99999, ripMarkBreadHeaven);
  appearAt(15000, 16000, drawMark);


  // pumasok si Mark sa bahay after makalayas sa lahat ng natural na disaster
  messageBox(15200, 15500, "MARK: Lezzgo mga lods nakauwi din ako");
  messageBox(15600, 15900, "MARK: nasan na ang aking peyborit pandesal");
  messageBox(16000, 16300, "MARK: WKWKWKWKWKWKWKWKWKW BREAD");
  
  // mark eat bread
  
  messageBox(16400, 16700, "MARK: *COUGH* *COUGH* AGH EXPIRED NA PALA TO");
  messageBox(16800, 17100, "MARK: Oof");
  //mrak final end rip scene
  messageBox(17200, 17800, "Here Lies Mark, Cause of Death: Expired Bread");
  
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

// Chapter 4: Volcanic Eruption
void KB_Chapter_4(unsigned char key) {
  // TODO: Mark dodges falling volcanic debris
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

// Ending Scene (Resolution / Credits)
void KB_Ending(unsigned char key) {
  // TODO: Mark finds expired bread, humorous credits roll
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
void drawText(float x, float y, const std::string& text) {
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

  

  if (ticks < 3000) { // Intro Scene (Tutorial + Breakfast)
    Display_Intro();
  }
  else if (ticks < 6000) { // Chapter 1: Tornado
    Display_Chapter_1();
  }
  else if (ticks < 9000) { // Chapter 2: Flood
    Display_Chapter_2();
  }
  else if (ticks < 12000) { // Chapter 3: Earthquake
    Display_Chapter_3();
  }
  else if (ticks < 15000) { // Chapter 4: Volcanic Eruption
    Display_Chapter_4();
  }
  else if (ticks < 18000) { // Ending Scene (Credits)
    Display_Ending();
  }
  else { // Post-ending / Restart
    theEnd();
  }

  Display_Whole_Scene();

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
  }
  else if (ticks < 6000) { // Chapter 1: Tornado
    KB_Chapter_1(key);
  }
  else if (ticks < 9000) { // Chapter 2: Flood
    KB_Chapter_2(key);
  }
  else if (ticks < 12000) { // Chapter 3: Earthquake
    KB_Chapter_3(key);
  }
  else if (ticks < 15000) { // Chapter 4: Volcanic Eruption
    KB_Chapter_4(key);
  }
  else if (ticks < 18000) { // Ending Scene (Credits)
    KB_Ending(key);
  }
}
// ! ---------------------------------------

// * ---------------------------------------
// * MAIN
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("Mobile Ligaments");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(0, update, 0);
  glutMainLoop();
  return 0;
}