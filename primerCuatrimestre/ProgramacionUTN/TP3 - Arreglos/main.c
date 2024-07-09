#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

int cantValidos(int arreglo[], int dimension);
void mostrarArreglo(int arreglo[], int validos);
int sumaArreglo(int arreglo[], int validos);
void deArregloAPila(int arreglo[], int validos, Pila *pila);
int cargarFlotantes(float arreglo[], int dimension);
float sumaArreglosFloat(float arreglo[], int validos);
void mostrarArregloFloat(float arreglo[], int validos);
int cargarChar(char arreglo[], int dimension);
int encontrarElemento(char arreglo[],int validos, char dato);
int insertarCaracterEnArregloOrdenado(char arreglo[], int validos, char dato);
void mostrarArregloChar(char arreglo[], int validos);
char maximoCaracter(char arreglo[], int validos);
int esCapicua(char arreglo[], int validos);
void invertirElementos(char arreglo[], int validos);
void insertar(int arreglo[], int inicioBusqueda, int dato);
void ordenarInsersion(int arreglo[], int validos);
int posicionMenor(int arreglo[], int inicioBusqueda, int validos);
void ordenarSeleccion(int arreglo[], int validos);
int unirArreglosOrdenado(char arreglo1[], int validos1, char arreglo2[], int validos2, char arreglo3[], int dimension3);

int main()
{
    char respuesta = 's';
    int eleccion, validos, suma, resultado, elegir;
    int valor=0;
    int i=0;
    int arreglo[5];
    int vector[5]={1,5,6,7,8};
    int nuevoVector[5];
    char arregloOrdenado[5] = {'a','c','e'};
    char arregloOrdenado2[6] = {'b','d','f'};
    char arregloOrdenado3[20];
    float validosFloat, sumaFloat;
    float arregloFloat[100];
    char validosChar, maxCaracter;
    char arregloChar[10];
    Pila pila;
    inicpila(&pila);

    do{
        printf("Que desea hacer? \n"
               "1) Cargar datos en arreglo \n"
               "2) Mostrar arreglo \n"
               "3) Suma del arreglo \n"
               "4) Pasar numeros de un arreglo a una pila \n"
               "5) Cargar, sumar y mostrar arreglo de dimensiones \n"
               "6) Encontrar elemento en arreglo de caracteres \n"
               "7) Insertar dato en arreglo ordenado \n"
               "8) Obtener el maximo caracter \n"
               "9) El arreglo es capicua? \n"
               "10) Invertir elementos \n"
               "11) Ordenar arreglo \n"
               "12) Intercalar arreglo ordenado de char \n"
               "13) Formar un nuevo vector con valor en indice de la suma de sus anteriores \n");
        fflush(stdin);
        scanf("%i", &eleccion);

        switch(eleccion){
    case 1:
        printf("Que desea hacer? \n"
               "1) Cargar datos en arreglo entero \n"
               "2) Cargar datos en arreglo char \n");
        fflush(stdin);
        scanf("%i", &elegir);
        if(elegir == 1){
           validos = cantValidos(arreglo,5);
            printf("Validos: %i \n", validos);
        }else if(elegir == 2){
            validosChar =cargarChar(arregloChar, 10);
            printf("Validos: %i \n", validosChar);
        }else{
        printf("El valor elegido no es valido \n");
        }
        break;
    case 2:
        printf("Que desea hacer? \n"
               "1) Mostrar datos en arreglo entero \n"
               "2) Mostrar datos en arreglo char \n");
        fflush(stdin);
        scanf("%i", &elegir);
        if(elegir == 1){
           mostrarArreglo(arreglo, validos);
        }else if(elegir == 2){
            mostrarArregloChar(arregloChar, validosChar);
        }else{
        printf("El valor elegido no es valido \n");
        }
        break;
    case 3:
        suma = sumaArreglo(arreglo, validos);
        printf("Suma: %i \n", suma);
        break;
    case 4:
        deArregloAPila(arreglo, validos, &pila);
        mostrar(&pila);
        break;
    case 5:
        validosFloat = cargarFlotantes(arregloFloat, 100);
        sumaFloat = sumaArreglosFloat(arregloFloat, validosFloat);
        printf("Suma: %.2f \n", sumaFloat);
        mostrarArregloFloat(arregloFloat, validosFloat);
        break;
    case 6:
        resultado = encontrarElemento(arregloChar, validosChar, 'd');
        if(resultado == 0){
            printf("Se encontro el elemento \n");
        }else{
        printf("No se encontro el elemento \n");
        }
        break;
    case 7:
        validosChar = insertarCaracterEnArregloOrdenado(arregloChar,validosChar,'e');
        printf("La nueva cantidad de validos es: %i \n", validosChar);
        break;
    case 8:
        maxCaracter = maximoCaracter(arregloChar, validosChar);
        printf("El maximo caracter es: %c \n", maxCaracter);
        break;
    case 9:
        resultado = esCapicua(arregloChar, validosChar);
        if(resultado==0){
            printf("El arreglo es capicua \n");
        }else{
        printf("El arreglo no es capicua \n");
        }
        break;
    case 10:
        invertirElementos(arregloChar, validosChar);
        printf("------Arreglo Invertido------\n");
        mostrarArregloChar(arregloChar,validosChar);
        break;
    case 11:
        printf("Que desea hacer? \n"
               "1) Ordenar por seleccion \n"
               "2) Ordenar por insersion \n");
        fflush(stdin);
        scanf("%i", &elegir);

        if(elegir == 1){
           ordenarSeleccion(arreglo, validos);
        }else if(elegir == 2){
            ordenarInsersion(arreglo,validos);
        }else{
        printf("El valor elegido no es valido \n");
        }
        break;
    case 12:
        validos = unirArreglosOrdenado(arregloOrdenado, 3, arregloOrdenado2,3, arregloOrdenado3,20);
        printf("Nuevo arreglo ordenado: \n");
        mostrarArregloChar(arregloOrdenado3, validos );
        break;
    case 13:
        /** 13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del
        contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.*/
        for(i=0;i<5;i++){
            valor+=vector[i];
            nuevoVector[i]=valor;
        }
        mostrarArreglo(nuevoVector,5);
    default:
        printf("Error, ingrese un numero valido \n");
        }
    printf("Si desea continuar presione s \n");
    fflush(stdin);
    scanf("%c", &respuesta);
    }while(respuesta == 's');

    return 0;
}


