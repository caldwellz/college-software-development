###############################################################
# Program:
#     Assignment 06, NODE
#     Brother JonesL, CS235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     This program uses a linked list to implement a insertion
#     sort function.
#     Total time spent on this project was about 18 hours combined
#     The trickiest part was getting the insert function working.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -o $@ assignment06.o  -g -std=c++11
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g -std=c++11
