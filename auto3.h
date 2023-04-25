/***************************************************************************
 *   auto3.h                                 Version 20210512.104607         *
 *   ER to AFND                                                            *
 *                                                                         *
 *   Library for auto3, a program that converts ER into AFND                 *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License                *
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
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file auto3.h
 * \ingroup GroupUnique
 * \brief Converte ER para AFND
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

#ifndef _EX14_H
#define _EX14_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h>  /* Strings functions definitions */

/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
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
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION
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

/* ---------------------------------------------------------------------- */
/* globals */

    static int verb=0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_lef
{
    unsigned short int f; /* num estado final */
    struct st_lef *prox;  /* prox nodo */
} t_lef;

/* tipo lista encadeada simples da funcao de transicao delta */
typedef struct st_delta
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* string com rotulos dos arcos */
    unsigned short int ef;  /* estado destino final */
    struct st_delta *ant;   /* nodo anterior*/
    struct st_delta *prox;  /* prox nodo */
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

typedef struct st_folha
{
    char carac; //caractere
    struct st_folha *ant; // elemento a esquerda
    struct st_folha *esq; // elemento a esquerda
    struct st_folha *dir; // elemento a direita
} t_folha;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void auto3_init(void); /* global initialization function */
void auto3_update(void); /**< Updates values during program cycle */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
t_quintupla entrada(void); /* recebe os dados da quintupla do AFD */
char *s_entrada(char *sfile, char *expressao);
void criar_arvore(t_folha **topo, char *expressao);
unsigned short cria_K(t_delta *trans);
char cria_A(t_delta *D);
int cria_S(t_delta *trans);
t_lef *busca(t_lef *cabeca, int es);
void inserir_ef(t_lef **cabeca, unsigned short int x);
t_lef *remove_ef(t_lef **F, int num); /* remove elementos da lista de estados finais */
t_lef *cria_F(t_delta *trans);
int info_trans(t_delta *trans, int x);
int info_ef(t_lef *lista, int x);
void cria_D(t_folha *topo, t_delta **trans, t_delta **lt_kleene,t_lef **lista, int ei, int ef);
void inserir_delta(t_delta **cabeca, int ei, char *le, int ef);
void pipe(t_delta **trans, t_folha *topo, int *ei, int *ef);
void pipe_parenteses(t_delta **trans, int conta, int *ei, int *ef);
void pipe_pipe(t_delta **trans, int conta, int *ei, int *ef);
void trans_kleene(t_folha *topo, t_delta **trans, t_delta **lt_kleenef,t_lef **lista, int *ei, int *ef);
void kleene_parenteses(t_delta **trans,t_delta **lt_kleene,t_lef **lista, int conta);
void kleene_pipe(t_delta **trans, t_delta **lt_kleene,t_lef **lista, int conta);
t_quintupla cria_quintupla(unsigned short K, char A, unsigned short S, t_lef *F, t_delta *D);
void imprimir(t_quintupla aut);
void une_e_ordena_trans(t_delta *lista1, t_delta *lista2);
void une_ef(t_lef *lista1, t_lef *lista2);
void clean_Q(t_quintupla *aut);
void clean_ef( t_lef **cabeca);
void clean_delta(t_delta **cabeca);
void derruba_arvore(t_folha *topo);

#endif /* NOT def _EX14_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

