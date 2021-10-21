# Simple 2D Platformer Example

This C++ program exhibits simple 2D tile based collision with smooth player movement. There are also some added features - such as a rudimentary state system and support for entities - but in its current state it would still need some work to fully expand on that.

## How to build

The only libraries needed are SDL2 and SDL2_image. If you have not used these libaries before, you can find them online. Make sure to change the CMakeLists.txt file to point to where they are located on your computer. The CMake file was written for Windows, but should be fairly easy to convert to be more Linux friendly and use commands such as find_package().

To actually build, simply create a directory called build, open it in the terminal/command prompt/shell, and enter "cmake ..". After, type "make" and an exe should be created. 

**MAKE SURE YOU HAVE THE RIGHT .dll FILES IN YOUR BUILD DIRECTORY!!! OTHERWISE THE OUTPUT FILE WILL NOT RUN!!!**

## More to learn

If you are interested in improving on this or finding more on 2D platforming collision, [this blog post](http://higherorderfun.com/blog/2012/05/20/the-guide-to-implementing-2d-platformers/) was very helpful in getting my implementation going. It has more tidbits that are pretty useful when concerning 2D collision detection.