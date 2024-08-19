package model;

public class Sales {
    private static int lastID;
    private final int id;
    Client client;
    Product product;

    public Sales(Client client, Product product) {
        this.id = lastID++;
        this.client = client;
        this.product = product;
        this.product.sales();
    }
    public int getID(){
        return id;
    }
    public Client getClient() {
        return client;
    }

    public void setClient(Client client) {
        this.client = client;
    }

    public Product getProduct() {
        return product;
    }

    public void setProduct(Product product) {
        this.product = product;
    }
}
