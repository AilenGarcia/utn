package ejercicio3;

public class Automoviles extends Vehiculo implements VehiculoDePasajeros{
    private static int cont;
    private int id;
    private int cantPasajeros;

    public Automoviles(String marca, String modelo, int velocidad, int cantPasajeros) {
        super(marca, modelo, velocidad);
        this.cantPasajeros = cantPasajeros;
        this.id=cont;
        cont++;
    }

    @Override
    public String moverse() {
        return "El automovil se pone en marcha";
    }

    @Override
    public String detenerse() {
        return "El automovil se detiene";
    }

    @Override
    public int getId() {
        return id;
    }

    public int getCantPasajeros() {
        return cantPasajeros;
    }

    public void setCantPasajeros(int cantPasajeros) {
        this.cantPasajeros = cantPasajeros;
    }

    @Override
    public String subirPasajeros(int cantidad) {
        if(cantidad<this.cantPasajeros){
            return "Los pasajeros se subieron";
        }else{
            return "Demasiados pasajeros quieren subirse";
        }
    }

    @Override
    public String bajarPasajeros() {
        return "Los pasajeros quieren subirse";
    }
}
