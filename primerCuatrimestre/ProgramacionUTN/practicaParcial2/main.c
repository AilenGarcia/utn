#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int idEquipo;
char nombre[30];
int zona; /// las zonas pueden ser 1, 2 o 3
} stEquipo;

typedef struct {
int idJugador;
char nombre[30];
int edad;
int idEquipo;
} stJugador;

void cargaDeEquipos(char equipos[]);
void mostrarJugadores(stJugador jugadores[], int cant);
void mostrarJugador(stJugador jugador);
int existeEquipo(char equipos[], int id);
stJugador* cargarJugadores(int cant, char equipos[]);
stJugador cargarJugador(char equipos[]);
void mostrarArchivoEquipos(char equipos[]);
void mostrarArchivoJugadores(char jugadores[]);
void pasarArrayAarchivo(char archiJugadores[], stJugador jugadores);
void juniorSenior(stJugador *jugadores,int cant, char jugadoresJunior[], char jugadoresSenior[]);
void mostrarContenidoRecur(FILE *archi);
void mostrarContenido(char jugadores[]);
stJugador retornarMenorRecur(FILE *archi);
stJugador retornarMenor(char jugadores[]);

int main()
{
    int menu, cantidad;
    char control;
    stJugador *jugadores;
    char jugadoresJuniors[30];
    strcpy(jugadoresJuniors, "jugadoresJunior.dat");
    char jugadoresSeniors[30];
    strcpy(jugadoresSeniors, "jugadoresSenior.dat");
    char equipos[30];
    strcpy(equipos, "equipos.dat");
    stJugador menor;

    cargaDeEquipos(equipos);
    //mostrarArchivoEquipos(equipos);
    do{
        printf("Que desea hacer? \n"
               "1) Cargar jugadores en array \n"
               "2) Pasar jugadores a archivos \n"
               "3) Listado de jugadores \n"
               "4) Retornar el menor \n");
        fflush(stdin);
        scanf("%i", &menu);

        switch(menu){
            case 1:
                printf("\n -------------------------------------\n");
                printf("Cuantos jugadores desea ingresar? ");
                fflush(stdin);
                scanf("%i", &cantidad);

                jugadores = cargarJugadores(cantidad, equipos);
                break;
            case 2:
                mostrarJugadores(jugadores,cantidad);
                printf("\n CANTIDAD: %i", cantidad);
                juniorSenior(jugadores, cantidad, jugadoresJuniors, jugadoresSeniors);
                //pasarArrayAarchivo(jugadoresJuniors, jugadoresSeniors, jugadores, cantidad);
                printf("\n------------------ JUNIORS ------------------ \n");
                mostrarArchivoJugadores(jugadoresJuniors);
                printf("\n------------------ SENIORS ------------------ \n");
                mostrarArchivoJugadores(jugadoresSeniors);
                break;
            case 3:
                //printf("\n LISTA JUGADORES SIN RECURSIVIDAD \n");
                //mostrarArchivoJugadores(jugadoresJuniors);
                printf("\n LISTA JUGADORES CON RECURSIVIDAD \n");
                mostrarContenido(jugadoresJuniors);
                break;
            case 4:
                menor = retornarMenor(jugadoresJuniors);
                mostrarJugador(menor);
                break;
            default:
                printf("Error, ingrese una opcion valida. \n");
        }

        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c",&control);

    }while(control == 's');

    return 0;
}

/**1. Efectuar la carga de nuevos jugadores sobre un arreglo dinámico con intervención del usuario del sistema.
Esta función deberá validar que el idEquipo ingresado exista en el archivo de equipos que se le ha entregado.
Dicha operación se debe realizar en una función aparte (Modularizar). Una vez cargado el arreglo de jugadores,
deberá mostrarlos por pantalla a fin de corroborar que los datos han sido debidamente ingresados. Modularizar.*/

stJugador cargarJugador(char equipos[]){
    stJugador jugador;
    printf("\n -------------------------------- \n");
    printf("Ingrese jugador \n");
    printf(" Id: ");
    fflush(stdin);
    scanf("%i", &jugador.idJugador);

    printf("\n Nombre: ");
    fflush(stdin);
    gets(jugador.nombre);

    printf(" Edad: ");
    fflush(stdin);
    scanf("%i", &jugador.edad);

    do{
    printf(" Id Equipo: ");
    fflush(stdin);
    scanf("%i", &jugador.idEquipo);
    }while(existeEquipo(equipos, jugador.idEquipo)!=0);

    printf("\n -------------------------------- \n");

    return jugador;
}

