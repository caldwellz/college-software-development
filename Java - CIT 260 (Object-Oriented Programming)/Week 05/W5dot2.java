package Week05;

public class W5dot2 {

    public static void main(String[] args) {
        final int NUM_START = 100;
        final int NUM_MAX = 1000;
        final int NUM_DIVISOR = 30; // 5 * 6
        final int ROW_LENGTH = 10;

        System.out.println("This program displays all of the numbers from 100 to 1000");
        System.out.println("that are divisible by both 5 and 6.\n");

        // Calculate the matching numbers and display in rows
        for (int n = NUM_START, column = 1; n <= NUM_MAX; n++) {
            if (n % NUM_DIVISOR == 0) {
                System.out.format("%d ", n);

                // Move to the next row if we've reached the end
                if (column % ROW_LENGTH == 0) {
                    System.out.println();
                    column = 0;
                }
                column++;
            }
        }

        System.out.println("\nGoodbye");
    }
}
