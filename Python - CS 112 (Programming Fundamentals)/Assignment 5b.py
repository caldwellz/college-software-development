#Program: 5b
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 9, 2017
#Instructor: Jeff Light
#Description: Improved Interest Calculator


def main(): #main function need in all programs for automated testing

    print("This program will ask the user for a monthly deposit, an annual interest rate and the number of years the user plans on saving.")
    print("It will then show the monthly balance over the period of planned saving.")
    print()
    while True:
        deposit = input("Please enter the amount to be deposited each month: ")
        if deposit.isdigit():
            deposit = int(deposit)
            break
        else:
            print("Invalid response. Please enter a whole number.")
            print()
    # end input validation: deposit

    while True:
        interest = input("Please enter the annual interest rate percent. ")
        if interest.isdigit():
            interest = int(interest)
            interest = (interest / 100) / 12
            break
        else:
            print("Invalid response. Please enter a whole number.")
            print()
    # end input validation: interest

    while True:
        years = input("Please enter the number of years you plan to save: ")
        if years.isdigit():
            years = int(years)
            months = years * 12
            break
        else:
            print("Invalid response. Please enter a whole number.")
            print()
    # end input validation: years
    print()
    print("The following table shows the balance of the account for each month of the designated savings period.")
    
    print(" Month    Balance ")
    balance = 0
    for i in range(1, months + 1):
        balance = (deposit + balance) * (interest + 1)
        print("Month " + str(i) + ":   $" + str(round(balance, 2)))

                  
if __name__ == '__main__':
    main()  #execute main function
