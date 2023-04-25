/***************************************************************************
 *   auto1.h                                 Version 20210512.104607         *
 *   AFND to AFD                                                           *
 *                                                                         *
 *   Converte AFND para AFD                                                *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file auto1.h
 * \ingroup GroupUnique
 * \brief Converte AFND para AFD
 * \details This program really do a nice job as a template, and template only!
 * \version 20160618.013412
 * \date 2016-06-18
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _EX12_H
#define _EX12_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <allegro.h> /* A game library for graphics, sounds, etc. */
#include <math.h>  /* Mathematics functions */
#include <unistd.h> /* UNIX standard function */
#include <ctype.h> /* Character functions */

/* #include <math.h> */ /* Mathematics functions */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <time.h> */ /* Time and date functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <limits.h> */ /* Various C limits */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20210512.104607" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* Defines Allegro */
#define CORPRETO 1
#define CORBRANCO (makecol(255,255,255))
#define CORCINZA (makecol(160,160,160))
#define CORVERDE (makecol(0, 255, 0))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERMELHO (makecol(255, 0, 0))
#define CORAMARELO (makecol(255,255,100))
#define IMAGENAME "automato.bmp" /* nome do arquivo de imagem */
#define RAIO_ESTADO 20
#define PI 3.14

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_lef
{
    unsigned short int f; /* num estado final */
    struct st_lef *prox;  /* prox nodo */
} t_lef;

/* tipo lista encadeada que contem cabecas das listas de closures de estados */
typedef struct st_novodelta
{
    unsigned short int n; /* numero do estado */
    t_lef *c; /* cabeca da lista de closures */
    struct st_novodelta *prox; /* prox nodo */
} t_novo;

/* tipo lista encadeada simples da funcao de transicao delta */
typedef struct st_delta
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* string com rotulos dos arcos */
    unsigned short int ef;  /* estado destino final */
    struct st_delta *prox;  /* prox nodo */
} t_delta;

/* struct auxiliar para a transicao de deltas */
typedef struct st_rcc
{
    unsigned short int ei; /* estado inicial */
    char *le; /* string com rotulos dos arcos */
    unsigned short int ef; /* estado destino final */
} rcc;

typedef struct st_leal    /* lista de estados allegro  */
{
    int e;                /* numero do estado */
    int x;                /* posicao x do centro do estado */
    int y;                /* posicao y do centro do estado */
    struct st_leal *prox; /* prox nodo */
} t_leal;


