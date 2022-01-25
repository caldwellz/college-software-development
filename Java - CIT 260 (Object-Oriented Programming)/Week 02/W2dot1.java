package Week02;

import java.util.Scanner;

// Celsius to Fahrenheit converter
public class W2dot1 {
    // Celsius-to-Fahrenheit step ratio
    public static final double FAHRENHEIT_RATIO = 9.0 / 5.0;

    //  Temperature baseline adjustment
    public static final int FAHRENHEIT_ADJUSTMENT = 32;

    // Main entry point
    public static void main(String[] args) {
        System.out.println("This program converts a temperature in degrees Celsius into");
        System.out.println("a temperature in degrees Fahrenheit. Enter a temperature in");
        System.out.print("degrees Celsius: ");

        // Get and validate a Celsius number from the user
        Scanner input = new Scanner(System.in);
        double celsius;
        while (true) {
            try {
                celsius = input.nextDouble();
                break;
            }
            catch (Exception e) {
                System.out.println("Invalid number");
                input.nextLine();
                System.out.print("Degrees Celsius: ");
            }
        }

        // Convert and display Fahrenheit
        double fahrenheit = (celsius * FAHRENHEIT_RATIO) + FAHRENHEIT_ADJUSTMENT;
        System.out.format("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.%nGoodbye.%n", celsius, fahrenheit);
    }
}
