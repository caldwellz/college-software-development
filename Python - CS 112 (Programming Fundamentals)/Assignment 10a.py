#Program: 10a
#Names: Svetlana Solovaya, Zach Caldwell
#Date: March 16th, 2017
#Instructor: Jeff Light
#Description: Password Scanner

import os

def hasUpper(password):
	for letter in password:
		if letter.isupper():
			return True
	# end for
	return False

def hasLower(password):
	for letter in password:
		if letter.islower():
			return True
	return False
	
def hasNumber(password):
	for letter in password:
		if letter.isdigit():
			return True
	return False

def hasSpecial(password):
	specialChars = ['@', '#', '%', '^', '&', '*']
	for letter in password:
		if letter in specialChars:
			return True
	return False
			

def main(): #main function needed in all programs for automated testing
	print("Beginning password analysis....")
	print ("Opening file 'pwd.txt'.")
	try:
		passwordfile = open("pwd.txt", 'r')
		validFile = open("validpwd.txt", 'w')
		invalidFile = open("invalidpwd.txt", 'w')
	except:
		print("Could not open file! Exiting...")
		return

	stringcontent= passwordfile.readlines()
	for password in stringcontent:
		if len(password) < 8:
			invalidFile.write(password)
		elif not hasUpper(password):
			invalidFile.write(password)
		elif not hasLower(password):
			invalidFile.write(password)
		elif not hasNumber(password):
			invalidFile.write(password)
		elif not hasSpecial(password):
			invalidFile.write(password)
		else:
			validFile.write(password)
	# end for

	print("Analysis complete. Closing files.")
	passwordfile.close()
	validFile.close()
	invalidFile.close()

	print ("Results can be found in files 'validpwd.txt' and 'invalidpwd.txt' in the " + os.getcwd() + " directory")
    

if __name__ == '__main__':
    main()  #execute main function
