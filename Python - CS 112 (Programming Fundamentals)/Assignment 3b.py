#Program: 3b
#Names: Jordan Evans, Zachary Caldwell
#Date: 01/24/2017
#Instructor: Brother Light
#Description: Body Mass Index


def main(): #main function need in all programs for automated testing

    print("In this program we will calculate a person's BMI")
    print()
    inch_height = float(input("Please enter a person's height in inches: "))
    pound_weight = float(input("Please enter a person's weight in pounds: "))
    meter_height = inch_height * 0.0254
    kg_weight = pound_weight * 0.45359237
    BMI = round((kg_weight)/(meter_height**2), 2)
    if BMI < 18.5:
        print ("The person's BMI is:", BMI, "The person has a BMI classification of: Underweight")
    elif BMI <= 24.914:
        print ("The person's BMI is:", BMI, "The person has a BMI classification of: Normal")
    elif BMI <= 29.9:
        print ("The person's BMI is:", BMI, "The person has a BMI classification of: Overweight")
    else:
        print ("The person's BMI is:", BMI, "The person has a BMI classification of: Obese")

    
    
                

    

if __name__ == '__main__':
    main()  #excucte main function
