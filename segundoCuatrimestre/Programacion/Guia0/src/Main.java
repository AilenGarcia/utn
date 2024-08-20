import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        scanner.close();
    }
}

//EJERCICIO 1
       /* int numN = 1;
        double numA = 2.5;
        char numC = 'c';
        System.out.println("Valor de numN: " + numN);
        System.out.println("Valor de numA: " + numA);
        System.out.println("Valor de numC: " + numC);
        System.out.println("Suma de numN + numA: " + (numN+numA));
        System.out.println("Resta de numN + numA: " + (numN-numA));
        System.out.println("Valor numerico de numC: " + Character.getNumericValue(numC));*/
//EJERCICIO 2
        /*int num1 = 1;
        int num2 = 2;
        double num3 = 1.5;
        double num4 = 2.5;

        System.out.println("Suma: " + (num1 + num3));
        System.out.println("Resta: " + (num2 - num4));
        System.out.println("Multiplicacion: " + (num1*num4));
        System.out.println("Division: " + (num2/num3));*/
//EJERCICIO 3
        /*System.out.println("Ingrese un valor numerico: ");
        int N = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Valor de N: " + N);
        N = 77;
        System.out.println("Valor de N: " + N);
        N = 3;
        System.out.println("Valor de N: " + N);
        N = N*2;
        System.out.println("Valor de N: " + N);*/
//EJERCICIO 4
        /*int A = 1;
        int B = 2;
        int C = 3;
        int D = 4;

        B=C;
        C=A;
        A=D;
        D=B;

        System.out.println("A = " + A + " B = " + B + " C = " + C + " D = " + D);*/
//EJERCICIO 5
        /*int a = 2;
        if((a%2) ==0){
            System.out.println(" es par ");
        }else{
            System.out.println(" es impar ");
        }*/
//EJERCICIO 6
        /*System.out.println("Ingrese un valor: ");
        int a = scanner.nextInt();
        scanner.nextLine();
        if(a>=0){
            System.out.println(" a es positivo");
        }else{
            System.out.println(" a es negativo");
        }*/
//EJERCICIO 7
        /*System.out.println("Ingrese una palabra: ");
        char letra = scanner.next().charAt(0);
        System.out.println(" valor ingresado: "+ letra);*/
//EJERCICIO 8
        /*System.out.println("Ingrese un valor numerico: ");
        int c = scanner.nextInt();
        scanner.nextLine();
        if(c >= 0){
            System.out.println("El numero ingresado es positivo");
        }else{
            System.out.println("El numero ingresado es negativo");
        }

        if((c%2) == 0){
            System.out.println("El numero ingresado es par");
        }else{
            System.out.println("El numero ingresado es impar");
        }

        if((c%5) == 0){
            System.out.println("El numero ingresado es multiplo de 5");
        }
        if((c%10) == 0){
            System.out.println("El numero ingresado es multiplo de 10");
        }

        if(c>100){
            System.out.println("El numero ingresado es mayor a 0");
        } else if(c<100){
            System.out.println("El numero ingresado es menor a 0");
        }else{
            System.out.println("El numero ingresado es 100");
        }*/
//EJERCICIO 9
        /*System.out.println("Ingrese su nombre");
        String nombre = scanner.nextLine();
        System.out.println("Buenos dias, " + nombre);*/
//EJERCICIO 10
        /*System.out.println("Ingrese el valor del radio de su circunferencia");
        double radio = scanner.nextDouble();
        System.out.println("Longitud de su circulo: " + (Math.PI * radio * 2) );
        System.out.println("Area de su circulo: " +(Math.PI * Math.pow(radio, 2)));*/
//EJERCICIO 11
        /*System.out.println("Ingrese la velocidad en KM/h : ");
        int kmH = scanner.nextInt();
        scanner.nextLine();
        System.out.println("La velocidad en m/s es: " + ((kmH * 1000) / 3600));*/
//EJERCICIO 12
        /*System.out.println("Ingrese el primer lado del triangulo:");
        double cateto1 = scanner.nextDouble();
        System.out.println("Ingrese el segundo lado del triangulo:");
        double cateto2 = scanner.nextDouble();
        double hipotenusa = Math.sqrt(cateto1 * cateto1 + cateto2 * cateto2) ;
        System.out.println("La longitud de la hipotenusa es: " + hipotenusa );*/
//EJERCICIO 13
        /*System.out.println("Ingrese el radio de su esfera: ");
        double radio = scanner.nextDouble();
        double volumen = Math.PI * 4/3 * Math.pow(radio, 3);
        System.out.println("El volumen de su esfera es: " + volumen);*/
