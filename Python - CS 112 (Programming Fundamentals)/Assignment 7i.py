#Program: 7i
#Name: Zach Caldwell
#Date: Feb. 21, 2017
#Instructor: Jeff Light
#Description: get_valid_input()


def get_valid_input(question, warning, type):
	while True:
		user_input = input(question)
		try:
			if type == "int":
				valid_input = int(user_input)
			elif type == "float":
				valid_input = float(user_input)
			elif type == "YN":
				if (user_input == 'Y') or (user_input == 'y'):
					return 'Y'
				elif (user_input == 'N') or (user_input == 'n'):
					return 'N'
				else:
					raise ValueError()
			else:
				return None
			# If we get here, a typecast succeeded, so
			#  escape down to the return statement.
			break

		except:
			print(warning)
			print()
			continue
	#end of validation loop

	return valid_input
#end of get_valid_input()


def main(): #main function needed in all programs for automated testing
	while True:
		#Get an int from the user
		intNum = get_valid_input("Please enter a whole number: ", "Invalid response. Please try again.","int")
		print("The whole number you entered was: ",intNum)
		print("Now we will test your whole number in a math equation...")
		print("Adding 10 to your whole number would be: 10 + " + str(intNum) + " = " + str(10+intNum))
		print()

		#Get a float from the user
		floatNum = get_valid_input("Please enter a float: ", "Invalid response. Please try again.","float")
		print("The float you entered was: ",floatNum)
		print("Now we will test your float in a math equation...")
		print("Adding 10 to your float would be: 10 + " + str(floatNum) + " = " + str(10+floatNum))
		print()

		playAgain = get_valid_input("Would you like to play again? ", "Invalid response. Please answer with a 'Y' or 'N'", "YN")
		if playAgain == 'N':
			break
		print()
		print()


if __name__ == '__main__':
    main()  #execute main function
