package model.ejercicio4;

public class Cylinder extends Circle{
    private Double height;

    public Cylinder() {
        this.height = 1.0;
    }

    public Cylinder(Double radius, Double height) {
        super(radius);
        this.height = height;
    }

    public Double getHeight() {
        return height;
    }

    public void setHeight(Double height) {
        this.height = height;
    }

    public Double volumen(){
        return Math.PI * 4/3 * Math.pow(super.getRadius(), 3);
    }

    @Override
    public Double area(){
        return Math.PI * super.getRadius() * height + (2*super.area());
    }

    @Override
    public String toString(){
        return "Cilindro: subclase de "+ super.toString()+" altura= "+ this.height;
    }
}
