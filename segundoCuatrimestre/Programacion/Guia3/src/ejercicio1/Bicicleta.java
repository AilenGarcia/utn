package ejercicio1;

public class Bicicleta implements Transporte{
    private String numeroSerie;
    private TipoTransporte tipo;

    public Bicicleta(String numeroSerie) {
        this.numeroSerie = numeroSerie;
        this.tipo = TipoTransporte.BICICLETA;
    }

    @Override
    public String arrancar() {
        return "Vehiculo arrancado";
    }

    @Override
    public String detener() {
        return "Vehiculo detenido";
    }

    @Override
    public int obtenerCapacidad() {
        return 1;
    }

    public String ajustarAsiento(int altura){
        return "La nueva altura del asiento es: " + altura;
    }
}
