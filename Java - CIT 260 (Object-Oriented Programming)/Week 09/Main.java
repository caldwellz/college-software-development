package Week09;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize and introduce program
        Scanner input = new Scanner(System.in);
        MyPoint p1 = new MyPoint();
        double distance;
        System.out.println("This program creates a point at (0,0) and a point at the coordinates");
        System.out.println("entered by you. It then computes and displays the distance from (0,0)");
        System.out.println("to the point defined by you, using three different methods.");

        // Get coordinates from the user
        System.out.print("Enter the x coordinate of a point: ");
        int userX = input.nextInt();
        System.out.print("Enter the y coordinate of a point: ");
        int userY = input.nextInt();

        // Show results of first distance method
        distance = p1.distance(userX, userY);
        System.out.format("Using method 1, the distance from (0,0) to (%d,%d) is %.2f%n", userX, userY, distance);

        // Show results of second and third distance methods
        MyPoint p2 = new MyPoint(userX, userY);
        distance = p1.distance(p2);
        System.out.format("Using method 2, the distance from (0,0) to (%d,%d) is %.2f%n", userX, userY, distance);
        distance = MyPoint.distance(p1, p2);
        System.out.format("Using method 3, the distance from (0,0) to (%d,%d) is %.2f%n", userX, userY, distance);

        System.out.println("Goodbye...");
    }
}
