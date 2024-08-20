package model;

public class ItemVenta {
    private static int contID;
    private int id;
    private String descripcion;
    private int cantidad;
    private Double precioUnitario;

    public ItemVenta(String descripcion, int cantidad, Double precioUnitario) {
        this.descripcion = descripcion;
        this.cantidad = cantidad;
        this.precioUnitario = precioUnitario;
        id = contID;
        contID++;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public Double getPrecioUnitario() {
        return precioUnitario;
    }

    public void setPrecioUnitario(Double precioUnitario) {
        this.precioUnitario = precioUnitario;
    }

    public Double calcularPrecioTotal(){
        return precioUnitario*(double)cantidad;
    }
    @Override
    public String toString(){
        return "ItemVenta[id= "+id+", descripcion= "+descripcion+", cantidad= "+cantidad+", pUnitario= $"+precioUnitario+", pTotal= $"+calcularPrecioTotal()+"]";
    }
}
