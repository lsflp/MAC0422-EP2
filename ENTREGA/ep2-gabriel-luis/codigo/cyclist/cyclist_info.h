/********************************************************************
 *  Nomes: Gabriel Capella                       Números USP: 8962078 
 *         Luís Felipe de Melo Costa Silva                    9297961
 * 
 *  Arquivo:   cyclist_info.h
 *  Descrição: Arquivo que contém a definição de cyclist (ciclista).
 ********************************************************************/ 

#ifndef CYCLIST_INFO_H
#define CYCLIST_INFO_H

/* Definições de velocidade*/
#define SPEED_30 0
#define SPEED_60 1

/* Definições de modo */
#define RANDOM 1
#define CONSTANT 0

/* Definindo o tipo de ciclista que usaremos. */
struct cyclist {
    int             number;        /* Número do ciclista */
    int             team;          /* Número do time: 0 ou 1 */
    int             dist;          /* A distância total percorrida */
    int             status;        /* Ver STATUS. */ 
    int             speed;         /* 0: 30 km/h; 1: 60 km/h */
    int             speedway;      /* Ver SPEEDWAY */
    double          end_moment;    /* Momento em que acaba a prova */
    int             init_position; /* Qual é a linha de chegada */
    int             lap;           /* Marca em qual volta ele está */
    int             lap_marker;    /* A volta só será computada se o fiscal deixar */
};
typedef struct cyclist * Cyclist;

/* STATUS:
 * 0: Esperando para entrar;
 * 1: Correndo;
 * 2: Acabou;
 * 3: Quebrado. */

/* SPEEDWAY:
 * 0:  Internal;
 * 1:  External;
 * -1: Ainda não entrou ou teve que sair; */

#endif
