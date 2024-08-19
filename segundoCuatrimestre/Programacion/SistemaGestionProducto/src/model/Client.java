package model;

public class Client {
    private static int lastID =0;
    private final int id;
    private String name;
    private String lastName;
    private String address;
    private String dni;
    private String phoneNumber;
    private int status;

    public Client(String name, String lastName, String address, String dni, String phoneNumber) {
        this.id = lastID++;
        this.name = name;
        this.lastName = lastName;
        this.address = address;
        this.dni = dni;
        this.phoneNumber = phoneNumber;
        this.status = 1;
    }
    public int getID(){
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String adress) {
        this.address = adress;
    }

    public String getDni() {
        return dni;
    }

    public void setDni(String dni) {
        this.dni = dni;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public int getActive() {
        return status;
    }

    public void active(){
        this.status = 1;
    }
    public void inactive() {
        this.status = 0;
    }
}
