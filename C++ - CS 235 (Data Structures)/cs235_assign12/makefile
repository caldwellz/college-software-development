###############################################################
# Program:
#     Assignment 12, Hash
#     Brother JonesL, CS 235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     Implementation of hash data structure and spellcheck using
#     hash class.
# Time:
#     2 team hours, 14 total man-hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment12.o spellCheck.o
	g++ -o a.out assignment12.o spellCheck.o -g -std=c++11
	-tar -cf assignment12.tar *.h *.cpp makefile

.PHONY: clean
clean:
	-rm *.tar *.o*

##############################################################
# The individual components
#      assignment12.o     : the driver program
#      spellCheck.o       : the spell-check program and driver
##############################################################
assignment12.o: hash.h assignment12.cpp list.h
	g++ -c assignment12.cpp -g -std=c++11

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g -std=c++11

