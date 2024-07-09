#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} StAlumno;

StAlumno cargarAlumno();
int cargarArregloDeAlumnos(StAlumno alumnos[], int dimension);
void mostrarAlumno(StAlumno alumno);
void mostrarAlumnos(StAlumno alumnos[], int validos);
int encontrarMatricula();
int encontrarPosPorMatricula(StAlumno alumnos[], int validos, int matricula);
int mostrarAlumnoPorMatricula(StAlumno alumnos[], int validos);
int posicionMenor(StAlumno alumnos[], int posInicio, int validos);
void ordenarPorSeleccion(StAlumno alumnos[], int validos);
int posicionPorGenero(StAlumno alumnos[], int validos, char genero[], int posInicial);
int cantAlumnosPorGenero(StAlumno alumnos[], int validos, char genero[]);
void mostrarAlumnosPorGenero(StAlumno alumnos[], int validos, char genero[]);
int insertarAlumnoEnArregloOrdenado(StAlumno alumnos[], int validos);
void insertar(StAlumno alumnos[], int posBusqueda, StAlumno alumno);
void ordenarPorInsercion(StAlumno alumnos[], int validos);

int main()
{
    char control='s';
    char genero='m';
    int eleccion,validos, cantidad;
    int dimension=10;
    StAlumno alumnos[10];
    StAlumno alumnosXGenero[10];

    do{
    printf("Que desea hacer? \n"
           "1) Cargar Alumnos \n"
           "2) Mostrar Alumnos \n"
           "3) Buscar alumno por matricula \n"
           "4) Ordenar por seleccion \n"
           "5) Mostrar alumnos por genero \n"
           "6) Agregar alumno en arreglo ordenado \n"
           "7) Ordenar por insercion \n"
           "8) Cantidad de alumnos por genero \n");
    fflush(stdin);
    scanf("%i", &eleccion);

        switch(eleccion){
    case 1:
        validos = cargarArregloDeAlumnos( alumnos, dimension);
        break;
    case 2:
        mostrarAlumnos( alumnos, validos);
        break;
    case 3:
        mostrarAlumnoPorMatricula(alumnos, validos);
        break;
    case 4:
        ordenarPorSeleccion(alumnos,validos);
        break;
    case 5:
        mostrarAlumnosPorGenero(alumnos,validos,genero);
        break;
    case 6:
        validos = insertarAlumnoEnArregloOrdenado(alumnos, validos);
        break;
    case 7:
        ordenarPorInsercion(alumnos, validos);
        break;
    case 8:
        cantidad = cantAlumnosPorGenero(alumnos, validos, genero);
        if(cantidad != -1){
            printf("Hay %i alumnos del genero %c \n", cantidad, genero);
        }else{
            printf("No hay alumnos del genero %c \n", genero);
        }
        break;
    default:
        printf("Ingrese una opcion valida. \n");
        break;
    }

    printf("Si desea continuar presione s.  ");
    fflush(stdin);
    scanf("%c", &control);

    }while(control=='s');

    return 0;
}


/** 1- Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida. */
StAlumno cargarAlumno(){
    StAlumno alumno;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", &alumno.nombre);

    printf("Ingrese el genero (m: masculino, f:femenino): ");
    fflush(stdin);
    scanf("%c", &alumno.genero);

    printf("Ingrese la matricula: ");
    fflush(stdin);
    scanf("%i", &alumno.matricula);

    return alumno;
}

int cargarArregloDeAlumnos(StAlumno alumnos[], int dimension){
    int i=0;
    char control='s';

    while(i<dimension && control=='s'){
        alumnos[i]=cargarAlumno();
        i++;

        printf("Desea seguir cargando alumnos? s/n \n");
        fflush(stdin);
        scanf("%c", &control);
    }

    return i;
}


/** 2- Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.*/
void mostrarAlumno(StAlumno alumno){
    printf("\n ----------------------------- \n");
    printf("Nombre: %s  \n", alumno.nombre);
    printf("Genero: %c  \n", alumno.genero);
    printf("Matricula: %i  \n", alumno.matricula);
    printf("----------------------------- \n");
}

void mostrarAlumnos(StAlumno alumnos[], int validos){

    for(int i=0; i<validos; i++){
        mostrarAlumno(alumnos[i]);
    }
}

