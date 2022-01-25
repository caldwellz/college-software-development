package Week03;

import java.util.Scanner;

public class W3dot2 {

    public static void main(String[] args) {

        // Month constants
        final int JANUARY = 1;
        final int FEBRUARY = 2;
        final int MARCH = 3;
        final int APRIL = 4;
        final int MAY = 5;
        final int JUNE = 6;
        final int JULY = 7;
        final int AUGUST = 8;
        final int SEPTEMBER = 9;
        final int OCTOBER = 10;
        final int NOVEMBER = 11;
        final int DECEMBER = 12;

        // Introduce program to user
        System.out.println("Given a year and a month in that year, this program will tell you");
        System.out.println("the number of days in that month.");

        // Get the year
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a year: ");
        int year = input.nextInt();
        if (year < 0) {
            System.out.format("%d is invalid. You must enter a positive number.", year);
            return;
        }

        // Is it a leap year?
        boolean isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        // Get the month
        System.out.print("Enter a value for the month (1 = Jan, 2 = Feb, etc): ");
        int month = input.nextInt();

        // Figure out the month name and number of days
        String monthName = "";
        int daysInMonth = 0;
        switch (month) {
            case JANUARY:
                monthName = "January";
                daysInMonth = 31;
                break;
            case FEBRUARY:
                monthName = "February";
                if (isLeapYear)
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
                break;
            case MARCH:
                monthName = "March";
                daysInMonth = 31;
                break;
            case APRIL:
                monthName = "April";
                daysInMonth = 30;
                break;
            case MAY:
                monthName = "May";
                daysInMonth = 31;
                break;
            case JUNE:
                monthName = "June";
                daysInMonth = 30;
                break;
            case JULY:
                monthName = "July";
                daysInMonth = 31;
                break;
            case AUGUST:
                monthName = "August";
                daysInMonth = 31;
                break;
            case SEPTEMBER:
                monthName = "September";
                daysInMonth = 30;
                break;
            case OCTOBER:
                monthName = "October";
                daysInMonth = 31;
                break;
            case NOVEMBER:
                monthName = "November";
                daysInMonth = 30;
                break;
            case DECEMBER:
                monthName = "December";
                daysInMonth = 31;
                break;
            default:
                System.out.format("%d is invalid. Month values must be between between 1 and 12, inclusive.", month);
                return;
        }

        // Display the month and days and a goodbye message
        System.out.format("%n%s of %d has %d days in it.%nGoodbye.", monthName, year, daysInMonth);
    }
}
