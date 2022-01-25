/** Represents CIT260 Final Project
 * @author Reid Bolander and Zach Caldwell
 * @version 0.1
 */
package UtilityBills;

// imported to work with ArrayLists
import java.util.ArrayList;
// Imported to get user input via keyboard
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        /** From user input, obtains values related to Electric, Water, and Gas Utility bills. If a non-numeric value is
         *   entered, the program displays an error message and re-prompts the user to enter that value.
         *  1) Prints a description of the program
         *  2) Solicits input from the user related to each bill
         *      a) What is the cost per unit (gallons, therms, or KWHs)
         *      b) How many units for each bill were consumed
         *  3) Instantiates a class for each utility--storing it in an ArrayList
         *  4) Writes the information about each utility to files (1 file for each) by calling the setRate() method of the
         *     superClass
         *  5) Reads the utility data from each file, and....
         *  6) Calculates the bill amount for each bill and displays the results to the user
         */

        String greetingMessage = "This program takes user input related to 3 different utility bills.\n" +
                "After entering your bill specifics, the bill amounts are computed and displayed.";
        String billPromptSection = "Enter the amounts for your ";
        String billPromptUnitCost = "   Enter the cost per ";
        String billPromptUnits = "   How many ";
        String goodbyeMessage = "Goodbye...";

        String[][] billTypes = { {"Gas bill", "Water bill", "Electricity bill"}, {"therm", "thousand gallon", "killowatt hour"} };

        ArrayList<UtilityBill> collBills = new ArrayList<UtilityBill>();

        // Print a program description
        System.out.println(greetingMessage);

        // Prompt the user for all input, write the data file, and create an object for each utility
        for (int i = 0; i < billTypes[0].length; ++i) {

            // Loop through the billTypes and prompt the user to enter the bill info
            System.out.println(billPromptSection + billTypes[0][i] + ":" );
            double unitCost = getUserValue(billPromptUnitCost + billTypes[1][i] + ": ");
            double unitQuantity = getUserValue(billPromptUnits + billTypes[1][i] + "s were used?: ");

            // Instantiate an object for the utilityBill and add it to the ArrayList
            switch(billTypes[0][i]) {
                case "Gas bill" :
                    collBills.add(new GasBill());
                    break;
                case "Water bill" :
                    collBills.add(new WaterBill());
                    break;
                case "Electricity bill" :
                    collBills.add(new ElectricBill());
                    break;
            }


            // Set the rate of the new utility object -- which writes the rate to a file
            try {
                collBills.get(i).setRate(unitCost);
            }
            catch (java.io.IOException e) {
                System.out.println("Failed to write to the " + collBills.get(i).getUtilityName() + " rate file!");
                System.exit(1);
            }

            // Set the quantity used
            collBills.get(i).setUsage(unitQuantity);

        }

        // Loop through each utility class object, reading from the files via the class's getRate() method
        for (int i = 0; i < collBills.size(); i++)
        {
            double utilityRate = -1;
            double usage = -1;

            // Instruct the class to load the rate from the data file
            try {
                collBills.get(i).loadRate();
            }
            catch (java.io.IOException e)
            {
                System.out.println("Failed to read from the " + collBills.get(i).getUtilityName() + " rate file!");
                System.exit(2);
            }

            // getRate() could throw an exception if the rate needs to be loaded from disk
            try {
                utilityRate = collBills.get(i).getRate();
            }
            catch (java.io.IOException e)
            {
                System.out.println("Failed to read from the " + collBills.get(i).getUtilityName() + " rate file!");
                System.exit(2);
            }

            // Calculate the bill amount and print out the results
            usage = collBills.get(i).getUsage();

            System.out.printf("%nYour %s bill is $%.2f%n", collBills.get(i).getUtilityName(), (utilityRate * usage));

        }

        // And, because no CIT 260 assignment would be complete without it...
        System.out.println("\n" + goodbyeMessage);



    }

    static double getUserValue(String prompt)
    {
        /**
         * The getUserValue Method
         * Purpose: Prompts the user for input and then returns the input as an double.  If the user supplied
         *          data is not an double, an error is displayed and the prompt is re-presented.
         * @param prompt the string prompt text for the user's input
         * @return  A double containing the value the user entered
         */

        Double userValue = null;
        Scanner userInput;


        // Loop until we get a valid integer value from the user
        while (userValue == null) {

            System.out.print(prompt);
            userInput = new Scanner(System.in);

            // Get an integer, or return an error and go around for another try in the while loop
            try {
                userValue = userInput.nextDouble();
            } catch (java.util.InputMismatchException e) {
                System.out.println("Error: input must be a numeric value.");
            }

        }
        return userValue;

    }

}
