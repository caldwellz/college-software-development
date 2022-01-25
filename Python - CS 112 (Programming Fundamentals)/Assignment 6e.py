#Program: 6e
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 21, 2017
#Instructor: Jeff Light
#Description: *_reverse()


def for_reverse(string):
	new_string = ''
	string = str(string)
	for i in range(len(string)-1, -1, -1):
		new_string = new_string + string[i]

	return new_string
# end for_reverse


def while_reverse(string):
	new_string = ''
	string = str(string)
	i = len(string)
	while i > 0:
		i = i - 1
		new_string = new_string + string[i]

	return new_string
# end while_reverse


def main(): #main function need in all programs for automated testing
	while True:
		print("This program will ask the user to enter something and then print out a reversed version of the user's input.")
		print()
		user_input = input("Please enter something: ")
		print("Using the for-loop: The reverse of '" + user_input + "' is:", for_reverse(user_input))
		print("Using the while-loop: The reverse of '" + user_input + "' is:", while_reverse(user_input))

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
