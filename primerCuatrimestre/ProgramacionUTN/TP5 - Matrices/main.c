#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int fila = 3;
const int col = 3;
const int filaS = 5;
const int colS = 5;
const int num = 5;
void cargarMatriz(int matriz[fila][col]);
void mostrarMatriz(int matriz[fila][col]);
void cargarMatrizAleatorio(int matriz[fila][col]);
int sumaMatriz(int matriz[fila][col]);
float promedioMatriz(int matriz[fila][col]);
int encontrarElemento(int matriz[fila][col], int num);
int cargarMatrizStrings(char matriz[filaS][colS]);
void mostrarMatrizString(char matriz[][colS], int cant);
int encontrarElementoString(char matriz[][colS], int cant, char palabra[]);
int encontrarElementoStringOrdenado(char matriz[][colS], int cant, char palabra[]);
void ordenarAlfabeticamente(char arreglo[][colS], int cant);

/*
int main()
{
    int eleccion, suma, resultado, cantidad ;
    char respuesta;
    char palabra[5]= {"hola"};
    char palabras[5][5] = {"pez", "gato", "loro", "leon"};
    int matriz[fila][col];
    char matrizStrings[filaS][colS];
    float promedio;

    do{
        printf("Que desea hacer? \n"
                "1) Cargar matriz \n"
                "2) Mostrar matriz \n"
                "3) Cargar una matriz con valores aleatorios \n"
                "4) Suma del contenido de una matriz \n"
                "5) Promedio del contenido de una matriz \n"
                "6) Encontrar elemento en una matriz \n"
                "7) Cargar matriz de palabras \n"
                "8) Mostrar matriz de palabras \n"
                "9) Encontrar elemento en matriz de palabras \n"
                "10) Encontrar elemento en matriz de palabras ordenadas \n"
                "11) Ordenar matriz alfabeticamente \n");
        fflush(stdin);
        scanf("%i", &eleccion);

    switch(eleccion){
    case 1:
        cargarMatriz(matriz);
        break;
    case 2:
        mostrarMatriz(matriz);
        break;
    case 3:
        cargarMatrizAleatorio(matriz);
        break;
    case 4:
        suma = sumaMatriz(matriz);
        printf("La suma de la matriz es: %i \n", suma);
        break;
    case 5:
        promedio = promedioMatriz(matriz);
        printf("El promedio de la matriz es: %.2f \n", promedio);
        break;
    case 6:
        resultado = encontrarElemento(matriz, num);
        if(resultado == 0){
            printf("El numero se encuentra en la matriz \n");
        }else{
        printf("El numero no se encuentra en la matriz \n");
        }
        break;
    case 7:
        cantidad = cargarMatrizStrings(matrizStrings);
        printf("Se cargaron %i palabras \n", cantidad);
        break;
    case 8:
        mostrarMatrizString(matrizStrings, cantidad);
        break;
    case 9:
        resultado = encontrarElementoString(matrizStrings, cantidad, palabra);
        if(resultado == -1){
        printf("La palabra no se encuentra en la matriz \n");
        }else{
        printf("La palabra se encuentra en el indice: %i \n", resultado);
        }
        break;
    case 10:
        resultado = encontrarElementoStringOrdenado(matrizStrings, cantidad, palabra);
        if(resultado == -1){
        printf("La palabra no se encuentra en la matriz \n");
        }else{
        printf("La palabra se encuentra en el indice: %i \n", resultado);
        }
        break;
    case 11:
        ordenarAlfabeticamente(palabras, 5);
        mostrarMatrizString(palabras, 5);
        break;
    default:
        printf("Por favor ingrese un valor valido \n");
    }

    printf("Desea seguir? Si es asi, ingrese s \n");
    fflush(stdin);
    scanf("%c", &respuesta);
    }while(respuesta == 's');

    return 0;
}*/

/** 1. Hacer una función que reciba como parámetro una matriz de números enteros y permita que el usuario ingrese valores al
mismo por teclado. La función debe cargar la matriz por completo.*/
void cargarMatriz(int matriz[fila][col]){
    for(int i=0; i<fila; i++){
        for(int j=0; j<col;j++){
            printf("Cargue un dato: \n");
            fflush(stdin);
            scanf("%i", &matriz[i][j]);
        }
    }
}

/** 2. Hacer una función que reciba como parámetro una matriz de números enteros y la muestre por pantalla (en formato matricial). */
void mostrarMatriz(int matriz[fila][col]){
    for(int i=0; i<fila; i++){
        for(int j=0; j<col; j++){
            printf(" |%i| ", matriz[i][j]);
        }
        printf("\n");
    }
}

/**  3. Hacer una función que reciba como parámetro una matriz de números enteros y que cargue la misma con números aleatorios
(sin intervención del usuario). La función debe cargar la matriz por completo.*/
void cargarMatrizAleatorio(int matriz[fila][col]){
    srand(time(NULL));
    for(int i=0; i<fila; i++){
        for(int j=0; j<col;j++){
            matriz[i][j] = rand()%101;
        }
    }
}

