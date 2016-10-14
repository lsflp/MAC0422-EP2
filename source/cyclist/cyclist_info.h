/* //////////////////////////////////////////////////////////////
// 
// Autor: Gabriel Capella
// Numero USP: 8962078
// Sigla: GABRIELC
// Data: 2015-10-13
// 
////////////////////////////////////////////////////////////// */
#ifndef CYCLIST_INFO_H
#define CYCLIST_INFO_H

/* definicoes de velocidade*/
#define SPEED_30 0
#define SPEED_60 1

/* definicoes de modo */
#define RANDOM 1
#define CONSTANT 0


struct cyclist {
    int             number; /* numero do ciclista */
    int             team; /* numero do time, 0 ou 1 */
    int             dist; /* a distancia total percorrida */
    int             status; /* 0, esperando entrar, 1 correndo, 2 acabou, 3 quebrado */
    int             speed; /* 1: 60, 0: 30 */
    int             speedway; /* 0: internal, 1: external, -1 ainda nao entrou ou teve que sair */
    double          end_moment; /* momento em que acaba prova */
    int             init_position; /* qual e a linha de chegada */
    int             lap; /* marca em qual volta esta */
    int             lap_marker; /* o volta somnete sera computado se o fiscal deixar */
};
typedef struct cyclist * Cyclist;

#endif
