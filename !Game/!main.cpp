
// ! Debugging purposes why its on top 
// ! ALSO this runs the code, do not remove
int ticks = 2350;






/*
Use Better Comments Extension para ez readability
*/

#include <functional> 
#include <GL/glut.h>
#include <iostream>
using namespace std;



// * YUNG MGA POSITIONS NG CHARACTERS ANDITO
// * -----------------------------------------------



int drawMark_XPOS = 0;
int drawMark_YPOS = 4;

int smallMark_XPOS = 0;
int smallMark_YPOS = 0;

int breadOnTable_XPOS = 0;
int breadOnTable_YPOS = 6;

int window_XPOS = 8;
int window_YPOS = 0;


int introFloor_XPOS = 0;
int introFloor_YPOS = 3;


int nameBarNew_XPOS = 0;
int nameBarNew_YPOS = 0;

int brokenWindow_XPOS = 2;
int brokenWindow_YPOS = -1;

int tornadoNew_XPOS = 5;
int tornadoNew_YPOS = -3;

int introWall_XPOS = 0;
int introWall_YPOS = 0;

int oneLastBite_XPOS = 0;
int oneLastBite_YPOS = 0;
















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



// ! ---------------------------------------
// ! DO NOT GALAW GALAW ALSO WAG NIYO MANUALLY PALITAN VARIABLES



// Pixel canvas size
const int PIXEL_WIDTH = 64;
const int PIXEL_HEIGHT = 36;


// Window size
const int WIN_WIDTH = 1920;
const int WIN_HEIGHT = 1080;


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
//Basically sets the ticks to kung ano ang starting ticks ng mga to
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








    messageBox(200, 580, "MARK: sarap buhay gagi lods angas naman sheesh pare lods 67");
    messageBox(780, 1080, "MARK: Gagi may tinapay, makain nga yan sarap naman wow duterte moment");
    messageBox(1300, 1680, "MARK: sheesh sarap nung pandesal bagong luto mainit init pa");
    messageBox(1800, 2100, "MARK: kainin ko na to bago lumamig, bread taste better than key ehh");
    messageBox(2450, 2650, "MARK: GAGI ANO YUN TORNADO SI YOLANDA");
    messageBox(2750, 3000, "TORNADO: TAKBO TITIRAHIN KITA WAHAHAHA");



}


// Chapter 1: Tornado
void Display_Chapter_1() {
    // TODO: Mark runs away from the tornado
    appearAt(3000, 3300, oneLastBite);



    messageBox(3400, 3700, "TORNADO: Trip lang pre ah hahuiuwh penge ng tinapay (mo)");
    messageBox(3800, 4100, "MARK: Di nakakatuwa pre gusto ko lng kainin tong tinapay ko sah");
    messageBox(4500, 4800, "TORNADO: Di ka napapagod eh no, well at least sweaty :>");
    messageBox(5000, 5300, "MARK: Umay sah... Lomayo ka. de keta mahal");
    messageBox(5600, 5800, "TORNADO: UGHHH PAGOD NA AKO, LAPIT NAAA!");
    messageBox(5850, 6000, "MARK: LEZZGO!");


}


