#Program: 6b
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 15, 2017
#Instructor: Jeff Light
#Description: power()


def main(): #main function need in all programs for automated testing
    while True:
        print("This program will ask the user for 2 numbers and raise the first number to the power of the second.")
        while True:
            print()
            user_number1 = input("Please enter the first number (X): ")
            if user_number1.isdigit():
                user_number1 = int(user_number1)
                break
            else:
                print("Invalid response. Please enter a whole number.")
        # end input validation: number

        while True:
            user_exponent = input("Please enter the second number (y): ")
            if user_exponent.isdigit():
                user_exponent = int(user_exponent)
                break
            else:
                print("Invalid response. Please enter a whole number.")
        # end input validation: exponent

        print()
        print(user_number1, "raised to the power of", user_exponent, "is:", power(user_number1, user_exponent))

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

def power(num, exp):
    if exp == 0:
        return 1
    result = num
    for i in range(1, exp):
        result = result * num
    return result

if __name__ == '__main__':
    main()  #execute main function
