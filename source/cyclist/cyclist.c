/* //////////////////////////////////////////////////////////////
// 
// Autor: Gabriel Capella
// Numero USP: 8962078
// Sigla: GABRIELC
// Data: 2015-10-13
// 
////////////////////////////////////////////////////////////// */

/* Cada ciclista sabe suas regras, ele tem que completar 16, tem 

*/
#include "cyclist.h"

static int **positions; /* ponteiro para endereco da pista */
static int lap_distance; /* marca o tamanho da pista */
static pthread_mutex_t *positions_lock; /* mutexs das posicoes */
static Barrier sync;
static int mode; /* 0 velocidade uniforme, 1 velocidade variada */
static int count[2]; /* conta quantos tem em cada equipe */
static pthread_mutex_t count_lock; /* trava o count */

/* retorna a posicao da frente da bike */
static int p (Cyclist data, int i) {
    return ((data->init_position+data->dist)+i)%(2*lap_distance);
}

/* retorna o mutex da posicao da frente da bike */
static pthread_mutex_t * m (Cyclist data, int i) {
    return &positions_lock[p(data, i)];
}

/* Tenta colocar o cara na pista */
static void cyclist_start (Cyclist data) {
    pthread_mutex_lock(m(data,0));
    pthread_mutex_lock(m(data,1));
    { /* conseguiu a chave para editar a posicao */
        if (positions[0][p(data,1)] == -1 && positions[0][p(data,0)] == -1) {
            positions[0][p(data,1)] = data->number;
            positions[0][p(data,0)] = data->number;
            data->status = 1;
            data->speedway = 0;
        }
    }
    pthread_mutex_unlock(m(data,0));
    pthread_mutex_unlock(m(data,1));
}

/* tenta vançar o ciclista i posicoes, retorna o numero de posicoes avancadas */
static int advance (Cyclist data, int i) {
    int j, k;
    for (k = i; k > 0; --k) {
        for (j = 0; j < 2; ++j) {
            pthread_mutex_lock(m(data,0+i));
            pthread_mutex_lock(m(data,1+i));
            { /* conseguiu a chave para editar a posicao */
                if (positions[j][p(data, k)] == -1 && positions[j][p(data, 1+k)] == -1) {
                    positions[j][p(data, k)] = data->number;
                    positions[j][p(data, 1+k)] = data->number;
                    data->speedway = j;
                    pthread_mutex_unlock(m(data,1+i));
                    pthread_mutex_unlock(m(data,0+i));
                    return k;
                }
            }
            pthread_mutex_unlock(m(data,1+i));
            pthread_mutex_unlock(m(data,0+i));
        }
    }
    /* fprintf(stderr, "Ciclista ficou parado!\n"); */
    return 0;
}

/* antes de criar as threads, chmar essa funcao para configurar o ambiente */
void cyclists_setup (int **speedway, pthread_mutex_t *lock, int d, int n, int _mode) {
    lap_distance = d;
    positions = speedway;
    positions_lock = lock;
    mode = _mode;
    /* cria barreira */
    barrier_init(&sync, 2 * n);
    count[0] = n;
    count[1] = n;
    pthread_mutex_init(&count_lock, 0);
}

void cyclist_setup (Cyclist data, int number, int team) {
    data->number = number;
    data->team = team;
    data->dist = 0;
    data->status = 0;
    if (mode == RANDOM) data->speed = SPEED_30;
    else data->speed = SPEED_60;
    data->speedway = -1;
    data->end_moment = -1;
    data->lap = 0;
    data->lap_marker = 0;
    if (team == 1) data->init_position = 0;
    else data->init_position = lap_distance;
}

void cyclists_free () {
    barrier_destroy(&sync);
    pthread_mutex_destroy(&count_lock);
}

void * cyclist_thread (void *info) {
    Cyclist data;
    int tmp;
    int round;
    round = 0;
    data = (Cyclist) info;

    while (1) {
        if (round%2 == SPEED_30) { /* anda as pessoas de 30km/h */
            if (data->status == 1 && data->speed == SPEED_30) {
                data->dist += advance (data, 1); /* avanca uma casa, d/2 */
            }
        } else if (round%2 == SPEED_60) { /* anda as pessoas de 60km/h */
            if (data->status == 0) { 
                cyclist_start(data);
            } else if (data->status == 1 && data->speed == SPEED_60) {
                data->dist += advance (data, 2); /* avanca duas casas, d */
            }
            tmp = data->dist/(lap_distance*2);
            /* atualiza a volta e sortea velocidade */
            if (data->lap != tmp) {
                if (mode == RANDOM && rand()%2 == 1) {
                    if (ins_can_go_60 (data)) data->speed = 1;
                } else {
                    data->speed = 1 - mode;
                }
                data->lap_marker = 1;
            }

            /* verifica se deve quebrar */
            if ((data->speed+1)/(80.0*lap_distance) >= rand()*1.0/RAND_MAX ) {
                pthread_mutex_lock(&count_lock);
                if (count[data->team] > 3) {
                    --(count[data->team]);
                    data->status = 3;
                }
                pthread_mutex_unlock(&count_lock);
            }

            /* chama o inspetor */
            barrier_wait(&sync, ins_check, (void *)&sync);
            if (data->status != 0) {
                positions[data->speedway][p(data,1)] = -1;
                positions[data->speedway][p(data,0)] = -1;
            }
            if (data->status == 3 || data->status == 2) {
                /* multiplica o numero de passos por 60 ms */
                data->end_moment = round * 0.03;
                break;
            }
        }
        barrier_wait(&sync, NULL, NULL);
        ++(round);
    }
    return NULL;
}
