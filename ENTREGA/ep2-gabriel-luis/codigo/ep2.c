/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 * 
 *  Arquivo:    ep2.c
 *  Compilação: make
 *  Execução:   ./ep2 d n [v|u] [-v]              
 ********************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "cyclist/cyclist.h"
#include "inspector/inspector.h"

#define NONE -1

/* Definições de término. */
#define EMPATE 0
#define TEAM_0 1
#define TEAM_1 2

int main(int argc, char const *argv[]) {
    pthread_t *threads;              /* Salva o id de cada thread */
    int i, n, d, verbose;
    char mode;
    int * positions[2];
    Cyclist cyclists;                /* As informações de cada ciclista */
    pthread_mutex_t *positions_lock; /* Mutexes das posições */

    srand((unsigned) time(NULL));

    if (argc != 4 && argc != 5) {
        printf("ep2 d n [v|u] [-v]\n");
        return EXIT_FAILURE;
    }

    sscanf (argv[1],"%d",&d);
    sscanf (argv[2],"%d",&n);
    sscanf (argv[3],"%c",&mode);
    if (argc == 5) verbose = 1;
    else verbose = 0;
    mode -= 117;

    if (verbose) printf("%d %d\n", d, n);

    if (mode == RANDOM && !verbose) printf("Mode: RANDOM\n");
    if (mode == CONSTANT && !verbose) printf("Mode: CONSTANT\n");

    /* Pista interna: 0 e externa: 1 */
    positions[0] = malloc(2 * d * sizeof(int*));
    positions[1] = malloc(2 * d * sizeof(int*));

    positions_lock = malloc(2 * d * sizeof(pthread_mutex_t));
    threads = malloc(2 * n * sizeof(pthread_t));
    cyclists = malloc(2 * n * sizeof(struct cyclist));


    for (i = 0; i < 2 * d; ++i) {
        if(pthread_mutex_init(&positions_lock[i], 0) < 0) {
            fprintf(stderr, "Error creating mutex\n");
            return EXIT_FAILURE;
        }
        positions[0][i] = -1;
        positions[1][i] = -1;
    }

    /* Informa as regras para todos */
    cyclists_setup (positions, positions_lock, d, n, (int)mode);
    for (i = 0; i < 2 * n; ++i) cyclist_setup (&cyclists[i], i, i/n);

    /* informa dados ao inspetor */
    ins_init (verbose, cyclists, n, d);

    /* Cria as threads */
    for (i = 0; i < 2 * n; ++i) {
        if(pthread_create(&threads[i], NULL, cyclist_thread, (void *)&cyclists[i])) {
            fprintf(stderr, "Error creating thread\n");
            return EXIT_FAILURE;
        }
    }
    /* Faz o join das threads */
    for (i = 0; i < 2 * n; ++i) {
        if(pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread\n");
            return EXIT_FAILURE;
        }
    }

    for (i = 0; i < 2 * d; ++i) {
        pthread_mutex_destroy(&positions_lock[i]);
    }

    ins_show_broken ();
    ins_show_end_results ();

    free(positions_lock);
    free(positions[0]);
    free(positions[1]);
    free(cyclists);
    free(threads);
    cyclists_free ();

    return EXIT_SUCCESS;
}
