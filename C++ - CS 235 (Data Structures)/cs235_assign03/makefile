###############################################################
# Program:
#     Assignment 03, QUEUE
#     Brother JonesL, CS235
# Author:
#     John Batty
#     Jordon Thompson
#     Brian Thompson
#     Zach Caldwell
# Summary:
#     A porgram to utilize the queue data structure to calculate
#     profit/loss when buying stocks. The most dificult part was
#     the sell function. Overall this week went really well for
#     our group. We strated early and planned well.
# Time:
#     10-12 hours
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h assignment03.o dollars.o stock.o
	g++ -o a.out assignment03.o dollars.o stock.o -std=c++11
	tar -cf assignment03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      assignment03.o : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
assignment03.o: queue.h assignment03.cpp
	g++ -c assignment03.cpp -std=c++11

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp -std=c++11

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp -std=c++11
