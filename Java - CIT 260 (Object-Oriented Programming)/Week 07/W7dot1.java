package Week07;

import java.util.Scanner;

public class W7dot1 {
    /**
     * Calculates and returns the mean average of an array of doubles.
     * @param array An array of double values
     * @return The average of the given values
     */
    public static double average(double[] array) {
        int len = array.length;
        double total = 0.0;

        for (int i = 0; i < len; ++i) {
            total += array[i];
        }

        return total / (double) len;
    }


    /** Main entry point */
    public static void main(String[] args) {
        // Declare variables and introduce program to user
        final int MAX_VALUES = 5;
        double[] userValues = new double[MAX_VALUES];
        Scanner input = new Scanner(System.in);
        System.out.println("This program calculates the average of five numbers.");

        // Get 5 numbers from the user
        for (int i = 0; i < MAX_VALUES; ++i) {
            while (true) {
                System.out.print("Please enter a number: ");
                try {
                    userValues[i] = input.nextDouble();
                    break;
                }
                catch (Exception e) {
                    System.out.println("Invalid input");
                    input.nextLine();
                }
            }
        }

        // Calculate and display the average
        double avg = average(userValues);
        if ((avg % 1) == 0) // Per the assignment example, don't display trailing digits on an exact number
            System.out.format("The average of these five numbers is %.0f\n", avg);
        else
            System.out.format("The average of these five numbers is %.2f\n", avg);
        System.out.println("Goodbye.");
    }
}
