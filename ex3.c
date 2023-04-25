/***************************************************************************
 *   ex3.c                                    Version 20221211.120939      *
 *                                                                         *
 *   Brief description                                                     *
 *   Copyright (C) 2022         by Fernando Laguzza De Oliveira Filho      *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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
 *   Fernando Laguzza De Oliveira Filho                                    *
 *   Email: flof@poli.br                                                   *
 *   Webpage: http://beco.poli.br/flof@poli.br                             *
 *   Phone: (87) 99150-3087                                                *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex3.c -o ex3.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include "libre.h" /* My personal library */
#include <time.h>  /* Time and date functions */

/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex3.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20221211.120939" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */

/* ---------------------------------------------------------------------- */

int main(void)

{
    /* local declarations */
	int vetor[25] = {0};
    int i;

    /* code */
    help();
    copyr();

    srand(time(NULL));
    for(i = 0; i < 25; i++)
    {
        vetor[i] = rand() % 50;
    }

	sorteio(vetor, 25);

    /* ...and we are done */
    return EXIT_SUCCESS;
}

/* add more functions here */

/* ---------------------------------------------------------------------- */
/* Prints help information 
 *  usually called by opt -h or --help
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex3", "Brief description");
    printf("\nUsage: %s\n\n", "ex3");
    printf("This program does...\n");
    /* add more stuff here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Fernando Laguzza De Oliveira Filho", "flof@poli.br");
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information 
 *  usually called by opt -V
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex3", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2022, "Fernando Laguzza De Oliveira Filho", "flof@poli.br");
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

