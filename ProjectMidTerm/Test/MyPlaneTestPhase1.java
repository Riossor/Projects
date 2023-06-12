import org.junit.*;
/****************************************************
 * MyPlaneTestPhase1 - to test the class Plane Phase1
 *
 * @author  Jonnathan Resendiz
 * @version Summer 2021
 ****************************************************/
public class MyPlaneTestPhase1 {
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
     * Test toString
     *****************************************************/
    @Test
    public void testToString() {
        Plane p = new Plane("Southwest", "747", 2021, 3600.0);

        Assert.assertEquals("Something is wrong with your ToString method. Check commas, spaces, and caps.",
                "Southwest 747 2021 Flight Hours: 0.00 JetFuel in Tank: 50,000.00", p.toString());
    }


}
