# Mini Black Hole

This is a minigame written in C++ and using the SDL library (https://www.libsdl.org/). It works on Windows and Linux.

## Game instructions

Press "Credits In!" to add credits to game. 

Press "Start" to start the game. Press "Start" again to pause. 

Press "Credits Out!" to remove credits from the game. 

Press the ESCAPE key to exit game.

## Directories

### assets

The "assets" directory includes all the files needed to run the minigame. These assets include images and a font. All images were made by me.

### mini black hole 

The "mini black hole" directory includes all the source and header files developed. 

### windows game

The "windows game" directory includes all needed files to run the minigame in the Windows OS. 

### linux game

The "linux game" directory includes all needed files to run the minigame in the Linux OS.


## Running the minigame

### Windows

Enter the "windows game" directory and run "Mini Black Hole.exe". All assets and dlls needed are in the folder. 

Links to used libraries: 
- www.libsdl.org/download-2.0.php
- www.libsdl.org/projects/SDL_image/
- www.libsdl.org/projects/SDL_ttf/

### Linux

### Prerequisites

First install the necessary libraries. Open terminal and run:

- "apt-get install libsdl2-dev" 

This installs the SDL2 library that provides low level access to audio, keyboard, mouse, joystick and graphics hardware. (www.libsdl.org)

- "apt-get install libsdl2-image-dev" 

This install the image file loading library (www.libsdl.org/projects/SDL_image/)

- "apt-get install libsdl2-ttf-dev"

This installs the library that allows the use of TrueType fonts in SDL applications (www.libsdl.org/projects/SDL_ttf/)

### Running

Launch terminal and cd to "linux game" directory. Execute the command: 

- "chmod u+x mini_black_hole"
- "./mini_black_hole"

## Compiling 

### Linux

First, needed libraries must be installed as explained in "Running the minigame" -> "Linux" -> "Prerequisites".

The developed code runs on both OS but the names of the include files for Linux must be changed from:

-"SDL.h" to "SDL2/SDL.h"
-"SDL_image.h" to "SDL2/SDL_image.h"
-"SDL_ttf.h" to "SDL2/SDL_ttf.h"

Then cd to code directory. 

Run:

-"g++ -o mini_black_hole sceneObject.cpp window.cpp button.cpp minigame.cpp timer.cpp texture.cpp -lSDL2 -lSDL2_image -lSDL2_ttf"

The minigame is compiled.

-"./mini_black_hole"

To execute.


## Authors

* **Alcino Sousa** 2018

