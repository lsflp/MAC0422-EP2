/* //////////////////////////////////////////////////////////////
// 
// Autor: Gabriel Capella
// Numero USP: 8962078
// Sigla: GABRIELC
// Data: 2015-10-13
// 
////////////////////////////////////////////////////////////// */
#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "../barrier/barrier.h"
#include "../cyclist/cyclist_info.h"
#include "../cyclist/cyclist.h"

/* definicoes de termino */
#define EMPATE 0
#define TEAM_0 1
#define TEAM_1 2
#define TEAM_0_THIRD 3
#define TEAM_1_THIRD 4

#define NONE -1

void ins_show_end_results ();
int ins_can_go_60 (Cyclist data);
void ins_init (int _verbose, Cyclist _cyclists, int _n, int);
void ins_check (void *_sync);
void ins_show_broken ();

#endif
