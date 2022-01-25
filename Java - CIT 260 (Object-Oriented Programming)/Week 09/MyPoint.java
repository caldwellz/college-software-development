package Week09;

public class MyPoint {

    /** Private fields */
    private int x;
    private int y;


    /** Constructs a MyPoint with a default X and Y. */
    public MyPoint() {
        x = 0;
        y = 0;
    }


    /**
     * Constructs a MyPoint with the given X and Y.
     * @param _x The X coordinate
     * @param _y The Y coordinate
     */
    public MyPoint(int _x, int _y) {
        x = _x;
        y = _y;
    }


    /**
     * Gets the current X coordinate.
     * @return The X coordinate
     */
    public int getX() {
        return x;
    }


    /**
     * Sets the X coordinate.
     * @param _x The new X coordinate
     */
    public void setX(int _x) {
        x = _x;
    }


    /**
     * Gets the current Y coordinate.
     * @return The Y coordinate
     */
    public int getY() {
        return y;
    }


    /**
     * Sets the Y coordinate.
     * @param _y The new Y coordinate
     */
    public void setY(int _y) {
        y = _y;
    }


    /**
     * Computes the distance from this MyPoint to the given X and Y coordinates.
     * @param xCoord The X coordinate of another point
     * @param yCoord The Y coordinate of another point
     * @return The absolute distance between the two points
     */
    public double distance(int xCoord, int yCoord) {
        int xDist = Math.abs(x - xCoord);
        int yDist = Math.abs(y - yCoord);
        int totalDistSquared = (xDist * xDist) + (yDist * yDist);
        return Math.sqrt(totalDistSquared);
    }


    /**
     * Computes the distance from this MyPoint to another one.
     * @param p Another MyPoint to measure the distance to
     * @return The absolute distance between the two points
     */
    public double distance(MyPoint p) {
        return distance(p.getX(), p.getY());
    }


    /**
     * Computes the distance between two MyPoints.
     * @param mp1 The first MyPoint
     * @param mp2 The second MyPoint
     * @return The absolute distance between the two points
     */
    public static double distance(MyPoint mp1, MyPoint mp2) {
        return mp1.distance(mp2);
    }
}
