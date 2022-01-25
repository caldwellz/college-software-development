###############################################################
# Program:
#     Assignment 11, Sorts
#     Brother JonesL, CS235
# Author:
#     Jordon Thompson
#     John Batty
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     This program demonstrates a variety of sorting algorithms.
# Time:
#     5 total hours
#     The hardest part was getting the math on the merge sort.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment11.o
	g++ -o a.out assignment11.o -g -std=c++11
	tar -cf assignment11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment11.o     : the driver program
##############################################################
assignment11.o: assignment11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c assignment11.cpp -g -std=c++11

