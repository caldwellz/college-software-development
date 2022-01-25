package Week08;

public class Rectangle {

    /** Private fields */
    private double height;
    private double width;


    /** Constructs a Rectangle with a default height and width. */
    public Rectangle() {
        height = 1;
        width = 1;
    }


    /**
     * Constructs a Rectangle with the given height and width.
     * @param _height The rectangle's height
     * @param _width The rectangle's width
     */
    public Rectangle(double _height, double _width) {
        height = _height;
        width = _width;
    }


    /**
     * Gets the current height of the Rectangle.
     * @return The height
     */
    public double getHeight() {
        return height;
    }


    /**
     * Sets the height of the Rectangle.
     * @param _height The new height
     */
    public void setHeight(double _height) {
        height = _height;
    }


    /**
     * Gets the current width of the Rectangle.
     * @return The width
     */
    public double getWidth() {
        return width;
    }


    /**
     * Sets the width of the Rectangle.
     * @param _width The new width
     */
    public void setWidth(double _width) {
        width = _width;
    }


    /**
     * Computes and returns the area of the Rectangle.
     * @return The area
     */
    public double getArea() {
        return width * height;
    }


    /**
     * Computes and returns the perimeter of the Rectangle.
     * @return The perimeter
     */
    public double getPerimeter() {
        return (width * 2) + (height * 2);
    }
}
