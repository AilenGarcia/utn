package model.ejercicio1;

public class EmpleadoContratista extends EmpleadoPorHoras{

    public EmpleadoContratista(String nombre, Double salario, int horas) {
        super(horas, nombre, salario);
    }

    @Override
    public Double CalcularPago() {
        Double pagoFinal = (double)getHoras() * getSalario();
        return pagoFinal;
    }
}
