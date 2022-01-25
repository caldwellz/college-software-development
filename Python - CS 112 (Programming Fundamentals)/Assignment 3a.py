#Program: 3a
#Names: Jordan Evans, Zachary Caldwell
#Date: 01/24/2017
#Instructor: Brother Light
#Description: Potatos


def main(): #main function need in all programs for automated testing

    print("In this program we will indicate the grade of a potato based on weight")
    potato = float(input("Enter the weight of a potato in grams: "))
    if potato < 200:
        print("A potato weighing", potato, "grams is a grade X potato.")
    elif potato < 400:
        print("A potato weighing", potato, "grams is a grade A potato.")
    elif potato < 800:
        print("A potato weighing", potato, "grams is a grade B potato.")
    else:
        print("A potato weighing", potato, "grams is a grade Z potato.")


    

if __name__ == '__main__':
    main()  #excucte main function
