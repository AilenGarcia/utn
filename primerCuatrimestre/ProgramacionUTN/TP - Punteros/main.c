#include <stdio.h>
#include <stdlib.h>

int main()
{
/**Ejercicio 1: Punteros ¿Qué imprime?.*/
/*
int *punt;
int x=7;
int y=5;
punt=&x;
*punt=4;
printf("%d, %d",x,y); // ¿qué imprime este printf?
// 4  5
*/
/**Ejercicio 2: Punteros ¿Qué imprime?. */
/*
int *punt;
int x=7;
int y=5;
punt=&x;
x=4;
printf("%d, %d",*punt,y); // ¿qué imprime este printf?
// 4  5
*/
/**Ejercicio 3: Punteros ¿Qué imprime?. */
/*
int *punt;
int x=7;
int y=5;
punt=&x;
x=4;
punt=&y;
printf("%d, %d",*punt,x); // ¿qué imprime este printf?
// 5  4
*/
/**Ejercicio 4: Punteros ¿Qué imprime?. */
/*
int *punt;
int x=7;
int y=5;
punt=&x;
*punt=3;
punt=&y;
*punt=x;
x=9;
printf("%d, %d",*punt,x); // ¿qué imprime este printf?
// 3   9
*/
/**Ejercicio 5: Punteros ¿Qué imprime?. */
/*
int *punta, *puntb;
int x=7;
int y=5;
punta=&x; //7
*punta=3; //x=3
puntb=&y; //5
*puntb=x;  // y=3
x=9;
printf("%d, %d",*puntb,x); // ¿qué imprime este printf?
// 3  9
*/
/**Ejercicio 6: Punteros ¿Qué imprime?. */
/*
int *punta, *puntb;
int x=7;
int y=5;
punta=&x; //7
*punta=3; //x=3
puntb=&y; //5
*puntb=x; //y=3
x=9;      // x=9
printf("%d, %d",*puntb, *punta); // ¿qué imprime?
//  3  9
*/
/**Ejercicio 7: Punteros ¿Qué imprime?. */
/*
int *punta, *puntb;
int x=7;
int y=5;
punta=&x; //7
*punta=3; //x=3
puntb=&y; //5
*puntb=x; //y=3
x=9;      //x=9
puntb=punta;  //9
printf("%d, %d",*puntb, y); // ¿qué imprime?
// 9   3
*/
}