stJugador* cargarJugadores(int cant, char equipos[]){
    stJugador *array = (stJugador*) malloc(cant* sizeof(stJugador));
    int i =0;

    while(i<cant){
        array[i] = cargarJugador(equipos);
        i++;

    }
    mostrarJugadores(array, cant);
    return array;
}

int existeEquipo(char equipos[], int id){
    FILE *archi;
    archi = fopen(equipos, "rb");
    stEquipo equipo;
    int encontrado;

    if(archi!=NULL){
        while(fread(&equipo, sizeof(stEquipo),1,archi)>0){

            if(id==equipo.idEquipo){
                return 0;
            }else{
                encontrado = -1;
            }
        }
        fclose(archi);
    }
    printf("\n El id del equipo no existe \n");
    return encontrado;
}

void mostrarJugador(stJugador jugador){
    printf("\n ----------------------------------------------- \n");
    printf("Id: %i,  ", jugador.idJugador);
    printf("Nombre: %s,  ", jugador.nombre);
    printf("Edad: %i,  ", jugador.edad);
    printf("idEquipo: %i,  ", jugador.idEquipo);
    printf("\n ----------------------------------------------- \n");
}

void mostrarJugadores(stJugador jugadores[], int cant){
    for(int i=0; i<cant;i++){
        mostrarJugador(jugadores[i]);
    }
}

void cargaDeEquipos(char equipos[]){
    FILE *archi;
    archi =fopen(equipos, "rb");

   if (archi != NULL) {
        fclose(archi);
        return;
    }

    stEquipo equipo[3] = {
        {1, "Equipo1", 1},
        {2, "Equipo2", 2},
        {3, "Equipo3", 3}
    };

    archi = fopen(equipos, "wb");
    if (archi != NULL) {
        fwrite(equipo, sizeof(stEquipo), 3, archi);
        fclose(archi);
    }

}

void mostrarArchivoEquipos(char equipos[]){
    FILE *archi;
    archi=fopen(equipos, "rb");
    stEquipo equipo;

    if(archi !=NULL){
        while(fread(&equipo, sizeof(stEquipo), 1, archi)>0){
            printf("\n -------------------------------- \n");
            printf("IdEquipo: %i,  ", equipo.idEquipo);
            printf("Nombre: %s,  ", equipo.nombre);
            printf("Zona: %i ", equipo.zona);
            printf("\n -------------------------------- \n");
        }
        fclose(archi);
    }
}

/**2. A partir del arreglo cargado en el inciso anterior:
a. Pasar a dos archivos de jugadores (“jugadoresJunior.dat” y “jugadoresSenior.dat”) la información cargada en el arreglo, dependiendo
de la edad del jugador en cuestión. Se considera un jugador como “Senior” si ya tiene 30 años o más. Dentro de la función,
deberá trabajar con dos variables de tipo FILE *, una para cada archivo.
b. Realizar una función que muestre un archivo de jugadores por pantalla. Modularizar.*/
void juniorSenior(stJugador *jugadores,int cant, char jugadoresJunior[], char jugadoresSenior[]){

    for(int i=0; i<cant ; i++){
        if(jugadores[i].edad>=30){
            pasarArrayAarchivo(jugadoresSenior, jugadores[i]);
        }else{
            pasarArrayAarchivo(jugadoresJunior,jugadores[i]);
        }
    }
}

void pasarArrayAarchivo(char archiJugadores[], stJugador jugadores){
    FILE *archi;
    archi = fopen(archiJugadores, "ab");

    if(archi!=NULL){
            fwrite(&jugadores, sizeof(stJugador), 1, archi);
            fclose(archi);
        }
}

void mostrarArchivoJugadores(char jugadores[]){
    FILE *archi;
    archi=fopen(jugadores, "rb");
    stJugador jugador;

    if(archi !=NULL){
        while(fread(&jugador, sizeof(stJugador), 1, archi)>0){
            mostrarJugador(jugador);
        }
        fclose(archi);
    }
}


 /**4. Realice las siguientes funciones recursivas:
 a. Función que muestra el contenido del archivo realizado en incisos anteriores (de forma recursiva).
 b. Función que busca en el archivo el jugador de menor edad y lo retorna (de forma recursiva).*/
 void mostrarContenido(char jugadores[]){
    FILE *archi;
    archi = fopen(jugadores, "rb");
    stJugador jug;

    if(archi!=NULL){
        mostrarContenidoRecur(archi);
        fclose(archi);
    }
 }

 void mostrarContenidoRecur(FILE *archi){
    stJugador jug;
    if(fread(&jug, sizeof(stJugador), 1, archi)==0){
        printf(" \n ");
    }else{
        mostrarJugador(jug);
        mostrarContenidoRecur(archi);
    }
 }

