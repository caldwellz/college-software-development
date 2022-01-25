#Program: 14
#Names: Jackson Oh, Zach Caldwell
#Date: April 11, 2017
#Instructor: Jeff Light
#Description: CSV Grades

import csv

def main(): #main function needed in all programs for automated testing

	# Open CSV
	exampleFile = open('CS 112 Assignment 14 CSV File.csv')
	exampleReader = csv.reader(exampleFile)
	exampleData = list(exampleReader)

	print("Name                             Assignment With Zero")
	print("----------------------------------------------")

	# Loop over data
	for row in exampleData:
		for columnNum in range(len(row)):
			if row[columnNum] == '0':
				print(row[0].ljust(25, ' ') + str(columnNum).rjust(20, ' '))

	exampleFile.close()


if __name__ == '__main__':
	main()	#execute main function
