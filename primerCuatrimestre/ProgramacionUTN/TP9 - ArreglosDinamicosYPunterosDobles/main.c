#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIM = 10;

typedef struct{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
} Alumno;

int cantidadDePares(int arreglo[DIM]);
void cargarArrayDeParesVersion3(int **array, int arreglo[DIM], int cant);
void mostrarArray(int array[], int cant);
void cargarArrayDeParesVersion1(int array[], int arrayEntero[DIM]);
int* cargarArrayDeParesVersion2(int arrayEntero[DIM], int cant);
int cantidadDeRegistrosDeAlumnos(char alumnos[]);
void cargarAlumnos(char alumnos[]);
Alumno cargarAlumno();
void mostrarArrayAlumnos(Alumno alumnos[], int validos);
void mostrarAlumno(Alumno alumno);
void cargarAlumnosEnArrayVersion1(Alumno arrayAlumnos[], char alumnos[]);
Alumno* cargarAlumnosEnArrayVersion2(char alumnos[], int validos);
void cargarAlumnosEnArrayVersion3(Alumno **arrayAlumnos, char alumnos[], int validos);
int* agrandarArreglo(int *array, int cant, int nuevoCant);

int main()
{
    int arrayInt[10]={0,1,2,3,4,5,6,7,8,9};
    int *arrayPares;
    int *nuevoArray;

    char archivoAlumnos[30];
    strcpy(archivoAlumnos, "alumnos.dat" );
    Alumno *arrayAlumnos;

    int cantRegistros = cantidadDeRegistrosDeAlumnos(archivoAlumnos);
    int cant = cantidadDePares(arrayInt);

    /** EJERCICIO 2 A) */
    /* arrayPares = (int*) malloc(cant* sizeof(int));

    cargarArrayDeParesVersion1(arrayPares, arrayInt);*/

    /** EJERCICIO 2 B) */
    arrayPares = cargarArrayDeParesVersion2(arrayInt, cant);

    /** EJERCICIO 2 C) */
    /*cargarArrayDeParesVersion3(&arrayPares, arrayInt, cant);*/
    printf("Array de pares: \n");
    mostrarArray(arrayPares, cant);
    printf("\n-------\n");
    /*cargarAlumnos(archivoAlumnos);*/

    /** EJERCICIO 3 C) */
    /*arrayAlumnos = (Alumno*) malloc(cantRegistros* sizeof(Alumno));

    cargarAlumnosEnArrayVersion1(arrayAlumnos, archivoAlumnos);*/

    /** EJERCICIO 3 D) */
    /*arrayAlumnos = cargarAlumnosEnArrayVersion2(archivoAlumnos, cantRegistros);*/

    /** EJERCICIO 3 E) */
    /*cargarAlumnosEnArrayVersion3(&arrayAlumnos,archivoAlumnos,cantRegistros);*/

    //mostrarArrayAlumnos(arrayAlumnos, cantRegistros);

    /** EJERCICIO 4 */
    nuevoArray = agrandarArreglo(arrayPares, cant, 10);
    printf("Array modificado \n");
    mostrarArray(nuevoArray, 10);

    return 0;
}


/**2. Se cuenta con un arreglo de números enteros que ya fue cargado.
a) Se pide hacer una función que copie los datos de todos los valores del arreglo mencionado que sean pares en otro arreglo
del tamaño justo.
A tal fin, desarrolle una función que cuente la cantidad de elementos pares y otra función que se encargue del traspaso de los
datos pares.
El ejercicio deberá ser realizado usando en la función dos parámetros de tipo arreglo (uno para el arreglo original de enteros
y otro para el arreglo de pares) y creando el arreglo dinámico utilizando malloc en el Main antes de la invocación de la
función de traspaso.
b) Ahora deberá realizarse lo mismo del ejercicio anterior pero creando el arreglo dinámico utilizando malloc dentro de la
función y retornando el arreglo
c) Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc dentro de la función, y en lugar de retornar el
arreglo, trabajar con puntero doble*/

void cargarArrayDeParesVersion1(int array[], int arrayEntero[DIM]){
    int j=0;
    for(int i=0; i<DIM; i++){
        if(arrayEntero[i]%2 == 0){
            array[j]= arrayEntero[i];
            j++;
        }
    }
}

int* cargarArrayDeParesVersion2(int arrayEntero[DIM], int cant){
    int j=0;

    int* array = (int*) malloc(cant* sizeof(int));

    for(int i=0; i<DIM; i++){
        if(arrayEntero[i]%2 ==0){
            array[j]= arrayEntero[i];
            j++;
        }
    }

    return array;
}

void cargarArrayDeParesVersion3(int **array, int arreglo[DIM], int cant){
    int i=0;
    int j=0;

    *array = (int*) malloc(cant* sizeof(int));

    while( i<DIM ){
        if((arreglo[i]%2) == 0){
            (*array)[j]= arreglo[i];
            j++;
        }
        i++;
    }
}

void mostrarArray(int array[], int cant){
    for(int i=0; i<cant; i++){
        printf(" | %i | ", array[i]);
    }
}

int cantidadDePares(int arreglo[DIM]){
    int acc=0;

    for(int i=0; i<DIM; i++){
        if(arreglo[i]%2==0){
            acc++;
        }
    }

    return acc;
}

