/**
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#define MAX 10

void *funcion1()
{
    printf("Thread: %d\n", pthread_self());
    pthread_exit(0);
}

int main()
{
    pthread_attr_t attr;
    pthread_t thid[MAX];
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for(int i = 0; i < MAX; i++)
    {
        pthread_create(&thid[i], &attr, funcion1, NULL);
    }

    printf("Start sleep\n");
    Sleep(10000);
    printf("End sleep\n");

    return 0;
}
*/
/**
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *funcion(void *p)
{
printf("Thread: %d\n", pthread_self());
pthread_exit(0);
}
int main()
{
pthread_t th1, th2;
pthread_create(&th1, NULL, funcion, NULL);
pthread_create(&th2, NULL, funcion, NULL);
printf("El thread principal continua ejecutando: %d\n", pthread_self());
pthread_join(th1,NULL);
pthread_join(th2,NULL);
return 0;
}
*/

/**6. [LAB] “Hello World!” V2.0... ahora con Threads!
Escribir el código C que escriba en pantalla n veces el mensaje: “Hola Threads!. Soy el
thread [idThread] ejecutando por [enésima] vez”, donde [idThread] es el identificador de
thread asignado por el lenguaje C y [n-ésima] es la cantidad de veces que se imprimió el
texto por pantalla. Para obtener este identificador se puede utilizar el siguiente código:
getpid()
El código C debe crear 10 threads y ejecutar cada uno de ellos 10.000 veces (n = 10,000).
Describir brevemente el resultado de la ejecución.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10
#define NUM_PRINTS 10000

void *print_message(void *threadid)
{
    long tid = (long)threadid;
    for (int i = 0; i < NUM_PRINTS; i++)
    {
        printf("Hola Threads!. Soy el thread %ld ejecutando por %d vez\n", tid, i+1);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&threads[t], NULL, print_message, (void *)t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    return 0;
}
// Se ejecutaron y finalizaron primero el hilo1, despues el hilo2 y despues el hilo3
