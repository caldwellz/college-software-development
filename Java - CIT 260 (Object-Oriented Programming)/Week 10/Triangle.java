package Week10;

public class Triangle extends GeometricObject {
    /** Internal variables */
    private double side1;
    private double side2;
    private double side3;

    /** Default constructor */
    public Triangle() {
        super();
        side1 = 0;
        side2 = 0;
        side3 = 0;
    }

    /** Parameterized constructor
     * Sets each side to the given values.
     * @param side1 Length of the first side
     * @param side2 Length of the second side
     * @param side3 Length of the third side
     */
    public Triangle(double side1, double side2, double side3) {
        super();
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    /** Get the length of side1
     * @return The length
     */
    public double getSide1() {
        return side1;
    }

    /** Set a new side1
     * @param side1 The new side 1 length
     */
    public void setSide1(double side1) {
        this.side1 = side1;
    }

    /** Get the length of side2
     * @return The length
     */
    public double getSide2() {
        return side2;
    }

    /** Set a new side2
     * @param side2 The new side 2 length
     */
    public void setSide2(double side2) {
        this.side2 = side2;
    }

    /** Get the length of side3
     * @return The length
     */
    public double getSide3() {
        return side3;
    }

    /** Set a new side3
     * @param side3 The new side 3 length
     */
    public void setSide3(double side3) {
        this.side3 = side3;
    }

    /** Calculate the area of the triangle
     * @return The area
     */
    @Override
    public double getArea() {
        double semiPerimeter = (side1 + side2 + side3) / 2;
        double squaredArea = semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3);
        return Math.sqrt(squaredArea);
    }

    /** Get a string representation of this Triangle
     * @return A string representation
     */
    @Override
    public String toString() {
        String triangleInfo = String.format("Triangle: side1 = %.1f, side2 = %.1f, side3 = %.1f\n", side1, side2, side3);
        return triangleInfo + super.toString();
    }
}