/**  4. Hacer una función tipo int que sume el contenido total de una matriz de números enteros.*/
int sumaMatriz(int matriz[fila][col]){
    int suma =0;
    for(int i=0; i<fila;i++){
        for(int j=0; j<col;j++){
            suma += matriz[i][j];
        }
    }
    return suma;
}

/** 5. Hacer una función tipo float que calcule el promedio de una matriz de números enteros.*/
float promedioMatriz(int matriz[fila][col]){
    float promedio;
    int suma = sumaMatriz(matriz);
    promedio = suma/(fila*col);
    return promedio;
}

/**  6. Hacer una función que determine si un elemento se encuentra dentro de una matriz de números enteros.
La función recibe la matriz y el dato a buscar.*/
int encontrarElemento(int matriz[fila][col], int num){
    int flag = -1;
    for(int i=0; i<fila; i++){
        for(int j=0; j<col; j++){
            if(matriz[i][j] == num){
                flag=0;
            }
        }
    }
    return flag;
}

/**  7. Hacer una función que cargue un arreglo de palabras (strings). La función debe retornar cuantas palabras se cargaron.
(puede ser a través del parámetro como puntero)*/
int cargarMatrizStrings(char matriz[filaS][colS]){
    char eleccion = 's';
    int i=0;
    while( i<fila && eleccion == 's'){
        printf("Ingrese una palabra \n");
        fflush(stdin);
        scanf("%s",matriz[i]);
        i++;

        printf("Desea seguir cargando? Si es asi, presione s \n");
        fflush(stdin);
        scanf("%c", &eleccion);
    }
    return i;
}

/**  8. Hacer una función que muestre un arreglo de palabras.*/
void mostrarMatrizString(char matriz[][colS], int cant){
    for(int i=0; i<cant;i++){
        printf(" %s  \n", matriz[i]);
    }
}

/**  9. Hacer una función que determine si un string se encuentra dentro de un arreglo de strings. La función recibe el arreglo,
la cantidad de palabras que contiene y la palabra a buscar. ///devuelve el índice de la fila en que se encuentra,
de lo contrario retorna-1*/
int encontrarElementoString(char matriz[][colS], int cant, char palabra[]){
    int resultado;
    for(int i=0; i<cant; i++){
        resultado = strcmp(matriz[i], palabra);
    if(resultado==0){
        return i;
    }
    }
    return -1;
}

/**  10. Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado alfabéticamente.
La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar. ///devuelve el índice de la fila en
que se encuentra, de lo contrario retorna-1*/
int encontrarElementoStringOrdenado(char matriz[][colS], int cant, char palabra[]) {
    int inicio = 0;
    int fin = cant - 1;
    int medio;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        int comparacion = strcmp(matriz[medio], palabra);

        if (comparacion == 0) {
            return medio;
        } else if (comparacion < 0) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}


/**  11.Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético.*/
void ordenarAlfabeticamente(char arreglo[][colS], int cant) {
    int i, j;
    char clave[50];

    for (i = 1; i < cant; i++) {
        strcpy(clave, arreglo[i]);
        j = i - 1;

        // Desplaza los elementos mayores que la clave hacia adelante
        while (j >= 0 && strcmp(arreglo[j], clave) > 0) {
            strcpy(arreglo[j + 1], arreglo[j]);
            j = j - 1;
        }
        strcpy(arreglo[j + 1], clave);
    }
}

/** 14. Los resultados de las últimas elecciones a Intendente en el pueblo “La Matrix” han sido los siguientes:
 Distrito       Candidato A     Candidato B     Candidato C     Candidato D
 1                 194               48             206              45
 2                 180               20             320              16
 3                 221               90             140              20
 4                 432               51             821              14
 5                 820               61             946              18
 Escribir un programa que haga las siguientes tareas:
 a. Imprimir la tabla anterior con cabeceras incluidas.

 b. Calcular e imprimir el número total de votos recibidos por cada candidato y el porcentaje total de votos emitidos.
 Así mismo, visualizar el candidato más votado.

 c. Si algún candidato recibe más del 50% de los votos, el programa imprimirá un mensaje declarándolo ganador.
 d. Si algún candidato recibe menos del 50% de los votos, el programa debe imprimir el nombre de los dos candidatos más votados
 que serán los que pasen a la segunda ronda de las elecciones.*/
/* Distrito       Candidato A     Candidato B     Candidato C     Candidato D
 1                 194               48             206              45
 2                 180               20             320              16
 3                 221               90             140              20
 4                 432               51             821              14
 5                 820               61             946              18*/
