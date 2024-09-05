package ejercicio1;

public class Autobus implements Transporte{
    private int numeroLinea;
    private int capacidad;
    private TipoTransporte tipo;

    public Autobus(int numeroLinea, int capacidad) {
        this.numeroLinea = numeroLinea;
        this.capacidad = capacidad;
        this.tipo = TipoTransporte.AUTOBUS;
    }

    @Override
    public String arrancar() {
        return "Vehiculo en marcha";
    }

    @Override
    public String detener() {
        return "Vehiculo detenido";
    }

    @Override
    public int obtenerCapacidad() {
        return this.capacidad;
    }

    public String anunciarParada(){
        return "Arrivando a la parada";
    }

    public int getNumeroLinea() {
        return numeroLinea;
    }

    public void setNumeroLinea(int numeroLinea) {
        this.numeroLinea = numeroLinea;
    }

    public int getCapacidad() {
        return capacidad;
    }

    public void setCapacidad(int capacidad) {
        this.capacidad = capacidad;
    }

    public TipoTransporte getTipo() {
        return tipo;
    }
}
