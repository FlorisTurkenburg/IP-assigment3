

public interface Hotel extends java.rmi.Remote {
    public String help() throws java.rmi.RemoteException;
    public int[] listRooms() throws java.rmi.RemoteException;
    public void bookRoom(int type, String name) throws java.rmi.RemoteException;
    public String[] listGuests() throws java.rmi.RemoteException;

}
