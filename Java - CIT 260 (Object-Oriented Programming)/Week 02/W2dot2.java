package Week02;

import java.util.Scanner;

// Tip & Tax calculator
public class W2dot2 {
    // Percentage-to-decimal conversion factor
    public static final double PERCENTAGE_FACTOR = 100.0;

    // Current tax rate: 3.2%
    public static final double TAX_RATE = 3.2 / PERCENTAGE_FACTOR;

    // Main entry point
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Given the price of a meal and a percentage to use for the tip, this");
        System.out.println("program calculates the tip, the tax, and the total amount of the bill.");

        // Get a meal cost from the user
        double mealCost;
        while (true) {
            try {
                System.out.print("Enter the cost of the meal: ");
                mealCost = input.nextDouble();
                break;
            }
            catch (Exception e) {
                System.out.println("Not a valid number");
                input.nextLine();
            }
        }

        // Get a tip percent from the user
        double tipPercent;
        while (true) {
            try {
                System.out.print("Enter the tip percentage: ");
                tipPercent = input.nextDouble();
                break;
            }
            catch (Exception e) {
                System.out.println("Not a valid number");
                input.nextLine();
            }
        }

        // Calculate the tip, tax, and bill
        double tipRate = tipPercent / PERCENTAGE_FACTOR;
        double totalTip = mealCost * tipRate;
        double totalTax = mealCost * TAX_RATE;
        double totalBill = mealCost + totalTip + totalTax;

        // Display the totals
        System.out.format("%nThe tip is $%.2f%n", totalTip);
        System.out.format("The tax is $%.2f%n", totalTax);
        System.out.format("The total bill is $%.2f%nGoodbye.%n", totalBill);
    }
}
