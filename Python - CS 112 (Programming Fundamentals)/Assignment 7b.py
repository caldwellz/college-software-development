#Program: 7b
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 23, 2017
#Instructor: Jeff Light
#Description: Check School Eligibility

import datetime

def check_eligibility(student_name, year):
	student_age = calculate_age(year)
	
	if student_age >= 18:
		print(student_name + " is " + str(student_age) + " years old. " + student_name + " may attend College.")
	elif student_age >= 15:
		print(student_name + " is " + str(student_age) + " years old. " + student_name + " may attend High School.")
	elif student_age >= 12:
		print(student_name + " is " + str(student_age) + " years old. " + student_name + " may attend Jr. High School.")
	elif student_age >= 5:
		print(student_name + " is " + str(student_age) + " years old. " + student_name + " may attend Elementary School.")
	elif student_age <= 4:
		print(student_name + " is " + str(student_age) + " years old. " + student_name + " is not eligible to attend school.")
	
	
def calculate_age(year):
	now = datetime.datetime.now()
	thisyear = now.year
	age = thisyear - year
	return age
	


def main(): #main function need in all programs for automated testing
	print("This program will ask the user to enter a name and a birth year for a potential student.")
	print("The program will then determine what type of school, if any, the potential student is eligible to attend.")
	while True:
		print()
		student_name = input("Please enter the name of a potential student: ")

		while True:
			student_year = input("Please enter the potential student's birth year: ")
			if student_year.isdigit():
				student_year = int(student_year)
			else:
				print("Invalid response. Please enter a whole number for the birth year.")
				continue
	
			if calculate_age(student_year) < 0:
				print("Invalid response. Please enter a year prior to the current year.")
			else:
				break
		# end input validation: year

		check_eligibility(student_name, student_year)

		while True:
			print()
			replay = input("Would you like to play again? (Y/N): ")
			if (replay == "Y") or (replay == "y") or (replay == "N") or (replay == "n"):
				break
			else:
				print("Invalid response. Please enter 'Y' or 'N'")
		if (replay == "N") or (replay == "n"):
			break
		# end replay question
# end of main


if __name__ == '__main__':
    main()  #execute main function
