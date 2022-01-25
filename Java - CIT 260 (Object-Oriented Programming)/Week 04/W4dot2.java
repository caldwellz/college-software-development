package Week04;

import java.util.Scanner;

public class W4dot2 {

    public static void main(String[] args) {
        // Declare variables
        String firstName, lastName;
        double hoursWorked, hourlyWage, grossPay, netPay, stateTaxes, fedTaxes;
        Scanner input = new Scanner(System.in);

        // Declare tax constants
        final double STATE_WH_TAX_RATE = 0.09; // 9%
        final double FED_WH_TAX_RATE = 0.20;   // 20%

        // Introduce program to the user
        System.out.println("Given your name, hours worked, and hourly wage, this program calculates your");
        System.out.println("gross pay, state withholding tax, federal withholding tax, and your net pay.");
        System.out.println("It then displays your pay stub.");

        // Get their name
        System.out.print("Enter your first and last name: ");
        firstName = input.next();
        lastName = input.next();

        // Get their hours worked
        while (true) {
            System.out.print("Enter the hours you worked this week: ");
            try {
                hoursWorked = input.nextDouble();
                if (hoursWorked < 0)
                    throw new Exception();
                break;
            }
            catch (Exception e) {
                System.out.println("Invalid input. Please enter a positive number.");
                input.nextLine();
            }
        }

        // Get their hourly wage
        while (true) {
            System.out.print("Enter your hourly wage: ");
            try {
                hourlyWage = input.nextDouble();
                if (hourlyWage < 0)
                    throw new Exception();
                break;
            }
            catch (Exception e) {
                System.out.println("Invalid input. Please enter a positive number.");
                input.nextLine();
            }
        }

        // Calculate pay and taxes
        grossPay = hoursWorked * hourlyWage;
        stateTaxes = grossPay * STATE_WH_TAX_RATE;
        fedTaxes = grossPay * FED_WH_TAX_RATE;
        netPay = grossPay - stateTaxes - fedTaxes;

        // Display the pay stub
        System.out.format("%nPay Stub for %s %s%n", firstName, lastName);
        System.out.format("Hours Worked: %.1f%n", hoursWorked);
        System.out.format("Hourly Wage: $%.2f%n", hourlyWage);
        System.out.format("Gross Pay: $%.2f%n", grossPay);
        System.out.format("State Tax Withheld: $%.2f%n", stateTaxes);
        System.out.format("Federal Tax Withheld: $%.2f%n", fedTaxes);
        System.out.format("Net Pay: $%.2f%n", netPay);
        System.out.println("\nGoodbye.");
    }
}
