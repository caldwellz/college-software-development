/** Represents CIT260 Final Project
 * @author Zach Caldwell and Reid Bolander
 * @version 0.1
 */
package UtilityBills;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;

abstract class UtilityBill {
    /** The cost rate of the utility */
    protected double utilityRate;

    /** The amount of the utility used by the user */
    protected double utilityUsage;

    /** Indicates whether the utilityRate has been successfully loaded and/or set */
    protected boolean rateLoaded;

    /** UtilityBill constructor. */
    public UtilityBill() {
        utilityRate = 0;
        utilityUsage = 0;
        rateLoaded = false;
    }

    /**
     * Get the amount of the utility used by the user.
     * @return The utility usage
     */
    public double getUsage() {
        return utilityUsage;
    }

    /**
     * Set the amount of the utility used by the user.
     * @param usage The utility usage
     */
    public void setUsage(double usage) {
        utilityUsage = usage;
    }

    /**
     * Get the cost rate of the utility.
     * Attempts to load the rate from a file the first time it's called,
     * unless one has been set using setRate; throws an IOException on read failure.
     * @return The utility's cost rate per usage unit
     * @throws IOException
     */
    public double getRate() throws IOException {
        if (!rateLoaded)
            loadRate();

        return utilityRate;
    }

    /**
     * Set the cost rate of the utility.
     * Also attempts to save the rate to a file, and throws an IOException on failure.
     * @param rate The utility's cost rate per usage unit
     * @throws IOException
     */
    public void setRate(double rate) throws IOException {
        utilityRate = rate;
        rateLoaded = true;
        saveRate();
    }

    /**
     * Load the utility rate from a file.
     * @throws IOException
     */
    protected void loadRate() throws IOException {
        // Open the rate data file
        String filename = getUtilityName() + ".dat";
        File infile = new File(filename);
        Scanner input = new Scanner(infile); // May throw a FileNotFound IOException

        // Read the rate
        try {
            double rate = input.nextDouble();
            input.close();
            utilityRate = rate;
            rateLoaded = true;
        }
        catch (Exception e) {
            throw new IOException(e.getMessage());
        }
    }

    /**
     * Save the utility rate to a file.
     * @throws IOException
     */
    protected void saveRate() throws IOException {
        String filename = getUtilityName() + ".dat";
        PrintWriter writer = new PrintWriter(filename); // May throw a FileNotFound IOException
        writer.print(utilityRate);
        writer.close();
    }

    /**
     * Calculate the total cost of the utility bill, based on the rate and usage.
     * @return The total bill cost
     */
    public abstract double calculateCost();

    /**
     * Get the name (type) of the utility.
     * @return The utility name.
     */
    public abstract String getUtilityName();

    /**
     * Get the name (type) of the measurement units of the utility.
     * @return The measurement unit name.
     */
    public abstract String getUnitName();

    /**
     * Get a string representation of the utility bill.
     * @return A string representation of the bill.
     */
    @Override
    public String toString() {
        return String.format("Utility: %s\nUnit: %s\nUsage: %.2f\nRate: %.2f", getUtilityName(), getUnitName(), utilityUsage, utilityRate);
    }
}
