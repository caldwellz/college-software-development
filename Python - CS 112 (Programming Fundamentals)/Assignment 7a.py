#Program: 7a
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 23, 2017
#Instructor: Jeff Light
#Description: make_even() & add_numbers()


def add_numbers(num1, num2, num3):
	if num1 % 2 != 0:
		num1 = make_even(num1)
	if num2 % 2 != 0:
		num2 = make_even(num2)
	if num3 % 2 != 0:
		num3 = make_even(num3)
	
	num4 = num1 + num2 + num3
	
	print(str(num1) + " + " + str(num2) + " + " + str(num3) + " = " + str(num4))


def make_even(num):
	return num + 1


def main(): #main function need in all programs for automated testing
	print("This program will ask the user for 3 numbers.")
	print("If the user enters an odd number, the program will add 1 to that number to make it even.")
	print("Once all three numbers are even, the program will add them together and print the result.")
	while True:
		print()
		while True:
			print()
			num1 = input("Please enter the first number: ")
			if num1.isdigit():
				num1 = int(num1)
				break
			else:
				print("Invalid response. Please enter a whole number.")
		# end input validation: first number

		while True:
			num2  = input("Please enter the second number: ")
			if num2.isdigit():
				num2 = int(num2)
				break
			else:
				print("Invalid response. Please enter a whole number.")
		# end input validation: second number

		while True:
			num3 = input("Please enter the third number: ")
			if num3.isdigit():
				num3 = int(num3)
				break
			else:
				print("Invalid response. Please enter a whole number.")
		# end input validation: third number

		print()
		add_numbers(num1, num2, num3)

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
