#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
} Alumno;

void cargarAlArchivo(char numeros[]);
void mostrarNumeros(char numeros[]);
int cantidadDeRegistros(char numeros[]);
Alumno cargarAlumno();
void cargarAlumnos(char alumnos[]);
void mostrarAlumno(Alumno alumno);
void mostrarAlumnos(char alumnos[]);
void agregarAlFinal(char alumnos[]);
void cargarEnPilaMayoresDe18(char alumnos[], Pila *pila);
int cantAlumnosMayoresA(char alumnos[], int edad);
void alumnosEntreRangoDeEdad(char alumnos[], int edad1, int edad2);
void mostrarAlumnosMayoresdeEdad(char alumnos[]);
int cantAlumnosDelAnio(char alumnos[], int anio);
int cantidadDeRegistrosDeAlumnos(char alumnos[]);
void mostrarAlumnoPorPosicion(char alumnos[], int pos);
void pasajeDeArregloAArchivo(Alumno *array, char alumnos[]);
void pasajeDeArchivoAArray(Alumno *array,int anio, char alumnos[]);
void modificarAlumnoPorLegajo(char alumnos[], int legajo);
Alumno modificarAlumno(Alumno alumno);
void invertirArchivo(char alumnos[]);

int main()
{
    int cantidad, eleccion, pos, legajo;
    int edad = 25;
    int anio = 2024;
    char control = 's';
    char archivoAlumnos[30];
    strcpy(archivoAlumnos, "alumnos.dat" );
    Pila legajos;
    inicpila(&legajos);
    Alumno alumno;
    Alumno alumno2;

    do{
        printf("Elija que desea hacer: \n"
               "1) Cargar archivo de numeros \n"
               "2) Mostrar archivo de numeros \n"
               "3) Mostrar cantidad de registros \n"
               "4) Cargar Alumnos \n"
               "5) Mostrar Alumnos \n"
               "6) Agregar alumno al final del archivo \n"
               "7) Cargar en Pila legajos de mayores de 18 \n"
               "8) Cantidad de alumnos mayores a X edad \n"
               "9) Alumnos entre rango de edad \n"
               "10) Mostrar alumnos mayores de 18 \n"
               "11) Cantidad de alumnos de X anio \n"
               "12) Pasar de arreglo a Archivo y viceversa \n"
               "13) Cantidad de Alumnos \n"
               "14) Mostrar Alumno por posicion (0-9)\n"
               "15) Modificar un alumno por legajo \n"
               "16) Invertir orden del archivo \n");
        fflush(stdin);
        scanf("%i", &eleccion);

        switch(eleccion){
    case 1:
        cargarAlArchivo("numeros.dat");
        break;
    case 2:
        mostrarNumeros("numeros.dat");
        break;
    case 3:
        cantidad=cantidadDeRegistros("numeros.dat");
        printf("\n Hay %i registros \n", cantidad);
        break;
    case 4:
        cargarAlumnos(archivoAlumnos);
        break;
    case 5:
        mostrarAlumnos(archivoAlumnos);
        break;
    case 6:
        agregarAlFinal(archivoAlumnos);
        break;
    case 7:
        cargarEnPilaMayoresDe18(archivoAlumnos, &legajos);
        mostrar(&legajos);
        break;
    case 8:
        cantidad = cantAlumnosMayoresA(archivoAlumnos, edad);
        printf("Hay %i alumnos mayores de %i \n", cantidad, edad);
        break;
    case 9:
        alumnosEntreRangoDeEdad(archivoAlumnos, 18,25);
        break;
    case 10:
        mostrarAlumnosMayoresdeEdad(archivoAlumnos);
        break;
    case 11:
        cantidad = cantAlumnosDelAnio(archivoAlumnos, anio);
        printf("Hay %i alumnos de anio %i \n", cantidad, anio);
        break;
    case 12:
        alumno = cargarAlumno();
        printf("\n ---------ARCHIVO------------ \n");
        pasajeDeArregloAArchivo(&alumno, "alumnosParaPasaje.bin");
        mostrarAlumnos("alumnosParaPasaje.bin");
        printf("\n ---------ESTRUCTURA------------ \n");
        pasajeDeArchivoAArray(&alumno2,2023, "alumnosParaPasaje.bin");
        mostrarAlumno(alumno2);
        break;
    case 13:
        cantidad = cantidadDeRegistrosDeAlumnos(archivoAlumnos);
        printf("Hay %i registros \n", cantidad);
        break;
    case 14:
        cantidad = cantidadDeRegistrosDeAlumnos(archivoAlumnos);
        printf("Por favor, elija el legajo: ");
        fflush(stdin);
        scanf("%i", &pos);
        if(pos < cantidad){
            mostrarAlumnoPorPosicion(archivoAlumnos, pos);
        }else{
            printf("Elija un legajo valido. \n");
            }
        break;
    case 15:
        printf("Ingrese el legajo del alumno para modificar: ");
        fflush(stdin);
        scanf("%i", &legajo);

        modificarAlumnoPorLegajo(archivoAlumnos, legajo);
        break;
    case 16:
        invertirArchivo(archivoAlumnos);
        break;
    default:
        printf("\n Elija una opcion valida \n");
        break;
        }

        printf("\n Desea continuar s/n \n");
        fflush(stdin);
        scanf("%c", &control);

    }while(control == 's');

    return 0;
}

