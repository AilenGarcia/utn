#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <windows.h>
#define MAX 10

sem_t semaforo1;
sem_t semaforo2;
sem_t semaforo3;
/*
void* H1(void* arg) {
    for(int i = 0; i < 5; ++i) {
        sem_wait(&semaforo1);  // Espera a que el semáforo 1 esté disponible
        printf("Soy el hilo 1\n");
        sem_post(&semaforo2);  // Señaliza al semáforo 2
    }
    return NULL;
}

void* H2(void* arg) {
    for(int i = 0; i < 5; ++i) {
        sem_wait(&semaforo2);  // Espera a que el semáforo 2 esté disponible
        printf("Soy el hilo 2\n");
        sem_post(&semaforo3);  // Señaliza al semáforo 3
    }
    return NULL;
}

void* H3(void* arg) {
    for(int i = 0; i < 5; ++i) {
        sem_wait(&semaforo3);  // Espera a que el semáforo 3 esté disponible
        printf("Soy el hilo 3\n");
        sem_post(&semaforo1);  // Señaliza al semáforo 1
    }
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2, hilo3;

    // Inicializa los semáforos
    sem_init(&semaforo1, 0, 1);  // Comienza con el semáforo 1 disponible
    sem_init(&semaforo2, 0, 0);
    sem_init(&semaforo3, 0, 0);

    // Crea los hilos
    pthread_create(&hilo1, NULL, H1, NULL);
    pthread_create(&hilo2, NULL, H2, NULL);
    pthread_create(&hilo3, NULL, H3, NULL);

    // Espera a que los hilos terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

    // Destruye los semáforos
    sem_destroy(&semaforo1);
    sem_destroy(&semaforo2);
    sem_destroy(&semaforo3);

    return 0;
}
*/

/*
void *funcion1(){
    sem_wait(&semaforo1);

    printf("Thread: %d\n", pthread_self());

    sem_post(&semaforo1);
    pthread_exit(0);
}

int main()
{
pthread_attr_t attr;
pthread_t thid[MAX];

sem_init(&semaforo1,0,1);
pthread_attr_init(&attr);
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

for(int i = 0; i < MAX; i++){
pthread_create(&thid[i], &attr, funcion1, NULL);
}

//printf("Start sleep\n");
//Sleep(10000);
//printf("End sleep\n");

sem_destroy(&semaforo1);

return 0;
}
*/

void *procesoA(void *arg){
    for(int i=0; i<MAX; i++){
        sem_wait(&semaforo1);
        printf("Proceso A \n");
        sem_post(&semaforo2);
    }
    return NULL;
}

void *procesoB(void *arg){
    for(int i=0; i<MAX; i++){
        sem_wait(&semaforo2);
        printf("Proceso B \n");
        sem_post(&semaforo3);
    }
    return NULL;
}

void *procesoC(void *arg){
    for(int i=0; i<MAX; i++){
        sem_wait(&semaforo3);
        printf("PROCESO C \n");
        sem_post(&semaforo1);
    }
    return NULL;
}

int main(){
    pthread_t A,B,C;
    sem_init(&semaforo1,0,1);
    sem_init(&semaforo2,0,0);
    sem_init(&semaforo3,0,0);

    pthread_create(&A, NULL, procesoA, NULL);
    pthread_create(&B, NULL, procesoB, NULL);
    pthread_create(&C, NULL, procesoC, NULL);

    pthread_join(A, NULL);
    pthread_join(B, NULL);
    pthread_join(C, NULL);

    sem_destroy(&semaforo1);
    sem_destroy(&semaforo2);
    sem_destroy(&semaforo3);

    return 0;
    //PARA OTRA SECUENCIA AL HACER SEM_INIT, PONER EL ULTIMO VALOR EN 1 DE OTRO SEMAFORO
}
