package model;

public class Product {
    private static int lastID;
    private final int id;
    private String name;
    private Integer amount;
    private Float price;

    public Product(String name, Integer amount, Float price) {
        this.id = lastID++;
        this.name = name;
        this.amount = amount;
        this.price = price;
    }
    public void sales(){
        if(amount >0){
        this.amount--;
        }
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

    public Integer getAmount() {
        return amount;
    }

    public void setAmount(Integer amount) {
        this.amount = amount;
    }

    public Float getPrice() {
        return price;
    }

    public void setPrice(Float price) {
        this.price = price;
    }

    public String detalleDelProducto(){
        return "Producto: \n"+
                "Id: " + this.id + ", nombre: " + this.name + " \n" +
                ",cantidad disponible: " + this.amount + ", precio: "+ this.price;
    }

}
