#Program: 8a
#Names: Svetlana Solovaya, Zach Caldwell
#Date: Feb. 28, 2017
#Instructor: Jeff Light
#Description: Pass list to sum()


def sum(numlist):
	total = 0
	for i in range(0, len(numlist)):
		total = total + numlist[i]

	return total


def main(): #main function needed in all programs for automated testing
	while True:
		print("This program will ask the user to enter a series of numbers.")
		print("The user may enter as many numbers as they wish, hitting the enter key with no data when they wish to stop.")
		print("The program will then display the list of numbers and the sum total of those numbers.")
		print()

		numlist =[]
		while True:
			user_number = input("Please enter a number (or just hit enter to finish): ")
			if user_number.isdigit():
				user_number = int(user_number)
				numlist=numlist+[user_number]
			elif user_number == '':
				break
			else:
				print("Invalid response. Please enter a whole number.")
				print()
		# end number validation
		
		print("List Index  Item")
		for i in range(0, len(numlist)):
			print("   ", i, "     ", numlist[i])
		
		print()
		print ("There are", len(numlist), "items in the list.")
		print("The sum total of numbers in the list is", sum(numlist))

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

if __name__ == '__main__':
	main()  #execute main function
