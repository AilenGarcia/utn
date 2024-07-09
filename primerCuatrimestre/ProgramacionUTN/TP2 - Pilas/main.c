#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

void cargarPila(Pila *pila);
void pasarEntrePilas(Pila *pila1,Pila *pila2);
void pasarEntrePilasConOrden(Pila *pila1, Pila *pila2);
int eliminarMenorNumero(Pila *pila);
void ordenarPorSeleccionPuntero (Pila *pilaOrigen, Pila *pilaDestino);
void insertarEnPilaOrdenada(Pila *pila, Pila *dato);
Pila ordenarPorInsercion(Pila pila);
int sumaDeUltimosEnPila(Pila *pila);
int suma(Pila pila);
int cantNumeros(Pila pila);
float dividir (int suma, int cantidad);
float promedio(Pila pila);
int transformarPilaEnDecimal(Pila pila);
void mostrarPila(Pila pila);
void leerPorTeclado(Pila *pila);

int main()
{
    char respuesta;
    int eleccion, resultado;
    float prom;
    Pila dato;
    inicpila(&dato);
    apilar(&dato, 3);
    Pila pila;
    Pila pila2;
    Pila pila3;
    inicpila(&pila);
    inicpila(&pila2);
    inicpila(&pila3);

    do {
    printf("Que desea hacer? \n"
    "1) Cargar Pila \n"
    "2) Pasar el contenido de una pila a otra \n"
    "3) Pasar el contenido de una pila a otra conservando el orden \n"
    "4) Eliminar el menor numero \n"
    "5) Generar nueva pila ordenada \n"
    "6) Agregar numero en pila ordenada \n"
    "7) Ordenar por insersion \n"
    "8) Sumar ultimos contenidos de una pila \n"
    "9) Sacar promedio de una pila \n"
    "10) Transformar de pila a numero \n"
    "11) Cargar Pila (sin leer()) \n"
    "12) Mostrar Pila (sin mostrar()) \n");
    fflush(stdin);
    scanf("%i", &eleccion);

    switch(eleccion){
    case 1:
        cargarPila(&pila);
        mostrar(&pila);
        break;
    case 2:
        pasarEntrePilas(&pila, &pila2);
        printf("Pila 2: \n");
        mostrar(&pila2);
        break;
    case 3:
        pasarEntrePilasConOrden(&pila, &pila2);
        printf("Pila 2: \n");
        mostrar(&pila2);
    case 4:
        eliminarMenorNumero(&pila);
        mostrar(&pila);
        break;
    case 5:
        ordenarPorSeleccionPuntero(&pila, &pila2);
        mostrar(&pila2);
        break;
    case 6:
        insertarEnPilaOrdenada(&pila, &dato);
        mostrar(&pila);
        break;
    case 7:
        pila3 = ordenarPorInsercion(pila);
        mostrar(&pila3);
        break;
    case 8:
        resultado = sumaDeUltimosEnPila(&pila);
        printf("La suma del ultimo y anteultimo numero de la pila es: %i \n", resultado);
        break;
    case 9:
        prom = promedio(pila);
        printf("El promedio de la pila es: %.2f \n", prom);
        break;
    case 10:
        resultado = transformarPilaEnDecimal(pila);
        printf("El numero resultante es: %i \n", resultado);
        break;
    case 11:
        leerPorTeclado(&pila);
        break;
    case 12:
        mostrarPila(pila);
        break;
    default:
        printf("Error, elija un numero valido.");
    }

    printf("\n Quiere seguir? presione s si quiere seguir\n");
    fflush(stdin);
    scanf("%c", &respuesta);
    } while (respuesta == 's');

    return 0;
}

/** 1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.*/
void cargarPila(Pila *pila){
    int eleccion;

    printf("Cuantos elementos desea ingresar? \n");
    fflush(stdin);
    scanf("%i", &eleccion);

    for(int i=0; i<eleccion; i++){
        leer(pila);
    }
}

/**  2. Hacer una función que pase todos los elementos de una pila a otra. */
void pasarEntrePilas(Pila *pila1, Pila *pila2){
    while(!pilavacia(pila1)){
    apilar(pila2, desapilar(pila1));
    }
}