int main()
{
    int puebloMatrix[5][5];
    int arrayVotos[25]={1,2,3,4,5,194,180,221,432,820,48,20,90,51,61,206,320,140,821,946,45,16,20,14,18};
    int a=0;

    for(int i=0;i<5;i++){
        for(int j=0; j<5;j++){
            puebloMatrix[j][i]=arrayVotos[a];
            a++;
        }
    }

    /**a. Imprimir la tabla anterior con cabeceras incluidas.*/

    printf("Distrito     Candidato A     Candidato B     Candidato C     Candidato D \n");
    for(int i=0;i<5;i++){
        for(int j=0; j<5;j++){
            printf("    %i        ", puebloMatrix[i][j]);
        }
        printf("\n");
    }
    /**b. Calcular e imprimir el número total de votos recibidos por cada candidato y el porcentaje total de votos emitidos.
    Así mismo, visualizar el candidato más votado.  */
    int suma;
    float porcentaje;
    int votosA=0;
    int votosB=0;
    int votosC=0;
    int votosD=0;
    for(int i=1; i<5; i++){
        for(int j=0; j<5; j++){
            if(i==1){
                votosA+=puebloMatrix[j][i];
            }else if(i==2){
                votosB+=puebloMatrix[j][i];
            }else if(i==3){
                votosC+=puebloMatrix[j][i];
            }else{
                votosD+=puebloMatrix[j][i];
            }
        }
    }
    int total= votosA+votosB+votosC+votosD;

    printf("\n-----------------Votos por candidato-----------------\n");
    printf("Los votos al candidato A son: %i \n", votosA);
    printf("Los votos al candidato B son: %i \n", votosB);
    printf("Los votos al candidato C son: %i \n", votosC);
    printf("Los votos al candidato D son: %i \n", votosD);

    float porcentajeA=(votosA*100)/total;
    float porcentajeB=(votosB*100)/total;
    float porcentajeC=(votosC*100)/total;
    float porcentajeD=(votosD*100)/total;

    printf("\n-----------------Porcentaje de votos por candidato-----------------\n");
    printf("El candidato A recibio %.2f %c \n", porcentajeA,37);
    printf("El candidato B recibio %.2f %c \n", porcentajeB,37);
    printf("El candidato C recibio %.2f %c \n", porcentajeC,37);
    printf("El candidato D recibio %.2f %c \n", porcentajeD,37);

    printf("\n-----------------Candidato con mas votos-----------------\n");
    char ganador[20];
    if(votosA>votosB && votosA>votosC && votosA>votosD){
        strcpy(ganador,"Candidato A");
    }else if(votosB>votosA && votosB>votosC && votosB>votosD){
        strcpy(ganador,"Candidato B");
    }else if(votosC>votosA && votosC>votosB && votosC>votosD){
        strcpy(ganador,"Candidato C");
    }else{
        strcpy(ganador,"Candidato D");
    }

    printf("Felicidades al %s \n", ganador);

    /** c. Si algún candidato recibe más del 50% de los votos, el programa imprimirá un mensaje declarándolo ganador.*/
        printf("\n-----------------Candidato con mas porcentaje-----------------\n");
    if(porcentajeA>50){
        printf("Felicidades al Candidato A que gano con un %.2f %c \n", porcentajeA,37);
    }else if(porcentajeB>50){
        printf("Felicidades al Candidato B que gano con un %.2f %c \n", porcentajeB,37);
    }else if(porcentajeC>50){
        printf("Felicidades al Candidato C que gano con un %.2f %c \n", porcentajeC,37);
    }else{
        printf("Felicidades al Candidato D que gano con un %.2f %c \n", porcentajeD,37);
    }
    char segundo[20];
    char tercero[20];
    char cuarto[20];
    /** d. Si algún candidato recibe menos del 50% de los votos, el programa debe imprimir el nombre de los dos candidatos más
    votados que serán los que pasen a la segunda ronda de las elecciones. */
        if(votosA<votosB && votosA<votosC && votosA<votosD ){
        strcpy(cuarto,"Candidato A");
    }else if(votosB<votosA && votosB<votosC && votosB<votosD){
        strcpy(cuarto,"Candidato B");
    }else if(votosC<votosA && votosC<votosB && votosC<votosD){
        strcpy(cuarto,"Candidato C");
    }else{
        strcpy(cuarto,"Candidato D");
    }


    if(strcmp("Candidato A", ganador)!=0 && strcmp("Candidato A", cuarto)!=0){
        printf("Candidato A pasa a la siguiente ronda! \n");
    }
        if(strcmp("Candidato B", ganador)!=0 && strcmp("Candidato B", cuarto)!=0){
        printf("Candidato B pasa a la siguiente ronda! \n");
    }
        if(strcmp("Candidato C", ganador)!=0 && strcmp("Candidato C", cuarto)!=0){
        printf("Candidato C pasa a la siguiente ronda! \n");
    }
        if(strcmp("Candidato D", ganador)!=0 && strcmp("Candidato D", cuarto)!=0){
        printf("Candidato D pasa a la siguiente ronda! \n");
    }
    return 0;
}


