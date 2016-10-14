/* //////////////////////////////////////////////////////////////
// 
// Autor: Gabriel Capella
// Numero USP: 8962078
// Sigla: GABRIELC
// Data: 2015-10-13
// 
////////////////////////////////////////////////////////////// */
#ifndef CYCLIST_H
#define CYCLIST_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "../barrier/barrier.h"
#include "../inspector/inspector.h"
#include "cyclist_info.h"

void cyclists_setup (int **speedway, pthread_mutex_t *lock, int d, int n, int _mode);
void * cyclist_thread (void *info);
void cyclists_free ();
void cyclist_setup (Cyclist data, int number, int team);

#endif
