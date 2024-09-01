package model.ejercicio5;

public class Estudiante extends Persona{
    private static int contID = 0;
    private int id;
    private String year;
    private Double cuotas;
    private String carrera;

    public Estudiante(String dni, String name, String lastName, String email, String address, String year, Double cuotas, String carrera) {
        super(dni, name, lastName, email, address);
        this.year = year;
        this.cuotas = cuotas;
        this.carrera = carrera;
        this.id= contID;
        contID++;
    }

    public int getId() {
        return id;
    }

    public String getYear() {
        return year;
    }

    public void setYear(String year) {
        this.year = year;
    }

    public Double getCuotas() {
        return cuotas;
    }

    public void setCuotas(Double cuotas) {
        this.cuotas = cuotas;
    }

    public String getCarrera() {
        return carrera;
    }

    public void setCarrera(String carrera) {
        this.carrera = carrera;
    }
}
