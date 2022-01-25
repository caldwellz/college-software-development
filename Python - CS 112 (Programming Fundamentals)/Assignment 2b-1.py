#Program: 2b.1
#Name: Zach Caldwell, Frank Flores, Steve Stout
#Date: 01/17/2017
#Instructor: Jeff Light
#Description: Calculates bank account interest over 6 months
#Passed by Bethaly

print("This program will ask the user for a monthly deposit, an annual interest rate and then calculate the balance after 6 months.")
print()

monthly_deposit = float(input("Please enter the amount to be deposited each month: "))
annual_rate = float(input("Please enter the annual interest rate percent: ")) / 100.0
monthly_rate = annual_rate / 12

balance = monthly_deposit * (1 + monthly_rate)

balance = (monthly_deposit + balance) * (1 + monthly_rate)
balance = (monthly_deposit + balance) * (1 + monthly_rate)
balance = (monthly_deposit + balance) * (1 + monthly_rate)
balance = (monthly_deposit + balance) * (1 + monthly_rate)
balance = (monthly_deposit + balance) * (1 + monthly_rate)

print('The ending balance after 6 months is: ' , balance)



