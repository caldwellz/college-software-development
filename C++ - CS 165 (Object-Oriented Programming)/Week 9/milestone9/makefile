###############################################################
# Program:
#     Project 09, Skeet
#     Brother Barney, CS165
# Author:
#     Zachary Caldwell
# Summary:
#     Skeet-shooting game.
#
#     Estimated:  1.5 hrs
#     Actual:     2.0 hrs
#       The trickiest part was scrapping my old speed functions
#       and setting velocity the proper way.
#
# Above and Beyond
#     Makefile improvements (flexible flags, ignore 'rm' errors, etc.)
#     Made the Tough bird a bit smaller so it's also tougher to hit
#     Display the game name inside the top of the screen
###############################################################

DEBUG_CFLAGS = -Wall -Wextra -Wno-unused-parameter -ansi -pedantic -g
COMPILE_COMMAND = g++ -c -o $@ $<
COMPILE_COMMAND_DEBUG = g++ $(DEBUG_CFLAGS) -c -o $@ $<
LINUX_LFLAGS = -lglut -lGLU -lGL
MINGW_LFLAGS = -lfreeglut -lglu32 -lopengl32
LFLAGS = $(LINUX_LFLAGS)

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o movingobject.o bird.o bullet.o toughbird.o sacredbird.o
	g++ $^ $(LFLAGS)

###############################################################
# Provided files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	$(COMPILE_COMMAND)

uiInteract.o: uiInteract.cpp uiInteract.h
	$(COMPILE_COMMAND)

point.o: point.cpp point.h
	$(COMPILE_COMMAND)

game.o: game.cpp uiDraw.h uiInteract.h point.h velocity.h rifle.h bullet.h bird.h toughbird.h sacredbird.h
	$(COMPILE_COMMAND)

driver.o: driver.cpp game.h uiInteract.h
	$(COMPILE_COMMAND)

rifle.o: rifle.cpp rifle.h point.h uiDraw.h
	$(COMPILE_COMMAND)

#######################################################################
# Additional rules below
#######################################################################

velocity.o: velocity.cpp velocity.h
	$(COMPILE_COMMAND_DEBUG)

movingobject.o: movingobject.cpp movingobject.h velocity.h point.h
	$(COMPILE_COMMAND_DEBUG)

bird.o: bird.cpp bird.h movingobject.h
	$(COMPILE_COMMAND_DEBUG)

bullet.o: bullet.cpp bullet.h movingobject.h
	$(COMPILE_COMMAND_DEBUG)

toughbird.o: toughbird.cpp toughbird.h bird.h movingobject.h
	$(COMPILE_COMMAND_DEBUG)

sacredbird.o: sacredbird.cpp sacredbird.h bird.h movingobject.h
	$(COMPILE_COMMAND_DEBUG)

###############################################################
# General rules
###############################################################
clean:
	-rm a.out a.exe *.o
