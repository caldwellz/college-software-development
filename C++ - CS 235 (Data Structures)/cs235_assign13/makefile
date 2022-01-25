###############################################################
# Program:
#     Assignment 13, Graph
#     Brother JonesL, CS235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     A program to find the shortest path in a maze.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment13.o graph.o maze.o
	g++ -o a.out assignment13.o graph.o maze.o -g -std=c++11
	tar -cf assignment13.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment13.o     : the driver program
#      graph.o            : the graph code
#      maze.o             : the maze reading and solving code
##############################################################
assignment13.o: graph.h vertex.h assignment13.cpp
	g++ -c assignment13.cpp -g -std=c++11

graph.o: graph.h set.h vertex.h graph.cpp list.h
	g++ -c graph.cpp -g -std=c++11

maze.o: maze.cpp maze.h vertex.h graph.h list.h
	g++ -c maze.cpp -g -std=c++11
