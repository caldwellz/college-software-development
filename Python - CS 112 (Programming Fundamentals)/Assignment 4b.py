#Program: 4b
#Names: Zach Caldwell, Ben Badger
#Date: Feb. 6, 2017
#Instructor: Jeff Light
#Description: Random Number Game
#Passed by Bethaly

import random
def main(): #main function need in all programs for automated testing
    while True:
        count = 0
        randNum = random.randint(1, 100)
        guessNum = 222
        print("I am thinking of a number between 1 and 100.")
        while not (guessNum == randNum):
            while True:
                guess = input("What is your guess? ")
                if not guess.isdigit():
                    print("Invalid response. Please enter a whole number.")
                elif int(guess) > 100:
                    print("Invalid response. Please enter a number between 1 and 100.")
                else:
                    guessNum = int(guess)
                    break
            # end guess input while loop

            count = count + 1
            if guessNum > randNum:
                print("Your guess is too high.")
                continue
            elif guessNum < randNum:
                print("Your guess is too low.")
                continue
        # end guess loop
        print("CORRECT! You guessed it in", count, "tries!")
        replay = ''
        while True:
            replay = input("Would you like to play again? ")
            if (replay == 'Y') or (replay == 'y') or (replay == 'N') or (replay == 'n'):
                break
            else:
                print("Invalid response. Please answer with a 'Y' or 'N'")
        # end replay validation loop
        if (replay == 'N') or (replay == 'n'):
            break

if __name__ == '__main__':
    main()  #execute main function
