###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother JonesL, CS235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     An implementation of a deque data structure and a nowServing
#     program to accompany it.
# Time:
#     40 Total Man Hours
#     11 Total linear time
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o
	g++ -g -o $@ assignment04.o nowServing.o -std=c++11
	-tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -g -c assignment04.cpp -std=c++11

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -g -c nowServing.cpp -std=c++11

.PHONY: clean
clean:
	-rm a.out assignment04.tar *.o
