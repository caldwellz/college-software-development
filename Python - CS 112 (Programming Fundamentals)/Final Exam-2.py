#Program: Final Exam 2.
#Name: Zach Caldwell
#Date: 4/13/2017
#Instructor: Jeff Light
#Description: Functions and loops


def main(): #main function needed in all programs for automated testing
	print("In this program you will enter a list of numbers.")
	number_list = []

	# Input numbers until the user enters nothing
	while True:
		user_number = input("Please enter a number or just hit 'Enter' to stop: ")
		if user_number == '':
			break
		else:
			user_number = int(user_number)
			number_list.append(user_number)

	# Print out the list sum and the biggest number
	print()
	print("The total of the list of numbers is:", addNumbers(number_list))
	print("The biggest number in the list is:", biggestNumber(number_list))


def addNumbers(number_list):
	total = 0
	for num in number_list:
		total = total + num

	return total


def biggestNumber(number_list):
	biggest_num = 0
	for num in number_list:
		if num > biggest_num:
			biggest_num = num

	return biggest_num


if __name__ == '__main__':
    main()  #excucte main function