/**Utilizando datos primitivos (int, char, float, etc), elija un tipo de dato y realice las siguientes funciones: */
/** 1-Hacer una función que agregue un elemento al final de un archivo. */
void cargarAlArchivo(char numeros[]){
    int cont = 0;
    int num;
    FILE *archivo;

    archivo=fopen(numeros, "r+b");
    if(archivo== NULL){
        archivo=fopen(numeros,"w+b");
    }
    if(archivo!=NULL){
        printf("Ingreso de numeros: \n");
        while(cont<5){
            printf("Ingrese un numero: ");
            fflush(stdin);
            scanf("%i", &num);
            fwrite(&num, sizeof(int), 1, archivo);
            cont ++;
        }
        fclose(archivo);
    }
}

/** 2-Hacer una función que muestre por pantalla el contenido de un archivo. */
void mostrarNumeros(char numeros[]){
    FILE *archivo;
    int num;
    archivo=fopen(numeros, "rb");
    int i=0;

    if(archivo!=NULL){
        while(!feof(archivo)){
            fread(&num, sizeof(int),1, archivo);
            if(!feof(archivo)){
                printf(" \n Registro numero %i", i++);
                printf("  |%i|  ", num);
            }
        }
        fclose(archivo);
    }
}

/** 3-Hacer una función que retorne la cantidad de registros que contiene un archivo. */
int cantidadDeRegistros(char numeros[]){
    int cantidad=0;

    FILE *archivo;
    archivo=fopen(numeros, "rb");

    if(archivo!=NULL){
        fseek(archivo,0, SEEK_END);
        cantidad = ftell(archivo)/sizeof(int);
        fclose(archivo);
        }
    return cantidad;
}

/** ---------------- USANDO ESTRUCTURAS ------------------------ */

/** 4-Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado
previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función */
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
/** 5-Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.*/
void mostrarAlumno(Alumno alumno){
    printf("\n ------------------------ ");
    printf("\n Legajo: %i", alumno.legajo);
    printf("\n Nombre y apellido: %s", alumno.nombreYapellido);
    printf("\n Edad: %i", alumno.edad);
    printf("\n Anio: %i", alumno.anio);
    printf("\n ------------------------ \n");
}

void mostrarAlumnos(char alumnos[]){
    FILE *archivo;
    Alumno alum;
    archivo=fopen(alumnos, "rb");

    if(archivo!=NULL){
        while(!feof(archivo)){
            fread(&alum, sizeof(Alumno),1, archivo);
            if(!feof(archivo)){
                mostrarAlumno(alum);
            }
        }
        fclose(archivo);
    }
}

