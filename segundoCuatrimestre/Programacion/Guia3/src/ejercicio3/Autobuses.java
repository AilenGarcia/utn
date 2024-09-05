package ejercicio3;

public class Autobuses extends Vehiculo implements VehiculoDePasajeros {
    private static int cont;
    private int id;
    private int cantPasajeros;

    public Autobuses(String marca, String modelo, int velocidad, int cantPasajeros) {
        super(marca, modelo, velocidad);
        this.cantPasajeros = cantPasajeros;
        this.id = cont;
        cont++;
    }

    @Override
    public String moverse() {
        return "El autobus se pone en marcha";
    }

    @Override
    public String detenerse() {
        return "El autobus se detiene";
    }

    @Override
    public String subirPasajeros(int cantidad) {
        if(cantidad<this.cantPasajeros){
            return "Los pasajeros se suben";
        }else {
            return "Demasiados pasajeros quieren subir";
        }
    }

    @Override
    public String bajarPasajeros() {
        return "Los pasajeros se bajan";
    }

    public static int getCont() {
        return cont;
    }

    public static void setCont(int cont) {
        Autobuses.cont = cont;
    }

    public int getCantPasajeros() {
        return cantPasajeros;
    }

    public void setCantPasajeros(int cantPasajeros) {
        this.cantPasajeros = cantPasajeros;
    }

    @Override
    public int getId() {
        return id;
    }
}
