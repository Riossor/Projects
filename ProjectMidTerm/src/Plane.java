import java.text.DecimalFormat;
public class Plane {
    private String airline;
    private String model;
    private int year;
    private double hours;
    private double nextInspectionHours;
    private double fuel;
    private double gph;
    private static final double TANK_CAPACITY = 50000;
    private static final int HOURS_BETWEEN_INSPECTION = 48;
    private static DecimalFormat df = new DecimalFormat ("###,##0.00");
    private boolean onEngine;
    private boolean landAndStopEngine;


    public Plane(){
        airline = "Southwest";
        model = "747";
        year = 2021;
        gph = 3600.0;
        fuel = TANK_CAPACITY;
        nextInspectionHours = HOURS_BETWEEN_INSPECTION;
    }

    public Plane(String airline, String model, int year, double gph) {
        this.airline = airline;
        this.model = model;
        this.year = year;
        this.gph = gph;
        fuel = TANK_CAPACITY;
        nextInspectionHours = HOURS_BETWEEN_INSPECTION;
    }

    public String getAirline() {
        return airline;
    }

    public void setAirline(String airline) {
        this.airline = airline;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public double getGph() {
        return gph;
    }

    public void setGph(double gph) {
        this.gph = gph;
    }
    public double getHoursNextInspection ( ){
        return nextInspectionHours;
    }
    public double checkFlyingHours ( ){
        return hours;
    }
    public double checkGasGauge ( ){
        return fuel;
    }
    public String toString(){
        return airline + " " +
                model + " " +
                year + " " +
                "Flight Hours: " +
                df.format(hours) + " " +
                "JetFuel in Tank: " +
                df.format(fuel);

    }
    public void addGas(double gallons){
        if(landAndStopEngine == true) {
            if (gallons < 0) {
                System.out.printf("%s %s %d gallons cannot be a negative number - Fuel in Tank " +
                        "after the fill up: %s", airline, model, year, df.format(fuel));
            } else if ((gallons + fuel) > TANK_CAPACITY) {
                System.out.printf("%s %s %d tank overflowed - Fuel in Tank after the fill up: " +
                        "%s\n", airline, model, year, df.format(this.fuel));
                fuel = TANK_CAPACITY;
            } else {
                System.out.println("Fuel in the tank after fill");
                fuel += gallons;
            }
        }
        else{
            landAndStopEngine = false;
        }
    }
    public void fly(double hours){
        if(onEngine == true) {
            if (hours < 0) {
                System.out.printf("%s %s %d cannot fly negative miles", airline, model, year);
            } else if ((fuel / gph) < hours) {
                System.out.println("Out of fuel");
                this.hours += fuel / gph;
                fuel = 0;
                onEngine = false;
            } else {
                System.out.printf("%s %s %d flew %s hours.\n", airline, model, year, df.format(hours));
                fuel -= hours * gph;
                this.hours += hours;
            }
        }
        else{
            onEngine = false;
        }
    }
    public void inspect(){
        System.out.printf("%s %s %d has been inspected, next inspection is:\n", airline, model, year);
        this.nextInspectionHours = HOURS_BETWEEN_INSPECTION;
    }
    public void checkForInspection(){
        if(hours > nextInspectionHours){
            System.out.printf("%s %s %d - It is time to inspect.", airline, model, year);
        }
        else{
            System.out.printf("%s %s %d - Plane is OK, no need to inspect.", airline, model, year);
        }
    }
    public boolean equals(Plane other){
        if(airline.equals(other.getAirline()) && model == other.getModel() && year == other.getYear()){
            return true;
        }
        else {
            return false;
        }
    }
    public void startEngine(){
        if(onEngine = true){
            System.out.printf("%s %s %d – engine started.", airline, model, year);
        }
        else{
            onEngine = false;
        }
    }
    public void landAndStopEngine( ){
        if(landAndStopEngine = true){
            System.out.printf("%s %s %d – was landed and stopped.\n", airline, model, year);
             onEngine = false;
        }
        else{
            landAndStopEngine = false;
            onEngine = true;
        }
    }
    public boolean isEngineOn( ){
        if(onEngine == true){
            return true;

        }
        else{
            return false;
        }
    }
    private double calcRange(){
        hours = fuel * gph;
        return hours;
    }
    private double calcGasNeededToFillTank(){
        fuel = gph / hours;
        return fuel;
    }
    public void simulateMultiCityTrip (int numberCities ){

    }
}
