package model;

public class Product {
    private static int lastID;
    private final int id;
    private String name;
    private String color;
    private String code;
    private Integer amount;
    private Float price;

    public Product(String name, Integer amount, String color, String code, Float price) {
        this.id = lastID++;
        this.name = name;
        this.amount = amount;
        this.color=color;
        this.code = code;
        this.price = price;
    }
    public void sales(){
        this.amount--;
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

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
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
}
