/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 * 
 *  Arquivo:   cyclist.h
 *  Descrição: Biblioteca que trata das funções referentes ao 
 *             ciclistas.
 ********************************************************************/ 
 
#ifndef CYCLIST_H
#define CYCLIST_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "../barrier/barrier.h"
#include "../inspector/inspector.h"
#include "cyclist_info.h" /* Contém o tipo cyclist. */

/* Recebe a pista (implementada como uma matriz), um semáforo, o 
 * tamanho da pista d, o número de ciclistas n e o modo de execução
 * e então, configura o ambiente. Antes de criar as threads, chamar 
 * essa função. */
void cyclists_setup (int **speedway, pthread_mutex_t *lock, int d, int n, int _mode);

/* A partir das informações recebidas, inicializa um ciclista. */
void cyclist_setup (Cyclist data, int number, int team);

/* Recebe um ponteiro para a informação do ciclista e basicamente, 
 * é a orientação para a thread do ciclista. */
void * cyclist_thread (void *info);

/* Libera, no tipo ciclista, as posições de memória alocadas. */
void cyclists_free ();

#endif
