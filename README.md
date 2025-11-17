

# One Last Bite - MobileLigaments
### Where is the Main Game?
#### You can Find it here:
[Main.cpp](https://github.com/marhosa/MobileLigaments/blob/main/!Game/!main.cpp)

- The code has 20k+ lines of code since the assets are all pixel based, and added manually in the single file.
- You can see the code of the main engine driver of our code [HERE](https://github.com/marhosa/MobileLigaments/blob/main/!Game/explainingpurposes.cpp).
- TO Play the video, simiply pull this repository, install C++, and install the run++ extension.

# How is the code Structured?
### The code is structured in blocks.

#### First Block:
- Global Variable Declarations
- Example:
```cpp
int drawMark_XPOS = 0;
int drawMark_YPOS = 4;
int breadOnTable_XPOS = 0;
int breadOnTable_YPOS = 6;
int tornado_XPOS = 5;
int tornado_YPOS = -3;
```
- Each game object has an XPOS and YPOS for positioning.
- `int ticks` controls the timeline of the game.

#### Asset Declaration:
- Contains all functions that draw game objects and backgrounds.
- Example:
```cpp
void drawMark();
void smallMark();
void breadOnTable();
void window();
void tornadoNew();
```
- Each function is called inside the display functions for a scene.

#### Pixel Canvas & Window
- Logical canvas size: 64x36 pixels
- Window size: 1920x1080 pixels
- Function `drawPixel(int x, int y, int r, int g, int b)` draws a pixel at a canvas coordinate.

#### Scene Timeline (Ticks)
- Timeline controls which scene is displayed:
| Ticks      | Scene                               |
|-----------|------------------------------------|
| 0–2999    | Intro Scene                        |
| 3000–5999 | Chapter 1: Tornado                 |
| 6000–8999 | Chapter 2: Flood                    |
| 9000–11999| Chapter 3: Earthquake               |
| 12000–14999| Chapter 4: Volcanic Eruption       |
| 15000–17999| Ending Scene                        |
| ≥18000    | Post-ending / Restart               |

- Jump to specific scenes using starter functions:
```cpp
Start_Intro();       // ticks = 0
Start_Tornado();     // ticks = 3000
Start_Flood();       // ticks = 6000
Start_Earthquake();  // ticks = 9000
Start_Volcano();     // ticks = 12000
Start_Ending();      // ticks = 15000
```

#### Scene Functions
- Each scene has a `Display_<Scene>()` function.
- Example (Chapter 1: Tornado):
```cpp
void Display_Chapter_1() {
    helper_chapter1_updateTornado();
    appearAt(3300, 6000, smallMark);
    appearAt(3300, 6000, tornadoNew);
    messageBox(3400, 3700, "TORNADO: Trip lang pre ah...");
}
```
- Use `appearAt(startTick, endTick, func)` to run functions at specific tick ranges.

#### Keyboard Controls
- Each scene has a dedicated keyboard handler: `KB_<Scene>()`
- Controls Mark or triggers scene changes.
- `KB_Whole_Scene(unsigned char key)` allows jumping between scenes with keys 1–6, and reset with 'R'.

#### Helpers & Animations
- Meteor helpers: `helper_fallMeteor()` and `helper_fallMeteorBig()`
- Background scrolling: `helper_sharkBackground_update()`
- Earthquake animation: `earthquakeShake()`
- Golem drop animation: `golemHulog()`

#### Drawing Functions
- Draw text:
```cpp
drawText(float x, float y, const std::string& text);
```
- Draw pixels:
```cpp
drawPixel(int x, int y, int r, int g, int b);
```
- Show messages at the bottom:
```cpp
messageBox(startTick, endTick, msg);
```

#### Main Loop
- `display()` handles rendering based on the tick counter.
- `update(int value)` increments ticks (~60 FPS).
- `keyboard()` routes input to scene-specific keyboard handlers.

#### Adding a New Scene/Game
1. Declare your new asset functions.
2. Create `Display_<NewGame>()`.
3. Add keyboard controls in `KB_Whole_Scene()` and `KB_<NewGame>()`.
4. Use `Start_<NewGame>()` or tick ranges to trigger the scene.

#### Notes
- All assets and game logic are in one file for simplicity.
- Timeline is controlled by `ticks`.
- All objects have global position variables.
- Press keys 1–6 to jump between scenes, R to restart.
- Debugging: `drawText()` can show tick values or positions.

#### Recommended Workflow
1. Use helper functions for object movement and animation.
2. Keep `Display_<Scene>()` clean; call helpers and `appearAt()`.
3. Manage tick values carefully for timed events.
4. Add messages with `messageBox()` for storytelling.


# How Did We Create the Assets?

To create the pixel-based assets for the game, we used a custom `drawPixel()` function.  

The process was as follows:

1. We created a separate C++ tool that converts image files into pixel art representations.
2. This tool generates C++ code for each asset, formatted as functions that match our existing engine structure.
3. The output functions include both the drawing logic and any necessary setup code, which we then directly integrate into the main game file.

This approach allowed us to manage all assets programmatically and keep them compatible with our single-file engine.

