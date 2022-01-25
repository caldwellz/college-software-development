#Program: 5i
#Names: Zach Caldwell
#Date: Feb. 9, 2017
#Instructor: Jeff Light
#Description: Individual assignment


def main(): #main function needed in all programs for automated testing

    while True:
        print("This program will help us practice input validation and while loops.")
        print("The user will be asked to enter two numbers which will both be validated.")
        print("The sum of the numbers will then be displayed in a complex print statement and the user will be asked if they would like to run the program again.")
        print()

        while True:
            first_num = input("Please enter the first number: ")
            if first_num.isdigit():
                first_num = int(first_num)
                break
            else:
                print("Invalid response. Please enter a whole number.\n")
        #end input validation: first number

        while True:
            second_num = input("Please enter the second number: ")
            if second_num.isdigit():
                second_num = int(second_num)
                break
            else:
                print("Invalid response. Please enter a whole number.\n")
        #end input validation: second number

        print()
        print(first_num, "+", second_num, "=", first_num + second_num)
        print()

        rerun = ''
        while True:
            rerun = input("Would you like to run the program again? (Y/N): ")
            if (rerun == 'Y') or (rerun == 'y') or (rerun == 'N') or (rerun == 'n'):
                break
            else:
                print("Invalid response. Please answer with a 'Y' or 'N'.")
        # end rerun validation loop

        if (rerun == 'N') or (rerun == 'n'):
            break
        else:
            print()
            print()

if __name__ == '__main__':
    main()  #execute main function
