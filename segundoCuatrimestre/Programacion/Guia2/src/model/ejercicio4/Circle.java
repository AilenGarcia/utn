package model.ejercicio4;

public class Circle {
    private Double radius;
    private String color;

    public Circle() {
        this.radius = 1.0;
        this.color = "red";
    }

    public Circle(Double radius){
        this.radius = radius;
        this.color = "red";
    }

    public Double getRadius() {
        return radius;
    }

    public void setRadius(Double radius) {
        this.radius = radius;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Double area(){
        return Math.PI * Math.pow(this.radius, 2);
    }

    public String toString(){
        return "Circulo de "+ this.radius+" y de color "+this.color;
    }
}
