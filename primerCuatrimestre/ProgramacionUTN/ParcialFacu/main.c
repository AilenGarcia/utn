#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CANT_PALABRAS = 10;
const int MAX_LONGITUD_PALABRA = 10;

int informarPorPal(char matriz[CANT_PALABRAS][MAX_LONGITUD_PALABRA], char letra);

int main()
{
    int cantPalabras;
    char letra = 'a';
    char misPalabras[10][10] = {"casa","perro","gato","mesa","silla","libro","manzana","naranja", "computadora", "teclado"};

    cantPalabras = informarPorPal(misPalabras, letra);
    printf("Hay %i palabras que empiezan o terminan por la letra %c", cantPalabras, letra);

    return 0;
}

/** 6- Escribir la función (informaPorPal), la cual dado un arreglo de 10 palabras de un máximo de 30 letras cada una (usar ctes);
reciba por parámetro el arreglo (misPalabras), 1 letra ingresada por el usuario y muestre todas las palabras que comienzan
o terminan con esa letra y finalmente devuelva cuantas palabras fueron mostradas.*/
int informarPorPal(char matriz[CANT_PALABRAS][MAX_LONGITUD_PALABRA], char letra){
    int cantPalabras = 0;
    int cantLetras;

    for(int i = 0; i<CANT_PALABRAS; i++){
        cantLetras = strlen(matriz[i]);
            if(matriz[i][0]==letra || matriz[i][cantLetras -1]==letra){
                cantPalabras++;
            }
    }
    return cantPalabras;
}
