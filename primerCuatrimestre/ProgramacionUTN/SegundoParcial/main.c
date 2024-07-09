#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AILEN ROCIO GARCIA 40352485 COMISION 9
#define CAPACIDAD 7

typedef struct{
    int idViaje;
    char origen[50];
    char destino[50];
    int cantidadPasajeros;
} Viaje;

typedef struct{
    int idPasajero;
    int idViaje;
    char nombre[50];
    char dni[10];
    int despacheEquipaje; //1 o 0
} Pasajero;

void mostrarPasajero(Pasajero pasajero);
void mostrarArray(Pasajero pasajeros[], int validos);
void mostrarArchivoPasajeros(char archivo[]);
void mostrarArchivoViajes(char archivo[]);
//EJERCICIO 1
void cargaArchivoPasajeros(char pasajeros[], int cantidad);
void cargaArchivoViajes(char viajes[], int cantidad);
Pasajero cargarPasajero();
Viaje cargarViaje();
//EJERCICIO 2
int cantRegistrosViajes(char viajes[]);
//EJERCICIO 3
int pasajerosEnViaje(char pasajeros[], int idViaje);
int* pasarPajerosAArreglo(char pasajeros[], int idViaje);
//EJERCICIO 4
void mostrarViaje(Viaje viaje);
void mostrarViajesDisponibles(char viajes[]);
//EJERCICIO 5
Pasajero buscarPorPos(char pasajeros[], int pos);
Pasajero modificar(char pasajeros[], int idPasajero);
void modificarPasajeroEnArchivo(char pasajeros[], int idPasajero);
//EJERCICIO 6
void cargarArchivoDespachantes(char archivo[], Pasajero pasajero);
int despachanOno(Pasajero array[], int validos, char noDespachan[], char despachan[]);

int main()
{
    char archiPasajeros[20];
    char archiViajes[20];
    strcpy(archiPasajeros, "pasajeros.bin");
    strcpy(archiViajes, "viajes.bin");
    char archiDespachan[20];
    char archiNoDespachan[20];
    strcpy(archiDespachan, "despachan.bin");
    strcpy(archiNoDespachan, "noDespachan.bin");
    int cantViajes;
    int cantPasajeros;
    int cantidadRegistroViajes;
    int cantidadRegistroPasajeros;
    Pasajero *pasajeros;
    int validos;
    int idViaje;
    int idPasajero;

    //EJERCICIO 1
    printf("\n-------------------- EJERCICIO 1 --------------------\n");
    printf("Cuantos Viajes desea ingresar?");
    fflush(stdin);
    scanf("%i", &cantViajes);

    cargaArchivoViajes(archiViajes, cantViajes);
    mostrarArchivoViajes(archiViajes);

    printf("Cuantos Pasajeros desea ingresar?");
    fflush(stdin);
    scanf("%i", &cantPasajeros);

    cargaArchivoPasajeros(archiPasajeros, cantPasajeros);
    mostrarArchivoPasajeros(archiPasajeros);

    //EJERCICIO 2
    printf("\n-------------------- EJERCICIO 2 --------------------\n");
    cantidadRegistroViajes= cantRegistrosViajes(archiViajes);
    printf("\n Hay %i viajes registrados \n", cantidadRegistroViajes);

    //EJERCICIO 3
    printf("\n-------------------- EJERCICIO 3 --------------------\n");
    printf("Ingrese id de viaje: ");
    fflush(stdin);
    scanf("%i", &idViaje);
    pasajeros = pasarPajerosAArreglo(archiPasajeros, idViaje);

    //EJERCICIO 4
    printf("\n-------------------- EJERCICIO 4 --------------------\n");
    mostrarViajesDisponibles(archiViajes);

    //EJERCICIO 5
    printf("\n-------------------- EJERCICIO 5 --------------------\n");
    printf("Ingrese el id del pasajero a modificar: ");
    fflush(stdin);
    scanf("%i", &idPasajero);

    modificarPasajeroEnArchivo(archiPasajeros, idPasajero);

    //EJERCICIO 6
    printf("\n-------------------- EJERCICIO 6 --------------------\n");
    cantPasajeros = pasajerosEnViaje(archiPasajeros, idViaje);
    despachanOno(pasajeros,cantPasajeros,archiDespachan, archiNoDespachan);
    return 0;
}
/**1-Crear la/las funciones necesarias para cargar un archivo de Viajes y otro de Pasajeros.*/
Viaje cargarViaje(){
    Viaje viaje;

    printf("\n -------------- INGRESAR VIAJE --------------\n");
    printf("Ingrese id de viaje: \n");
    fflush(stdin);
    scanf("%i", &viaje.idViaje);

    printf("Ingrese origen: \n");
    fflush(stdin);
    gets(viaje.origen);

    printf("Ingrese destino: \n");
    fflush(stdin);
    gets(viaje.destino);

    printf("Ingrese cantidad de pasajeros: \n");
    fflush(stdin);
    scanf("%i",&viaje.cantidadPasajeros);
    printf("\n----------------------------\n");

    return viaje;
}