// Chapter 2: Flood
void Display_Chapter_2() {
    // TODO: Mark swims and avoids sharks
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(0, 0, "MARK TAKBO SA PATING");
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

    //TODO: LAgyan nyo nalang baba neto etc if may trip kayo idisplay na wala sa scope niyo.
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


// Chapter 1: Tornado
void KB_Chapter_1(unsigned char key) {
    // TODO: Mark runs away from the tornado


}


// Chapter 2: Flood
void KB_Chapter_2(unsigned char key) {
    // TODO: Mark swims and avoids sharks
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
    case '1':   // Key 1 → Jump sa Intro
        Start_Intro();      // ticks = 0
        break;
    case '2':   // Key 2 → Jump sa Tornado
        Start_Tornado();    // ticks = 3000
        break;
    case '3':   // Key 3 → Jump sa Flood
        Start_Flood();      // ticks = 6000
        break;
    case '4':   // Key 4 → Jump sa Earthquake
        Start_Earthquake(); // ticks = 9000
        break;
    case '5':   // Key 5 → Jump sa Volcano
        Start_Volcano();    // ticks = 12000
        break;
    case '6':   // Key 6 → Jump sa Ending
        Start_Ending();     // ticks = 15000
        break;
    case 'r':   // Key R → Reset/Restart
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
void drawText(float x, float y, const std::string& text)
{
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
    ticks = 0;       // Intro starts at tick 0
}

void Start_Tornado() {
    ticks = 3000;    // Chapter 1: Tornado starts at tick 3000
}

void Start_Flood() {
    ticks = 6000;    // Chapter 2: Flood starts at tick 6000
}

void Start_Earthquake() {
    ticks = 9000;    // Chapter 3: Earthquake starts at tick 9000
}

void Start_Volcano() {
    ticks = 12000;   // Chapter 4: Volcanic Eruption starts at tick 12000
}

void Start_Ending() {
    ticks = 15000;   // Ending Scene starts at tick 15000
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
    drawPixel(37 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(38 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(39 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(40 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(41 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(42 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(43 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(44 + tornadoNew_XPOS, 8 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(34 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(35 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(36 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(37 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(38 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(39 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(40 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(41 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(42 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(43 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(44 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(45 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(46 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(47 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(48 + tornadoNew_XPOS, 9 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(33 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(34 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(35 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 144, 155, 176);
    drawPixel(36 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(37 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(38 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(39 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(40 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(41 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 194, 210, 230);
    drawPixel(42 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(43 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(44 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(46 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(48 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(49 + tornadoNew_XPOS, 10 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(33 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(34 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(35 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 185, 210, 238);
    drawPixel(36 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 184, 210, 239);
    drawPixel(37 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(38 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 254, 254, 255);
    drawPixel(39 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(40 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 194, 210, 230);
    drawPixel(41 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(42 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(43 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(44 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(45 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 115, 125, 141);
    drawPixel(46 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(48 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 87, 94, 110);
    drawPixel(49 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 87, 94, 110);
    drawPixel(50 + tornadoNew_XPOS, 11 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(33 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(34 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(35 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 185, 210, 239);
    drawPixel(36 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(37 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 254, 254, 255);
    drawPixel(38 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 194, 210, 230);
    drawPixel(39 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(40 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 195, 211, 230);
    drawPixel(41 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 185, 210, 239);
    drawPixel(42 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 184, 210, 238);
    drawPixel(43 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 185, 210, 238);
    drawPixel(44 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(46 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 115, 125, 141);
    drawPixel(48 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(49 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(50 + tornadoNew_XPOS, 12 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(33 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(34 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 115, 125, 141);
    drawPixel(35 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(36 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 195, 211, 230);
    drawPixel(37 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 254, 255, 254);
    drawPixel(38 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(39 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(40 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 185, 210, 239);
    drawPixel(41 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 184, 210, 238);
    drawPixel(42 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(43 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(44 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(46 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(48 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(49 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 115, 125, 141);
    drawPixel(50 + tornadoNew_XPOS, 13 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(33 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(34 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 87, 94, 111);
    drawPixel(35 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 86, 95, 110);
    drawPixel(36 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 185, 210, 238);
    drawPixel(38 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(39 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(40 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(41 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(42 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(43 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(44 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(45 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(46 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(48 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(49 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(50 + tornadoNew_XPOS, 14 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(33 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(34 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 86, 95, 110);
    drawPixel(35 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 185, 210, 238);
    drawPixel(36 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 194, 210, 230);
    drawPixel(37 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 195, 211, 230);
    drawPixel(38 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(39 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 194, 210, 230);
    drawPixel(40 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 185, 210, 238);
    drawPixel(41 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 185, 210, 238);
    drawPixel(42 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 185, 210, 239);
    drawPixel(43 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(44 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 87, 94, 110);
    drawPixel(46 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 86, 95, 110);
    drawPixel(47 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(48 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(49 + tornadoNew_XPOS, 15 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(34 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(35 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(36 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 185, 211, 238);
    drawPixel(37 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(39 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 195, 211, 230);
    drawPixel(40 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 184, 210, 239);
    drawPixel(41 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(42 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(43 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(44 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(46 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 86, 94, 111);
    drawPixel(47 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(48 + tornadoNew_XPOS, 16 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(34 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(35 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(36 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 86, 94, 111);
    drawPixel(37 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(38 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 254, 254, 255);
    drawPixel(39 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(40 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(41 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(42 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(43 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(44 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(45 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(46 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(48 + tornadoNew_XPOS, 17 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(35 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 84, 85, 111);
    drawPixel(36 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 87, 94, 110);
    drawPixel(37 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(38 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(39 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(40 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(41 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(42 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 144, 155, 177);
    drawPixel(43 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(44 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 144, 155, 176);
    drawPixel(45 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(46 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(47 + tornadoNew_XPOS, 18 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(36 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(37 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(38 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(39 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 195, 211, 230);
    drawPixel(40 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(41 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(42 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 254, 254, 255);
    drawPixel(43 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(44 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(46 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(47 + tornadoNew_XPOS, 19 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(37 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(38 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 86, 95, 110);
    drawPixel(39 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 145, 155, 176);
    drawPixel(40 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(41 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(42 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 254, 255, 254);
    drawPixel(43 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 254, 255, 254);
    drawPixel(44 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 195, 211, 230);
    drawPixel(45 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 115, 125, 141);
    drawPixel(46 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 20 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(38 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(39 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(40 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(41 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(42 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(43 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 254, 255, 255);
    drawPixel(44 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(45 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(46 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(47 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 115, 125, 141);
    drawPixel(48 + tornadoNew_XPOS, 21 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(39 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(40 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 85, 85, 111);
    drawPixel(41 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 86, 94, 111);
    drawPixel(42 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(43 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(44 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 194, 210, 230);
    drawPixel(45 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(46 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(47 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(48 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(49 + tornadoNew_XPOS, 22 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(41 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(42 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 86, 94, 110);
    drawPixel(43 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 144, 155, 176);
    drawPixel(44 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(45 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(46 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 195, 210, 231);
    drawPixel(47 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 115, 124, 140);
    drawPixel(48 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 115, 125, 140);
    drawPixel(49 + tornadoNew_XPOS, 23 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(42 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(43 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(44 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(45 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 195, 210, 230);
    drawPixel(46 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 145, 154, 177);
    drawPixel(47 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(48 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(49 + tornadoNew_XPOS, 24 + tornadoNew_YPOS, 85, 84, 110);
    drawPixel(44 + tornadoNew_XPOS, 25 + tornadoNew_YPOS, 84, 85, 110);
    drawPixel(45 + tornadoNew_XPOS, 25 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(46 + tornadoNew_XPOS, 25 + tornadoNew_YPOS, 144, 155, 176);
    drawPixel(47 + tornadoNew_XPOS, 25 + tornadoNew_YPOS, 114, 125, 140);
    drawPixel(48 + tornadoNew_XPOS, 25 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(45 + tornadoNew_XPOS, 26 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(46 + tornadoNew_XPOS, 26 + tornadoNew_YPOS, 145, 155, 177);
    drawPixel(47 + tornadoNew_XPOS, 26 + tornadoNew_YPOS, 85, 85, 110);
    drawPixel(46 + tornadoNew_XPOS, 27 + tornadoNew_YPOS, 85, 85, 110);
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