



/*
Use Better Comments Extension para ez readability
*/


#include <GL/glut.h>
#include <iostream>
using namespace std;



// * YUNG MGA POSITIONS NG CHARACTERS ANDITO
// * -----------------------------------------------



int drawMark_XPOS = 0;
int drawMark_YPOS = 0;

int smallMark_XPOS = 0;
int smallMark_YPOS = 0;





// * Asset Declarations:
void drawMark();
void smallMark();






// ! ---------------------------------------
// ! DO NOT GALAW GALAW ALSO WAG NIYO MANUALLY PALITAN VARIABLES

// Eto wag talaga gawin
int ticks = 0;

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



// * ---------------------------------------


























// * ---------------------------------------
// * DISPLAY CONTROLLERS PER SCENE:



// Intro Scene (Tutorial + Breakfast)
void Display_Intro() {
    // TODO: Show title, controls, and Mark eating breakfast
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(0, 0, "MARK INTRO SCENE SCANDAL");

    drawMark();








}


// Chapter 1: Tornado
void Display_Chapter_1() {
    // TODO: Mark runs away from the tornado
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(0, 0, "MARK TAKBO SA TORNADO KASI TAKOT");

    smallMark();




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

    drawMark();






}


// Chapter 1: Tornado
void KB_Chapter_1(unsigned char key) {
    // TODO: Mark runs away from the tornado

    smallMark();
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