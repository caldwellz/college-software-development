###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Barney, CS165
# Author:
#     Zach Caldwell
# Summary:
#    Create a Lunar Lander game patterned after the original
#    Atari arcade game.
#
#    Estimated:  1.5 hrs
#    Actual:     1.65 hrs
#      Honestly, the hardest part was keeping the x/y directions straight...
# 
# Above and Beyond
#     Tweaked the makefile in several spots to make it a bit more flexible.
#     Stopped displaying thruster flames after landing/crashing.
#     Moved Point constructors from header to reduce unused parameter warnings.
###############################################################

CPPFLAGS = -Wall -Wextra
LFLAGS = -lglut -lGLU -lGL
WIN32LFLAGS = -lfreeglut -lglu32 -lopengl32
LFLAGS = $(WIN32LFLAGS)

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o
	g++ $^ $(LFLAGS)
#	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ $(CPPFLAGS) -c -o $@ $<

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ $(CPPFLAGS) -c -o $@ $<

point.o: point.cpp point.h
	g++ $(CPPFLAGS) -c -o $@ $<

ground.o: ground.cpp ground.h
	g++ $(CPPFLAGS) -c -o $@ $<

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h ground.h
	g++ $(CPPFLAGS) -c -o $@ $<

driver.o: driver.cpp game.h uiInteract.h
	g++ $(CPPFLAGS) -c -o $@ $<

lander.o: lander.cpp lander.h
	g++ $(CPPFLAGS) -c -o $@ $<

velocity.o: velocity.cpp velocity.h
	g++ $(CPPFLAGS) -c -o $@ $<

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
