import model.Client;
import model.Product;
import model.Sales;

import java.util.*;

//Una tienda de productos de computación necesita un sistema básico para gestionar su
// inventario de productos, clientes y registrar las ventas realizadas.
public class Main {

    private static final Scanner scanner = new Scanner(System.in);
    private static final Set<Client> clients = new HashSet<>();
    private static final Set<Sales> sales = new HashSet<>();
    private static final Set<Product> products = new HashSet<>();

    public static void main(String[] args) {
        boolean salir = false;
        int opcion;

        while (!salir) {

            System.out.println("1. Alta de un cliente");
            System.out.println("2. Listar los clientes");
            System.out.println("3. Alta de un producto");
            System.out.println("4. Listar los productos");
            System.out.println("5. Crear venta");
            System.out.println("6. Ver ventas");
            System.out.println("7. Salir");

            try {

                System.out.println("Que desea hacer?");
                opcion = scanner.nextInt();
                scanner.nextLine();

                switch (opcion) {
                    case 1:
                        createClient();
                        break;
                    case 2:
                        listClients();
                        break;
                    case 3:
                        createProduct();
                        break;
                    case 4:
                        listProducts();
                        break;
                    case 5:
                        createSales();
                        break;
                    case 6:
                        listSales();
                        break;
                    case 7:
                        salir = true;
                        break;
                    default:
                        System.out.println("El numero insertado no esta en las opciones");
                }
            } catch (InputMismatchException e) {
                System.out.println("Debes insertar un número");
                scanner.next();
            }
        }
    }

    //Clients
    public static void createClient(){
        System.out.println("Nombre: ");
        var name = scanner.nextLine();

        System.out.println("Apellido: ");
        var lastName = scanner.nextLine();

        System.out.println("DNI: ");
        var dni = scanner.nextLine();

        System.out.println("Direccion: ");
        var address = scanner.nextLine();

        System.out.println("Numero de tel: ");
        var phoneNumber = scanner.nextLine();

        Client client = new Client(name, lastName, address,dni, phoneNumber);
        clients.add(client);
        System.out.println("Cliente agregado exitosamente \n");
    }
    public static void listClients(){
        if(!clients.isEmpty()){
            for(Client client : clients){
                System.out.println("-------------------------------------------------------\n");
                System.out.println("Id: " + client.getID()+ "\n" +
                        "Nombre: " + client.getName() +" "+ client.getLastName() + "\n" +
                        "DNI: " + client.getDni() + "\n" +
                        "Direccion: " + client.getAddress() + "\n" +
                        "Numero de telefono: " + client.getPhoneNumber() + "\n");
                System.out.println("-------------------------------------------------------\n");
            }
        }else {
            System.out.println("No hay clientes.\n");
        }
    }

    //Products
    public static void createProduct(){
        System.out.println("Nombre del producto: ");
        var name = scanner.nextLine();

        System.out.println("Cantidad del producto: ");
        var amount = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Precio del producto: ");
        var price = scanner.nextFloat();

        Product product = new Product(name, amount, price);
        products.add(product);
        System.out.println("Producto agregado exitosamente \n");
    }
    public static void listProducts(){
        if(!products.isEmpty()){
            for(Product product : products){
                System.out.println("-------------------------------------------------------\n");
                System.out.println("Id: " + product.getID()+ "\n" +
                        "Nombre: " + product.getName() + "\n" +
                        "Cantidad: " + product.getAmount() + "\n" +
                        "Precio: " + product.getPrice() + "\n");
                System.out.println("-------------------------------------------------------\n");
            }
        }else {
            System.out.println("No hay productos.\n");
        }
    }

    //Sales
    public static void createSales(){
        boolean found = false;
        //Busca si el cliente existe
        Client client = null;
        do {
            System.out.println("Id del Cliente: ");
            var idClient = scanner.nextInt();
            scanner.nextLine();

            var iterator = clients.stream().filter(c -> c.getID() == idClient).iterator();
            var exist = iterator.hasNext();
            if (exist){
                client = iterator.next();
            }else{
                found = true;
                System.out.println("No existe el cliente solicitado.");
            }

        }while(found = false);

        found = false;

        //Busca si el producto existe
        Product product = null;
        do {
            System.out.println("Id del Producto: ");
            var idProduct = scanner.nextInt();
            scanner.nextLine();

            var iterator = products.stream().filter(c -> c.getID() == idProduct).iterator();
            var exist = iterator.hasNext();
            if (exist){
                product = iterator.next();
            }else{
                found = true;
                System.out.println("No existe el producto solicitado.");
            }

        }while(found);

        Sales sale = new Sales(client, product);
        sales.add(sale);
        System.out.println("Venta realizada con existo \n");
    }
    public static void listSales(){
        if(!sales.isEmpty()){
            for(Sales s : sales){
                System.out.println("-------------------------------------------------------\n");
                System.out.println("Id: " + s.getID()+ "\n" +
                        "Nombre del Cliente: " + s.getClient().getName() + "\n" +
                        "Nombre del producto: " + s.getProduct().getName()+ "\n");
                System.out.println("-------------------------------------------------------\n");
            }
        }else {
            System.out.println("No hay clientes.\n");
        }
    }
}

