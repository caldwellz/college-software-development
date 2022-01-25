package Week10;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    /** Construct a Triangle from user-given details
     * @return A Triangle object
     */
    public static Triangle createTriangle() {
        Scanner input = new Scanner(System.in);

        // Get user input
        System.out.println("Enter the color of a triangle (e.g. \"red\"):");
        String tColor = input.next();
        System.out.println("Is the triangle filled (y or n):");
        char tFilledChar = input.next().toLowerCase().charAt(0);
        boolean tFilled = (tFilledChar == 'y');
        System.out.println("Enter the lengths of the three sides of the triangle:");
        double tSide1 = input.nextDouble();
        double tSide2 = input.nextDouble();
        double tSide3 = input.nextDouble();

        // Set up the triangle
        Triangle tri = new Triangle(tSide1, tSide2, tSide3);
        tri.setColor(tColor);
        tri.setFilled(tFilled);

        return tri;
    }

    /** Program entry point */
    public static void main(String[] args) {
        // Initialize and introduce program
        final int NUM_TRIANGLES = 3;
	      System.out.println("This program gets input for three triangles from the user.");
        System.out.println("It then creates three Triangle objects and displays the");
        System.out.println("description of each.");
        ArrayList<GeometricObject> triangleList = new ArrayList<>();

        // Gather the list of triangles
        for (int i = 0; i < NUM_TRIANGLES; ++i)
            triangleList.add(createTriangle());

        // Display them in string format
        for (int i = 0; i < NUM_TRIANGLES; ++i)
            System.out.printf("\n%s\n", triangleList.get(i).toString());

        System.out.printf("\nGoodbye...");
    }
}
