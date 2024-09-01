package model.ejercicio1;

public class EmpleadoTiempoCompleto extends Empleado {


    public EmpleadoTiempoCompleto(String nombre, Double salario) {
        super(nombre, salario);
    }

    @Override
    public Double CalcularPago() {
        Double salarioAnual = getSalario() * 30.0;
        return salarioAnual;
    }
}
