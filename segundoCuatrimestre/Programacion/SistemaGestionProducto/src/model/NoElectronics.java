package model;

public class NoElectronics extends Product {
    private String color;

    public NoElectronics(String name, Integer amount, Float price, String color) {
        super(name, amount, price);
        this.color = color;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String detalleDelProducto(){
        String texto = super.detalleDelProducto() + ",color: " + this.color;
        return texto;
    }
}
