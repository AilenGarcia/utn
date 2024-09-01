package model.ejercicio1;

public abstract class Empleado {
    private static int contID=0;
    private int id;
    private String nombre;
    private Double salario;

    public Empleado(String nombre, Double salario) {
        this.nombre = nombre;
        this.salario = salario;
        this.id = contID;
        contID++;
    }

    public abstract Double CalcularPago();

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Double getSalario() {
        return salario;
    }

    public void setSalario(Double salario) {
        this.salario = salario;
    }
}
