###############################################################
# Program:
#     Milestone 06, Moon Lander
#     Brother Barney, CS165
# Author:
#     Zach Caldwell
# Summary:
#    Milestone for a Lunar Lander game similar to the original
#    Atari arcade game.
#
#    Estimated:  1.5 hrs
#    Actual:     1.25 hrs
#      The hardest part was really just debugging my OpenGL
#      setup, specifically the linking.
# 
# Above and Beyond
#     Tweaked the makefile to make it a tiny bit more flexible
###############################################################

# Usually I turn warnings on but the provided starter code produces
# way too many for the moment...
# -Wall -Wextra -ansi -pedantic 
CPPFLAGS = -g

LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o
	g++ -o $@ $^ $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ $(CPPFLAGS) -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ $(CPPFLAGS) -c uiInteract.cpp

point.o: point.cpp point.h
	g++ $(CPPFLAGS) -c point.cpp

ground.o: ground.cpp ground.h
	g++ $(CPPFLAGS) -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ $(CPPFLAGS) -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ $(CPPFLAGS) -c driver.cpp

lander.o: lander.cpp lander.h
	g++ $(CPPFLAGS) -c -o $@ $<

velocity.o: velocity.cpp velocity.h
	g++ $(CPPFLAGS) -c -o $@ $<

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
