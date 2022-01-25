package Week11;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class W11Exercise {
    /**
     * Gets a validated integer from the user.
     * @param prompt The prompt string to display to the user
     * @return The user's integer value
     */
    public static int getUserInteger(String prompt) {
        Scanner input = new Scanner(System.in);
        int userVal = 0;

        while (true) {
            System.out.println(prompt);
            try {
                userVal = input.nextInt();
                break;
            }
            catch (Exception e) {
                System.out.println("Error: input must be an integer.");
                input.nextLine();
            }
        }

        return userVal;
    }


    /**
     * Saves an Integer array to a file.
     * Throws an exception on failure
     * @param filename The destination filename
     * @param srcList An ArrayList of Integers to save
     */
    public static void saveIntegers(String filename, ArrayList<Integer> srcList) throws FileNotFoundException {
        PrintWriter fileOut = new PrintWriter(filename);
        for (int num : srcList)
            fileOut.println(num);

        fileOut.close();
    }


    /**
     * Loads and averages a file of integers.
     * Throws an exception on failure
     * @param filename The source filename
     * @return The average of the integers in the file
     */
    public static double averageIntegerFile(String filename) throws IOException {
        File fileIn = new File(filename);
        if (fileIn.isFile() && fileIn.canRead()) {
            Scanner input = new Scanner(fileIn);
            double sum = 0.0;
            double count = 0.0;

            try {
                while (input.hasNext()) {
                    sum += input.nextInt();
                    count++;
                }
            }
            catch (Exception e) {
                throw new IOException(filename + ": Contains invalid data");
            }

            if (count > 0)
                return sum / count;
            else
                return 0;
        }
        else
            throw new IOException(filename + ": Does not exist or cannot be read");
    }


    /** Program entry point */
    public static void main(String[] args) {
	      // Initialize and introduce program
        final int NUM_INTEGERS = 10;
        final String DATA_FILENAME = "data.txt";
        ArrayList<Integer> numList = new ArrayList<Integer>();
        System.out.println("This program gets ten numbers from the user, and");
        System.out.println("computes and displays the average.");
        System.out.println("\nPlease enter ten integer values.");

        // Gather user integers
        for (int i = 1; i <= NUM_INTEGERS; ++i)
            numList.add(getUserInteger("Enter integer " + i + ":"));

        // Save, load, and calculate the average of the integers
        double avg = 0;
        try {
            saveIntegers(DATA_FILENAME, numList);
            avg = averageIntegerFile(DATA_FILENAME);
        }
        catch (Exception e) {
            System.out.println("Error while reading or writing " + e.getMessage());
            return;
        }

        // Display the average and exit
        System.out.format("The average of the input values is %.2f\n", avg);
        System.out.println("Goodbye ...");
    }
}
