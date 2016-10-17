/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 ********************************************************************/ 

#ifndef BARRIER_H
#define BARRIER_H

#include <pthread.h>

#define BARRIER_LAST_THREAD 1

/* Definindo o tipo de barreira que usaremos. */
typedef struct {
    pthread_mutex_t mutex;
    pthread_mutex_t next_count;
    pthread_cond_t cond;
    int count;
    int threads_number;
} Barrier;

/* Essa função recebe um ponteiro para uma variável do nosso tipo 
 * Barrier e um inteiro que mostra o número de threads a serem 
 * utilizadas, e inicializa a barreira. */
int barrier_init(Barrier *barrier, unsigned int count);

/* Tem o trabalho de destruir a barreira que criamos. Em detalhes, 
 * é um envelope que chama as funções específicas para destruir partes
 * da nossa barreira. */
int barrier_destroy(Barrier *barrier);

/* Recebe uma função para ser executada depois de todas as threads 
 * chegarem na barreira e antes de elas proseguirem . Devolve 0 caso 
 * seja o fim de uma thread comun, retorna BARRIER_LAST_THREAD quando 
 * todas estiverem sincronizadas. */
int barrier_wait(Barrier *barrier, void (*func)(void *), void * func_in); 

/* Deleta um elemento da barreira. */
void barrier_remove_one(Barrier *barrier);

#endif
