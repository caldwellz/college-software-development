###############################################################
# Program:
#     Checkpoint 06a, Makefiles
#     Brother Barney, CS165
# Author:
#     Zach Caldwell
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################

CC=g++
CPPFLAGS=-Wall -Wextra -ansi -pedantic
LINK=g++
OUTPUT_FILE=a.out

build: $(OUTPUT_FILE)
	echo Build succeeded

clean:
	rm a.out point.o robot.o check06a.o

$(OUTPUT_FILE): point.o robot.o check06a.o
	$(LINK) -o $@ $^

robot.o: robot.cpp robot.h
	$(CC) $(CPPFLAGS) -c -o $@ $<

point.o: point.cpp point.h
	$(CC) $(CPPFLAGS) -c -o $@ $<

check06.o: check06.cpp robot.h point.h
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: build