typedef struct st_tral
{
    int num; // numero de transicoes com estados ja inseridos
    int e1;
    int e1x;// estado 1 conectado
    int e1y;
    int e2;
    int e2x; // estado 2 conectado
    int e2y;
    int e3;
    int e3x; // estado 3 conectado
    int e3y;
}t_tral;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    unsigned short int K;   /* numero de estados K=3 -> estados q0, q1 e q2 */
    char A;                 /* ultima letra do alfabeto A=b -> {a,b} */
    unsigned short int S;   /* estado inicial */
    t_lef *F;               /* lista de estados finais */
    t_delta *D;             /* lista da funcao de transicao d(ei, le, ef) */
} t_quintupla;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void auto1_init(void);  /**< Initializes some operations before start */
t_quintupla entrada(char *sfile); /**< recebe os dados da quintupla do AFD */
void inserir_ef(t_lef **cabeca, unsigned short int x); /**< insere estados finais */
void inserir_delta(t_delta **cabeca, rcc x); /**< insere lista de transicoes */
void inserir_nd(t_novo **cabeca, t_lef *inicio); /**< insere novo delta */
void imprimir_lista(t_lef *lista); /**< imprime a lista de estados finais */
void imprimir(t_quintupla aut); /**< imprimi quintupla */
void imprimir_ndt(t_novo *ndt); /**< imprimir novos deltas */
void clean(t_quintupla *auto1); /**< limpa a quintupla */
void clean_ndt(t_novo **ndt); /**< limpa lisra de novos deltas */
void remove_d(int es, t_delta **D); /**< remove transicoes de estados inalcansaveis */
void remove_ndt(int es, t_novo **ndt); /**< remove as os esdos inalcansaveis da lista de novos deltas */
void limpa_es_lixo(t_quintupla *aut, t_novo **ndt); /**< limpa os estados que sao inalcansaveis */
void E_closure(t_quintupla *afnd, t_novo **ndt); /**< faz os E-closures */
void assist_closure(int es, t_lef **cabeca, t_delta *D);
int size(t_lef *cabeca); /**< tamanho das listas */
t_novo *compare(t_novo *ndt, t_lef *nodo); /* compara a lista de novos deltas com os closures das transicoes */
t_delta *buscar(t_delta *cabeca, char *x, int es); /* busca se tem uma transicao com um rotulo naquele estado */
int procura(t_lef *cabeca, int es); /**< procura se ja existe um estado com aquele numero na lista */
void tran(t_quintupla *AFND, t_quintupla *afd, t_novo **ndt); /**< transicao da quintupla */
void tran_delta(t_novo *ndt, t_quintupla *afnd, t_quintupla *afd); /**< transicao de deltas */
void lndt(int es, char *le, t_lef **cabeca, t_delta *D); /**< le novos deltas */
void limpa_es_lixo(t_quintupla *aut, t_novo **ndt);
void remove_d(int es, t_delta **D);
void remove_ndt(int es, t_novo **ndt);
void desenho_al(t_quintupla AUT); /**< chama todas as funcoes para gerar o grafico do automato com allegro */
t_leal *cria_nd_al(int x, int y, int e); /**< alocacao de memoria para lista de coordenadas dos estados */
void inserir_estado_al(t_leal **lista, int x, int y, int e); /**< insere estados na lista de coordenadas inicialmente zeradas */
void estados_trans_ei_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int ei, int num_est); /**< insere estados com transicoes ao estado inicial */
void estados_restantes_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int num_est); /**< insere todos os estados do grafico do automato */
void estado_local_vago_al(BITMAP *bmp, t_leal *lista, int x_ref, int y_ref, int e, int num_estado); /**< insere o estado em um local disponivel no bitmap */
void busca_e_insere_al(BITMAP *bmp, t_leal *lista, int e, int x_centro, int y_centro); /**< chamada das funcoes do allegro de circulo e numero do estado */
void posicoes_hex_al(int num_estado, int x, int y, int *p1x, int *p1y, int *p2x, int *p2y, int *p3x, int *p3y, int *p4x, int *p4y, int *p5x, int *p5y, int *p6x, int *p6y); /**< coordenadas para inserir novo estado */
int local_ocupado_al(t_leal *lista, int xb, int yb); /**< testa se algum estado ja foi inserido naquela regiao */
int testa_estado_inserido_al(t_leal *lista, int e); /**< testa se o estado ja foi inserido no Bitmap */
t_tral info_transicoes_al(t_leal *lista, t_delta *trans, int e); /**< informacoes sobre as transicoes */
void estados_finais_al(BITMAP *bmp, t_leal *lista, t_lef *finais); /**< circulo menor no bitmap para estados finais */
void transicoes_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int ei); /**< funcao principal para as setas das transicoes */
void setas_al(BITMAP *bmp, t_delta *trans, int x1, int x2, int y1, int y2, int ei, int ef); /**< insere seta simples no bitmap */
void setas_rev_al(BITMAP *bmp, t_delta *trans, int x1, int y1, int x2, int y2, int ei, int ef); /**< insere setas paralelas para transicoes reversiveis */
void setas_loop_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int e); /**< insere setas das transicoes de loop */
int quadrante_vazio_al(t_leal *lista, t_delta *trans, int e); /**< teste de quadrante vago no bitmap para inserir transicoes de loop */
void clean_ef(t_lef **cabeca);
void clean_al(t_leal **cabeca);
void texto_trans_al(BITMAP *bmp, t_delta *trans, int x, int y, int ei, int ef);

#endif /* NOT def _EX12_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

