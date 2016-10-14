/* //////////////////////////////////////////////////////////////
// 
// Autor: Gabriel Capella
// Numero USP: 8962078
// Sigla: GABRIELC
// Data: 2015-10-13
// 
////////////////////////////////////////////////////////////// */
#ifndef BARRIER_H
#define BARRIER_H

#include <pthread.h>

#define BARRIER_LAST_THREAD 1

/* retorna 0 caso seja o fim de uma thread comun, retirna 
// BARRIER_LAST_THREAD qaundo todas estiverem sincronizadas */
typedef struct {
    pthread_mutex_t mutex;
    pthread_mutex_t next_count;
    pthread_cond_t cond;
    int count;
    int threads_number;
} Barrier;

int barrier_init(Barrier *barrier, unsigned int count);

int barrier_destroy(Barrier *barrier);

/* recebe uma funcao para ser executada depois de todas as threads 
// chegarem na barreira e antes delas proseguirem */
int barrier_wait(Barrier *barrier, void (*func)(void *), void * func_in); 

void barrier_remove_one(Barrier *barrier); /* deleta um elemento da barreira */

#endif
