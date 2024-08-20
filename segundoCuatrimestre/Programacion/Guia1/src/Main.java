import model.CuentaBancaria;
import model.Empleado;
import model.ItemVenta;
import model.Libro;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //EJERCICIO 4
        Scanner scanner = new Scanner(System.in);
        ItemVenta venta1 = null;
        System.out.println("----------- Bienvenidos -----------");
        do {
            System.out.println("Que desea hacer?");
            System.out.println("1. Agregar Venta");
            System.out.println("2. Imprimir datos de la venta");
            System.out.println("3. Modificar cantidad");
            System.out.println("4. Modificar precio unitario");
            System.out.println("5. Calcular total");
            System.out.println("6. Salir");

            int opcion = scanner.nextInt();
            scanner.nextLine();

            switch (opcion){
                case 1:
                    System.out.println("Ingrese descripcion del producto");
                    String descripcion= scanner.nextLine();
                    System.out.println("Ingrese cantidad");
                    int cantidad = scanner.nextInt();
                    scanner.nextLine();
                    System.out.println("Ingrese Precio unitario");
                    Double pUnitario = scanner.nextDouble();
                    venta1 = new ItemVenta(descripcion, cantidad, pUnitario);
                    break;
                case 2:
                    if(venta1!=null){
                    System.out.println(venta1.toString());
                    }else{
                        System.out.println("No hay venta cargada.");
                    }
                    break;
                case 3:
                    if(venta1!=null){
                    System.out.println("Ingrese nueva cantidad: ");
                    int nuevaCantidad = scanner.nextInt();
                    scanner.nextLine();
                    venta1.setCantidad(nuevaCantidad);
                    }else{
                        System.out.println("No hay venta cargada.");
                    }
                    break;
                case 4:
                    if(venta1!=null){
                    System.out.println("Ingrese nuevo precio unitario: ");
                    double nuevoPrecioUnitario = scanner.nextDouble();
                    venta1.setPrecioUnitario(nuevoPrecioUnitario);
                    }else{
                        System.out.println("No hay venta cargada.");
                    }
                    break;
                case 5:
                    if(venta1!=null){
                    Double precioTotal = venta1.calcularPrecioTotal();
                    System.out.println("Precio total: $"+ precioTotal);
                    }else{
                        System.out.println("No hay venta cargada.");
                    }
                    break;
                case 6:
                    System.out.println("Saliendo del programa .....");
                    scanner.close();
                    return;
                default:
                    System.out.println("Opcion no valida. Intentelo otra vez");
                    break;
            }
        }while(true);
    }
}

//Ejercicio 1
        /*Empleado carlos = new Empleado("23456345","Carlos", "Gutierrez", 25000.0);
        Empleado ana = new Empleado("34234123", "Ana", "Sanchez", 27500.0);
        System.out.println(carlos.toString());
        System.out.println( ana.toString());
        carlos.aumentarSalario(15);
        carlos.salarioAnual();
        System.out.println("El salario anual de Carlos es: " +  carlos.getSalario());*/
//EJERCICIO 2
        /*CuentaBancaria cuenta1 = new CuentaBancaria("Ailen", 15000.0);
        cuenta1.credito(2500.0);
        cuenta1.debito(1500.0);
        cuenta1.debito(30000.0);
        System.out.println(cuenta1.toString());*/
//EJERCICIO 3
        /*Libro libro1= new Libro("El Quijote", "Miguel de Cervantes", 500.0, 10);
        Libro libro2 = new Libro("Cien Anios de Soledad", "Gabriel Garcia Marquez", 700.0, 5);
        System.out.println(libro1.toString());
        System.out.println(libro2.toString());
        System.out.println("-------------------------------");
        libro1.vender(3);
        System.out.println(libro1.toString());
        System.out.println("-------------------------------");
        libro2.vender(8);
        System.out.println("-------------------------------");
        libro2.ingresoLibros(5);
        System.out.println(libro2.toString());*/