package Week08;

public class W8dot1 {

    public static void main(String[] args) {
        // Initialize constants and introduce program
        final double FIRST_HEIGHT = 4.0;
        final double FIRST_WIDTH = 40;
        final double SECOND_HEIGHT = 3.5;
        final double SECOND_WIDTH = 5;
        System.out.println("This program creates two rectangle objects and displays their width, height, area and perimeter.");

        // Create and display rectangle 1
        Rectangle rect1 = new Rectangle(FIRST_HEIGHT, FIRST_WIDTH);
        System.out.println("\nRectangle 1:");
        System.out.format("height = %.2f%n", rect1.getHeight());
        System.out.format("width = %.2f%n", rect1.getWidth());
        System.out.format("area = %.2f%n", rect1.getArea());
        System.out.format("perimeter = %.2f%n", rect1.getPerimeter());

        // Create and display rectangle 2
        Rectangle rect2 = new Rectangle(SECOND_HEIGHT, SECOND_WIDTH);
        System.out.println("\nRectangle 2:");
        System.out.format("height = %.2f%n", rect2.getHeight());
        System.out.format("width = %.2f%n", rect2.getWidth());
        System.out.format("area = %.2f%n", rect2.getArea());
        System.out.format("perimeter = %.2f%n", rect2.getPerimeter());

        System.out.println("\nGoodbye.");
    }
}
