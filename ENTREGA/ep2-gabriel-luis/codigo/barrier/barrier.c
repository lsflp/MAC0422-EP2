/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 * 
 *  AVISO: Baseado em 
 *         http://blog.albertarmea.com/post/47089939939/
 *         using-pthreadbarrier-on-mac-os-x
 ********************************************************************/ 

#include "barrier.h"

int barrier_init(Barrier *barrier, unsigned int count) {

    if(count == 0) {
        return -1;
    }

    if(pthread_mutex_init(&barrier->mutex, 0) < 0) {
        return -1;
    }

    if(pthread_cond_init(&barrier->cond, 0) < 0) {
        pthread_mutex_destroy(&barrier->mutex);
        return -1;
    }

    barrier->threads_number = count;
    barrier->count = 0;

    return 0;
}

int barrier_destroy(Barrier *barrier) {
    pthread_cond_destroy(&barrier->cond);
    pthread_mutex_destroy(&barrier->mutex);
    return 0;
}

int barrier_wait(Barrier *barrier, void (*func)(void *), void * func_in) {
    pthread_mutex_lock(&barrier->mutex);
    ++(barrier->count);
    if(barrier->count >= barrier->threads_number) {
        barrier->count = 0;
        if (func != NULL) (*func)(func_in);
        pthread_cond_broadcast(&barrier->cond);
        pthread_mutex_unlock(&barrier->mutex);
        return BARRIER_LAST_THREAD;
    } else {
        pthread_cond_wait(&barrier->cond, &(barrier->mutex));
        pthread_mutex_unlock(&barrier->mutex);
        return 0;
    }
    return -1;
}

void barrier_remove_one(Barrier *barrier) {
    --(barrier->threads_number);
}
