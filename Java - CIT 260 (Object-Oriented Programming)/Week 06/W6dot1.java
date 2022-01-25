package Week06;

import java.util.Scanner;

public class W6dot1 {
    /**
     * Gets from the user a validated double between two given values.
     * @param prompt       The prompt string to display to the user
     * @param minVal       The minimum acceptable value
     * @param minInclusive Whether the minimum should be inclusive (default is exclusive)
     * @param maxVal       The maximum acceptable value
     * @param maxInclusive Whether the maximum should be inclusive (default is exclusive)
     * @return The user's double value
     */
    public static double getDoubleBetween(String prompt, double minVal, boolean minInclusive, double maxVal, boolean maxInclusive) {
        Scanner input = new Scanner(System.in);
        double userVal = 0;

        while (true) {
            System.out.print(prompt);
            try {
                userVal = input.nextDouble();

                // Check the exclusive range
                if (userVal > minVal && userVal < maxVal)
                    break;
                // Check inclusive low bound
                if (minInclusive && userVal == minVal)
                    break;
                // Check inclusive high bound
                if (maxInclusive && userVal == maxVal)
                    break;
            }
            catch (Exception e) {
                // Parsing error; fall through
            }

            // Catch-all whether there was an error or the value was out of range
            System.out.format("Invalid input. Please enter a number between %.2f (%s) and %.2f (%s).%n", minVal, (minInclusive ? "inclusive" : "exclusive"), maxVal, (maxInclusive ? "inclusive" : "exclusive"));
            input.nextLine();
        }

        return userVal;
    }


    /**
     * Gets from the user a validated double above a given value.
     * @param prompt       The prompt string to display to the user
     * @param minVal       The minimum acceptable value
     * @param minInclusive Whether the minimum should be inclusive (default is exclusive)
     * @return The user's double value
     */
    public static double getDoubleAbove(String prompt, double minVal, boolean minInclusive) {
        Scanner input = new Scanner(System.in);
        double userVal = 0;

        while (true) {
            System.out.print(prompt);
            try {
                userVal = input.nextDouble();

                // Check the exclusive bounding
                if (userVal > minVal)
                    break;
                // Check inclusive low bound
                if (minInclusive && userVal == minVal)
                    break;
            }
            catch (Exception e) {
                // Parsing error; fall through
            }

            // Catch-all whether there was an error or the value was out of range
            System.out.format("Invalid input. Please enter a number greater than %s%.2f.%n", (minInclusive ? "or equal to " : ""), minVal);
            input.nextLine();
        }

        return userVal;
    }


    /**
     * Calculates the future value of an investment, with interest compounded monthly.
     * @param investmentAmount    The value of the initial investment
     * @param monthlyInterestRate The monthly interest rate of the investment
     * @param years               The number of years to accrue interest on the investment
     * @return The future value of the investment at the end of the time period
     */
    public static double futureValue(double investmentAmount, double monthlyInterestRate, int years) {
        double totalPeriods = years * 12;
        double totalRate = Math.pow(1 + monthlyInterestRate, totalPeriods);
        return investmentAmount * totalRate;
    }


    /** Program start point */
    public static void main(String[] args) {
	    System.out.println("Given an investment amount and an annual interest rate, this program");
        System.out.println("will calculate the future value of the investment for a period of");
        System.out.println("ten years.\n");
        final int START_YEAR = 1;
        final int END_YEAR = 10;
        final int APR_TO_MONTHLY_RATE_FACTOR = 100 * 12;

        // Get the investment value and rate from the user
        double investmentAmount = getDoubleAbove("Enter a positive, non-zero value for the investment: ", 0, false);
        double annualRatePercent = getDoubleBetween("Enter an annual interest rate, between 0 and 100: ", 0, true, 100, true);
        double monthlyRate = annualRatePercent / APR_TO_MONTHLY_RATE_FACTOR;

        // Display the ten-year future value table
        System.out.println("\nYears   Future Value");
        for (int year = START_YEAR; year <= END_YEAR; year++) {
            double futureVal = futureValue(investmentAmount, monthlyRate, year);
            System.out.format("%-7s $%.2f%n", Integer.toString(year), futureVal);
        }

        System.out.println("\nGoodbye.");
    }
}
