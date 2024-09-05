package ejercicio3;

public abstract class Vehiculo {
    private static int cont;
    private int id;
    private String marca;
    private String modelo;
    private int velocidad;

    public Vehiculo(String marca, String modelo, int velocidad) {
        this.marca = marca;
        this.modelo = modelo;
        this.velocidad = velocidad;
        this.id = cont;
        cont++;
    }

    public abstract String moverse();
    public abstract String detenerse();

    public int getId() {
        return id;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(int velocidad) {
        this.velocidad = velocidad;
    }
}