//EJERCICIO 14
        /*System.out.println("Ingrese un numero de 3 cifras");
        int num = scanner.nextInt();
        scanner.nextLine();
        if(num >= 100 && num <=999){
            int centenas  = num /10;
            int decenas = (num/10) % 10 ;
            int unidades = num % 10;
            System.out.println("Cecenas: " + centenas + ", decenas: " + decenas + ", unidades " + unidades);
        }else{
            System.out.println("El numero ingresado no es de 3 cifras.");
        }*/
//EJERCICIO 15
        /*System.out.println("Ingrese un numero de 5 cifras");
        int num = scanner.nextInt();
        scanner.nextLine();
        if(num >= 100 && num <=99999){
            int uno  = num /10000;
            int tres = (num/100) % 10 ;
            int cinco = num % 10;
            System.out.println("Cifras que posicion impar " + uno + " " + tres + " " + cinco);
        }else{
            System.out.println("El numero ingresado no es de 5 cifras.");
        }*/
//EJERCICIO 16
        /*System.out.println("Ingrese hora:");
        int h = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Ingrese minutos:");
        int m = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Ingrese segundos:");
        int s = scanner.nextInt();
        scanner.nextLine();

        if(h>23 || h<0 && m>59 || m<0 && s>59 || s<0){
            System.out.println("La hora ingresada no es valida");
        }else{
            System.out.println("La hora ingresada es " + h + ":" + m + ":" + s );
        }*/
//EJERCICIO 17
        /*System.out.println("Ingrese su nombre: ");
        String nombre = scanner.nextLine();
        System.out.println("Ingrese su edad: ");
        int edad = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Ingrese su salario: ");
        Double salario = scanner.nextDouble();
        Double sueldo = 0.0;

        if(edad<=16){
            System.out.println("Es menor de edad, no debe trabajar");
        }else if(edad>=19 && edad<=50){
            sueldo = (salario * 0.05)+salario;
        }else if(edad>=51 && edad<=60){
            sueldo = (salario * 0.1) + salario; //10
        }else{
            sueldo = (salario * 0.15) + salario;//15
        }

        System.out.println("El empleado " + nombre + " cobrara " + sueldo);*/

//EJERCICIO 18
        /*System.out.println("Ingrese su altura: ");
        double altura = scanner.nextDouble();
        scanner.nextLine();
        System.out.println("Ingrese su peso: ");
        double peso = scanner.nextDouble();
        scanner.nextLine();

        double indiceCorporal = peso / (Math.pow(altura, 2));

        if(indiceCorporal<18.5){
            System.out.println("Estas bajo de peso");
        }else if(indiceCorporal>=18.5 && indiceCorporal<=24.9){
            System.out.println("Estas saludable");
        }else{
            System.out.println("Estas con sobrepeso");
        }*/
//EJERCICIO 19
        /*int numeros [] = {0,1,2,3};
        int validos = numeros.length;
        int agregar;
        System.out.println("Cuantos numeros desea agregar al arreglo?");
        agregar = scanner.nextInt();
        scanner.nextLine();

        int[] arregloNumeros = Arrays.copyOf(numeros, validos + agregar);


        for (int i=0; i<agregar;i++ ){
            System.out.println("Ingrese un numero: ");
            arregloNumeros[(validos +i)] = scanner.nextInt();
            scanner.nextLine();
        }
        validos = arregloNumeros.length;
        int suma = 0;
        for (int num: arregloNumeros) {
            suma += num;
        }
        double promedio = (double) suma/validos;

        System.out.println("Carga finalizada con existo, ahora hay " + validos + " numeros en su arreglo");
        System.out.println("El promedio del arreglo es: "+ promedio);
        */
//EJERCICIO 20
        /*System.out.println("Por favor ingrese un numero: ");
        int numero = scanner.nextInt();
        scanner.nextLine();
        int suma =0;

        for (int i=1 ; i<=numero ; i++){
            suma+=i;
        }
        System.out.println("La suma de todos los numeros naturales hasta el " + numero + " es: " +suma);*/
//EJERCICIO 21
        /*Double temperaturas [] = new Double[21];
        Double suma = 0.0;
        System.out.println("Ingrese 20 temperaturas: ");
        for (int i=1 ; i<=20 ; i++){
            System.out.println("Temperatura " + i + ": ");
            temperaturas[(i-1)] = scanner.nextDouble();
            suma+= temperaturas[(i-1)];
        }
        Double promedio = suma/ (double)temperaturas.length;
        Double minimo = temperaturas[0];
        Double maximo = temperaturas[0];

        for (int i=1 ; i<20 ; i++){
            minimo = Math.min(minimo, temperaturas[i]);
            maximo = Math.max(maximo, temperaturas[i]);
        }

        System.out.println("La temperatura promedio es de: "+promedio);
        System.out.println("La temperatura minima fue de: "+minimo);
        System.out.println("La temperatura maxima fue de "+maximo);*/