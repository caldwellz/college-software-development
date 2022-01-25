#Program: 4a
#Names: Zach Caldwell, Ben Badger
#Date: Jan. 31, 2017
#Instructor: Jeff Light
#Description: Calculate Fibonacci sequence


def main(): #main function need in all programs for automated testing

    # Get and validate input
    while True:
        numFibLoop = input("How many Fibonacci numbers do you want to generate (Enter a number > 2)? ")
        if numFibLoop.isdigit():
            numFibLoop = int(numFibLoop)
            break
        else:
            print("Invalid response. Please enter a whole number > 2 ")

    print()
    print()


    prevFib = 0
    currentFib = 1
    print(1)
    while numFibLoop -1 > 0:
         newFib = currentFib + prevFib
         print(newFib)
         prevFib = currentFib
         currentFib = newFib
         numFibLoop = numFibLoop - 1 
    

if __name__ == '__main__':
    main()  #execute main function
