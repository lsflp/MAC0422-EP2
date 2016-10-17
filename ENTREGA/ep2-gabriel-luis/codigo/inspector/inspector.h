/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 ********************************************************************/ 

#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "../barrier/barrier.h"
#include "../cyclist/cyclist_info.h"
#include "../cyclist/cyclist.h"

/* Definições para o término da prova. */
#define EMPATE 0
#define TEAM_0 1
#define TEAM_1 2
#define TEAM_0_THIRD 3
#define TEAM_1_THIRD 4

#define NONE -1

/* Mostra na saída padrão todos os ciclistas que quebraram. */
void ins_show_broken ();

/* Mostra a ordem de chegada e quem ganhou ou se houve empate. */
void ins_show_end_results ();

/* Devolve 0 (false) caso o ciclista não possa andar a 60 km/h.
 * Devolve 1 (true) caso contrário. */
int ins_can_go_60 (Cyclist data);

/* Inicializa algumas variáveis necessárias para o trabalho do 
 * fiscal. Verbose, em especial, é utilizada para informar se
 * o modo é debug ou não. */
void ins_init (int _verbose, Cyclist _cyclists, int _n, int);

/* Função que checa algumas informações. Mais detalhes na 
 * implementação. */
void ins_check (void *_sync);

#endif
