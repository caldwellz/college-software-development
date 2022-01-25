###############################################################
# Program:
#     Assignment 09, Binary Search Tree
#     Brother JonesL, CS235
# Author:
#     Emmanuel Gatica
#     John Batty
#     Brian Thompson
#     Jordon Thompson
#     Zach Caldwell
# Summary:
#     Makes a Bianary Tree balanced with Red-Black-Tree rules
# Time:
#     Give or take 35 combined hours
#     The erase function was the most difficult because we 
#     struggled through it and then added the red-black tree
#     and struggled through it again.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment09.o
	g++ -o a.out assignment09.o -g -std=c++11
	tar -cf assignment09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment09.o     : the driver program
##############################################################
assignment09.o: bst.h assignment09.cpp
	g++ -c assignment09.cpp -g -std=c++11

