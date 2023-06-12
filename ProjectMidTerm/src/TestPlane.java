public class TestPlane {
    public static void main(String [] args){
        System.out.println("\n**Testing starts");
        Plane d = new Plane("Delta", "747", 2015, 3600.0);
        Plane s = new Plane();
        System.out.println(d.getAirline());
        System.out.println(d);
        System.out.println(s.getAirline());
        System.out.println("\n**Testing ends");
    }

}
