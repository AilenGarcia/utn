package model.ejercicio3;

import java.time.LocalDateTime;

public class Bill {
    private String id;
    private Double total;
    private LocalDateTime date;
    private Client client;

    public Bill(Double total, Client client) {
        this.total = total;
        this.client = client;
        this.date =  LocalDateTime.now();
        this.id = java.util.UUID.randomUUID().toString();
    }

    public Double totalWithPorcentage(){
        return this.total - ((client.getPorcentage()*total)/100);
    }

    public String getId() {
        return id;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public Double getTotal() {
        return total;
    }

    public void setTotal(Double total) {
        this.total = total;
    }

    @Override
    public String toString(){
        return ": Factura[id= "+this.id+", fecha= "+this.date+",\n" +
                "monto= "+this.total+", montoDesc= "+totalWithPorcentage()+", " +",\n" +
                "Cliente[id= "+ this.client.getId()+", nombre= "+this.client.getName() +" "+ this.client.getLastName()+",\n" +
                "email= "+this.client.getEmail()+", descuento= "+this.client.getPorcentage()+"]]\n";
    }
}
