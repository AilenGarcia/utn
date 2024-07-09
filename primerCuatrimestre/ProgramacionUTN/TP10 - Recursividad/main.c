#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int x);
int potencia(int x, int y);
void mostrarArreglo(int array[], int validos, int i);
void mostrarArregloInvertido(int array[], int validos, int i);
int esCapicua(int array[], int validos, int i);
int sumaRecursiva(int array[], int validos, int i);
int esMenor(int array[], int validos, int i);
void mostrarArchivoNumeros(char numeros[]);
void cargarArchivoEnteros(char numeros[], int array[], int validos);
int buscarMenorArchivoRecurs (FILE* archi);
int buscarMenorArchivo(char numeros[]);
void invertirArchivoRecur(FILE *archi, int cant, int pos);
void invertirArchivo(char numeros[]);
int cantRegistros(FILE *archi);
void mostrarArchivoInvertidoRecur(FILE *archi);
void mostrarArchivoInvertido(char numeros[]);
void mostrarPalabrasInver();
int encontrarElemento(int array[], int validos, int pos, int numero);

int main()
{
    char archivoNumeros[20];
    strcpy(archivoNumeros, "numeros.bin");
    int resultado;
    int arrayNumeros[10]={1,2,3,3,2,1};
    int arrayMenor[10]={5,2,1,4,2,6};
    int validos=6;
    int i =0;

    //resultado = factorial(5);
    //printf("El factorial de %i es %i",5, resultado);

    //resultado = potencia(5,5);
    //printf("La potencia de %i es %i",5, resultado);

    //mostrarArreglo(arrayNumeros,validos, i);

    //mostrarArregloInvertido(arrayNumeros,validos, i);

    //resultado = esCapicua(arrayNumeros, validos, i);
    //if(resultado == -1){
    //    printf("No es capicua \n");
    //}else{
    //    printf("Es capicua \n");
    //}

    //resultado = sumaRecursiva(arrayNumeros, validos, i);
    //printf("El resultado de la suma es %i \n", resultado);

    //resultado = esMenor(arrayMenor, validos, i);
    //printf("El menor es %i \n", resultado);

    //cargarArchivoEnteros(archivoNumeros, arrayMenor, validos);
    //mostrarArchivoNumeros(archivoNumeros);

    //resultado = buscarMenorArchivo(archivoNumeros);
    //printf("El menor del archivo es %i ", resultado);

    //mostrarArchivoInvertido(archivoNumeros);

    //mostrarArchivoNumeros(archivoNumeros);
    //invertirArchivo(archivoNumeros);
    //mostrarArchivoNumeros(archivoNumeros);

    //mostrarPalabrasInver();

    resultado = encontrarElemento(arrayNumeros, validos, 0, 3);
    if(resultado==0){
        printf("El numero se encuentra ");
    }else{
        printf("El numero no se encuentra ");
    }
    return 0;
}

/**1. Calcular el factorial de un número en forma recursiva. */
int factorial(int x){
    int rta;

    if(x==0){
        rta=1;
    }else{
        rta= x *factorial(x-1);
    }
    return rta;
}

/**2. Calcular la potencia de un número en forma recursiva. */
int potencia(int x, int y){
    int rta;

    if(y==0){
        rta=1;
    }else{
        rta = x*potencia(x, y-1);
    }
    return rta;
}

/**3. Recorrer un arreglo y mostrar sus elementos en forma recursiva. */
void mostrarArreglo(int array[], int validos, int i){
    if(i==(validos-1)){
        printf("  |%i|  ", array[i]);
    }else{
        printf("  |%i|  ", array[i]);
        mostrarArreglo(array, validos, i+1);
    }
}

/**4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo). */
void mostrarArregloInvertido(int array[], int validos, int i){
    if(i==(validos-1)){
        printf("  |%i|  ", array[i]);
    }else{
        mostrarArregloInvertido(array, validos, i+1);
        printf("  |%i|  ", array[i]);
    }
}

/**5. Determinar en forma recursiva si un arreglo es capicúa. */
int esCapicua(int array[], int validos, int i){
    int rta;

    if(validos <= i){
        rta =0;
        return rta;
    }else{
        if(array[validos-1] != array[i]){
            return -1;
        }else{
            rta = esCapicua(array, validos-1, i+1);
        }
    }
}

/**6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma. */
int sumaRecursiva(int array[], int validos, int i){
    int rta;

    if(validos == i){
        rta = 0;
    }else{
        rta = array[i] + sumaRecursiva(array, validos, i+1);
    }
    return rta;
}

