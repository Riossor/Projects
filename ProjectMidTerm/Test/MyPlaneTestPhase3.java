import org.junit.*;
import java.text.DecimalFormat;
/****************************************************
 * MyPlaneTestPhase1 - to test the class Plane Phase1
 *
 * @author  Jonnathan Resendiz
 * @version Summer 2021
 ****************************************************/
public class MyPlaneTestPhase3 {
    /** fuel tank capacity  */
    private static final double TANK_CAPACITY = 50000;

    /** hours in between oil inspections */
    private static final int HOURS_BETWEEN_INSPECTION = 48;

    /******************************************************
     * Test default constructor - no input parameters
     *****************************************************/
    @Test
    public void testDefaultConstructor() {
        Plane p = new Plane();
        Assert.assertEquals("Airline should be ","Southwest",
                p.getAirline());
        Assert.assertEquals("Plane model should be ","747",
                p.getModel());
        Assert.assertEquals("Plane year should be ",
                2021, p.getYear());
        Assert.assertEquals("Fuel in tank should be",
                TANK_CAPACITY, p.checkGasGauge(), 0.1);
        Assert.assertEquals("Plane GPH should be 3600",
                3600.0, p.getGph(),0.1);
        Assert.assertEquals("Next Inspection",
                HOURS_BETWEEN_INSPECTION, p.getHoursNextInspection(), 0.1);
    }

    /******************************************************
     * Test second constructor
     *****************************************************/
    @Test
    public void testSecondConstructor() {
        Plane p = new Plane("Southwest", "747", 2021, 3600.0);
        Assert.assertEquals("Airline should be equal to value of input parameter ","Southwest",
                p.getAirline());
        Assert.assertEquals("Plane model should be equal to value of input parameter","747",
                p.getModel());
        Assert.assertEquals("Plane year should be equal to value of input parameter ",
                2021, p.getYear());
        Assert.assertEquals("Fuel in tank should be",
                TANK_CAPACITY, p.checkGasGauge(), 0.1);
        Assert.assertEquals("Plane GPH should be equal to value of input parameter",
                3600.0, p.getGph(),0.1);
        Assert.assertEquals("Hours Until Next Inspection",
                HOURS_BETWEEN_INSPECTION, p.getHoursNextInspection(), 0.1);
    }

    /******************************************************
     * Test setAirline
     *****************************************************/
    @Test
    public void testSetAirline() {
        Plane p = new Plane("Southwest", "747", 2021, 3600.0);
        p.setAirline("Delta");
        Assert.assertEquals("Airline should be equal to value of input parameter ","Delta",
                p.getAirline());
    }

    /******************************************************
     * Test setModel
     *****************************************************/
    @Test
    public void testSetModel() {
        Plane p = new Plane("Southwest", "747", 2021, 3600.0);
        p.setModel("737");
        Assert.assertEquals("Plane model should be equal to value of input parameter","737",
                p.getModel());
    }

    /******************************************************
     * Test setYear
     *****************************************************/
    @Test
    public void testSetYear() {
        Plane p = new Plane("Southwest", "747", 2021, 3600.0);
        p.setYear(2019);
        Assert.assertEquals("Plane year should be equal to value of input parameter ",
                2019, p.getYear());
    }

    /******************************************************
     * Test setGph
     *****************************************************/
    @Test
    public void testSetGph() {
        Plane p = new Plane("Southwest", "747", 2021, 3600.0);
        p.setGph(4000.0);
        Assert.assertEquals("Plane GPH should be equal to value of input parameter",
                4000.0, p.getGph(),0.1);
    }

