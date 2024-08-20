package model;

public class Libro {
    private static int contId = 0;
    private int id;
    private String titulo;
    private String autor;
    private Double precio;
    private int cantidadDisponible;

    public Libro(String titulo, String autor, Double precio, int cantidadDisponible) {
        this.titulo = titulo;
        this.autor = autor;
        this.precio = precio;
        this.cantidadDisponible = cantidadDisponible;
        id = contId;
        contId++;
    }

    public int getId() {
        return id;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public Double getPrecio() {
        return precio;
    }

    public void setPrecio(Double precio) {
        this.precio = precio;
    }

    public int getCantidadDisponible() {
        return cantidadDisponible;
    }

    public void setCantidadDisponible(int cantidadDisponible) {
        this.cantidadDisponible = cantidadDisponible;
    }
    public void vender(int cantidad){
        if(cantidadDisponible>cantidad){
            cantidadDisponible-=cantidad;
        }else{
            System.out.println("No hay suficientes libros disponibles");
        }
    }
    public void ingresoLibros(int cantidad){
        this.cantidadDisponible+=cantidad;
    }
    @Override
    public String toString(){
        return "Libro[id= "+id+", titulo= "+titulo+", autor= "+autor+", precio= "+precio+", copias disponibles= "+cantidadDisponible+"]";
    }
}
