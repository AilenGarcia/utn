#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retornarUnRandom();
int mayorNumero(int num1, int num2, int num3);
int menorNumero(int num1, int num2, int num3);
void mayorMenor(int num1, int num2, int num3);
int sumaMenoresQueNumero(int num1);
void tablaMultiplicar(int num1);
float suma(int num1, int num2);
float resta(int num1, int num2);
float multiplicacion(int num1, int num2);
float division(int num1, int num2);
void calculadora();
int cambiarSigno(int num1);
void cargarNumeros(int *num1, int *num2);

int main()
{
    int numRandom, num1, num2, num3;
    float resultado;

    /**Ejercicio 1*/
    /*numRandom = retornarUnRandom();
    printf("El numero es: %i \n", numRandom);
    */
    /**Ejercicio 2*/
   /* printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%i", &num1);

    printf("Ingrese otro numero: ");
    fflush(stdin);
    scanf("%i", &num2);

    printf("Ingrese otro numero: ");
    fflush(stdin);
    scanf("%i", &num3);

    mayorMenor(num1, num2, num3);*/

    /**Ejercicio3*/
  /*printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%i", &num1);

    int suma= sumaMenoresQueNumero(num1);
    printf("Los numero anteriores a %i sumados = %i", num1, suma);
    */

    /**Ejercicio4*/
    /*printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%i", &num1);

    tablaMultiplicar(num1);*/

    /**Ejercicio5*/
    /*calculadora();*/

    /**Ejercicio6*/
    /*printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%i", &num1);

    int numeroCambiado = cambiarSigno(num1);
    printf("El numero cambiado es: %i", numeroCambiado);*/

    /**Ejercicio7*/
    int elemento1, elemento2;

    cargarNumeros(&elemento1, &elemento2);

    printf("Los numeros ingresados son: %i y %i\n", elemento1, elemento2);


    return 0;
}

 /** 1. Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.*/
 int retornarUnRandom(){
    srand(time(NULL));
    int random = rand()%100;

    return random;
}

 /** 2. Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.*/
 int mayorNumero(int num1, int num2, int num3){
    if(num1>num2 && num1>num3){
        return num1;
    }else if(num2>num1 && num2>num3){
        return num2;
    }else{
        return num3;
    }
 }

 int menorNumero(int num1, int num2, int num3){
    if(num1<num2 && num1<num3){
        return num1;
    }else if(num2<num1 && num2<num3){
        return num2;
    }else{
        return num3;
    }
 }

 void mayorMenor(int num1, int num2, int num3){
    int mayor = mayorNumero(num1, num2, num3);
    int menor = menorNumero(num1, num2, num3);
    printf("El mayor numero es: %i \n", mayor);
    printf("El menor numero es: %i \n", menor);
 }

 /** 3. Diseñe una función que reciba un número entero N y realice la suma de los números enteros positivos menores que N
        y lo retorne. N es un dato ingresado por el usuario en el main.*/
int sumaMenoresQueNumero(int num1){
    int suma;
    for(int i = 0; i<num1; i++){
        suma+=i;
    }
    return suma;
}

 /** 4. Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro.*/

void tablaMultiplicar(int num1){
    for(int i=0; i<= 10 ; i++){
        printf("%i * %i = %i \n", num1, i, num1*i);
    }
}

 /** 5. Realice una pequeña calculadora, utilizando funciones (una función de suma, una de multiplicación,  una de resta,
        una de división…)*/
float suma(int num1, int num2){
    return num1 + num2;
}

float resta(int num1, int num2){
    return num1 - num2;
}

float multiplicacion(int num1, int num2){
    return num1 * num2;
}

float division(int num1, int num2){
        if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: no se puede dividir por cero.\n");
        return 0;
    }
}

void calculadora(){
    int eleccion, num1, num2;
    printf("Que operacion desea realizar? \n"
           "1) Suma \n"
           "2) Resta \n"
           "3) Multiplicacion \n"
           "4) Division \n");
    fflush(stdin);
    scanf("%i", &eleccion);

    printf("Ingrese otro numero: ");
    fflush(stdin);
    scanf("%i", &num1);

    printf("Ingrese otro numero: ");
    fflush(stdin);
    scanf("%i", &num2);

    switch(eleccion){
    case 1:
        printf("El resultado de la suma es: %.0f",suma(num1, num2));
        break;
    case 2:
        printf("El resultado de la suma es: %.0f",resta(num1, num2));
        break;
    case 3:
        printf("El resultado de la suma es: %.0f",multiplicacion(num1, num2));
        break;
    case 4:
        printf("El resultado de la suma es: %.2f",division(num1, num2));
        break;
    default:
        printf("Error. Ingrese un valor valido.");
        }
}

 /** 6. Realizar una función que reciba un número positivo entero por parámetro por referencia, y cambie su signo a negativo.*/
int cambiarSigno(int num1){
    return -num1;
 }

 /** 7. Realizar una función que reciba dos números enteros por parámetro por referencia y cargue sus valores el usuario
        dentro de la función.*/
void cargarNumeros(int *num1, int *num2) {
    printf("Ingrese el primer numero entero: ");
    fflush(stdin);
    scanf("%i", num1);

    printf("Ingrese el segundo numero entero: ");
    fflush(stdin);
    scanf("%i", num2);
}