/** 6-Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo,
se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra. */
void agregarAlFinal(char alumnos[]){
Alumno alum;
FILE *archivo;

archivo=fopen(alumnos, "ab");

if(archivo!=NULL){
    alum = cargarAlumno();
    fwrite(&alum, sizeof(Alumno), 1, archivo);
}
    fclose(archivo);
}

/** 7-Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad. */
void cargarEnPilaMayoresDe18(char alumnos[], Pila *pila)
{
    Alumno alum;
    FILE *archivo;
    archivo=fopen(alumnos, "rb");

    if(archivo!=NULL){
        while(fread(&alum, sizeof(Alumno),1, archivo)>0){
                if(alum.edad>18){
                    apilar(pila, alum.legajo);
                }
        }
    }
    fclose(archivo);
}

/** 8-Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía
por parámetro.*/
int cantAlumnosMayoresA(char alumnos[], int edad){
    Alumno alum;
    FILE *archivo;
    archivo=fopen(alumnos,"rb");
    int acc = 0;

    if(archivo!=NULL){
        while(!feof(archivo)){
              fread(&alum, sizeof(Alumno), 1, archivo);
              if(!feof(archivo)){
                    if(alum.edad>edad){
                        acc++;
                    }
            }
        }
    }
    fclose(archivo);
    return acc;
}

/** 9-Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico
(por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar*/
void alumnosEntreRangoDeEdad(char alumnos[], int edad1, int edad2){
    Alumno alum;
    FILE *archivo;
    archivo=fopen(alumnos, "rb");

    if(archivo!=NULL){
        while(!feof(archivo)){
                fread(&alum, sizeof(Alumno), 1, archivo);
            if(!feof(archivo)){
                if(alum.edad>= edad1 && alum.edad<=edad2){
                    printf("\n %s \n", alum.nombreYapellido);
                }
            }
        }
    }
    fclose(archivo);
}

/** 10-Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.*/
void mostrarAlumnosMayoresdeEdad(char alumnos[]){
 Alumno alum;
    FILE *archivo;
    archivo=fopen(alumnos,"rb");

    if(archivo!=NULL){
        while(!feof(archivo)){
              fread(&alum, sizeof(Alumno), 1, archivo);
              if(!feof(archivo)){
                    if(alum.edad>=18){
                        mostrarAlumno(alum);
                    }
            }
        }
    }
    fclose(archivo);
}

/** 11-Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.*/
int cantAlumnosDelAnio(char alumnos[], int anio){
    Alumno alum;
    int acc = 0;
    FILE *archivo;
    archivo=fopen(alumnos, "rb");

    if(archivo!=NULL){
        while(!feof(archivo)){
            fread(&alum, sizeof(Alumno), 1, archivo);
            if(!feof(archivo)){
                if(alum.anio == anio){
                    acc++;
                }
            }
        }
    }
    fclose(archivo);
    return acc;
}

/** 12-Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos,
filtrando los estudiantes de un año en particular.*/
void pasajeDeArregloAArchivoPROFESORA(Alumno arreglo[], int validos, char nombreArchivo[])
{
    FILE * archi;
    archi = fopen(nombreArchivo, "ab");
    int i=0;

    if(archi!=NULL)
    {
        while(i< validos)
        {
            fwrite(&arreglo[i], sizeof(Alumno),1,archi);
            i++;
        }
    }
    fclose(archi);
}

void pasajeDeArregloAArchivo(Alumno *array, char alumnos[]){
    FILE *archivo;
    archivo=fopen(alumnos, "wb");
    int i=0;

    if(archivo!=NULL){
        fwrite(array, sizeof(Alumno), 1, archivo);
    }
    fclose(archivo);
}

void pasajeDeArchivoAArray(Alumno *array,int anio, char alumnos[]){
    FILE *archivo;
    archivo=fopen(alumnos, "rb");
    Alumno alumno;
    int i=0;

    if(archivo!=NULL){
        fread(&alumno, sizeof(Alumno), 1, archivo);
        if(alumno.anio == anio){
            *array = alumno;
            array++;
        }
    }
    fclose(archivo);
}