/** 3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.*/
void pasarEntrePilasConOrden(Pila *pila1, Pila *pila2){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pila1)){
    apilar(&aux, desapilar(pila1));
    }
    while(!pilavacia(&aux)){
    apilar(pila2, desapilar(&aux));
    }
}

/** 4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila. */
int eliminarMenorNumero(Pila *pila){
    Pila menor;
    inicpila(&menor);
    Pila descarte;
    inicpila(&descarte);

    if (!pilavacia(pila))
        apilar(&menor, desapilar(pila));
    while (!pilavacia(pila))
    {
        if (tope(pila) < tope(&menor))
        {
          apilar(&descarte, desapilar(&menor));
          apilar(&menor, desapilar(pila));
        }
        else
        {
          apilar(&descarte, desapilar(pila));
        }
    }
    while (!pilavacia(&descarte))
    {
        apilar(pila, desapilar(&descarte));
    }
    return tope(&menor);
}

/**  5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
Usar la función del ejercicio 4. (Ordenamiento por selección)*/
void ordenarPorSeleccionPuntero (Pila *pilaOrigen, Pila *pilaDestino){
    while (!pilavacia(pilaOrigen))
    {
         apilar(pilaDestino, eliminarMenorNumero(pilaOrigen));
    }
}

/** 6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.*/
void insertarEnPilaOrdenada(Pila *pila, Pila *dato){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pila) && tope(pila)>tope(dato)){
        apilar(&aux, desapilar(pila));
    }
    apilar(&aux, desapilar(dato));
    while(!pilavacia(&aux)){
        apilar(pila, desapilar(&aux));
    }
}

/**  7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
Usar la función del ejercicio 6. (Ordenamiento por inserción)*/
Pila ordenarPorInsercion(Pila pila){
    Pila ordenada;
    inicpila(&ordenada);
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&pila)){
        insertarEnPilaOrdenada(&ordenada, &pila);
    }

    return ordenada;
}

/**  8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma, sin alterar
el contenido de la pila.*/
int sumaDeUltimosEnPila(Pila *pila){
    Pila aux;
    inicpila(&aux);

    int suma=0;
    for(int i=0; i<4;i++){
        if(i<2){
            suma += tope(pila);
            apilar(&aux, desapilar(pila));
        }else{
        apilar(pila, &aux);
        }
    }
    return suma;
}

/** 9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule
la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca
a las otras 3.*/
int suma(Pila pila){
int num;
int suma =0;
while(!pilavacia(&pila)){
    num = desapilar(&pila);
    suma += num;
}
return suma;
}

int cantNumeros(Pila pila){
    int acc =0;
    while(!pilavacia(&pila)){
        desapilar(&pila);
        acc ++;
    }
    return acc;
}

float dividir (int suma, int cantidad){
    float result = (float)suma / (float) cantidad;
return result;
}

float promedio(Pila pila){
int s = suma(pila);
int c = cantNumeros(pila);
float promedio = dividir(s, c);
return promedio;
}

/** 10. Hacer una función que reciba una pila con números de un solo dígito y que transforme esos dígitos en un número decimal. */
int transformarPilaEnDecimal(Pila pila){
    Pila aux;
    inicpila(&aux);
    int numero=0;
        while (!pilavacia(&pila)){
        apilar (&aux, desapilar(&pila));
    }

    while (!pilavacia(&aux))
    {
        numero= (numero * 10) + tope(&aux);
        apilar (&pila, desapilar(&aux));
    }
    return numero;
}

/** EXTRAS */
/** ● Realizar una función que cargue la pila sin utilizar la función leer.*/
void leerPorTeclado(Pila *pila){
    int valor;
    char continuar='s';
    while (continuar=='s')
    {
        printf("Ingrese un numero\n ");
        scanf("%d",&valor);
        apilar(pila,valor);

        printf("desea continuar s/n\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
}

/** ● Realizar una función que muestre la pila sin utilizar la función mostrar.*/
void mostrarPila(Pila pila){
    Pila aux;
    inicpila(&aux);
    printf("\nBase----------------------Tope\n");
    while(!pilavacia(&pila))
        apilar(&aux,desapilar(&pila));
    while(!pilavacia(&aux))
        printf(" %d ",desapilar(&aux));

    printf("\nBase----------------------Tope\n");
}






