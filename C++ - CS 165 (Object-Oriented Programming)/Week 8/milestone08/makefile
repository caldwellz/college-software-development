###############################################################
# Program:
#     Milestone 08, Skeet
#     Brother Barney, CS165
# Author:
#     Zachary Caldwell
# Summary:
#     Skeet-shooting game.
#
#     Estimated:  1.5 hrs
#     Actual:     1.5 hrs
#       The hardest part was figuring out how to manage the data encapsulation.
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################

CFLAGS = -Wall -Wextra -ansi -pedantic
LINUXLFLAGS = -lglut -lGLU -lGL
WIN32LFLAGS = -lfreeglut -lglu32 -lopengl32
LFLAGS = $(LINUXLFLAGS)

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o movingobject.o bird.o bullet.o
	g++ $^ $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################

velocity.o: velocity.cpp velocity.h
	g++ $(CFLAGS) -c $<

movingobject.o: movingobject.cpp movingobject.h velocity.h point.h
	g++ $(CFLAGS) -c $<

bird.o: bird.cpp bird.h movingobject.h
	g++ $(CFLAGS) -c $<

bullet.o: bullet.cpp bullet.h movingobject.h
	g++ $(CFLAGS) -c $<

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
