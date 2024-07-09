#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pila.h"

// Ailen Rocio Garcia

const int fila=3;
const int col=3;
const int filaC=5;
const int colC=10;

void cargarPila(Pila *pila);
int cargarArregloDeImpares(int arreglo[], int dim, Pila pila);
void mostrarArreglo(int arreglo[], int validos);
int menorDeUnArreglo(int arreglo[], int validos);
void cargarMatriz(int matriz[fila][col]);
void mostrarMatriz(int matriz[fila][col]);
int posicionArray();
int buscarPorPosicionArray(int arreglo[]);
void mostrarPila(Pila pila);
float promedioDeMatriz(int matriz[fila][col]);
void cargarMatrizChar(char matriz[filaC][colC]);
void mostrarMatrizChar(char matriz[filaC][colC]);
int buscarPalabra(char matriz[filaC][colC], char palabra[]);

int main()
{
    char respuesta;
    char matrizChar[filaC][colC];
    int eleccion;
    int arreglo[20];
    int dimension =20;
    int validos;
    int menor;
    int matriz[fila][col];
    int valor;
    int resultado;
    float promedio;
    Pila pila;
    inicpila(&pila);

    do{
        printf("Que desea hacer? \n"
           "1) Cargar pila \n"
           "2) Cargar en arreglo contenido impar de una pila \n"
           "3) Capturar y mostrar el menor de un arreglo \n"
           "4) Cargar y mostrar matriz de enteros de 3x3 \n"
           "5) Mostrar valor en posicion de arreglo \n"
           "6) Mostrar pila sin usar mostrar()\n"
           "7) Promedio de una matriz de enteros \n"
           "8) Cargar matriz de char \n"
           "9) Buscar palabra en matriz \n");
    fflush(stdin);
    scanf("%i", &eleccion);

        switch(eleccion){
    case 1:
        cargarPila(&pila);
        break;
    case 2:
        validos = cargarArregloDeImpares(arreglo, dimension, pila);
        mostrarArreglo(arreglo, validos);
        break;
    case 3:
        menor = menorDeUnArreglo(arreglo, validos);
        printf("El numero menor del arreglo es: %i \n", menor);
        break;
    case 4:
        cargarMatriz(matriz);
        mostrarMatriz(matriz);
        break;
    case 5:
        valor = buscarPorPosicionArray(arreglo);
        printf("El valor en la posicion elegida es: %i \n", valor);
        break;
    case 6:
        mostrarPila(pila);
        break;
    case 7:
        promedio = promedioDeMatriz(matriz);
        printf("El promedio de la matriz es: %f \n", promedio);
        break;
    case 8:
        cargarMatrizChar(matrizChar);
        mostrarMatrizChar(matrizChar);
        break;
    case 9:
        resultado = buscarPalabra(matrizChar,"elefante");
        if(resultado==0){
            printf("La palabra se encuentra en la matriz \n");
        }else{
        printf("La palabra no se encuentra en la matriz \n");
        }
        break;
    default:
        printf("Error. Elija un valor valido (1-9) \n");
        }

    printf("Si desea continuar presione s \n");
    fflush(stdin);
    scanf("%c", &respuesta);

    }while(respuesta=='s');


    return 0;
}

/**1-Hacer una función que cargue una pila de números enteros mientras el usuario así lo desea. La pila se envía por parámetro.*/
void cargarPila(Pila *pila){
    int cant;
    int i=0;

    printf("Cuantos elementos desea cargar? \n");
    fflush(stdin);
    scanf("%i", &cant);

    while(i<cant){
        leer(pila);
        i++;
    }
}

/**2-Copiar los elementos impares de la pila a un arreglo. Dicho arreglo es de dimensión 20. La pila no debe sufrir modificaciones.*/
int cargarArregloDeImpares(int arreglo[], int dim, Pila pila){
    int valor;
    int i=0;
    while(!pilavacia(&pila)){
        valor = desapilar(&pila);
        if(valor%2 != 0){
            arreglo[i] = valor;
            i++;
        }
    }
    return i;
}

void mostrarArreglo(int arreglo[], int validos){
    for(int i=0; i<validos; i++){
        printf(" | %i | ", arreglo[i]);
    }
    printf("\n");
}

/**3-Buscar y retornar el menor elemento de un arreglo de enteros. */
int menorDeUnArreglo(int arreglo[], int validos){
    int menor = arreglo[0];
    for(int i=0; i<validos;i++){
        if(menor>arreglo[i]){
            menor=arreglo[i];
        }
    }
    return menor;
}

/**4-Realizar una función que cargue una matriz de tipo int 3 filas y 3 columnas.
Luego, realizar otra función que muestre una matriz de enteros.*/
void cargarMatriz(int matriz[fila][col]){
    for(int i=0; i<fila; i++){
        for(int j=0; j<col; j++){
            printf("Ingrese valor: ");
            fflush(stdin);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[fila][col]){
    for(int i=0; i<fila; i++){
        for(int j=0; j<col; j++){
            printf("  %i  ", matriz[i][j]);
        }
        printf("\n");
    }
}

/**5-Realizar dos funciones para: a) Pedirle al usuario una posición del arreglo (realizar validaciones) y
b) Mostrar una posición determinada del arreglo.        La función b debe invocar a la función a.*/
int posicionArray(){
    int posicion;

    printf("Ingrese posicion a buscar: ");
    fflush(stdin);
    scanf("%i", &posicion);

    return posicion;
}

int buscarPorPosicionArray(int arreglo[]){
    int posicion = posicionArray();
    return arreglo[posicion];
}

/**6-Realizar una función para mostrar una pila, sin invocar a la función mostrar(&pila). No utilizar arreglos. */
void mostrarPila(Pila pila){
    int valor;
    printf("\n Base .................................................. Tope \n \n");
    while(!pilavacia(&pila)){
        valor = desapilar(&pila);
        printf(" | %i | ", valor);
    }
    printf("\n \n Base .................................................. Tope \n");
}

/**7-Realizar una función que calcule y retorne el promedio de una matriz de enteros.*/
float promedioDeMatriz(int matriz[fila][col]){
    int suma = 0;
    float promedio;
        for(int i=0; i<fila; i++){
            for(int j=0; j<col; j++){
                suma += matriz[i][j];
            }
        }
    promedio = (float) suma/ (float) (fila*col);
    return promedio;
}

/**8-Realizar una función que cargue una matriz de tipo char. La misma debe ser de 5 filas y 10 columnas.*/
void cargarMatrizChar(char matriz[filaC][colC]){
    int i=0;
    while(i<filaC){
        printf("Ingrese una palabra: ");
        fflush(stdin);
        gets(matriz[i]);
        i++;
    }
}

void mostrarMatrizChar(char matriz[filaC][colC]){
    int i=0;
    while(i<filaC){
        printf("%s  \n", matriz[i]);
        i++;
    }
}

/**9-Realizar una función que reciba por parámetro una matriz de tipo char previamente cargada, y
una palabra elegida por el usuario. La función deberá indicar si la palabra elegida se encuentra cargada dentro de la matriz. */
int buscarPalabra(char matriz[filaC][colC], char palabra[]){
    int i=0;
    int resultado;
    while(i<filaC){
        resultado= strcmp(palabra, matriz[i]);
        if(resultado == 0){
            return 0;
        }
        i++;
    }
    return -1;
}



/**10-Realizar una función main() que invoque a las funciones anteriores y demuestre el funcionamiento del programa.
       Para esto, cree las variables que considere necesarias, carguelas con datos y muestre cada resultado.*/




