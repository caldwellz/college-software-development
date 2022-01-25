#Program: 2b.1
#Name: Zach Caldwell, Frank Flores, Steve Stout
#Date: 01/17/2017
#Instructor: Jeff Light
#Description: This program will ask the user questions about an employee and then display the employee's payroll information.
#Passed by Bethaly

def main(): #main function need in all programs for automated testing

    #your program goes here
    print("This program will ask the user questions about an employee and then display the employee's payroll information.")
    print()
    last_name = input("Please enter the employee's last name: ")    
    num_hours = float(input("Please enter the number of hours worked this week: "))
    hourly_rate = float(input("Please enter the employee's hourly pay rate: "))
    fed_rate = float(input("Please enter the employee's federal tax rate percentage: "))
    state_rate = float(input("Please enter the employee's state tax rate percentage: "))

    print("Employee Name: ", last_name )
    print("Hours Worked: ", num_hours )
    print("Pay Rate:    $", hourly_rate )
    gross_pay = num_hours * hourly_rate
    print("Gross Pay: $", gross_pay )
    print("Deductions: ")
    fed_tax = gross_pay * (fed_rate / 100)
    print("     Federal Withholding: $", fed_tax )
    state_tax = gross_pay * (state_rate / 100 )
    print( "     State Withholding: $", state_tax )
    total_deductions = fed_tax + state_tax
    print( "     Total Deductions: $", total_deductions )
    print( "Net Pay: $", gross_pay - total_deductions )    
    

if __name__ == '__main__':
    main()  #excucte main function
