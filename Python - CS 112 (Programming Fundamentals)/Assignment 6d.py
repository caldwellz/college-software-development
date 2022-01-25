#Program: 6d
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 21, 2017
#Instructor: Jeff Light
#Description: is_float()


def is_float(user_data):
	try:
		num = float(user_data)
		# Conversion succeded, must be a float
		return True
	except:
		# Conversion failed
		return False


def main(): #main function need in all programs for automated testing
	while True:
		print("This program will ask the user to enter something and then check to see if it can be converted to a float.")
		print()
		user_number1 = input("Please enter something: ")
		if is_float(user_number1):
			print("It's a float!")
		else:
			print("Sorry, that's not a float.")
		# end number input

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
	main()	#execute main function
