#Program: Final Exam 1.
#Name: Zach Caldwell
#Date: 4/13/2017
#Instructor: Jeff Light
#Description: Strings


def main(): #main function needed in all programs for automated testing
	# Get user and ward name
	user_name = input("Please enter your name: ")
	print()
	ward_name = input("Please enter the name of your LDS Ward: ")
	print()

	# Validate number of males
	while True:
		try:
			adult_males = input("Please enter the approximate number of adult males in the ward: ")
			adult_males = int(adult_males)
			break
		except:
			print("Invalid response. The number of adult males should be a whole number.")

	print()

	# Validate number of females
	while True:
		try:
			adult_females = input("Please enter the approximate number of adult females in the ward: ")
			adult_females = int(adult_females)
			break
		except:
			print("Invalid response. The number of adult females should be a whole number.")

	# Sum the total and print the result
	total_adults = adult_males + adult_females
	print("\nThere are", str(total_adults), "adult members in", user_name + "'s", ward_name, "ward.")


if __name__ == '__main__':
    main()  #excucte main function




