#Program: 6c
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 16, 2017
#Instructor: Jeff Light
#Description: between()


def main(): #main function need in all programs for automated testing
    while True:
        print("This program will ask the user for 3 numbers and determine if the second number lies between the first and the third.")
        while True:
            print()
            user_number1 = input("Please enter the first number - the low number: ")
            if user_number1.isdigit():
                user_number1 = int(user_number1)
                break
            else:
                print("Invalid response. Please enter a whole number.")
        # end input validation: first number

        while True:
            user_number2  = input("Please enter the second number - the test number: ")
            if user_number2.isdigit():
                user_number2 = int(user_number2)
                break
            else:
                print("Invalid response. Please enter a whole number.")
        # end input validation: second number

        while True:
            user_number3  = input("Please enter the third number - the high number: ")
            if user_number3.isdigit():
                user_number3 = int(user_number3)
                break
            else:
                print("Invalid response. Please enter a whole number.")
        # end input validation: third number

        print()
        print("The statement '" + str(user_number2) + " lies between " + str(user_number1) + " and " + str(user_number3) + "' is " + str(between(user_number1, user_number2, user_number3)))

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

def between(x, y, z):
    if (y >= x) and (y <= z):
        return True
    elif (y >= z) and (y <= x):
        return True
    else:
        return False

if __name__ == '__main__':
    main()  #execute main function
