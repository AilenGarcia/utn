#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main()
{

    return 0;
}*/

/** 1. Escriba un programa que pida al usuario ingresar dos cadenas y luego compare si son iguales utilizando la función strcmp().
El programa debería imprimir un mensaje indicando si las cadenas son iguales o diferentes.*/
/*int main()
{
    char cadena1[100];
    char cadena2[100];
    int resultado;

    printf("Ingrese la primera palabra \n");
    fflush(stdin);
    gets(cadena1);

    printf("Ingrese la segunda palabra \n");
    fflush(stdin);
    gets(cadena2);

    resultado = strcmp(cadena1,cadena2);

    if(resultado==-1){
        printf("Las palabra 1 es menor a la palabra 2");
    }else if(resultado==1){
        printf("Las palabra 2 es menor a la palabra 1");
    }else{
    printf("Las palabras son iguales");
    }

    return 0;
}*/

/** 2. Desarrolla un programa que solicite al usuario ingresar una cadena y luego utilice la función strlen() para determinar
y mostrar la longitud de la cadena ingresada.*/
/*int main()
{
    char cadena[100];
    int resultado;

    printf("Ingrese una palabra: \n");
    fflush(stdin);
    gets(cadena);

    resultado = strlen(cadena);

    printf("La palabra contiene %i caracteres", resultado);
    return 0;
}*/

/** 3. Crea un programa que pida al usuario ingresar una cadena y luego copie esa cadena en otra utilizando la función strcpy().
Imprime ambas cadenas para verificar que la copia se haya realizado correctamente.*/
/*int main()
{
    char cadena1[100];
    char cadena2[100];

    printf("Ingrese una palabra \n");
    fflush(stdin);
    gets(cadena1);

    strcpy(cadena2, cadena1);

    printf("La primera palabra es: %s \n"
           "La segunda pabala es: %s", cadena1, cadena2);
    return 0;
}*/

/** 4. Amplía el programa anterior para que después de copiar la cadena ingresada, solicite al usuario otra cadena y utilice
la función strcat() para concatenarla con la cadena copiada. Luego, imprime la cadena resultante.*/
/*int main()
{
    char cadena1[100];
    char cadena2[100];
    char cadena3[100];

    printf("Ingrese una palabra \n");
    fflush(stdin);
    gets(cadena1);

    strcpy(cadena2, cadena1);

    printf("Ingrese otra palabra \n");
    fflush(stdin);
    gets(cadena3);

    strcat(cadena2, cadena3);

    printf("La cadena resultante es: %s", cadena2);
    return 0;
}*/

/** 5. Crea un programa que solicite al usuario ingresar una cadena y luego utilice un bucle para recorrer la cadena y contar
la cantidad de vocales que contiene. Puedes utilizar las funciones strcmp() y strlen() para manejar la cadena.*/
/*int main()
{
    char cadena[100];
    int cantCaracteres;
    int acc;

    printf("Ingrese un texto \n");
    fflush(stdin);
    gets(cadena);

    cantCaracteres = strlen(cadena);

    for(int i=0; i<cantCaracteres; i++){
        char aux[2] = {cadena[i],0};
       if (strcmp(aux, "a") == 0 || strcmp(aux,"e") == 0 || strcmp(aux, "i") == 0 || strcmp(aux, "o") == 0 || strcmp(aux, "u") == 0){
               acc++;
           }
    }

    printf("Hay %i vocales \n", acc );
    return 0;
}*/

/** 6. Escribe un programa que defina dos cadenas de caracteres (strings) y luego utilice la función strcat() para concatenar
la segunda cadena a la primera. Finalmente, imprime la cadena resultante.*/
/*int main()
{
    char cadena1[100]={"Hola, como estas? \n"};
    char cadena2[100]={"Muy bien, gracias \n"};

    strcat(cadena1, cadena2);

    printf("La cadena resultante es: \n%s", cadena1);
    return 0;
}*/

/** 8. Escribe una función llamada insercionSort que ordene un array de caracteres que contiene las letras del abecedario
desordenadas utilizando el algoritmo de ordenamiento por inserción*/
void insercionSort(char arreglo[], int validos);
void insertar(char arreglo[], int posInicio, char dato);

int main(){
    char cadena[6]={'v','a','c','b','k',0};

    insercionSort(cadena,5);
    printf("El array ordenado es: %s \n", cadena);

return 0;
}

void insercionSort(char arreglo[], int validos){
    int indiceActual =0;
    while(indiceActual<validos-1){
        insertar(arreglo, indiceActual, arreglo[indiceActual+1]);
        indiceActual++;
    }
}

void insertar(char arreglo[], int posInicio, char dato){
    int i=posInicio;
    while(i>=0 && dato<arreglo[i]){
        arreglo[i+1]=arreglo[i];
        i--;
    }
    arreglo[i+1]=dato;
}



