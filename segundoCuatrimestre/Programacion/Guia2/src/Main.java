import model.ejercicio1.EmpleadoContratista;
import model.ejercicio1.EmpleadoPorHoras;
import model.ejercicio1.EmpleadoTiempoCompleto;
import model.ejercicio2.Autor;
import model.ejercicio2.Libro;
import model.ejercicio3.Bill;
import model.ejercicio3.Client;
import model.ejercicio4.Cylinder;
import model.ejercicio5.Estudiante;
import model.ejercicio5.Persona;
import model.ejercicio5.Staff;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //EJERCICIO 5
        Estudiante est1 = new Estudiante("12345678", "Ailen", "Garcia", "ailen@example.com", "casa de ailen", "2024", 46.0, "TUP");
        Estudiante est2 = new Estudiante("23456789", "Maria", "Perez", "maria@example.com", "casa de maria", "2023", 46.0, "TUP");
        Estudiante est3 = new Estudiante("45678912", "Juana", "Sanchez", "juana@example.com", "casa de juana", "2022", 46.0, "TUP");
        Estudiante est4 = new Estudiante("67894123", "Laura", "Martinez", "laura@example.com", "casa de laura", "2024", 46.0, "TUP");
        Staff staff1 = new Staff("78945612", "Martin", "Garcia", "martin@example.com", "casa de martin", 50.0, "noche");
        Staff staff2 = new Staff("56123789", "Facundo", "Perez", "facu@example.com", "casa de facu", 60.0, "tarde");
        Staff staff3 = new Staff("12456789", "Marcos", "Gullo", "marcos@example.com", "casa de marcos", 70.0, "noche");
        Staff staff4 = new Staff("65123789", "Gaston", "Bocero", "gaston@example.com", "casa de gaston", 80.0, "tarde");

        Persona[] personas = new Persona[8];
        personas[0]= est1;
        personas[1]= est2;
        personas[2]= est3;
        personas[3]= est4;
        personas[4]= staff1;
        personas[5]= staff2;
        personas[6]= staff3;
        personas[7]= staff4;

        int cantidadE = 0;
        int cantidadS = 0;
        for(int i =0 ; i<8 ; i++){
            if(personas[i] instanceof Estudiante){
                cantidadE++;
            }else if(personas[i] instanceof Staff){
                cantidadS++;
            }else{
                System.out.println("No es un estudiante ni un miembro del Staff");
            }
        }
        System.out.println("Hay "+cantidadE +" estudiantes y "+cantidadS+" miembros del staff" );

        int cantIngresos =0;
        for(int i =0 ; i<8 ; i++){
            if(personas[i] instanceof Estudiante){
                cantIngresos+= ((Estudiante) personas[i]).getCuotas();
            }
        }
        System.out.println("La cantidad de dinero ingresado es: " + cantIngresos);
    }
}

//EJERCICIO 1
        /*Scanner scanner = new Scanner(System.in);
        int opcion;
        EmpleadoTiempoCompleto empleado1 = null;
        EmpleadoPorHoras empleado2 = null;
        EmpleadoContratista empleado3 = null;

        do{
            System.out.println("""
                Que desea hacer?
                1. Alta empleado tiempo completo
                2. Alta empleado por horas
                3. Alta contratista
                4. Calcular salario de empleado fijo
                5. Calcular salario de empleado temporario
                6. Calcular salario de contratista
                7. Salir
                """);
            opcion = scanner.nextInt();
            scanner.nextLine();

            String nombre;
            Double salario;
            int horas;

            switch (opcion){
                case 1:
                    System.out.println("Nombre:");
                    nombre = scanner.nextLine();
                    System.out.println("Salario");
                    salario = scanner.nextDouble();
                    empleado1 = new EmpleadoTiempoCompleto(nombre, salario);
                    break;
                case 2:
                    System.out.println("Nombre:");
                    nombre = scanner.nextLine();
                    System.out.println("Salario por hora:");
                    salario = scanner.nextDouble();
                    System.out.println("Horas trabajadas:");
                    horas = scanner.nextInt();
                    scanner.nextLine();
                    empleado2=new EmpleadoPorHoras(horas, nombre, salario);
                    break;
                case 3:
                    System.out.println("Nombre:");
                    nombre = scanner.nextLine();
                    System.out.println("Salario");
                    salario = scanner.nextDouble();
                    System.out.println("Horas trabajadas:");
                    horas = scanner.nextInt();
                    scanner.nextLine();
                    empleado3 = new EmpleadoContratista(nombre, salario, horas);
                    break;
                case 4:
                    if( empleado1 != null){
                    System.out.println("El pago es de: "+ empleado1.CalcularPago());
                    }else{
                        System.out.println("No existe el empleado");
                    }
                    break;
                case 5:
                    if( empleado2 != null){
                        System.out.println("El pago es de: "+ empleado2.CalcularPago());
                    }else{
                        System.out.println("No existe el empleado");
                    }
                    break;
                case 6:
                    if( empleado3 != null){
                        System.out.println("El pago es de: "+ empleado3.CalcularPago());
                    }else{
                        System.out.println("No existe el empleado");
                    }
                    break;
                case 7:
                    System.out.println("Saliendo del sistema....");
                    scanner.close();
                    return;
                default:
                    System.out.println("Opcion no existente. Intentelo de nuevo");
                    break;
            }
        }while(true);*/
//EJERCICIO 2
        /*Autor autor = new Autor("Joshua","Bloch","joshua@emailcom","M");
        System.out.println("Datos del autor");
        System.out.println(autor);
        Libro libro = new Libro("Effective Java", 450.0, 150, autor);
        System.out.println("Datos del libro");
        System.out.println(libro);
        libro.setPrecio(500.0);
        libro.setStock(libro.getStock()+50);
        System.out.println("Datos del autor desde libro:");
        System.out.println(libro.getAutor().toString());*/
//Ejercicio 3
        /*Client client1 = new Client("Ailen", "Garcia", "ailen@example.com", 5.0);
        System.out.println("Datos del primer cliente: ");
        System.out.println(client1);

        Bill bill1 = new Bill(200.0, client1);
        System.out.println("Datos de la factura: ");
        System.out.println("Monto de la factura: "+ bill1.getTotal() + ". Monto con el descuento: "+ bill1.totalWithPorcentage());

        System.out.println("Metodo de impresion");
        System.out.println(bill1);*/
//EJERCICIO 4
        /*Cylinder cilindro = new Cylinder();
        System.out.println("Informacion del cilindro: ");
        System.out.println("Radio: " + cilindro.getRadius());
        System.out.println("Altura: " + cilindro.getHeight());
        System.out.println("Area: " + cilindro.area());
        System.out.println("Volumen: " + cilindro.volumen());

        Cylinder cilindro2 = new Cylinder(1.5, 2.0);
        System.out.println("Informacion del cilindro: ");
        System.out.println("Radio: " + cilindro2.getRadius());
        System.out.println("Altura: " + cilindro2.getHeight());
        System.out.println("Area: " + cilindro2.area());
        System.out.println("Volumen: " + cilindro2.volumen());

        System.out.println(cilindro2);*/