/** 1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores
al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).*/
int cantValidos(int arreglo[], int dimension){
    char respuesta = 's';
    int i=0;
    do{
        printf("Ingrese un dato: \n");
        fflush(stdin);
        scanf("%i", &arreglo[i]);

        i++;
        printf("Si quiere seguir ingresando datos presione s \n");
        fflush(stdin);
        scanf("%c", &respuesta);
    }while((respuesta == 's') && (i<dimension))
    ;
    return i;
}

int cargarChar(char arreglo[], int dimension){
    char respuesta = 's';
    int i=0;
    do{
        printf("Ingrese un dato: \n");
        fflush(stdin);
        scanf("%c", &arreglo[i]);

        i++;
        printf("Si quiere seguir ingresando datos presione s \n");
        fflush(stdin);
        scanf("%c", &respuesta);
    }while((respuesta == 's') && (i<dimension));
    return i;
}

/** 2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él
y los muestre por pantalla.*/
void mostrarArreglo(int arreglo[], int validos){
    int i=0;
    while(i<validos){
        printf(" |%i| \n", arreglo[i]);
        i++;
    }
}

void mostrarArregloChar(char arreglo[], int validos){
    int i=0;
    while(i<validos){
        printf(" |%c| \n", arreglo[i]);
        i++;
    }
}

/** 3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule
la suma de sus elementos.*/
int sumaArreglo(int arreglo[], int validos){
    int suma;
    for(int i=0; i<validos; i++){
        suma += arreglo[i];
    }
    return suma;
}

/** 4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila.
La función debe copiar los elementos del arreglo en la pila.*/
void deArregloAPila(int arreglo[], int validos, Pila *pila){
    for(int i=0; i<validos; i++){
        apilar(pila, arreglo[i]);
    }
}

/** 5. Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.
(se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)*/
int cargarFlotantes(float arreglo[], int dimension){
    char respuesta = 's';
    int i=0;
    do{
        printf("Ingrese un dato: \n");
        fflush(stdin);
        scanf("%f", &arreglo[i]);

        i++;
        printf("Si quiere seguir ingresando datos presione s \n");
        fflush(stdin);
        scanf("%c", &respuesta);
    }while((respuesta == 's') && (i<dimension))
    ;
    return i;
}