/** * Utilizar el archivo de alumnos ya generado con el ejercicio 4 de dicho TP e incorporarlo a este TP.
* Utilizar la función ya hecha en el ejercicio 13 de dicho TP para contar la cantidad de alumnos existentes en el archivo
* Y en base a ello realizar lo siguiente:
c) Hacer una función que copie los registros de todos los alumnos existentes en el archivo en un arreglo del tamaño justo,
creando el arreglo dinámico en el Main antes de la invocación de la función.
d) Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc dentro de la función y retornando el arreglo
e) Ahora deberá realizarse lo mismo del ejercicio anterior pero usando malloc dentro de la función, y en lugar de retornar el
arreglo, trabajar con puntero doble*/

/** EJERCICIO 4 TP-ARCHIVOS (cargar alumnos) */
Alumno cargarAlumno(){
    Alumno a;

    printf("\n ------------------------ ");
    printf("\n Ingrese legajo: ");
    fflush(stdin);
    scanf("%i", &a.legajo);
    printf("\n Ingrese nombre y apellido: ");
    fflush(stdin);
    gets(a.nombreYapellido);
    printf("\n Ingrese edad: ");
    fflush(stdin);
    scanf("%i", &a.edad);
    printf("\n Ingrese anio: ");
    fflush(stdin);
    scanf("%i", &a.anio);
    printf("\n ------------------------ \n");
    return a;
}

void cargarAlumnos(char alumnos[]){
    int cont = 0;
    Alumno alum;
    FILE *archivo;

    archivo=fopen(alumnos, "ab");

    if(archivo!=NULL){
        printf("Ingreso de alumnos: \n");
        while(cont<5){
            alum = cargarAlumno();
            fwrite(&alum, sizeof(Alumno), 1, archivo);
            cont ++;
        }
        fclose(archivo);
    }
}

/** EJERCICIO 13 TP-ARCHIVOS (cantidad de Registros) */
int cantidadDeRegistrosDeAlumnos(char alumnos[]){
    int cantidad=0;

    FILE *archivo;
    archivo=fopen(alumnos, "rb");

    if(archivo!=NULL){
        fseek(archivo,0, SEEK_END);
        cantidad = ftell(archivo)/sizeof(Alumno);
        fclose(archivo);
        }
    return cantidad;
}

void cargarAlumnosEnArrayVersion1(Alumno arrayAlumnos[], char alumnos[]){
    FILE *archi;
    archi = fopen(alumnos, "rb");
    Alumno alum;
    int i=0;

    if(archi!=NULL){
            if(archi!=NULL){
        while(fread(&alum, sizeof(Alumno),1, archi)>0){
            arrayAlumnos[i] = alum;
            i++;
        }
    }
    fclose(archi);
    }
}

Alumno* cargarAlumnosEnArrayVersion2(char alumnos[], int validos){
    int i =0;
    Alumno* array = (Alumno*) malloc(validos* sizeof(Alumno));
    FILE *archi;
    archi = fopen(alumnos, "rb");
    Alumno alum;

    if(archi!=NULL){
        while(fread(&alum, sizeof(Alumno),1, archi)>0){
            array[i]=alum;
            i++;
        }
    }
    fclose(archi);

    return array;
}

void cargarAlumnosEnArrayVersion3(Alumno **arrayAlumnos, char alumnos[], int validos){
    FILE *archi;
    archi = fopen(alumnos, "rb");
    Alumno alum;
    *arrayAlumnos = (Alumno*) malloc(validos* sizeof(Alumno));
    int i =0;

    if(archi!=NULL){
        while(fread(&alum, sizeof(Alumno), 1, archi)){
            (*arrayAlumnos)[i]=alum;
            i++;
        }
    }
    fclose(archi);
}

void mostrarAlumno(Alumno alumno){
    printf("\n------------------------------------\n");
    printf("Legajo: %i \n", alumno.legajo);
    printf("Nombre completo: %s \n", alumno.nombreYapellido);
    printf("Edad: %i \n", alumno.edad);
    printf("Anio: %i", alumno.anio);
    printf("\n------------------------------------\n");
}

void mostrarArrayAlumnos(Alumno alumnos[], int validos){
    for(int i=0; i<validos;i++){
        mostrarAlumno(alumnos[i]);
    }
}

/** 4. Hacer una función que reciba un arreglo dinámico por parámetro, la cantidad de elementos válidos del mismo, y un valor
que indique el nuevo tamaño que se le quiere dar a dicho arreglo. La función debe redimensionar el arreglo
(usar la función realloc) y retornar el puntero a dicho espacio de memoria*/
int* agrandarArreglo(int *array, int cant, int nuevoCant){
    int* nuevoArray = (int*) realloc(array, nuevoCant);

    for(int i=cant; i<nuevoCant; i++){
        nuevoArray[i]=i;
    }
    return nuevoArray;
}


/**1. Se desea construir un programa que ilustre la situación que se tiene al emplear punteros y dobles punteros.
Para ello, declare un puntero de int y un puntero de puntero del anterior, en la forma:
int valor;
int * pint = &valor;
int ** ppint = &pint;
Se pide construir un programa que muestre las direcciones de valor, pint y ppint, y que asigne distintos valores a la
variable valor empleando pint y ppint.*/

/**int main()
{
    int valor;
    int * pint = &valor;
    int ** ppint = &pint;

    printf("\n Direccion de valor: %p", &valor);
    printf("\n Direccion de pint: %p", &pint);
    printf("\n Direccion de ppint: %p \n", &ppint);

    valor = 5;
    printf("Valor: %i \n", valor);

    *pint = 10;
    printf("Valor: %i \n", valor);

    **ppint = 15;
    printf("Valor: %i \n", valor);

    return 0;
}*/
