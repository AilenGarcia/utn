package ejercicio3;

public class Camiones extends Vehiculo implements VehiculoDeCarga {
    private static int cont;
    private int id;
    private int cantCarga;

    public Camiones(String marca, String modelo, int velocidad, int cantCarga) {
        super(marca, modelo, velocidad);
        this.cantCarga = cantCarga;
        this.id=cont;
        cont++;
    }

    @Override
    public String moverse() {
        return "El camion se mueve";
    }

    @Override
    public String detenerse() {
        return "El camion se detiene";
    }

    @Override
    public String cargarVehiculo() {
        return "Se carga el camion";
    }

    @Override
    public String descargarVehiculo() {
        return "Se descarga el camion";
    }

    @Override
    public int getId() {
        return id;
    }

    public int getCantCarga() {
        return cantCarga;
    }

    public void setCantCarga(int cantCarga) {
        this.cantCarga = cantCarga;
    }
}
