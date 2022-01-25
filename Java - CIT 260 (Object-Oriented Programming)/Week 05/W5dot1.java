package Week05;

public class W5dot1 {

    public static void main(String[] args) {
        final int KG_START = 1;
        final int KG_MAX = 15;
        final int KG_INCREMENT = 2;

        System.out.println("This program calculates and displays a conversion table of odd kilograms (up to 15) to pounds.");
        System.out.println("\nkilograms    pounds");
        System.out.println("---------    ------");

        // Calculate and display the conversion table
        for (int kg = KG_START; kg <= KG_MAX; kg += KG_INCREMENT) {
            double pounds = kg * 2.2;
            System.out.format("%-12d %-6.1f%n", kg, pounds);
        }

        System.out.println("\nGoodbye.");
    }
}