/** 3- Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar. */
int encontrarMatricula(){
    int matricula;

    printf("Ingrese la matricula del alumno: ");
    fflush(stdin);
    scanf("%i", &matricula);

    return matricula;
}

int encontrarPosPorMatricula(StAlumno alumnos[], int validos, int matricula){
    int i=0;

    while(i<validos){
        if(matricula == alumnos[i].matricula){
            return i;
        }
        i++;
    }
    return -1;
}

int mostrarAlumnoPorMatricula(StAlumno alumnos[], int validos){
    int matricula = encontrarMatricula();
    int posicion = encontrarPosPorMatricula(alumnos, validos, matricula);

    if(posicion == -1){
        printf("No existe un alumno con esa matricula \n");
    }else{
    mostrarAlumno(alumnos[posicion]);
    }
}

/** 4- Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
       El criterio de ordenación es el número de matrícula. */
void ordenarPorSeleccion(StAlumno alumnos[], int validos)
{
    int posMenor;
    StAlumno aux;
    int i=0;
    while(i<validos-1)
    {
        posMenor = posicionMenor(alumnos, i, validos);

        strcpy(aux.nombre, alumnos[posMenor].nombre);
        aux.genero = alumnos[posMenor].genero;
        aux.matricula=alumnos[posMenor].matricula;

        alumnos[posMenor].matricula= alumnos[i].matricula;
        strcpy(alumnos[posMenor].nombre, alumnos[i].nombre);
        alumnos[posMenor].genero = alumnos[i].genero;

        alumnos[i].matricula= aux.matricula;
        strcpy(alumnos[i].nombre, aux.nombre);
        alumnos[i].genero = aux.genero;
        i++;
    }
}

int posicionMenor(StAlumno alumnos[], int posInicio, int validos){

int menor= alumnos[posInicio].matricula;
int posMenor= posInicio;
int i= posInicio++;

while(i<validos){

    if(menor>alumnos[i].matricula){
        menor= alumnos[i].matricula;
        posMenor=i;
    }
    i++;
}

return posMenor;
}

/** 5- Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro).
       Modularizar.*/
void mostrarAlumnosPorGenero(StAlumno alumnos[], int validos, char genero[]){
int posAux = 0;
int i=0;
int pos;
StAlumno aux[10];

int cant = cantAlumnosPorGenero(alumnos,validos,genero);
while(i<validos){
    pos = posicionPorGenero( alumnos, cant, genero, i);
    if(pos != -1){
        strcpy(aux[posAux].nombre, alumnos[pos].nombre);
        aux[posAux].genero = alumnos[pos].genero;
        aux[posAux].matricula = alumnos[pos].matricula;
        posAux++;
    }

    i++;
}
mostrarAlumnos(aux, cant);
}

int posicionPorGenero(StAlumno alumnos[], int validos, char genero[], int posInicial){
    int i = posInicial;

    if(genero== alumnos[i].genero){
        return i;
    }
    return -1;
}

/** 6- Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden. */
int insertarAlumnoEnArregloOrdenado(StAlumno alumnos[], int validos){
    StAlumno alumno;
    alumno = cargarAlumno();
    alumnos[validos] = alumno;
    ordenarPorSeleccion(alumnos, (validos+1));
    return validos+1;
}

/** 7- Hacer una función que ordene el arreglo de alumnos por medio del método de inserción.
       El criterio de ordenación es el nombre.*/
void ordenarPorInsercion(StAlumno alumnos[], int validos){
    int indiceActual = 0;
    while(indiceActual<validos-1){
        insertar(alumnos, indiceActual, alumnos[indiceActual+1]);
        indiceActual++;
    }
}

void insertar(StAlumno alumnos[], int posBusqueda, StAlumno alumno){
    int i = posBusqueda;
    while(i>=0 && alumno.matricula<alumnos[i].matricula ){
        alumnos[i+1]=alumnos[i];
        i--;
    }
    alumnos[i+1]=alumno;
}

/** 8- Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro)
       que tiene un arreglo de alumnos. */

int cantAlumnosPorGenero(StAlumno alumnos[], int validos, char genero[]){
    int i = 0;
    int acc = 0;

    while(i<validos){
        if(genero == alumnos[i].genero){
            acc++;
        }
        i++;
    }
    if(acc == 0){
        return -1;
    }else{
        return acc;
    }
}


/** 9- Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para
       poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.*/

