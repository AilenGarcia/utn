#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

// Ailen Rocio Garcia

const int fila=3;
const int col=3;
const int filaC=10;
const int colC=10;

int cargarPilaYArreglo(Pila *pila,int arreglo[]);
int esCapicua(int arreglo[], int validos);
int pasarElementosAUnArreglo(Pila *pila, int arreglo[]);
void mostrarArreglo(int arreglo[],int validos);
int sumaMatriz(int matriz[fila][col]);
int buscarPalabra(char matriz[filaC][colC],int validosMatriz, char palabra[]);

int main()
{
    char respuesta;
    int eleccion,validosArreglo, resultado, suma;
    int arreglo[20];
    int arregloDim10[10];
    int arregloCapicua[4]= {1,2,2,1};
    int validosCapicua=4;
    int matriz[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int validosChar=6;
    char matrizChar[10][10]= {"elefante","perro","elefante", "gato", "loro", "elefante"};
    char palabra[10]="elefante";

    Pila pila;
    inicpila(&pila);


    do
    {
        printf("Que desea hacer? \n"
               "1) Cargar pila y arreglo (pares en pila, impares en arreglo) \n"
               "2) Es capicua el arreglo? \n"
               "3) Pasar elementos de una pila a un arreglo \n"
               "4) Suma de elementos pares de una matriz \n"
               "5) Encontrar cuantas veces esta una palabra en una matriz \n");
        fflush(stdin);
        scanf("%i",&eleccion);

        switch(eleccion)
        {
        case 1:
            validosArreglo = cargarPilaYArreglo(&pila, arreglo);
            printf("Hay %i validos en el arreglo \n", validosArreglo);
            break;
        case 2:
            resultado = esCapicua(arregloCapicua, validosCapicua);
            if(resultado == 0)
            {
                printf("El arreglo es capicua \n");
            }
            else
            {
                printf("El arreglo no es capicua \n");
            }
            break;
        case 3:
            resultado = pasarElementosAUnArreglo(&pila, arregloDim10);

            if(resultado == 0)
            {
                printf("La pila tenia menos de 10 elementos \n");
            }
            else
            {
                printf("La pila tenia mas de 10 elementos \n");
            }
            break;
        case 4:
            suma = sumaMatriz(matriz);
            printf("El resultado de la suma de la matriz es %i \n", suma);
            break;
        case 5:
            resultado = buscarPalabra(matrizChar, validosChar, palabra);
            printf("Se encontro la palabra deseada %i veces \n", resultado);
            break;
        default:
            printf("Elija una opcion valida. \n");
            break;
        }

        printf("Si desea continuar presione s. \n");
        fflush(stdin);
        scanf("%c", &respuesta);

    }
    while(respuesta == 's');

    return 0;
}

/** 1. Hacer una función de tipo entero que permita al usuario cargar tantos valores como él desee para agregar en una pila
(usar punteros), pero solo agregaremos a la misma los números que sean pares. Aquellos que sean impares, deberán ser cargados
en un arreglo que se recibirá por parámetro. La función debe ir contando la cantidad de elementos que se cargan en el arreglo
y debe retornarlo.*/
int cargarPilaYArreglo(Pila *pila,int arreglo[])
{
    int cant, valor;
    int j=0;

    printf("Cuantos elementos desea ingresar? \n");
    fflush(stdin);
    scanf("%i", &cant);

    for(int i=0; i<cant; i++)
    {
        printf("Ingrese un valor: ");
        fflush(stdin);
        scanf("%i", &valor);

        if((valor%2) == 0)
        {
            apilar(pila, valor);
        }
        else
        {
            arreglo[j]= valor;
            j++;
        }
    }
    return j;
}

/** 2. Hacer una función que reciba un arreglo de tipo int por parámetro y determine si el mismo es capicúa.
(Si, el mismo ejercicio del módulo 😉​)*/
int esCapicua(int arreglo[], int validos)
{
    int ultimo = validos-1;
    int flag = 0;

    for(int i=0; i<(validos/2) && flag ==0; i++)
    {
        if(arreglo[i] != arreglo[ultimo])
        {
            flag=-1;
        }
        ultimo--;
    }
    return flag;
}

/** 3. Hacer una función que copie los primeros 10 elementos de una Pila cargada (por referencia) a un arreglo vacío.
En caso de que la Pila tenga menos de 10 elementos, deberá pasar al arreglo la totalidad de los elementos que contenga.
La función deberá retornar un 1 si tenía más de 10 elementos o un 0 si tenía menos. La pila no debe sufrir modificaciones. */
int pasarElementosAUnArreglo(Pila *pila, int arreglo[])
{
    int flag = 0;
    int i=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila) && i<10)
    {
        arreglo[i] = desapilar(pila);
        i++;
    }

    for(int j=0; j<i; j++)
    {
        apilar(&aux, arreglo[j]);
    }

    for(int j=0; j<i; j++)
    {
        apilar(pila, desapilar(&aux));
    }

    if(i>9)
    {
        flag=1;
    }

    return flag;
}

/**4. Hacer una función que reciba una matriz de tipo int previamente cargada, y retorne la suma de todos sus elementos pares.*/
int sumaMatriz(int matriz[fila][col])
{
    int suma;

    for(int i=0; i<fila; i++)
    {
        for(int j=0; j<col; j++)
        {
            if((matriz[i][j])%2 == 0 )
            {
                suma += matriz[i][j];
            }
        }
    }

    return suma;
}

/** 5. Hacer una función que reciba una matriz de tipo char previamente cargada, y una palabra elegida por el usuario.
La función deberá retornar la cantidad de veces que dicha palabra se encuentre dentro de la matriz.*/

int buscarPalabra(char matriz[filaC][colC],int validosMatriz, char palabra[])
{
    int i=0;
    int acc=0;

    while(i<validosMatriz)
    {
        if(strcmp(matriz[i], palabra)==0)
        {
            acc++;
        }
        i++;
    }
    return acc;
}




void mostrarArreglo(int arreglo[],int validos)
{

    for(int i=0; i<validos; i++)
    {
        printf("  | %i |  ", arreglo[i]);
    }
    printf("\n");
}

