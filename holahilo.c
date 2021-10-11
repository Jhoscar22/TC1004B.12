#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5
int saldo;

void *printHola(void *arg){
    printf("Hola desde un hilo\n");
    int saldolocal = saldo;
    saldolocal += 100; //Normalmente seróa un cálculo complejo
    saldo = saldolocal;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("El valor de saldo es %d\n", saldo);

    pthread_exit(NULL);
}