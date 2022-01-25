###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother JonesL, CS235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     <put a description here>
# Time:
#     <how long did it take to complete this program>?
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o huffman.o 
	g++ -o $@ assignment08.o huffman.o -g -std=c++11
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h huffman.h assignment08.cpp
	g++ -c assignment08.cpp -g -std=c++11

huffman.o: bnode.h huffman.h huffman.cpp list.h vector.h
	g++ -c huffman.cpp -g -std=c++11

.PHONY: clean
clean:
	-rm *.o *.out *.exe *.tar
