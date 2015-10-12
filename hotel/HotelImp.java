import java.util.ArrayList;

public class HotelImp extends java.rmi.server.UnicastRemoteObject implements Hotel {

    private int type1num = 10;
    private int type2num = 20;
    private int type3num = 20;

    private ArrayList<Booking> bookings;

    private String HELPMESSAGE = "";

    public HotelImp() throws java.rmi.RemoteException {
        super();
    }
    public String help() throws java.rmi.RemoteException {
        return this.HELPMESSAGE;
    }

    @Override
    public synchronized int[] listRooms() throws java.rmi.RemoteException {
        return new int[]{type1num, type2num, type3num};
    }

    @Override
    public synchronized void bookRoom(int type, String name) throws java.rmi.RemoteException {
        switch (type){
            case 1:
                type1num--;
            case 2:
                type2num--;
            case 3:
                type3num--;
            default: System.exit(1);
        }
        this.bookings.add(new Booking(type, name));
    }

    @Override
    public synchronized String[] listGuests() throws java.rmi.RemoteException {
        ArrayList<String> arr = new ArrayList<String>();
        for (int i=0; i<this.bookings.size(); i++){
            arr.add(this.bookings.get(i).getName());
        }
        return (String[]) arr.toArray();
    }
}
