/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 ********************************************************************/ 

#include "inspector.h"

static Cyclist cyclists;                 /* Vetor de ciclistas */
static int n;                            /* Número de ciclistas */
static int d;                            /* Tamanho da pista */
static int verbose;                      /* Modo debug ou não. */
static Cyclist first_3[2][3] = {{NULL}}; /* Ordena os 3 primeiros */
static int end_mode = NONE;              /* Marca como a corrida acabou */
static int third_lap[3] = {0};           /* Marca a volta do terceiro ciclista */
static double time_count;                /* Conta o tempo */
static int *finish_order;                /* Vetor com as ordens de chegada */
static int finish_order_count;           /* Conta quantos já finalizaram */

/* FUNÇÃO PRIVADA ///////////////////////////////////////////////// */

/* Faz uma ordenação "na mão" para saber a ordem dos três ciclistas mais
 * à frente. */
static void ins_first_three () {
    int i, t;
    for (i = 0; i < 2*n; ++i) {
        t = cyclists[i].team;
        if (first_3[t][0] == NULL || first_3[t][0]->dist < cyclists[i].dist) {
            first_3[t][2] = first_3[t][1];
            first_3[t][1] = first_3[t][0];
            first_3[t][0] = &cyclists[i];
        } else if (first_3[t][1] == NULL || first_3[t][1]->dist < cyclists[i].dist) {
            first_3[t][2] = first_3[t][1];
            first_3[t][1] = &cyclists[i];
        } else if (first_3[t][2] == NULL || first_3[t][2]->dist < cyclists[i].dist) {
            first_3[t][2] = &cyclists[i];
        }
    }
}

/* FUNÇÕES PÚBLICAS /////////////////////////////////////////////// */

void ins_show_broken () {
    int i;
    printf("Broken: Team 0: ");
    for (i = 0; i < n; ++i) {
        if (cyclists[i].status == 3)
            printf("%d (%d), ", i, cyclists[i].lap);
    }
    printf("\n");
    printf("Broken: Team 1: ");
    for (i = n; i < 2*n; ++i) {
        if (cyclists[i].status == 3)
            printf("%d (%d), ", i, cyclists[i].lap);
    }
    printf("\n");
}

void ins_show_end_results () {
    int i;
    printf("Finishing order: ");
    for (i = 0; i < 2*n; ++i) {
        if (finish_order[i] == -1) break;
            printf("%d (%4.2f), ", finish_order[i], cyclists[finish_order[i]].end_moment);
    }
    printf("\n");
    printf("Result: ");

    if (end_mode == EMPATE) printf("A TIE\n");
    else if (end_mode == TEAM_0) printf("TEAM 0 WIN\n");
    else if (end_mode == TEAM_1) printf("TEAM 1 WIN\n");
    else if (end_mode == TEAM_0_THIRD) printf("TEAM 0 WIN*\n");
    else if (end_mode == TEAM_1_THIRD) printf("TEAM 1 WIN*\n");

    free (finish_order);
}

int ins_can_go_60 (Cyclist data) {
    int i;
    for (i = 0; i < 2*n; ++i) {
        if (cyclists[i].team == data->team 
            && cyclists[i].lap > data->lap 
            && cyclists[i].speed == SPEED_30) return 0;
    }
    return 1;
}

void ins_init (int _verbose, Cyclist _cyclists, int _n, int _d) {
    int i;
    cyclists = _cyclists;
    verbose = _verbose;
    n = _n;
    d = _d;
    end_mode = -1;
    time_count = 0.0;
    finish_order_count = 0;
    finish_order = malloc (n*2*sizeof(int));
    for (i = 0; i < n*2; ++i) finish_order[i] = -1;
}

void ins_check (void * _sync) {
    int i;
    Barrier *sync;
    sync = (Barrier*) _sync;

    /* Vamos olhar se temos que tirar alguém */
    for (i = 0; i < 2*n; ++i) {

        /* Atualiza o número de voltas. */
        if (cyclists[i].lap_marker == 1) {
            cyclists[i].lap_marker = 0;
            ++(cyclists[i].lap);
            if (cyclists[i].lap == 16) {
                cyclists[i].status = 2;
                finish_order[finish_order_count] = i;
                finish_order_count++;
            }
        }

        /* Verifica o decremento da barreira */
        if ((cyclists[i].status == 3 || cyclists[i].status == 2) 
            && cyclists[i].speed != -1) {  
            barrier_remove_one(sync);
            cyclists[i].speed = -1;
        }
        if (verbose) {
            printf("N %4d, T %d, P %6d, S %2d, E %2d, D %6d, V %2d\n", cyclists[i].number, cyclists[i].team, (cyclists[i].init_position+cyclists[i].dist)%(2*d), cyclists[i].status, cyclists[i].speedway, cyclists[i].dist, cyclists[i].lap);
        }
    }

    ins_first_three ();

    if (verbose) printf("C\n");

    for (i = 0; i < 2; ++i) {
        if (first_3[i][2]->lap != third_lap[i]) {
            third_lap[i] = first_3[i][2]->lap;
            if (!verbose) {
                printf("%4.2f s > TEAM: %d \t", time_count, i);
                printf("F: %d \t (%d) \t", first_3[i][0]->number, first_3[i][0]->dist/2);
                printf("S: %d \t (%d) \t", first_3[i][1]->number, first_3[i][1]->dist/2);
                printf("T: %d \t (%d) \t", first_3[i][2]->number, first_3[i][2]->dist/2);
                printf("LAP %d\n", third_lap[i]);
            }
        }
    }

    if ((third_lap[0] == 16 || third_lap[1] == 16) 
        && end_mode == -1) {
        if (first_3[0][2]->dist == first_3[1][2]->dist) {
            end_mode = EMPATE;
        } else if (first_3[0][2]->dist > first_3[1][2]->dist) {
            end_mode = TEAM_0;
        } else {
            end_mode = TEAM_1;
        }
    }
    
    if (first_3[0][2]->dist - first_3[1][2]->dist > d && end_mode == -1) {
            end_mode = TEAM_0_THIRD;
    } else if (first_3[1][2]->dist - first_3[0][2]->dist > d && end_mode == -1) {
            end_mode = TEAM_1_THIRD;
    }

    for (i = 0; i < 3; ++i) {
        first_3[0][i] = NULL;
        first_3[1][i] = NULL;
    }

    time_count += 0.06;
}
