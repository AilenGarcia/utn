#include <stdio.h>
#include <pthread.h>
int a=10;
void *f1(void *arg) {
sleep(5);
a=a*2;
printf("Thread: %d - valor de a: %d",pthread_self(),a);
pthread_exit(0);
}
void *f2(void *arg) {
sleep(15);
a=a+5;
printf("Thread: %d - valor de a: %d",pthread_self(),a);
pthread_exit(0);
}
void main() {
pthread_t h1,h2;
printf("Thread: %d",pthread_self());
pthread_create(&h1,NULL,f2,NULL);
pthread_create(&h2,NULL,f1,NULL);
pthread_join(h2,NULL);
return(0);
}