/** 13-Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell.
Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.*/
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

/** 14-Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que muestre el contenido de un registro,
cuyo número (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo.*/
void mostrarAlumnoPorPosicion(char alumnos[], int pos){
    FILE *archivo;
    archivo=fopen(alumnos, "rb");
    Alumno alum;

    if(archivo!=NULL){
        fseek(archivo, sizeof(Alumno)*(pos-1), SEEK_SET);

        fread(&alum, sizeof(Alumno),1, archivo);

        printf("El alumno es: \n");
        mostrarAlumno(alum);
    }

        fclose(archivo);
}

/** 15-Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos.
La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo.*/
Alumno modificarAlumno(Alumno alumno){
    printf("Modificacion del alumno con legajo %i", alumno.legajo);
    char eleccion='s';
    int control;

    do{
        printf("Que desea modificar? \n"
               "1) Nombre y apellido \n"
               "2) Edad \n"
               "3) Anio \n");
        fflush(stdin);
        scanf("%i", &control);

        switch(control){
    case 1:
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(alumno.nombreYapellido);
        break;
    case 2:
        printf("Ingrese la edad: ");
        fflush(stdin);
        scanf("%i", &alumno.edad);
        break;
    case 3:
        printf("Ingrese el anio: ");
        fflush(stdin);
        scanf("%i", &alumno.anio);
        break;
    default:
        printf("Elija una opcion valida \n");
        break;
    }
    printf("Si desea continuar modificando presione s \n");
    fflush(stdin);
    scanf("%c", &eleccion);
    }while(eleccion=='s');
    return alumno;
}

void modificarAlumnoPorLegajo(char alumnos[], int legajo){
    FILE *archivo;
    archivo = fopen(alumnos, "r+b");
    Alumno alum;
    int encontrado = 0;

    if(archivo!=NULL){
        fseek(archivo, sizeof(Alumno)*(legajo-1), SEEK_SET);

        fread(&alum, sizeof(Alumno), 1, archivo);

        if(alum.legajo == legajo){
            encontrado=1;
        }
    }

    if(encontrado==0){
        printf("El alumno no fue encontrado \n");
    }

    if(encontrado==1){
        alum = modificarAlumno(alum);
    }
    fseek(archivo, sizeof(Alumno)*(legajo-1), SEEK_SET);
    fwrite(&alum, sizeof(Alumno), 1, archivo);

    fclose(archivo);
}

/** 16-Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo.
No se puede usar otro archivo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el archivo.
Puede utilizar variables de tipo alumno auxiliares.*/
void invertirArchivo(char alumnos[]){
    FILE *archivo;
    archivo= fopen(alumnos, "r+b");
    Alumno alum, aux;
    int cantRegistros = cantidadDeRegistrosDeAlumnos(alumnos);

    if(archivo!=NULL){
        for(int i=0; (i < (cantRegistros/2)); i++){
            fseek(archivo,  (i*sizeof(Alumno)), SEEK_SET);
            fread(&alum, sizeof(Alumno), 1, archivo);

            fseek(archivo, ( (cantRegistros -i -1)*sizeof(Alumno)), SEEK_SET);
            fread(&aux, sizeof(Alumno), 1, archivo);

            fseek(archivo,  (i*sizeof(Alumno)), SEEK_SET);
            fwrite(&aux, sizeof(Alumno), 1, archivo);

            fseek(archivo, ( (cantRegistros -i -1)*sizeof(Alumno)), SEEK_SET);
            fwrite(&alum, sizeof(Alumno), 1, archivo);
        }
    }
    fclose(archivo);
}

/** 17-Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores,
con un menú de opciones para poder ejecutar todas las funciones requeridas.
Tengan presente la correcta declaración y el ámbito de variables.*/
/* EN MAIN*/


