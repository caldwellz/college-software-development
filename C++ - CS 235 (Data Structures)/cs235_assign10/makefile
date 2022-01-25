###############################################################
# Program:
#     Assignment 10, Map
#     Brother JonesL, CS 235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Emmanuel Gatica
#     Zach Caldwell
# Summary:
#     Implementation and tests of a Map ADT.
# Time:
#     2.5 team hours, 13 total man-hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g -std=c++11
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g -std=c++11

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g -std=c++11

wordcount.exe: wordCount.cpp wordCount.h
	g++ -o $@ -g -std=c++11 -DWCTEST $<

.PHONY: clean
clean:
	-rm *.out *.o *.exe *.tar err.txt