Pasajero cargarPasajero(){
    Pasajero pasajero;

    printf("\n -------------- INGRESAR PASAJERO --------------\n");
    printf("Ingrese id de pasajero: \n");
    fflush(stdin);
    scanf("%i", &pasajero.idPasajero);

    printf("Ingrese id de viaje: \n");
    fflush(stdin);
    scanf("%i", &pasajero.idViaje);

    printf("Ingrese nombre: \n");
    fflush(stdin);
    gets(pasajero.nombre);

    printf("Ingrese dni: \n");
    fflush(stdin);
    gets(pasajero.dni);

    printf("Ingrese 0 si no despacha equipaje y 1 si despacha equipaje : \n");
    fflush(stdin);
    scanf("%i", &pasajero.despacheEquipaje);
    printf("\n----------------------------\n");

    return pasajero;
}

void cargaArchivoViajes(char viajes[], int cantidad){
    FILE *archi;
    archi = fopen(viajes, "ab");
    int i=0;
    Viaje viaje;

    if(archi!=NULL){
        while(i< cantidad){
            viaje = cargarViaje();
            fwrite(&viaje, sizeof(Viaje), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

void cargaArchivoPasajeros(char pasajeros[], int cantidad){
    FILE *archi;
    archi = fopen(pasajeros, "ab");
    int i=0;
    Pasajero pasajero;

    if(archi!=NULL){
        while(i< cantidad){
            pasajero = cargarPasajero();
            fwrite(&pasajero, sizeof(Pasajero), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

/**2-Realizar una función que retorne la cantidad de registros cargados en el archivo de viajes.
No se debe recorrer todo el archivo ni utilizar contadores.*/
int cantRegistrosViajes(char viajes[]){
    FILE *archi;
    archi=fopen(viajes, "rb");
    int cantidad;

    if(archi!=NULL){
        fseek(archi, 0, SEEK_END);
        cantidad = ftell(archi)/sizeof(Viaje);
        fclose(archi);
    }

    return cantidad;
}

/**3-Realizar una función que reciba por parámetro un número de id y pase a todos los pasajeros que correspondan a dicho viaje
a un arreglo dinámico. Pensar muy bien las funciones auxiliares que serán necesarias para trabajar la dimensión del arreglo.*/
int* pasarPajerosAArreglo(char pasajeros[], int idViaje){

    int cantPasajeros = pasajerosEnViaje(pasajeros, idViaje);
    Pasajero *array = (Pasajero*) malloc(cantPasajeros*sizeof(Pasajero));

    FILE *archi;
    archi=fopen(pasajeros, "rb");
    Pasajero pasajero;
    int i=0;

    if(archi!=NULL){
        while(fread(&pasajero, sizeof(Pasajero), 1, archi)>0){
            if(pasajero.idViaje == idViaje){
                array[i]=pasajero;
                i++;
            }
        }
        fclose(archi);
    }
    //mostrarArray(array, cantPasajeros);
    return array;
}

int pasajerosEnViaje(char pasajeros[], int idViaje){
    FILE *archi;
    archi=fopen(pasajeros, "rb");
    int cantidad=0;
    Pasajero pasajero;

    if(archi!=NULL){
        while(fread(&pasajero, sizeof(Pasajero), 1, archi)>0){
            if(pasajero.idViaje == idViaje){
                cantidad++;
            }
        }
        fclose(archi);
    }

    return cantidad;
}

/**4-Realizar una función que muestre todos los viajes disponibles en el archivo de forma recursiva.
Disponibles: aquellos cuya cantidad de pasajeros esté por debajo de la constante CAPACIDAD. */
void mostrarViajesDisponibles(char viajes[]){
    FILE *archi;
    archi=fopen(viajes, "rb");
    Viaje viaje;

    if(archi!=NULL){
        while(fread(&viaje, sizeof(Viaje),1, archi)>0){
            if(viaje.cantidadPasajeros < CAPACIDAD){
                mostrarViaje(viaje);
            }
        }
    fclose(archi);
    }
}

void mostrarViaje(Viaje viaje){
    printf("\n----------------- VIAJE ----------------- \n");
    printf(" Id: %i   ", viaje.idViaje);
    printf(" Origen: %s   ", viaje.origen);
    printf(" Destino: %s   ", viaje.destino);
    printf(" Cant. de Pasajeros: %i   ", viaje.cantidadPasajeros);
    printf("\n----------------------------------\n");
}

/**5-Realizar una función que permita modificar uno o más datos de un registro específico dentro del archivo de pasajeros.
La función recibe por parámetro el número de registro.*/
void modificarPasajeroEnArchivo(char pasajeros[], int idPasajero){
    FILE *archi;
    archi = fopen(pasajeros, "r+b");
    Pasajero pasajero;
    pasajero = modificar(pasajeros, idPasajero);

    if(archi!=NULL){
        fseek(archi, (idPasajero-1)*sizeof(Pasajero), SEEK_SET);
        fwrite(&pasajero, sizeof(Pasajero),1, archi);
        fclose(archi);
    }
}

Pasajero modificar(char pasajeros[], int idPasajero){
    char control = 's';
    int eleccion;
    Pasajero pasajero;
    pasajero= buscarPorPos(pasajeros, idPasajero);

    do{
        printf("Que desea modificar? \n"
               "1) Nombre \n"
               "2) DNI \n"
               "3) Despacho de equipaje \n");
        fflush(stdin);
        scanf("%i", &eleccion);

        switch(eleccion){
            case 1:
                printf("El nombre actual es: %s , por cual desea cambiarlo? \n", pasajero.nombre);
                fflush(stdin);
                gets(pasajero.nombre);
                break;
            case 2:
                printf("El DNI actual es: %s , por cual desea cambiarlo? \n", pasajero.dni);
                fflush(stdin);
                gets(pasajero.dni);
                break;
            case 3:
                printf("El despacho de equipaje actual es: %i , por cual desea cambiarlo? \n", pasajero.despacheEquipaje);
                fflush(stdin);
                scanf("%i", &pasajero.despacheEquipaje);
                break;
            default:
                printf("\n ERROR. Elija una opcion valida \n");
        }

        printf("Desea seguir modificando? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }while(control == 's');

    return pasajero;
}

Pasajero buscarPorPos(char pasajeros[], int pos){
    FILE *archi;
    archi =fopen(pasajeros, "rb");
    Pasajero pasajero;

    if(archi!=NULL){
        fseek(archi, (pos-1)*sizeof(Pasajero), SEEK_SET);
        fread(&pasajero, sizeof(Pasajero), 1, archi);
        mostrarPasajero(pasajero);
        fclose(archi);
    }
    return pasajero;
}

/**6-Hacer una función que pase los pasajeros cargados en el arreglo dinámico del punto 3 a dos archivos:
 uno para los que despachan equipaje y otro para los que no.*/
int despachanOno(Pasajero array[], int validos, char noDespachan[], char despachan[]){
    for(int i=0; i<validos; i++){
        if(array[i].despacheEquipaje == 0){
            cargarArchivoDespachantes(noDespachan, array[i]);
        }else{
            cargarArchivoDespachantes(despachan, array[i]);
        }
    }
}

void cargarArchivoDespachantes(char archivo[], Pasajero pasajero){
    FILE *archi;
    archi  =fopen(archivo, "ab");

    if(archi!=NULL){
        fwrite(&pasajero, sizeof(Pasajero), 1, archi);
        fclose(archi);
    }
}






void mostrarPasajero(Pasajero pasajero){
    printf("\n----------------- VIAJE ----------------- \n");
    printf(" Id Pas.: %i   ", pasajero.idPasajero);
    printf(" Id Via.: %i   ", pasajero.idViaje);
    printf(" Nombre: %s   ", pasajero.nombre);
    printf(" DNI: %s   ", pasajero.dni);
    printf(" Despacha equi.: %i   ", pasajero.despacheEquipaje);
    printf("\n----------------------------------\n");
}

void mostrarArchivoViajes(char archivo[]){
    FILE *archi;
    archi= fopen(archivo, "rb");
    Viaje viaje;

    if(archi!=NULL){
        while(fread(&viaje, sizeof(Viaje), 1, archi)>0){
            mostrarViaje(viaje);
        }
        fclose(archi);
    }
}

void mostrarArchivoPasajeros(char archivo[]){
    FILE *archi;
    archi= fopen(archivo, "rb");
    Pasajero pasajero;

    if(archi!=NULL){
        while(fread(&pasajero, sizeof(Pasajero), 1, archi)>0){
            mostrarPasajero(pasajero);
        }
        fclose(archi);
    }
}

void mostrarArray(Pasajero pasajeros[], int validos){
    for(int i=0; i<validos;i++){
        printf(" NOMBRE %s ", pasajeros[i].nombre);
    }
}