float sumaArreglosFloat(float arreglo[], int validos){
float suma;
    for(int i=0; i<validos; i++){
        suma += arreglo[i];
    }
    return suma;
}

void mostrarArregloFloat(float arreglo[], int validos){
    for(int i=0; i<validos; i++){
        printf(" |%.2f| \n", arreglo[i]);
    }
}

/** 6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.*/
int encontrarElemento(char arreglo[],int validos, char dato){
    int flag = -1;
    int i = 0;
    while(flag != 0 && i<validos){
        if(dato == arreglo[i]){
            flag = 0;
            return flag;
        }
        i++;
    }
    return -1;
}

/** 7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.*/
int insertarCaracterEnArregloOrdenado(char arreglo[], int validos, char dato){
    for(int i=0; i<=validos; i++){
        if(i=validos){
            arreglo[i]=dato;
        }
    }
    return validos+1;
}

/** 8. Realizar una función que obtenga el máximo carácter de un arreglo dado.*/
char maximoCaracter(char arreglo[], int validos){
    char max=arreglo[0];
    for(int i=0; i<validos;i++){
        if(arreglo[i]>max){
            max=arreglo[i];
        }
    }
    return max;
}

/** 9. Realizar una función que determine si un arreglo es capicúa.*/
int esCapicua(char arreglo[], int validos){
    int i=0;
    int flag=-1;
    int ultimo = validos-1;
    while(i<validos){
        if(arreglo[i]==arreglo[ultimo]){
            flag=0;
        }
        i++;
        ultimo--;
    }
    return flag;
}

/** 10. Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)*/
void invertirElementos(char arreglo[], int validos){
    int i=0;
    char aux;
    int ultimo=validos-1;
    while(i<(validos/2)){
        aux = arreglo[ultimo];
        arreglo[ultimo]=arreglo[i];
        arreglo[i]=aux;
        i++;
        ultimo--;
    }
}

/** 11. Ordenar un arreglo según los siguientes métodos:
 a. Selección
 b. Inserción*/
void ordenarSeleccion(int arreglo[], int validos){
    int posMenor;
    int aux;
    int i=0;
    while(i<validos-1){
        posMenor=posicionMenor(arreglo, i, validos);
        aux= arreglo[posMenor];
        arreglo[posMenor]=arreglo[i];
        arreglo[i]=aux;
        i++;
    }
}

int posicionMenor(int arreglo[], int inicioBusqueda, int validos){
    int menor=arreglo[inicioBusqueda];
    int posMenor= inicioBusqueda;
    int i=inicioBusqueda++;
    while(i<validos){
        if(menor>arreglo[i]){
            menor=arreglo[i];
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}

void ordenarInsersion(int arreglo[], int validos){
    int indiceActual = 0;
    while(indiceActual<validos-1){
        insertar(arreglo, indiceActual, arreglo[indiceActual+1]);
        indiceActual++;
    }
}

void insertar(int arreglo[], int inicioBusqueda, int dato){
    int i=inicioBusqueda;
    while(i>=0 && dato<arreglo[i]){
        arreglo[i+1]=arreglo[i];
        i--;
    }
    arreglo[i+1]=dato;
}

/** 12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
 los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.*/
int unirArreglosOrdenado(char arreglo1[], int validos1, char arreglo2[], int validos2, char arreglo3[], int dimension3){
     int i1=0;
     int i2=0;
     int i3=0;

     while((i1<validos1) && (i2<validos2) && (i3<dimension3)){
        if (arreglo1[i1]<arreglo2[i2]){
            arreglo3[i3]=arreglo1[i1];
            i3++;
            i1++;
        }else{
            arreglo3[i3]=arreglo2[i2];
            i3++;
            i2++;
        }
    }
    while(i1<validos1) //a partir de aca recorro los arrays por si quedaron elementos en alguna de ellas
    {
        arreglo3[i3]=arreglo1[i1];
        i3++;
        i1++;
    }
    while(i2<validos2){
        arreglo3[i3]=arreglo2[i2];
        i3++;
        i2++;
    }
return i3;
}





