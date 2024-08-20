package model;

public class Empleado {
    private String dni;
    private String nombre;
    private String apellido;
    private Double salario;

    public Empleado(String dni, String nombre, String apellido, Double salario) {
        this.dni = dni;
        this.nombre = nombre;
        this.apellido = apellido;
        this.salario = salario;
    }

    public Double salarioAnual(){
        Double anual = salario*(double)12;
        return  anual;
    }
    public void aumentarSalario(int porcentaje){
        if (porcentaje > 0) {
            salario += salario * ((double)porcentaje / 100);
        }
    }

    public String getDni() {
        return dni;
    }

    public void setDni(String dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public Double getSalario() {
        return salario;
    }

    public void setSalario(Double salario) {
        this.salario = salario;
    }

    @Override
    public String toString() {
        return "Empleado... Dni= "+dni+", nombre= "+nombre+ ", apellido= "+ apellido + ", salario= "+ salario;
    }

}
