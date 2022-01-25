package Week06;

public class W6dot2 {
    /**
     * Calculates a Fahrenheit temperature given a Celsius value
     * @param tempCelsius A Celsius temperature
     * @return A Fahrenheit temperature
     */
    public static double celsiusToFahrenheit(double tempCelsius) {
        // Conversion factors
        final double FAHRENHEIT_RATIO = 9.0 / 5.0;
        final int FAHRENHEIT_ADJUSTMENT = 32;

        return (tempCelsius * FAHRENHEIT_RATIO) + FAHRENHEIT_ADJUSTMENT;
    }


    /**
     * Calculates a Celsius temperature given a Fahrenheit value
     * @param tempFahrenheit A Fahrenheit temperature
     * @return A Celsius temperature
     */
    public static double fahrenheitToCelsius(double tempFahrenheit) {
        // Conversion factors
        final double CELSIUS_RATIO = 5.0 / 9.0;
        final int CELSIUS_ADJUSTMENT = 32;

        return (tempFahrenheit - CELSIUS_ADJUSTMENT) * CELSIUS_RATIO;
    }


    /** Program start point */
    public static void main(String[] args) {
        // User introduction and constants
        System.out.println("This program displays a convenient table of Celsius<->Fahrenheit conversions.\n");
        final double CELSIUS_START = 40.0;
        final double CELSIUS_END = 31.0;
        final double FAHRENHEIT_START = 120.0;
        final double FAHRENHEIT_END = 30.0;
        final double FAHRENHEIT_STEP = 10.0;

        // Begin the table display
        System.out.println("Celsius        Fahrenheit     |    Fahrenheit     Celsius");
        System.out.println("---------------------------------------------------------");
        for (double baseCelsius  = CELSIUS_START, baseFahrenheit  = FAHRENHEIT_START;
                    baseCelsius >= CELSIUS_END && baseFahrenheit >= FAHRENHEIT_END;
                    baseCelsius--, baseFahrenheit -= FAHRENHEIT_STEP)
        {
            // Calculate and round each number string, then format as a table line
            String convertedFahrenheit = String.format("%5.1f", celsiusToFahrenheit(baseCelsius));
            String convertedCelsius = String.format("%5.2f", fahrenheitToCelsius(baseFahrenheit));
            System.out.format("%-14.1f %-14s |    %-14.1f %-7s%n", baseCelsius, convertedFahrenheit, baseFahrenheit, convertedCelsius);
        }

        System.out.println("\nGoodbye.");
    }
}