/**7. Buscar el menor elemento de un arreglo en forma recursiva. */
int esMenor(int array[], int validos, int i){
int menor;

    if (i==validos-1){
        menor= array[i]; // cuando llego al final del arreglo, retorno ese valor
    }                 // para comparar con los de las etapas recursivas anteriores
    else{
       menor= esMenor(array, validos, i+1);
       if(menor > array[i]){   // en esta compara en el camino de vuelta
            menor= array[i];
       }
    }
 return menor;
}

/**8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)*/
void cargarArchivoEnteros(char numeros[], int array[], int validos){
    FILE *archi;
    archi = fopen(numeros, "ab");
    int i=0;

    if(archi!=NULL){
        while(validos>i){
            fwrite(&array[i], sizeof(int), 1, archi);
            i++;
        }
    fclose(archi);
    }
}

void mostrarArchivoNumeros(char numeros[]){
    FILE *archi;
    archi = fopen(numeros, "rb");
    int num;

    if(archi!=NULL){
        while(fread(&num, sizeof(int), 1, archi)>0){
            printf("  |%i|  ", num);
        }
    fclose(archi);
    }
}


int buscarMenorArchivo(char numeros[]){

     FILE* archi = fopen(numeros, "rb");
     int menor;

     if(archi!=NULL){
       menor= buscarMenorArchivoRecurs(archi);
       fclose (archi);
     }
     return menor;
}


int buscarMenorArchivoRecurs (FILE* archi){
    int menor;
    int valor;

    //como lee y luego evalua, en cada llamada qued� guardado en valor lo leido
    if(fread(&valor,sizeof(int),1,archi)==0) // COND CORTE: no ley� nada, cuando llego al final del archivo
    {
        fseek(archi, -1*sizeof(int), SEEK_END); // me muevo uno para atras p poder leer
        fread(&menor, sizeof(int),1,archi); // leo el ultimo elemento para retornarlo
    }
    else {
        menor= buscarMenorArchivoRecurs(archi);

        if(menor > valor){
            menor= valor;
        }
    }
    return menor;
}

/**9. Invertir los elementos de un archivo de números enteros de forma recursiva.
(si no te sale, primero proba con invertir los elementos de un arreglo de int)*/
int cantRegistros(FILE *archi){
    int cant=0;

    fseek(archi, 0, SEEK_END);
    cant = ftell(archi)/sizeof(int);

    return cant;
}

void invertirArchivo(char numeros[]){
    FILE *archi;
    archi = fopen(numeros, "r+b");
    int num;
    int cant;

    if(archi!=NULL){
        cant = cantRegistros(archi);
        invertirArchivoRecur(archi, cant-1, 0);
        fclose(archi);
    }
}

void invertirArchivoRecur(FILE *archi, int cant, int pos){
    int prim, ult;
    if(pos<cant){
        fseek(archi, cant*sizeof(int), 0);
        fread(&ult, sizeof(int), 1, archi);

        fseek(archi, pos*sizeof(int), 0);
        fread(&prim, sizeof(int),1, archi);

        fseek(archi, pos*sizeof(int), 0);
        fwrite(&ult, sizeof(int), 1, archi);

        fseek(archi, cant*sizeof(int), 0);
        fwrite(&prim, sizeof(int), 1, archi);

        invertirArchivoRecur(archi, cant-1, pos+1);
    }
}

/**10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva. */
void mostrarArchivoInvertido(char numeros[]){
    FILE *archi;
    archi = fopen(numeros, "rb");
    int num;

    if(archi!=NULL){
    FILE *archi;
    archi = fopen(numeros, "rb");

    if(archi!=NULL){
        mostrarArchivoInvertidoRecur(archi);
        fclose(archi);
    }
}
}

void mostrarArchivoInvertidoRecur(FILE *archi){
    int num;
    if(fread(&num, sizeof(int), 1, archi)==0){
        printf("\n");
    }else{
        mostrarArchivoInvertidoRecur(archi);
        printf("  |%i|  ", num);
    }
}

/**11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’)
de forma recursiva. NO usar arreglos. */
void mostrarPalabrasInver(){
    char palabra[20];

    printf("Ingrese una palabra o * para salir \n");
    fflush(stdin);
    gets(palabra);

    if(strcmp(palabra, "*")==0){
        printf("   ");
    }else{
        mostrarPalabrasInver();
        printf("  %s  ", palabra);
    }
}

/**12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.
(Pueden intentarlo también con una función void)(Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)*/
int encontrarElemento(int array[], int validos, int pos, int numero){
    if(array[pos]==numero){
        return 0;
    }else{
        if(pos>=(validos-1)){
            return -1;
        }else{
            encontrarElemento(array, validos, pos+1, numero);
        }
    }
}