stJugador retornarMenor(char jugadores[]){
    FILE *archi;
    archi = fopen(jugadores, "rb");
    stJugador jug;

    if(archi!=NULL){
        jug = retornarMenorRecur(archi);
        fclose(archi);
    }
    return jug;
}

stJugador retornarMenorRecur(FILE *archi){
    stJugador jug;
    stJugador menor;

    if(fread(&jug, sizeof(stJugador), 1,archi)==0){
        fseek(archi, (-1)*sizeof(stJugador), SEEK_END);
        fread(&menor, sizeof(stJugador),1,archi);
    }else{
        menor = retornarMenorRecur(archi);
        if(menor.edad>jug.edad){
            menor = jug;
        }
    }
    return menor;
}



float promedioDeEdades(char jugadores[], int edad);
int mayoresDe(char jugadores[], int edad);
int cantRegistros(char archivo[]);

/*int main(){
    int edad;
    float promedio;
    char jugadoresJuniors[30];
    strcpy(jugadoresJuniors, "jugadoresJunior.dat");
    char jugadoresSeniors[30];
    strcpy(jugadoresSeniors, "jugadoresSenior.dat");
    char equipos[30];
    strcpy(equipos, "equipos.dat");

    cargaDeEquipos(equipos);
    //mostrarArchivoEquipos(equipos);

    int cantRegistrosJuniors = cantRegistros(jugadoresJuniors);
    int cantRegistrosSeniors = cantRegistros(jugadoresSeniors);

    printf("\n La cantidad de registros de juniors es: %i", cantRegistrosJuniors);
    printf("\n La cantidad de registros de seniors es: %i", cantRegistrosSeniors);

    //mostrarArchivoJugadores(jugadoresJuniors);
    printf("\n Ingrese apartir de que edad quiere saber el promedio de jugadores: ");
    fflush(stdin);
    scanf("%i", &edad);

    if(edad>=30){
        promedio = promedioDeEdades(jugadoresSeniors, 31);
        printf("\n El promedio de jugadores mayores de %i es %.2f", edad, promedio);
    }else{
        promedio = promedioDeEdades(jugadoresJuniors, 15);
        printf("\n El promedio de jugadores mayores de %i es %.2f", edad, promedio);
    }
    return 0;
}*/

/**3. Averiguar el porcentaje de jugadores mayores a una edad específica sobre el total de jugadores almacenados en un archivo.
Para lo cual deberá realizar:
 a. Una función que calcule la cantidad total de registros que posee un archivo.
 No se puede recorrer la totalidad del archivo para calcularlo.
 b. Una función que calcule qué porcentaje de jugadores representa del total cargado en el archivo, aquellos que sean mayores
 a una edad específica que se envía por parámetro.
 c. Un subprograma, que deberá invocar a las funciones anteriores (3.a y 3.b)
 e informar por pantalla los resultados obtenidos en cada caso. Deberá buscar en el archivo correspondiente de jugadores
 (juniors o seniors), de acuerdo a, la edad ingresada por el usuario del sistema.*/
int cantRegistros(char archivo[]){
    FILE *archi;
    archi=fopen(archivo, "rb");
    int acc =0;

    if(archi != NULL){
        fseek(archi,0, SEEK_END);
        acc = ftell(archi)/sizeof(stJugador);
        fclose(archi);
    }

    return acc;
}

int mayoresDe(char jugadores[], int edad){
    FILE *archi;
    archi = fopen(jugadores, "rb");
    int acc=0;
    stJugador jugador;

    if(archi!=NULL){
        while(fread(&jugador, sizeof(stJugador),1,archi)>0){
            if(jugador.edad>edad){
                acc++;
            }
        }
        fclose(archi);
    }
    return acc;
}

float promedioDeEdades(char jugadores[], int edad){
    int cantidadRegistros = cantRegistros(jugadores);
    int cantidadMayoresDe = mayoresDe(jugadores, edad);
    float promedio = (float)cantidadRegistros / (float)cantidadMayoresDe;

    return promedio;
}
