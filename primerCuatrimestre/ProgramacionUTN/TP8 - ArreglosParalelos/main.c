#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIM = 20;
const int COL = 30;

int cargarAlumnos(int legajos[DIM],int anios[DIM], char nombres[DIM][COL]);
void mostrarAlumnos(int legajos[DIM],int anios[DIM], char nombres[DIM][COL], int validos);
int mostrarPosDeLegajo(int legajos[DIM], int validos);
void buscarNombrePorLegajo(int legajos[DIM],int anios[DIM], char nombres[DIM][COL], int validos);
int posicionMenor(char nombres[DIM][COL], int posInicio, int validos);
void ordenarPorSeleccion(int legajos[DIM],int anios[DIM], char nombres[DIM][COL], int validos);

int main()
{
    int legajos[DIM];
    char nombres[DIM][COL];
    int anios[DIM];
    int eleccion, validos, pos;
    char control = 's';

    do{
        printf("Que desea hacer? \n"
               "1) Cargar alumnos \n"
               "2) Posicion del legajo \n"
               "3) Buscar nombre por legajo \n"
               "4) Ordenar por nombre \n"
               "5) Mostrar Registros \n");
        fflush(stdin);
        scanf("%i", &eleccion);

        switch(eleccion){
    case 1:
        validos = cargarAlumnos(legajos, anios, nombres);
        break;
    case 2:
        pos = mostrarPosDeLegajo(legajos, validos);
        if(pos == -1){
            printf("\n No se encontro el legajo \n ");
        }else{
            printf("La posicion del legajo es %i \n", pos);
        }
        break;
    case 3:
        buscarNombrePorLegajo(legajos, anios, nombres, validos);
        break;
    case 4:
        ordenarPorSeleccion(legajos, anios, nombres, validos);
        break;
    case 5:
        mostrarAlumnos(legajos, anios, nombres, validos);
        break;
    default:
        printf("\n Error. Ingrese una opcion valida \n");
        }

        printf("Si desea continuar presiones s. \n");
        fflush(stdin);
        scanf("%c", &control);
       }while(control =='s');

    return 0;
}

/**1- Crear una función que los cargue, hasta que el usuario lo decida. */
int cargarAlumnos(int legajos[DIM],int anios[DIM], char nombres[DIM][COL]){
    int control = 's';
    int i=0;

    printf("--------------- Ingresar Alumno --------------- \n");
    while(i<DIM && control == 's'){

    printf("Ingrese legajo: ");
    fflush(stdin);
    scanf("%i", &legajos[i]);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(&nombres[i]);

    printf("Ingrese anio: ");
    fflush(stdin);
    scanf("%i", &anios[i]);

    i++;

    printf("Si desea continuar cargando alumnos presione s.\n");
    fflush(stdin);
    scanf("%c", &control);
    }

    return i;
}

/**2- Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor. */
int mostrarPosDeLegajo(int legajos[DIM], int validos){
    int legajo;
    int flag = -1;

    printf("Ingrese el legajo que busca: ");
    fflush(stdin);
    scanf("%i", &legajo);

    for(int i=0; (i<validos) && (flag == -1); i++){
        if(legajo == legajos[i]){
            return i;
        }
    }
    return -1;
}

/**3- Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente
a un determinado legajo y lo imprima por pantalla. Se debe invocar la función 2.*/
void buscarNombrePorLegajo(int legajos[DIM],int anios[DIM], char nombres[DIM][COL], int validos){
    int pos = mostrarPosDeLegajo(legajos, validos);
    printf(" \n La persona con el legajo %i es: %s \n" , pos, nombres[pos]);
}

/**4- Hacer una función que reciba como parámetro todos los arreglos y los ordene por nombre.
(por el método de selección o inserción).*/
void ordenarPorSeleccion(int legajos[DIM],int anios[DIM], char nombres[DIM][COL], int validos){
    int posMenor;
    int legajoAux;
    int anioAux;
    char nombresAux[DIM];

    int i=0;
    while(i<validos-1)
    {
        posMenor = posicionMenor(nombres, i, validos);

        legajoAux = legajos[posMenor];
        anioAux = anios[posMenor];
        strcpy(nombresAux, nombres[posMenor]);

        legajos[posMenor]=legajos[i];
        anios[posMenor]=anios[i];
        strcpy(nombres[posMenor], nombres[i]);

        legajos[i] = legajoAux;
        anios[i] = anioAux;
        strcpy(nombres[i], nombresAux);
        i++;
    }
}

int posicionMenor(char nombres[DIM][COL], int posInicio, int validos){

char *menor= nombres[posInicio];
int posMenor= posInicio;
int i= posInicio++;

while(i<validos){

    if(strcmp(menor, nombres[i]) > 0){
        menor= nombres[i];
        posMenor=i;
    }
    i++;
}

return posMenor;
}

/**5- Mostrar por pantalla los 3 arreglos pero de a un “registro” o alumno por vez
(es decir: muestra el legajo, nombre y años del 1er alumno, luego el legajo, nombre y años del 2do alumno, y así sucesivamente).*/
void mostrarAlumnos(int legajos[DIM],int anios[DIM], char nombres[DIM][COL], int validos){
    printf("\n -------------- Alumnos registrados -------------- \n");
    for(int i=0; i<validos; i++){
        printf("\n----------------------------\n");
        printf("Legajo: %i,  ", legajos[i]);
        printf("Nombre: %s,  ", nombres[i]);
        printf("Anio: %i  ", anios[i]);
        printf("\n----------------------------\n");
    }
}

