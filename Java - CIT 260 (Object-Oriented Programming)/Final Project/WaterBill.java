/** Represents CIT260 Final Project
 * @author Zach Caldwell and Reid Bolander
 * @version 0.1
 */
package UtilityBills;

public class WaterBill extends UtilityBill {
    /**
     * Calculate the total cost of the utility bill, based on the rate and usage.
     * @return The total bill cost
     */
    @Override
    public double calculateCost()
    {
        return utilityUsage * utilityRate;
    }
    /**
     * Get the name (type) of the utility.
     * @return The utility name.
     */
    @Override
    public String getUtilityName() {
        return "water";
    }

    /**
     * Get the name (type) of the measurement units of the utility.
     * @return The measurement unit name.
     */
    @Override
    public String getUnitName() {
        return "gallons";
    }
}
