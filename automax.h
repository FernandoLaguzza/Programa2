/***************************************************************************
 *   automax.h                                 Version 20210512.104607         *
 *   AFND, AFD and ER                                                      *
 *                                                                         *
 *   Converte de tudo: AFD, AFND e ER                                      *
 *   Copyright (C) 2016-2021         by Ruben Carlo Benante                *
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
 * \file automax.h
 * \ingroup GroupUnique
 * \brief Converte AFD, AFND e ER
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

#ifndef _EXALL_H
#define _EXALL_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <string.h> /* Strings functions definitions */
#include <getopt.h> /* get options from system argc/argv */
#include <allegro.h> /* A game library for graphics, sounds, etc. */
#include <math.h>  /* Mathematics functions */
#include <unistd.h> /* UNIX standard function */
#include <ctype.h> /* Character functions */

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
#define DEFAULT 65535 /**< estado de default */

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

/* tipo lista encadeada simples das posicoes do allegro */
typedef struct st_leal
{
    int x; /* posicao x */
    int y; /* posicao i */
    int e; /* estado */
    struct st_leal *prox; /* prox nodo */
} t_leal;

/* tipo lista para transicao dos deltas */
typedef struct st_novodelta
{
    unsigned short int n; /* numero do estado */
    t_lef *c; /* endereco para lista de estados */
    struct st_novodelta *prox; /* prox nodo */
} t_novo;

 /* tipo tral: estados conectados e suas posicoes */
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
} t_tral;

 /* tipo arvore para organizar elementos da expressao regular */
typedef struct st_folha
{
    char carac; //caractere
    struct st_folha *ant; // elemento a esquerda
    struct st_folha *esq; // elemento a esquerda
    struct st_folha *dir; // elemento a direita
} t_folha;

