#Program: 11
#Names: Zach Caldwell
#Date: March 28, 2017
#Instructor: Jeff Light
#Description: Deleting files by extension

import os

def main(): #main function needed in all programs for automated testing
	print("This program will delete all files with the given extension in the current directory.")

	while True:
		user_ext = input("Please enter the extension of the file type you would like to delete (ex. .pdf): ")
		# Make sure the user actually entered something
		if user_ext == '':
			print("Invalid input, please try again.")
			print()
		else:
			break
	# End of input loop
	print()

	# Convert to lowercase and add a beginning dot if the user didn't enter it
	user_ext = user_ext.lower()
	if not user_ext.startswith('.'):
		user_ext = '.' + user_ext

	# Delete files
	files_deleted = 0
	allnames = os.listdir(os.getcwd())
	for name in allnames:
		if name.lower().endswith(user_ext):
			try:
				# os.unlink(os.path.join(os.getcwd(), name))
				print("Deleted '" + name + "'")
				files_deleted = files_deleted + 1
			except:
				print("Could not delete '" + name + "'!")

	print()
	print("Files deleted:", files_deleted)


if __name__ == '__main__':
    main()  #execute main function
