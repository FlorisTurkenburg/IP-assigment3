import java.rmi.Naming;

public class HotelClient {
    public static void main(String args[]){
        try
        {
            Hotel c = (Hotel) Naming.lookup("rmi://localhost/HotelService");
            c.bookRoom(1,"Foo");
            //String [] guests = c.listGuests();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
