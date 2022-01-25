/** Represents CIT260 Final Project
 * @author Zach Caldwell and Reid Bolander
 * @version 0.1
 */
package UtilityBills;

public class GasBill extends UtilityBill {
    /**
     * Calculate the total cost of the utility bill, based on the rate and usage.
     * @return The total bill cost
     */

    public static final String BILL_TYPE= "gas";
    public static final String BILLED_UNITS= "therms";

    @Override
    public double calculateCost() {

        return (utilityUsage * utilityRate);

    }

    /**
     * Get the name (type) of the utility.
     * @return The utility name.
     */
    @Override
    public String getUtilityName() {

        return BILL_TYPE;
    }

    /**
     * Get the name (type) of the measurement units of the utility.
     * @return The measurement unit name.
     */
    @Override
    public String getUnitName() {

        return BILLED_UNITS;
    }
}
