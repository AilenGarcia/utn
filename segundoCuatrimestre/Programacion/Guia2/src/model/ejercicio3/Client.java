package model.ejercicio3;

public class Client {
    private String id;
    private String name;
    private String lastName;
    private String email;
    private Double porcentage;

    public Client(String name, String lastName, String email, Double porcentage) {
        this.name = name;
        this.lastName = lastName;
        this.email = email;
        this.porcentage = porcentage;
        this.id = java.util.UUID.randomUUID().toString();
    }

    public String getId() {
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

    public Double getPorcentage() {
        return porcentage;
    }

    public void setPorcentage(Double porcentage) {
        this.porcentage = porcentage;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString(){
        return "Cliente[id= "+this.id+", nombre= "+this.name+", email= "+this.email+", descuento= "+this.porcentage+"]";
    }
}