/* tipo lista encadeada simples da funcao de transicao delta */
typedef struct st_delta
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* string com rotulos dos arcos */
    unsigned short int ef;  /* estado destino final */
    struct st_delta *prox;  /* prox nodo */
    struct st_delta *ant;   /* nodo anterior */
} t_delta;

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
void automax_init(void);  /**< Initializes some operations before start */
void afnd2afd_init(char *sfile, t_quintupla *afd);
void afd2er_init(char *sfile, t_quintupla *afd);
void er2afnd_init(char *sfile, char *expressao, t_quintupla *aut);
void automax_update(void); /**< Updates values during program cycle */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
t_quintupla entrada(char *sfile); /* recebe os dados da quintupla do AFD */
char *entrada_ER(char *sfile, char *expressao); /**< recebe a ER */
void inserir_delta(t_delta **cabeca, t_delta x); /**< Insere as transicoes do delta */
void inserir_ef(t_lef **cabeca, unsigned short int x); /**< Insere a lista de estados finais */
void inserir_nd(t_novo **cabeca, t_lef *inicio);
void inserir_estado_al(t_leal **lista, int x, int y, int e);
void clean_Q(t_quintupla *aut);
void clean_ef(t_lef **cabeca);
void clean_ndt(t_novo **ndt);
void clean_al(t_leal **cabeca);
void clean_delta(t_delta **cabeca);
void derruba_arvore(t_folha *topo);
void remove_ndt(int es, t_novo **ndt);
void remove_d(int es, t_delta **D);
void remover_delta(t_delta **D, t_delta *es);
void remover_ei(t_lef **cabeca, t_lef *remover);
void retira_es(t_delta **cabeca, int es);
t_lef *remove_ef(t_lef **F, int num); /* remove elementos da lista de estados finais */
void imprimir(t_quintupla aut);
int procura(t_lef *cabeca, int es);
t_delta *buscar(t_delta *cabeca, char *x, int es);
t_lef *procura_ef(t_lef *cabeca, int es);
t_novo *compare(t_novo *ndt, t_lef *nodo);
int size(t_lef *nodo);
/* ------------ afnd 2 afd ------------*/
void E_closure(t_quintupla *aut, t_novo **ndt);
void assist_closure(int es, t_lef **cabeca, t_delta *D);
void afnd2afd(t_quintupla *AFND, t_quintupla *afd, t_novo **ndt);
void tran_delta(t_novo *ndt, t_quintupla *afnd, t_quintupla *afd);
void lndt(int es, char *le, t_lef **cabeca, t_delta *D);
void limpa_es_lixo(t_quintupla *aut, t_novo **ndt);
/* ------------- afd 2 er -------------*/
void cria_ei(t_quintupla *aut);
void cria_ef(t_quintupla *aut);
void conversao(t_quintupla *aut);
char *estrela(int es, t_delta *D);
void elimina_estado(int es, t_delta **D);
void elimina_E(t_delta **D, int old_ei, t_lef *old_ef);
void simplifica_deltas(t_delta **D);
/* ------------ er 2 afnd -------------*/
//char *s_entrada(char *sfile, char *expressao);
void criar_arvore(t_folha **topo, char *expressao);
unsigned short cria_K(t_delta *trans);
char cria_A(t_delta *D);
int cria_S(t_delta *trans);
t_lef *cria_F(t_delta *trans);
int info_trans(t_delta *trans, int x);
int info_ef(t_lef *lista, int x);
void cria_D(t_folha *topo, t_delta **trans, t_delta **lt_kleene,t_lef **lista, int ei, int ef);
void inserir_delta_auto3(t_delta **cabeca, int ei, char *le, int ef);
void barra(t_delta **trans, t_folha *topo, int *ei, int *ef);
void pipe_parenteses(t_delta **trans, int conta, int *ei, int *ef);
void pipe_pipe(t_delta **trans, int conta, int *ei, int *ef);
void trans_kleene(t_folha *topo, t_delta **trans, t_delta **lt_kleenef,t_lef **lista, int *ei, int *ef);
void kleene_parenteses(t_delta **trans,t_delta **lt_kleene,t_lef **lista, int conta, int continua);
void kleene_pipe(t_delta **trans, t_delta **lt_kleene,t_lef **lista, int conta, int continua);
t_quintupla cria_quintupla(unsigned short K, char A, unsigned short S, t_lef *F, t_delta *D);
void une_e_ordena_trans(t_delta *lista1, t_delta *lista2);
void une_ef(t_lef *lista1, t_lef *lista2);
/* ------------- ALLEGRO --------------*/
void desenho_al(t_quintupla AUT);
void estados_trans_ei_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int ei, int num_est);
void estados_restantes_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int num_est);
void estado_local_vago_al(BITMAP *bmp, t_leal *lista, int x_ref, int y_ref, int e, int num_est);
void busca_e_insere_al(BITMAP *bmp, t_leal *lista, int e, int x_centro, int y_centro);
void posicoes_hex_al(int num_estado, int x, int y , int *p1x, int *p1y, int *p2x, int *p2y, int *p3x, int *p3y, int *p4x, int *p4y, int *p5x, int *p5y, int *p6x, int *p6y);
int local_ocupado_al(t_leal *lista, int xb, int yb);
int testa_estado_inserido_al(t_leal *lista, int e);
t_tral info_transicoes_al(t_leal *lista, t_delta *trans, int e);
void estados_finais_al(BITMAP *bmp, t_leal *lista, t_lef *finais);
void transicoes_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int ei);
void setas_al(BITMAP *bmp, t_delta *trans, int x1, int x2, int y1, int y2, int ei, int ef);
void setas_rev_al(BITMAP *bmp, t_delta *trans, int x1, int y1, int x2, int y2, int ei, int ef);
void setas_loop_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int e);
int quadrante_vazio_al(t_leal *lista, t_delta *trans, int e);
void texto_trans_al(BITMAP *bmp, t_delta *trans, int x, int y, int ei, int ef);

#endif /* NOT def _EXALL_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

