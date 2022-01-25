###############################################################
# Program:
#     Assignment 01, Vector
#     Brother JonesL, CS235
# Author:
#     Zachary Caldwell
# Summary:
#     Simple implementation of a vector template, a variable-size
#     single-type data storage class.
# Time:
#     3.5 hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: vector.h assignment01.o
	g++ -o a.out assignment01.o -std=c++11
	tar -cf assignment01.tar vector.h assignment01.cpp makefile

##############################################################
# The individual components
#      assignment01.o     : the driver program
##############################################################
assignment01.o: vector.h assignment01.cpp
	g++ -c assignment01.cpp -O0 -g -std=c++11

