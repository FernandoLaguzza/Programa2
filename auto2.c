/***************************************************************************
 *   auto2.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert AFD into ER                                                   *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.               *
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
 * @file auto2.c
 * @ingroup GroupUnique
 * @brief Convert AFD into ER
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2017-11-28
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc auto2.c -o auto2.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto2.h */

#include "auto2.h" /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./auto2 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int d = 0;
    char *sfile = NULL;
    t_quintupla AFD;
    AFD.D = NULL;
    char er[SBUFF];

    IFDEBUG("Starting optarg loop...");


    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hcvdf:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'd':
                d++;
                break;
            case 'f':
                sfile = malloc(strlen(optarg) * sizeof(char*));
                strcpy(sfile, optarg);
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    if(!d)
    {
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }
    if(verb)
        printf("Verbose level set at: %d\n", verb);

    auto2_init(); /* global initialization function: ainda a saber para que usar se precisar */

    /* ...and we are done */
    /* Write your code here... */
    AFD = entrada(sfile);
    free(sfile);
    cria_ei(&AFD);
    cria_ef(&AFD);
    conversao(&AFD);
    strcpy(er, AFD.D->le);
    printf("%s\n", er);
    clean(&AFD);

    return EXIT_SUCCESS;
}

/* Write your functions here... */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "auto2", VERSION, "Convert AFD into ER");
    printf("\nUsage: %s [-h|-v|-c]\n", "auto2");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-d): input data is an DFA (Deterministic Finite Automata) 5-tuple to be converted to RE (Regular Expression) string.\n");
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto2", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void auto2_init(void)
{
    IFDEBUG("auto2_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return t_quintupla
 * @todo Need to implement it. Its empty now.
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221230.095802
 * @date 2022-12-30
 *
 */

t_quintupla entrada(char *sfile)
{
    t_quintupla afd;
    FILE *entrada;
    rcc delta;
    unsigned short int f = 0;
    int n = 0;
    char aux[10] = {0};
    afd.F = NULL;
    afd.D = NULL;

    IFDEBUG("entrada()");
    if(sfile != NULL)
    {
        entrada = fopen(sfile, "r");
        do
        {
            n = fscanf(entrada, "%s", aux);
            if(!strcmp (aux, "#K"))
                fscanf(entrada, "%hu", &afd.K);

            if(!strcmp (aux, "#A"))
                fscanf(entrada, "%s", &afd.A);

            if(!strcmp (aux, "#S"))
                fscanf(entrada, "%hu", &afd.S);

            if(!strcmp(aux,"#F"))
            {
                fscanf(entrada, "%s", aux);
                while(strcmp(aux, "#D"))
                {
                    f = aux[0] - '0';
                    inserir_ef(&afd.F, f);
                    fscanf(entrada, "%s", aux);
                }
            }

            if(!strcmp(aux, "#D"))
            {
                fscanf(entrada, "%hu %s %hu", &delta.ei, aux, &delta.ef);
                do
                {
                    strtok(aux, "\n");
                    delta.le = malloc(strlen(aux) * sizeof(char*));
                    strcpy(delta.le, aux);
                    inserir_delta(&afd.D, delta);
                    free(delta.le);
                    n = fscanf(entrada, "%hu%s%hu", &delta.ei, aux, &delta.ef);
                }
                while(n == 3);
            }
        }
        while(n == 1);
        fclose(entrada);
    }
    else
    {
        do
        {
            n = scanf("%s", aux);
            if(!strcmp (aux, "#K"))
                scanf("%hu", &afd.K);

            if(!strcmp(aux, "#A"))
                scanf("%s", &afd.A);

            if(!strcmp (aux, "#S"))
                scanf("%hu", &afd.S);

            if(!strcmp(aux,"#F"))
            {
                scanf("%s", aux);
                while(strcmp(aux, "#D"))
                {
                    f = aux[0] - '0';
                    inserir_ef(&afd.F, f);
                    scanf("%s", aux);
                }
            }

            if(!strcmp(aux, "#D"))
            {
                scanf("%hu %s %hu", &delta.ei, aux, &delta.ef);
                do
                {
                    strtok(aux, "\n");
                    delta.le = malloc(strlen(aux) * sizeof(char*));
                    strcpy(delta.le, aux);
                    inserir_delta(&afd.D, delta);
                    free(delta.le);
                    n = scanf("%hu%s%hu", &delta.ei, aux, &delta.ef);
                }
                while(n == 3);
            }
        }
        while(n == 1);
    }

    return afd;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief This function initializes some operations before start
* @details Details to be written
* @return Void
* @todo Need to implement it. Its empty now.
* @author Marcio Andre Alves goncalves sobrinho
* @version 20160520.000202
* @date 2016-05-20
*
*/

void inserir_delta(t_delta **cabeca, rcc x)
{
    t_delta *pl = *cabeca;
    t_delta *plant = NULL;

    IFDEBUG("inserir_delta()");
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(t_delta));
    pl->le = malloc(strlen(x.le) * sizeof(char*));
    pl->ei = x.ei;
    strcpy(pl->le, x.le);
    pl->ef=x.ef;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;

}

/*---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief This function initializes some operations before start
* @details Details to be written
* @return Void
* @todo Need to implement it. Its empty now.
* @author Marcio Andre Alves goncalves sobrinho
* @version 20160520.000202
* @date 2016-05-20
*
*/
void clean(t_quintupla *auto2)
{
    t_delta *d = auto2->D, *dant = NULL;

    IFDEBUG("clean()");
    clean_ef(&auto2->F);
    while(d != NULL)
    {
        dant = d;
        d = d->prox;
        free(dant->le);
        free(dant);
    }
    auto2->F = NULL;
    auto2->D = NULL;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221230.095802
 * @date 2022-12-30
 *
 */

void inserir_ef(t_lef **cabeca, unsigned short int x)
{
    t_lef *pl = *cabeca;
    t_lef *plant = NULL;

    IFDEBUG("inserir_ef()");
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(t_lef));
    pl->f = x;
    pl->prox = NULL;
    if(plant != NULL)
        plant->prox = pl;
    else
        *cabeca = pl;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return void
 * @todo Need to implement it. Its empty now.
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221230.095802
 * @date 2022-12-30
 *
 */

void imprimir(t_quintupla aut)
{
    t_delta *pi = aut.D;
    t_lef *pl = aut.F;

    IFDEBUG("imprimir()");
    printf("#K\n");
    printf("%hu\n", aut.K);

    printf("#A\n");
    printf("%c\n", aut.A);

    printf("#S\n");
    printf("%hu\n", aut.S);

    printf("#F\n");
    while(pl!=NULL)
    {
        printf("%hu ", pl->f);
        pl=pl->prox;
    }
    printf("\n");

    printf("#D\n");
    while(pi!=NULL)
    {
        printf("%hu %s %hu\n", pi->ei, pi->le, pi->ef);
        pi=pi->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return void
 * @todo Need to implement it. Its empty now.
 * @author Fernando Laguzza De Oliveira Filho
 * @version 20221230.095802
 * @date 2022-12-30
 *
 */

void cria_ei(t_quintupla *aut)
{
    rcc novo;

    IFDEBUG("cria_ei()");
    novo.ei = aut->K;
    novo.le = "E";
    novo.ef = aut->S;
    inserir_delta(&aut->D, novo);

    aut->S = aut->K;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return void
 * @todo Need to implement it. Its empty now.
 * @author Fernando Laguzza De Oliveira Filho
 * @version 20221230.095802
 * @date 2023-03-14
 *
 */

void cria_ef(t_quintupla *aut)
{
    t_lef *pl = aut->F;
    int x = aut->K + 1;
    rcc novo;

    IFDEBUG("cria_ef()");
    while(pl != NULL)
    {
        novo.ei = pl->f;
        novo.le = "E";
        novo.ef = x;
        inserir_delta(&aut->D, novo);
        pl = pl->prox;
    }
    clean_ef(&aut->F);
    inserir_ef(&aut->F, x);

    return;
}

/* ---------------------------------------------------------------------- */

void clean_ef(t_lef **cabeca)
{
    t_lef *pl = *cabeca, *plant = NULL;

    IFDEBUG("clean_ef()");
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
        free(plant);
    }
    *cabeca = NULL;

    return;
}

/* ---------------------------------------------------------------------- */

int procura(t_lef *cabeca, int es)
{
    t_lef *pl = cabeca;

    IFDEBUG("procura()");
    while(pl != NULL)
    {
        if(pl->f == es)
            return 1;
        pl = pl->prox;
    }
    return 0;
}

/* ---------------------------------------------------------------------- */

t_lef *busca(t_lef *cabeca, int es)
{
    t_lef *pl = cabeca;
    IFDEBUG("busca()");
    while(pl != NULL)
    {
        if(pl->f == es)
            return pl;
        pl = pl->prox;
    }

    return NULL;
}

/* ---------------------------------------------------------------------- */

void remover_ei(t_lef **cabeca, t_lef *remover)
{
    t_lef *pl = *cabeca;
    t_lef *plant = NULL;

    IFDEBUG("remover_ei()");
    if(remover == NULL)
        return;

    while(pl != NULL && pl != remover)
    {
        plant = pl;
        pl = pl->prox;
    }

    if(pl == NULL)
        return;
    if(plant != NULL)
        plant->prox  = pl->prox;
    else
        *cabeca = pl->prox;

    free(pl);

    return;
}

/* ---------------------------------------------------------------------- */

int size(t_lef *nodo)
{
    t_lef *pl = nodo;
    int count = 0;

    IFDEBUG("size()");
    while(pl != NULL)
    {
        count++;
        pl = pl->prox;
    }
    return count;
}

/* ---------------------------------------------------------------------- */

void conversao(t_quintupla *aut)
{
    t_lef *fant = NULL;
    int eiant = 0, aux = aut->F->f;
    t_delta *pl = aut->D;

    IFDEBUG("conversao()");
    while(pl != NULL)
    {
        if(pl->ei == aut->S)
            eiant = pl->ef;
        if(pl->ef == aux)
            inserir_ef(&fant, pl->ei);
        pl = pl->prox;
    }
    pl = aut->D;
    while(pl != NULL)
    {
        if(pl->ei != eiant && !procura_ef(fant, pl->ei) && pl->ei != aut->S)
        {
            elimina_estado(pl->ei, &aut->D);
            pl = aut->D;
        }
        else
            pl = pl->prox;
    }
    simplifica_deltas(&aut->D);
    elimina_E(&aut->D, eiant, fant);
    pl = aut->D;
    while(pl != NULL)
    {
        if(pl->ei != aut->S && procura(aut->F, pl->ef))
            elimina_estado(pl->ei, &aut->D);
        pl = pl->prox;
    }
    simplifica_deltas(&aut->D);
    clean_ef(&fant);

    return;
}

/* ---------------------------------------------------------------------- */

void simplifica_deltas(t_delta **D)
{
    t_delta *pl = *D, *pi = NULL;
    rcc aux;
    char tran[SBUFF] = {'\0'};

    IFDEBUG("simplifica_deltas()");
    while(pl != NULL)
    {
        aux.ei = pl->ei;
        aux.ef = pl->ef;
        pi = *D;
        while(pi != NULL)
        {
            if(aux.ei == pi->ei && aux.ef == pi->ef && pl != pi)
            {
                if(strlen(pl->le) == 1)
                {
                    strcpy(tran, pl->le);
                    strcat(tran, "|");
                }
                else
                    if(strlen(pl->le) > 1)
                    {
                        strcpy(tran, "(");
                        strcat(tran, pl->le);
                        strcat(tran, ")|");
                    }
                if(strlen(pi->le) > 1)
                {
                    strcat(tran, "(");
                    strcat(tran, pi->le);
                    strcat(tran, ")");
                }
                else
                    strcat(tran, pi->le);
                aux.le = malloc(strlen(tran) * sizeof(char*));
                strcpy(aux.le, tran);
                inserir_delta(D, aux);
                remover_delta(D, pi);
                remover_delta(D, pl);
                free(aux.le);
                pl = *D;
                break;
            }
            pi = pi->prox;
        }
        pl = pl->prox;
    }
}

/* ---------------------------------------------------------------------- */

void remover_delta(t_delta **D, t_delta *es)
{
    t_delta *pl = *D, *plant = NULL;

    IFDEBUG("remover_delta()");
    while(pl != NULL && pl != es)
    {
        plant = pl;
        pl = pl->prox;
    }
    if(pl == NULL)
        return;
    if(plant != NULL)
        plant->prox = pl->prox;
    else
        *D = pl->prox;
    free(pl->le);
    free(pl);

    return;
}

/* ---------------------------------------------------------------------- */

t_lef *procura_ef(t_lef *cabeca, int es)
{
    t_lef *pl = cabeca;

    IFDEBUG("procura_ef()");
    while(pl != NULL)
    {
        if(pl->f == es)
            return pl;
        pl = pl->prox;
    }

    return NULL;
}

/* ---------------------------------------------------------------------- */

void elimina_estado(int es, t_delta **D)
{
    t_delta *pl = *D, *aux1 = NULL, *pi = NULL;
    rcc aux;
    char *str = NULL, tran[SBUFF] = {'\0'};

    IFDEBUG("elimina_estado()");
    while(pl != NULL)
    {
        if(pl->ef == es && pl->ef != pl->ei)
        {
            if(strchr(pl->le, '|'))
            {
                strcpy(tran, "(");
                strcat(tran, pl->le);
                strcat(tran, ")");
                aux.le = tran;
            }
            else
                aux.le = pl->le;
            aux.ei = pl->ei;
            aux.ef = DEFAULT;
            inserir_delta(D, aux);
        }
        pl = pl->prox;
    }
    pl = *D;
    while(pl != NULL)
    {
        if(pl->ef == DEFAULT)
        {
            aux1 = pl;
            pi = *D;
            while(pi != NULL)
            {
                if(pi->ei == es)
                {
                    aux.ei = aux1->ei;
                    strcpy(tran, aux1->le);
                    strcat(tran, ".");
                    str = estrela(es, *D);
                    if(str != NULL)
                    {
                        strcat(tran, str);
                        strcat(tran, ".");
                    }
                    strcat(tran, pi->le);
                    aux.ef = pi->ef;
                    aux.le = malloc(strlen(tran)*sizeof(char*));
                    strcpy(aux.le, tran);
                    inserir_delta(D, aux);
                    free(str);
                    free(aux.le);
                }
                pi = pi->prox;
            }
        }
        pl = pl->prox;
    }
    retira_es(D, es);

    return;
}

/* ---------------------------------------------------------------------- */
void elimina_E(t_delta **D, int old_ei, t_lef *old_ef)
{
    t_delta *pl = *D, *pi = *D;
    t_lef *fant = old_ef;
    rcc aux;
    char tran[SBUFF] = {'\0'};
    int i = 0;
    char *str = NULL;

    IFDEBUG("elimina_E()");
    while(fant != NULL)
    {
        str = estrela(fant->f, *D);
        if(str == NULL)
        {
            while(pl != NULL)
            {
                if(pl->ei == fant->f)
                    i++;
                pl = pl->prox;
            }
            pl = *D;
            if(i == 1)
            {
                while(pi != NULL)
                {
                    if(pi->ei == fant->f && !strcmp(pi->le, "E"))
                        break;
                    pl = pl->prox;
                }
                if(pi == NULL)
                {
                    printf("algo deu errado\n");
                    exit(0);
                }
                while(pl != NULL)
                {
                    if(pl->ef == fant->f)
                        pl->ef = pi->ef;
                    pl = pl->prox;
                }
            }
            else
                continue;
        }
        else
        {
            while(pi != NULL)
            {
                if(pi->ei == fant->f && pi->ef == pi->ei)
                    remover_delta(D, pi);
                pi = pi->prox;
            }
            while(pl != NULL)
            {
                pi = *D;
                if(pl->ei == fant->f && pl->ef != pl->ei && !strcmp(pl->le, "E"))
                {
                    aux.ei = pl->ei;
                    aux.le = malloc(strlen(str) * sizeof(char*));
                    aux.ef = pl->ef;
                    strcpy(aux.le, str);
                    inserir_delta(D, aux);
                    free(aux.le);
                    while(pi != NULL)
                    {
                        if(pi->ei == aux.ei && strcmp(pi->le, "E") && !strstr(pi->le, str))
                        {
                            strcpy(tran, str);
                            if(strlen(pi->le) > 1)
                            {
                                strcat(tran, ".(");
                                strcat(tran, pi->le);
                                strcat(tran, ")");
                            }
                            else
                            {
                                strcat(tran, ".");
                                strcat(tran, pi->le);
                            }
                            aux.le = malloc(strlen(tran) * sizeof(char*));
                            aux.ef = pi->ef;
                            strcpy(aux.le, tran);
                            inserir_delta(D, aux);
                            free(aux.le);
                            remover_delta(D, pi);
                            pi = *D;
                        }
                        pi = pi->prox;
                    }
                    remover_delta(D, pl);
                    pl = *D;
                }
                pl = pl->prox;
            }
            free(str);
        }
        pl = *D;
        fant = fant->prox;
    }
    pl = *D;
    while(pl != NULL)
    {
        if(pl->ef == old_ei)
        {
            i = pl->ei;
            pl = *D;
            break;
        }
        pl = pl->prox;
    }
    while(pl != NULL)
    {
        if(pl->ei == old_ei)
            pl->ei = i;
        if(pl->ef == old_ei)
            pl->ef = i;
        if(pl->ei == i && !strcmp(pl->le, "E"))
            remover_delta(D, pl);
        pl = pl->prox;
    }

    return;
}

/* ---------------------------------------------------------------------- */

char *estrela(int es, t_delta *D)
{
    IFDEBUG("estrela()");
    t_delta *pl = D;
    char aux[SBUFF] = "default", *aux2 = NULL;
    int i = 0;

    while(pl != NULL && pl->ei != es)
        pl = pl->prox;

    while(pl != NULL)
    {
        if(pl->ei == pl->ef && i == 0 && pl->ei == es)
        {
            strcpy(aux, pl->le);
            i++;
        }
        else
            if(pl->ei == pl->ef && i > 0 && pl->ei == es)
            {
                strcat(aux, "|");
                strcat(aux, pl->le);
            }
        pl = pl->prox;
    }
    if(!strcmp(aux, "default"))
        return NULL;
    strtok(aux, "\n");
    if(strlen(aux) == 1)
    {
        aux2 = malloc(strlen(aux) * sizeof(char*));
        strcat(aux, "*");
        strcpy(aux2, aux);
        return aux2;
    }
    else
    {
        aux2 = malloc(strlen(aux) * sizeof(char*));
        strcpy(aux2, "(");
        strcat(aux2, aux);
        strcat(aux2, ")*");
        return aux2;
    }
    printf("saiu\n");
    return NULL;
}

/* ---------------------------------------------------------------------- */



/* ---------------------------------------------------------------------- */

void retira_es(t_delta **cabeca, int es)
{
    t_delta *pl = *cabeca, *plant = NULL;

    IFDEBUG("retira_es()");
    while(pl != NULL)
    {
        if(pl->ei == es || pl->ef == es || pl->ef == DEFAULT)
        {
            if(plant != NULL)
            {
                plant->prox = pl->prox;
                free(pl->le);
                free(pl);
                pl = *cabeca;
            }
            else
            {
                *cabeca = pl->prox;
                free(pl->le);
                free(pl);
                pl = *cabeca;
            }
        }
        else
        {
            plant = pl;
            pl = pl->prox;
        }
    }

    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */
int funcexample(int i, int *o, int *z)
{
    IFDEBUG("funcexample()");
    i += *z;
    *o = (*z)++;
    return i - 4;
}


/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

