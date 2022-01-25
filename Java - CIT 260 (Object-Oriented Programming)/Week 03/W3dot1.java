package Week03;

import java.util.Scanner;

public class W3dot1 {

    public static void main(String[] args) {

        // Days of the week constants
        final int SUNDAY = 0;
        final int MONDAY = 1;
        final int TUESDAY = 2;
        final int WEDNESDAY = 3;
        final int THURSDAY = 4;
        final int FRIDAY = 5;
        final int SATURDAY = 6;

        // Introduce program to user
        System.out.println("Given today's day of the week and some number of days in the future");
        System.out.println("this program will tell you the day of the week for the future day.");

        // Get current day number
        Scanner input = new Scanner(System.in);
        System.out.print("Enter today's day of the week (0 for Sunday, 1 for Monday, etc): ");
        int today = input.nextInt();

        // Set the current day name
        String todayName = "";
        switch (today) {
            case SUNDAY:
                todayName = "Sunday";
                break;
            case MONDAY:
                todayName = "Monday";
                break;
            case TUESDAY:
                todayName = "Tuesday";
                break;
            case WEDNESDAY:
                todayName = "Wednesday";
                break;
            case THURSDAY:
                todayName = "Thursday";
                break;
            case FRIDAY:
                todayName = "Friday";
                break;
            case SATURDAY:
                todayName = "Saturday";
                break;
            default:
                System.out.format("%d is invalid. Please enter a number between 0 and 6.", today);
                return;
        }

        // Get number of future days
        System.out.print("Enter the number of days in the future: ");
        int futureDaysTotal = input.nextInt();
        if (futureDaysTotal < 0) {
            System.out.format("%d is invalid. You must enter a positive number.", futureDaysTotal);
            return;
        }
        int futureDay = (today + futureDaysTotal) % 7;

        // Set the future day name
        String futureDayName = "";
        switch (futureDay) {
            case SUNDAY:
                futureDayName = "Sunday";
                break;
            case MONDAY:
                futureDayName = "Monday";
                break;
            case TUESDAY:
                futureDayName = "Tuesday";
                break;
            case WEDNESDAY:
                futureDayName = "Wednesday";
                break;
            case THURSDAY:
                futureDayName = "Thursday";
                break;
            case FRIDAY:
                futureDayName = "Friday";
                break;
            case SATURDAY:
                futureDayName = "Saturday";
                break;
        }

        // Display the day names and a goodbye message
        System.out.format("%nToday is %s and the future day is %s.%nGoodbye.", todayName, futureDayName);
    }
}
