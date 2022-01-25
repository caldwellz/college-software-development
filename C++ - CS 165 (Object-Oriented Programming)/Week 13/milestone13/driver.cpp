/*****************************************************
 * File: Driver.cpp
 * Author: Br. Burton
 *
 * Description: This file contains the main function
 *  that starts the game and the callback function
 *  that specifies what methods of the game class are
 *  called each time through the game loop.
 ******************************************************/
#include "game.h"
#include "uiInteract.h"

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *pGame = (Game *)p;
   
   pGame->advance();
   pGame->handleInput(*pUI);
   pGame->draw(*pUI);
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Point topLeft(-200, 200);
   Point bottomRight(200, -200);
   
   Interface ui(argc, argv, "Asteroids", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   try {
      ui.run(callBack, &game);
   }
   // See note in Game::advanceShip()
   catch(NormalExit) {
      return 0;
   }

   // If we ever get here, something is wrong, because normally there's no
   // proper way to get out of the run loop except via the catch above (or a
   // GLUT function that I'm sure exists, but I'm too lazy to find what it is).
   return 1;
}
