package Week07;

import java.util.Scanner;

public class W7dot2 {
    /**
     * Calculates and returns the mean average of an array of doubles.
     * @param x An array of double values
     * @return The mean average of the given values
     */
    public static double mean(double[] x) {
        int len = x.length;
        double total = 0.0;

        for (int i = 0; i < len; ++i) {
            total += x[i];
        }

        return total / (double) len;
    }


    /**
     * Calculates and returns the standard deviation of an array of doubles.
     * @param x An array of double values to calculate deviation on
     * @return The standard deviation of the given values
     */
    public static double deviation(double[] x) {
        int len = x.length;
        double basicMean = mean(x);
        double diffSum = 0.0;

        for (int i = 0; i < len; ++i) {
            diffSum += Math.pow(x[i] - basicMean, 2);
        }
        double sampleVariance = diffSum / (double) (len - 1);

        return Math.sqrt(sampleVariance);
    }


    /** Main entry point */
    public static void main(String[] args) {
        // Declare variables and introduce program to user
        final int MAX_VALUES = 5;
        double[] userValues = new double[MAX_VALUES];
        Scanner input = new Scanner(System.in);
        System.out.println("This program computes the mean and the standard deviation for a set of numbers.");

        // Get 5 numbers from the user
        for (int i = 0; i < MAX_VALUES; ++i) {
            while (true) {
                System.out.print("Enter a number: ");
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

        // Calculate and display the mean & deviation
        double avg = mean(userValues);
        double devi = deviation(userValues);
        System.out.format("\nThe mean of this set of numbers is %.2f\n", avg);
        System.out.format("The standard deviation is %.2f\n", devi);
        System.out.println("Goodbye.");
    }
}
