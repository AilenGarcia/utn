package ejercicio1;

public class Tranvia implements Transporte{
    private String ruta;
    private int capacidad;
    private TipoTransporte tipo;

    public Tranvia(String ruta, int capacidad) {
        this.ruta = ruta;
        this.capacidad = capacidad;
        this.tipo = TipoTransporte.TRANVIA;
    }

    @Override
    public String arrancar() {
        return "Arrancando el vehiculo";
    }

    @Override
    public String detener() {
        return "Deteniendo vehiculo";
    }

    @Override
    public int obtenerCapacidad() {
        return this.capacidad;
    }

    public String cambiarVia(int nuevaVia){
        return "Cambia a via: " + nuevaVia;
    }

    public String getRuta() {
        return ruta;
    }

    public void setRuta(String ruta) {
        this.ruta = ruta;
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
