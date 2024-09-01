package model.ejercicio1;

public class EmpleadoPorHoras extends Empleado{

    private int horas;

    public EmpleadoPorHoras(int horas, String nombre, Double salario) {
        super(nombre, salario);
        this.horas = horas;
    }

    @Override
    public Double CalcularPago() {
        Double salarioPorHoras = getSalario() * (double) horas;
        return salarioPorHoras;
    }

    public int getHoras() {
        return horas;
    }

    public void setHoras(int horas) {
        this.horas = horas;
    }
}
