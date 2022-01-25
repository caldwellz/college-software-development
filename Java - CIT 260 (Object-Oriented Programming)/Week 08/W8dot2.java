package Week08;

import java.util.Date;

public class W8dot2 {

    public static void main(String[] args) {
        // Initialize constants and introduce program.
        // Elapsed times in requirement 2 use powers 4-11 and skip 6, but
        // the range below actually matches the desired example output.
        final int START_POWER = 5;
        final int END_POWER = 11;
        final int BASE = 10;
        System.out.println("This program uses the Date class to display a set of dates and times.");

        // Convert powers of 10 milliseconds to Dates and display them
        for (int power = START_POWER; power <= END_POWER; ++power) {
            long millis = (long) Math.pow(BASE, power);
            Date date = new java.util.Date(millis);
            System.out.println(date.toString());
        }

        System.out.println("Goodbye.");
    }
}
