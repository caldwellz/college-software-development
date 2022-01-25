#Program: 5a
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 7, 2017
#Instructor: Jeff Light
#Description: Divisible by 5?


def main(): #main function need in all programs for automated testing

    print("In this program, we will print out a series of numbers divisible by 5.")
    print("You will determine the range of numbers to be considered.")
    while True:
        print()
        user_number1 = input("Please enter the Beginning Number: ")
        if user_number1.isdigit():
            user_number1 = int(user_number1)
            break
        else:
            print("Invalid response. Please enter a whole number.")
    # end input validation: first number

    while True:
        user_number2  = input("Please enter the Ending Number: ")
        if user_number2.isdigit():
            user_number2 = int(user_number2)
            break
        else:
            print("Invalid response. Please enter a whole number.")
    # end input validation: second number

    print()
    print("Here are the numbers between", user_number1, "and", user_number2, "that are divisible by 5:")

    for i in range(user_number1, user_number2 + 1):
        if (i % 5) == 0:
            print(i)


if __name__ == '__main__':
    main()  #execute main function