    /******************************************************
     * Test addGas- negative Value
     *****************************************************/
    @Test
    public void testAddGasNegativeValEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.landAndStopEngine();
        p.addGas(-10);
        Assert.assertEquals("Fuel in tank should not change" +
                        " when trying to add fuel with a negative value",
                TANK_CAPACITY, p.checkGasGauge(), 0.1);
    }


    /******************************************************
     * Test addGasNegativeVal - Engine on
     *****************************************************/
    @Test
    public void testAddGasNegativeVaEngineOn() {
        Plane p = new Plane();;
        p.startEngine();
        double previousGas = p.checkGasGauge();
        p.addGas(-10);
        Assert.assertEquals("You cannot add gas because the engine is on",
                previousGas, p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test addGas - overflow
     *****************************************************/
    @Test
    public void testAddGasOverflowEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.landAndStopEngine();
        p.addGas(10);
        //trying to add gas when tank is full
        Assert.assertEquals("Fuel in tank should not change" +
                        " when trying to overflow the tank",
                TANK_CAPACITY, p.checkGasGauge(), 0.1);

        //trying to add more fuel than the required to fill the tank
        p = new Plane();
        p.startEngine();
        p.fly(2);
        p.landAndStopEngine();
        p.addGas(30000);
        Assert.assertEquals("Fuel in tank should be",
                TANK_CAPACITY , p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test addGas - overflow
     *****************************************************/
    @Test
    public void testAddGasOverflowEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        double previousGas = p.checkGasGauge();
        p.addGas(10);
        //trying to add gas when tank is full
        Assert.assertEquals("You cannot add gas " +
                        " because the engine is on.",
                previousGas, p.checkGasGauge(), 0.1);

        //trying to add more fuel than the required to fill the tank
        p = new Plane();
        p.startEngine();
        p.fly(2);
        previousGas = p.checkGasGauge();
        p.addGas(30000);
        Assert.assertEquals("You cannot add gas " +
                        "because the engine is on.",
                previousGas, p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test addGas - valid input parameter
     *****************************************************/
    @Test
    public void testAddGasOKValEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(1);
        p.landAndStopEngine();
        p.addGas(1000);
        Assert.assertEquals("Fuel in tank should be",
                47400 , p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test addGas - valid input parameter
     *****************************************************/
    @Test
    public void testAddGasOKValEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(1);
        double previousGas = p.checkGasGauge();
        p.addGas(1000);
        Assert.assertEquals("You cannot add gas " +
                        "because the engine is on.",
                previousGas, p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test addGasIncrements
     *****************************************************/
    @Test
    public void testAddGasOKIncrementsEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(3);
        p.landAndStopEngine();
        p.addGas(1000);
        p.addGas(1000);

        Assert.assertEquals("Gas in tank should be",
                41200 , p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test addGasIncrements
     *****************************************************/
    @Test
    public void testAddGasOKIncrementsEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(3);
        double previousGas = p.checkGasGauge();
        p.addGas(1000);
        p.addGas(1000);

        Assert.assertEquals("You cannot add gas " +
                        "because the engine is on.",
                previousGas, p.checkGasGauge(), 0.1);
    }

    /******************************************************
     * Test fly Negative Val
     *****************************************************/
    @Test
    public void testFlyNegativeValEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(-2);
        Assert.assertEquals("Fuel in tank should not change" +
                        " when trying to fly negative hours",
                TANK_CAPACITY, p.checkGasGauge(), 0.1);

        Assert.assertEquals("Hours flown should not change" +
                        " when trying to fly negative hours",
                0.0, p.checkFlyingHours(), 0.1);

    }

    /******************************************************
     * Test fly Negative Val
     *****************************************************/
    @Test
    public void testFlyNegativeValEngineOff() {

        Plane p = new Plane();
        p.landAndStopEngine();
        double previousGas = p.checkGasGauge();
        double previousHours = p.checkFlyingHours();
        p.fly(-2);


        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousGas, p.checkGasGauge(), 0.1);

        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousHours, p.checkFlyingHours(), 0.1);

    }

    /******************************************************
     * Test driveOkVal
     *****************************************************/
    @Test
    public void testFlyOKValEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(2);
        Assert.assertEquals("Problem with formula to update the fuel in tank" +
                        "- after flying, the fuel in tank should decrement" ,
                42800, p.checkGasGauge(), 0.1);

        Assert.assertEquals("Problem with formula to update the flying hours" +
                        "- after flying, the hours should increment" ,
                2, p.checkFlyingHours(), 0.1);

    }

    /******************************************************
     * Test driveOkVal
     *****************************************************/
    @Test
    public void testFlyOKValEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.landAndStopEngine();
        double previousGas = p.checkGasGauge();
        double previousHours = p.checkFlyingHours();
        p.fly(2);
        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousGas, p.checkGasGauge(), 0.1);

        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousHours, p.checkFlyingHours(), 0.1);

    }

    /******************************************************
     * Test running out of fuel
     *****************************************************/
    @Test
    public void testRunningOutFuelEngineOn() {

        Plane p1 = new Plane();
        p1.startEngine();
        p1.fly(15);
        Assert.assertEquals("Problem with formula to update the fuel in tank" +
                        "- after running out of fuel, the fuel in tank should be" ,
                0.0, p1.checkGasGauge(), 0.1);

        Assert.assertEquals("Problem with formula to update the number of flying hours" +
                        "- after running out of fuel, the hours flown should be" ,
                13.89, p1.checkFlyingHours(), 0.1);

        Assert.assertFalse("Airplane ran out of gas, the plane must land and engine must be off " ,
                p1.isEngineOn());

    }

    /******************************************************
     * Test running out of fuel
     *****************************************************/
    @Test
    public void testRunningOutFuelEngineOff() {

        Plane p1 = new Plane();
        p1.startEngine();
        p1.landAndStopEngine();
        double previousGas = p1.checkGasGauge();
        double previousHours = p1.checkFlyingHours();
        boolean previousEngineStatus = p1.isEngineOn();
        p1.fly(15);
        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousGas, p1.checkGasGauge(), 0.1);

        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousHours, p1.checkFlyingHours(), 0.1);

        Assert.assertEquals("Engine off - boolean engineOn should be " ,
                previousEngineStatus,  p1.isEngineOn());

    }

    /******************************************************
     * Test fly - increments with valid input parameter
     *****************************************************/
    @Test
    public void testFlyOKValIncrementsEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        p.fly(2);
        p.fly(1);

        Assert.assertEquals("Problem with formula to update the fuel in tank" +
                        "- after flying, the fuel in tank should decrement" ,
                39200, p.checkGasGauge(), 0.1);

        Assert.assertEquals("Problem with formula to update the number of flying hours" +
                        "- after flying, the hours flown should be" ,
                3, p.checkFlyingHours(), 0.1);

    }


    /******************************************************
     * Test fly - increments with valid input parameter
     *****************************************************/
    @Test
    public void testFlyOKValIncrementsEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.landAndStopEngine();
        double previousGas = p.checkGasGauge();
        double previousHours = p.checkFlyingHours();
        p.fly(2);
        p.fly(1);

        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousGas, p.checkGasGauge(), 0.1);

        Assert.assertEquals("You cannot fly " +
                        "because the engine is off.",
                previousHours, p.checkFlyingHours(), 0.1);

    }

    /******************************************************
     * Test inspection
     *****************************************************/
    @Test
    public void testInspectionEngineOff() {

        Plane p = new Plane();
        p.startEngine();
        p.landAndStopEngine();
        p.inspect();
        Assert.assertEquals("The next inspection should be " ,
                p.checkFlyingHours() + HOURS_BETWEEN_INSPECTION ,
                p.getHoursNextInspection (), 0.1);
    }

    /******************************************************
     * Test inspection
     *****************************************************/
    @Test
    public void testInspectionEngineOn() {

        Plane p = new Plane();
        p.startEngine();
        double previousInspectionHours = p.getHoursNextInspection();
        p.inspect();
        Assert.assertEquals("You cannot inspect the plane " +
                        "because the engine is on.",
                previousInspectionHours, p.getHoursNextInspection(), 0.1);
    }

    /******************************************************
     * Test startEngine
     *****************************************************/
    @Test
    public void testStartEngine() {
        Plane p = new Plane();
        p.startEngine();
        Assert.assertTrue("When you start the engine the engineOn boolean should be true " ,
                p.isEngineOn());
    }

    /******************************************************
     * Test stopEngine
     *****************************************************/
    @Test
    public void testStopEngine() {
        Plane p = new Plane();
        p.startEngine();
        p.landAndStopEngine();
        Assert.assertFalse("When you stop the engine the engineOn boolean should be false " ,
                p.isEngineOn());
    }

    /******************************************************
     * Test toString
     *****************************************************/
    @Test
    public void testToString() {
        Plane p = new Plane("Delta", "737", 2021, 3000);
        DecimalFormat df = new DecimalFormat ("###,##0.00");


        Assert.assertTrue("Error formatting fuel in tank" ,
                p.toString().contains (df.format(p.checkGasGauge ())));

        Assert.assertTrue("Error formatting odometer",
                p.toString().contains (df.format(p.checkFlyingHours ())));
    }

    /******************************************************
     * Test equals
     *****************************************************/
    @Test
    public void testEquals() {
        Plane p1 = new Plane("Delta", "747", 2021, 3600);
        Plane p2 = new Plane("Delta", "747", 2021, 3600);
        Assert.assertTrue("Problems with the equal method" +
                " - the two planes have the same airline, model and year", p1.equals(p2));

        p1 = new Plane("Delta", "747", 2021, 3600);
        p2 = new Plane("Delta", "737", 2021, 3600);
        Assert.assertFalse("Problems with the equal method" +
                " - the two planes do not have the same airline, model and year", p1.equals(p2));


        p1 = new Plane("Spirit", "747", 2021, 3600);
        p2 = new Plane("Delta", "737", 2021, 3600);
        Assert.assertFalse("Problems with the equal method" +
                " - the two planes do not have the same airline, model and year", p1.equals(p2));

        p1 = new Plane("Spirit", "747", 2021, 3600);
        p2 = new Plane("Delta", "747", 2021, 3600);
        Assert.assertFalse("Problems with the equal method" +
                " - the two planes do not have the same airline, model and year", p1.equals(p2));

    }


}