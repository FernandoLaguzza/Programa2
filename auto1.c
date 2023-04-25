/***************************************************************************
 *   auto1.c                                 Version 20210512.104607         *
 *                                                                         *
 *   Converte AFND para AFD                                                *
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
 * @file auto1.c
 * @ingroup GroupUnique
 * @brief Converte AFND para AFD
 * @details This program really do a nice job as a template, and template only!
 * @version 20160618.013215
 * @date 2016-06-18
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
 *   $gcc auto1.c -o ex12.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astyle -A1 -s4 -k3 -xj -SCNeUpv auto1.c
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto1.h */

#include "auto1.h" /* To be created for this template if needed */

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
 *    $./auto1 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-18
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int n = 0;
    char *sfile = NULL;
    t_quintupla AFND, AFD;
    t_novo *ndt = NULL;

    IFDEBUG("Starting optarg loop...");

    AFD.D = NULL;
    AFD.F = NULL;

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hcvnf:")) != EOF)
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
            case 'n':
                n++;
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

    if(!n)
    {
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }
    if(verb)
        printf("Verbose level set at: %d\n", verb);

    auto1_init(); /* global initialization function: ainda a saber para que usar se precisar */

    /* ...and we are done */
    /* Write your code here... */
    AFND = entrada(sfile);
    E_closure(&AFND, &ndt);
    tran(&AFND, &AFD, &ndt);
    desenho_al(AFD);
    imprimir(AFD);
    free(sfile);
    clean_ndt(&ndt);
    clean(&AFND);
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
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "auto1", "Converte AFND para AFD");
    printf("\nUsage: %s [-h|-v]\n", "auto1");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-n): input data is a NFA (Nondeterministic Finite Automata) 5-tuple to be converted to a DFA (Deterministic Finite Automata) 5-tuple.\n");
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
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto1", VERSION);
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
void auto1_init(void)
{
    IFDEBUG("auto1_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Uma quintupla
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221230.095802
 * @date 2022-12-30
 *
 */
t_quintupla entrada(char *sfile)
{
    t_quintupla afnd;
    FILE *entrada;
    rcc delta;
    unsigned short int f = 0;
    int n = 0;
    char aux[10] = {0};
    afnd.F = NULL;
    afnd.D = NULL;

    IFDEBUG("entrada()");
    if(sfile != NULL)
    {
        entrada = fopen(sfile, "r");
        do
        {
            n = fscanf(entrada, "%s", aux);
            if(!strcmp (aux,"#K"))
                fscanf(entrada, "%hu", &afnd.K);

            if(!strcmp (aux,"#A"))
                fscanf(entrada, "%s", &afnd.A);

            if(!strcmp(aux,"#S"))
                fscanf(entrada, "%hu", &afnd.S);

            if(!strcmp(aux,"#F"))
            {
                fscanf(entrada, "%s", aux);
                while(strcmp(aux,"#D"))
                {
                    f = aux[0] - '0';
                    inserir_ef(&afnd.F, f);
                    fscanf(entrada, "%s", aux);
                }
            }

            if(!strcmp(aux,"#D"))
            {
                fscanf(entrada, "%hu %s %hu", &delta.ei, aux, &delta.ef);
                do
                {
                    strtok(aux, "\n");
                    delta.le = malloc(strlen(aux) * sizeof(char*));
                    strcpy(delta.le, aux);
                    inserir_delta(&afnd.D, delta);
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
            if(!strcmp (aux,"#K"))
                scanf("%hu", &afnd.K);

            if(!strcmp (aux,"#A"))
                scanf("%s", &afnd.A);

            if(!strcmp(aux,"#S"))
                scanf("%hu", &afnd.S);

            if(!strcmp(aux,"#F"))
            {
                scanf("%s", aux);
                while(strcmp(aux,"#D"))
                {
                    f = aux[0] - '0';
                    inserir_ef(&afnd.F, f);
                    scanf("%s", aux);
                }
            }

            if(!strcmp(aux,"#D"))
            {
                scanf("%hu %s %hu", &delta.ei, aux, &delta.ef);
                do
                {
                    strtok(aux, "\n");
                    delta.le = malloc(strlen(aux) * sizeof(char*));
                    strcpy(delta.le, aux);
                    inserir_delta(&afnd.D, delta);
                    free(delta.le);
                    n = scanf("%hu%s%hu", &delta.ei, aux, &delta.ef);
                }
                while(n == 3);
            }
        }
        while(n == 1);
    }
    return afnd;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Essa funcao insere as transicoes em uma lista
 * @details Details to be written
 * @return Void
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221231.095802
 * @date 2022-12-31
 *
 */
void inserir_delta(t_delta **cabeca, rcc x)
{
    t_delta *pl=*cabeca;
    t_delta *plant=NULL;

    IFDEBUG("inserir_delta()");
    while(pl!=NULL) // loop para deixar pl no fim da lista
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(t_delta)); // aloca memoria para um nodo da lista
    pl->le=malloc(strlen(x.le) * sizeof(char*)); // aloca memoria para a string
    pl->ei=x.ei; // copia o estado inicial
    strcpy(pl->le, x.le); // copia o rotulo da transicao
    pl->ef=x.ef; // copia o estado final
    pl->prox=NULL; // define fim da lista
    if(plant!=NULL) // caso nao seja o primeiro nodo
        plant->prox=pl; // isere ao final
    else
        *cabeca=pl; // inicio da lista recebe pl

}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Essa funcao limpa os dados da quintupla
 * @details Details to be written
 * @return Nada
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20230113.095802
 * @date 2023-01-13
 *
 */
void clean(t_quintupla *auto1)
{
    t_delta *d = auto1->D, *dant = NULL;

    IFDEBUG("clean()");
    clean_ef(&auto1->F);
    while(d != NULL) // roda a lista de transicoes e limpa os estados
    {
        dant = d;
        d = d->prox;
        free(dant->le);
        free(dant);
    }
    auto1->F = NULL;
    auto1->D = NULL;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Insere estados finais
 * @details Details to be written
 * @return Void
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221231.095802
 * @date 2022-12-31
 *
 */
void inserir_ef(t_lef **cabeca, unsigned short int x)
{
    t_lef *pl=*cabeca;
    t_lef *plant=NULL;

    IFDEBUG("inserir_ef()");
    while(pl!=NULL) // loop para deixar pl no fim da lista
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(t_lef)); // aloca memoria para o nodo
    pl->f = x; // recebe numero do estado
    pl->prox = NULL; // define o fim da lista
    if(plant != NULL) // se a lista nao estiver vazia pl e colocado no fim
        plant -> prox=pl;
    else
        *cabeca = pl; // se estover vazia define o primeiro nodo
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Essa funcao imprime uma quintupla
 * @details Details to be written
 * @return Void
 * @author Marcio Andre Alves goncalves sobrinho
 * @version 20221231.095802
 * @date 2022-12-31
 *
 */
void imprimir(t_quintupla aut)
{
    t_delta *pi = aut.D;
    t_lef *pl = aut.F;

    IFDEBUG("inprimir()");
    printf("#K\n"); // imprime o total de estados
    printf("%hu\n", aut.K);

    printf("#A\n"); // imprme o alfabeto aceitado
    printf("%c\n", aut.A);

    printf("#S\n"); // imprime o estado inicial
    printf("%hu\n", aut.S);

    printf("#F\n"); // imprime a lista de estados finais
    while(pl!=NULL)
    {
        printf("%hu ", pl->f);
        pl=pl->prox;
    }
    printf("\n");

    printf("#D\n"); // imprime a lista de transicoes
    while(pi!=NULL)
    {
        printf("%hu %s %hu\n", pi->ei, pi->le, pi->ef);
        pi=pi->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Essa funcao insere os deltas na lista de listas para transicao
 * @details Details to be written
 * @return Void
 * @author Marcio Andre Alves Goncalves Sobrinho
 * @version 20230123.095802
 * @date 2023-01-23
 *
 */
void inserir_nd(t_novo **cabeca, t_lef *inicio)
{
    t_novo *pl = *cabeca;
    t_novo *plant = NULL;
    t_lef *aux = inicio;

    IFDEBUG("inserir_nd()");
    while(pl != NULL) // roda ate o fim da lista
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(t_novo)); // aloca um espaco para o novo nodo
    pl->c = NULL;
    while(aux != NULL)
    {
        inserir_ef(&pl->c, aux->f);
        aux = aux->prox;
    }
    pl->prox = NULL; // define o final
    if(plant!=NULL) // se a lista nao estiver vazia adiciona o novo nodo no final e coloca o novo rotulo do estado
    {
        plant->prox=pl;
        pl->n = plant->n + 1;
    }
    else // caso a lista esteja vazia pl se torna o primeiro estado
    {
        pl->n = 0;
        *cabeca = pl;
    }
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief cria os closures das transicoes
 * @details Details to be written
 * @return Void
 * @author Marcio Andre Alves Goncalves Sobrinho
 * @version 20221230.095802
 * @date 2022-12-30
 *
 */
void E_closure(t_quintupla *afnd, t_novo **ndt)
{
    t_delta *D = afnd->D;
    t_delta *aux = NULL;
    t_lef *nodo = NULL;
    int es = -1;

    IFDEBUG("E_clousure()");
    while(D != NULL) // roda na lista de transicoes
    {
        if(es != D->ei) // caso o estado nao esteja enserido na lista
        {
            es = D->ei;
            if(procura(nodo, es))
                inserir_ef(&nodo, es);
        }
        aux = buscar(D, "E", es);
        while(aux != NULL && aux->ei == es)
        {
            assist_closure(aux->ei, &nodo, afnd->D);
            aux = aux->prox;
        }
        if(size(nodo) != 0 && compare(*ndt, nodo) == NULL)
            inserir_nd(ndt, nodo);
        clean_ef(&nodo);
        D = D->prox;
    }

    return;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief  Funcao que ajuda a calcular quais estados um AFND pode alcancar atravss de transições vazias
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230323171822
* @date 2023-03-23
*
*/

void assist_closure(int es, t_lef **cabeca, t_delta *D)
{
    t_delta *d = D;

    IFDEBUG("assist_closure()");
    while(d != NULL && d->ei != es)
        d = d->prox;
    while(d != NULL && d->ei == es)
    {
        if(!strcmp(d->le, "E") && procura(*cabeca, d->ef))
        {
            inserir_ef(cabeca, d->ef);
            assist_closure(d->ef, cabeca, D);
        }
        d = d->prox;
    }
    return;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que verifica se um elemento esta presente em uma lista encadeada e retorna 0 se estiver, ou 1 caso contrario
* @return int
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230301150709
* @date 2023-03-01
*
*/

int procura(t_lef *cabeca, int es)
{
    t_lef *pl = cabeca;

    IFDEBUG("procura()");
    while(pl != NULL)
    {
        if(pl->f == es)
            return 0;
        pl = pl->prox;
    }
    return 1;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que busca um elemento em uma lista encadeada e retorna um ponteiro para ele ou NULL se não encontrá-lo.
* @return Nodo que foi desejado
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230301150709
* @date 2023-03-01
*
*/

t_delta *buscar(t_delta *cabeca, char *x, int es)
{
    t_delta *pl = cabeca;

    IFDEBUG("buscar()");
    while(pl != NULL && pl->ei != es)
        pl = pl->prox;
    while(pl != NULL && pl->ei == es)
    {
        if(strcmp(pl->le, x) == 0)
            return pl;
        pl = pl->prox;
    }
    return NULL;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que imprime cada elemento da lista na saida padrao
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230228151945
* @date 2023-02-28
*
*/

void imprimir_lista(t_lef *lista)
{
    t_lef *pl = lista;

    IFDEBUG("imprimir_lista()");
    while(pl != NULL)
    {
        printf("%i->", pl->f);
        pl = pl->prox;
    }
    printf("lista\n");
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que compara duas listas encadeadas
* @return retorna o nodo que e igual
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230228151945
* @date 2023-02-28
*
*/

t_novo *compare(t_novo *ndt, t_lef *nodo)
{
    t_novo *pl = ndt;
    t_lef *aux = NULL, *aux2 = NULL;
    int x = 0;

    IFDEBUG("compare()");
    while(pl != NULL)
    {
        aux = pl->c;
        while(aux != NULL)
        {
            aux2 = nodo;
            while(aux2 != NULL)
            {
                if(aux->f == aux2->f)
                {
                    x++;
                    break;
                }
                aux2 = aux2->prox;
            }
            aux = aux->prox;
        }
        if(size(nodo) == x && size(nodo) == size(pl->c))
            return pl;
        else
        {
            x = 0;
            pl = pl->prox;
        }
    }

    return NULL;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que retorna o tamanho de uma lista encadeada de elementos
* @return int
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230228151945
* @date 2023-02-28
*
*/

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
/**
* @ingroup GroupUnique
* @brief Funcao que imprime o conteudo de uma lista encadeada de elementos t_novo
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version
* @date
*
*/

void imprimir_ndt(t_novo *ndt)
{
    t_novo *pl = ndt;
    t_lef *plaux = NULL;

    IFDEBUG("imprimir_ndt()");
    while(pl!=NULL)
    {
        plaux = pl->c;
        while(plaux != NULL)
        {
            printf("%i ", plaux->f);
            plaux = plaux->prox;
        }
        pl = pl->prox;
        printf("\n");
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que libera memoria alocada
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version
* @date
*
*/

void clean_ndt(t_novo **ndt)
{
    t_novo *pl = *ndt, *plant = NULL;

    IFDEBUG("clean_ndt()");
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
        clean_ef(&plant->c);
        free(plant);
    }

    return;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que remove estados nao alcancados a partir do estado inicial
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230322171659
* @date 2023-03-22
*
*/

void limpa_es_lixo(t_quintupla *aut, t_novo **ndt)
{
    t_delta *d = aut->D, *aux = NULL;
    int x = 0;

    IFDEBUG("limpa_es_lixo()");
    while(d != NULL)
    {
        aux = aut->D;
        while(aux != NULL)
        {
            if(d->ei == aux->ef || d->ei == aut->S)
                break;
            aux = aux->prox;
        }
        if(aux == NULL)
        {
            x = d->ei;
            aux = aut->D;
            d = aut->D;
            remove_d(x, &aut->D);
            remove_ndt(x, ndt);
        }
        else
            d = d->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que remove um elemento da estrutura NDT
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230322171659
* @date 2023-03-22
*
*/

void remove_ndt(int es, t_novo **ndt)
{
    t_novo *pl = *ndt, *plant = NULL;

    IFDEBUG("remove_ndt()");
    while(pl != NULL)
    {
        if(pl->n == es)
        {
            if(plant != NULL)
            {
                plant->prox = pl->prox;
                free(pl);
                pl = *ndt;
            }
            else
            {
                *ndt = pl->prox;
                free(pl);
                pl = *ndt;
            }
        }
        plant = pl;
        pl = pl->prox;
    }
    pl = *ndt;
    while(pl != NULL)
    {
        if(pl->n > es)
            pl->n -= 1;
        pl = pl->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que remove uma transicao de estado de lista de transicoes (delta)
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230322171659
* @date 2023-03-22
*
*/


void remove_d(int es, t_delta **D)
{
    t_delta *pl = *D,*plant = NULL;

    IFDEBUG("remove_d()");
    while(pl != NULL)
    {
        if(pl->ei == es)
        {
            if(plant != NULL)
            {
                plant->prox = pl->prox;
                free(pl->le);
                free(pl);
                pl = *D;
            }
            else
            {
                *D = pl->prox;
                free(pl->le);
                free(pl);
                pl = *D;
            }
            continue;
        }
        plant = pl;
        pl = pl->prox;
    }
    pl = *D;
    while(pl != NULL)
    {
        if(pl->ei > es)
            pl->ei -= 1;
        if(pl->ef > es)
            pl->ef -= 1;
        pl = pl->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que realiza a conversao de um automato finito não deterministico para um deterministico.
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230416115907
* @date 2023-03-01
*
*/

void tran(t_quintupla *AFND, t_quintupla *afd, t_novo **ndt)
{
    t_quintupla *afnd = AFND;
    t_delta *aux = NULL;
    t_novo *pl = *ndt;
    t_lef *f = AFND->F;
    afd->K = 0;

    IFDEBUG("tran()");
    afd->A = afnd->A;
    while(pl != NULL)
    {
        if(pl->c->f == afnd->S)
        {
            afd->S = pl->c->f;
            break;
        }
        pl = pl->prox;
    }
    if(pl == NULL)
        afd->S = 0;
    pl = *ndt;
    tran_delta(*ndt, afnd, afd);
    aux = afd->D;
    limpa_es_lixo(afd, ndt);
    while(aux != NULL)
    {
        if(aux->ei >= afd->K)
            afd->K = aux->ei +1;
        aux = aux->prox;
    }
    while(pl != NULL)
    {
        while(f != NULL)
        {
            if(!procura(pl->c, f->f))
            {
                inserir_ef(&afd->F, pl->n);
                break;
            }
            f = f->prox;
        }
        f = afnd->F;
        pl = pl->prox;
    }
}
/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que implementa a transicao por delta de um AFND para um AFD
* @details Details to be written
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230416114856
* @date 2023-03-01
*
*/

void tran_delta(t_novo *ndt, t_quintupla *afnd, t_quintupla *afd)
{
    char x = 'a', *le = NULL;
    t_novo *pl = ndt, *plaux = NULL;
    t_lef *help = NULL, *aux = NULL;
    rcc y;

    IFDEBUG("tran_delta()");
    y.le = malloc(sizeof(char*));
    le = malloc(sizeof(char*));
    while(pl != NULL)
    {
        for(x = 'a'; x <= afnd->A; x++)
        {
            y.ei = pl->n;
            sprintf(y.le, "%c", x);
            sprintf(le, "%c", x);
            help = pl->c;
            while(help != NULL)
            {
                lndt(help->f, le, &aux, afnd->D);
                help = help->prox;
            }
            plaux = compare(ndt, aux);
            if(plaux != NULL)
                y.ef = plaux->n;
            else
            {
                if(size(aux) != 0)
                    inserir_nd(&ndt , aux);
                if((plaux = compare(ndt, aux)) != NULL)
                    y.ef = plaux->n;
            }
            if(size(aux) != 0)
                inserir_delta(&afd->D, y);
            clean_ef(&aux);
        }
        pl = pl->prox;
    }
    free(le);
    free(y.le);
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao para limpar lista de estados finais
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 202304161148
* @date 20203-04-16
*
*/
void clean_ef(t_lef **cabeca)
{
    t_lef *pl = *cabeca, *plant = NULL;

    IFDEBUG("clean_ef()");
    if(*cabeca == NULL)
        return;
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
/**
* @ingroup GroupUnique
* @brief Funcao para limpar lista de estados do allegro
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 202304161148
* @date 2023-04-16
*
*/
void clean_al(t_leal **cabeca)
{
    IFDEBUG("clean_al()");
    t_leal *pl = *cabeca, *plant = NULL;

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
/**
* @ingroup GroupUnique
* @brief Funcao que verifica as transicoes delta a partir de um estado de entrada
* @return Void
* @author Marcio Andre Alves Goncalves Sobrinho
* @version 20230451148
* @date 2023-03-01
*
*/

void lndt(int es, char *le, t_lef **cabeca, t_delta *D)
{
    t_delta *pl = D;

    IFDEBUG("lndt()");
    while(pl != NULL && pl->ei != es)
        pl=pl->prox;
    while(pl != NULL && pl->ei == es)
    {
        if(strcmp(pl->le, le) == 0)
        {
            if(procura(*cabeca, pl->ef))
                inserir_ef(cabeca, pl->ef);
            assist_closure(pl->ef, cabeca, D);
        }
        pl = pl->prox;
    }
    return;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que desenha um AFD na tela usando a biblioteca Allegro
* @details
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version 20221231.095802
* @date
*
*/

void desenho_al(t_quintupla AUT)
{
    BITMAP *bmp;
    PALETTE pal;
    int i, xmax, ymax, xei, yei;
	t_leal *lista = NULL; // lista de coordenadas dos estados do alegro
	t_lef *finais = AUT.F; // lista de estados finais
	t_delta *trans = AUT.D; // lista das transicoes do automato

	if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
		exit(EXIT_FAILURE);
    set_color_depth(16);
    get_palette(pal);
    xmax = 800; //Tamanho do eixo x
    ymax = 600; //Tamanho do eixo y
    if(AUT.K > 2)
    {
        xmax = 1024; //Tamanho do eixo x
        ymax = 800; //Tamanho do eixo y
    }
    xei = xmax/4; //Define x da posicao inicial
    yei = ymax/2; //Define y da posicao inicial
    bmp = create_bitmap(xmax,ymax); //Cria bitmap

	clear_to_color(bmp, CORBRANCO); // preenche o bitmap com a cor branca
	for(i = 0; i < AUT.K; i++)
		inserir_estado_al(&lista, 0, 0, i); // cria a lista dos estados com as coordenadas zeradas
	busca_e_insere_al(bmp, lista, AUT.S, xei, yei); // define as coordenadas iniciais no estado inicial
	estados_trans_ei_al(bmp, lista, trans, AUT.S, AUT.K); // Insere o estado inicial e os estados conectados a ele no bitmap
    estados_restantes_al(bmp, lista, trans, AUT.K); // insere o restante dos estados no bitmap
    estados_finais_al(bmp, lista, finais);
    transicoes_al(bmp, lista, trans, AUT.S);
    save_bitmap(IMAGENAME, bmp, pal);
    clean_al(&lista);

    destroy_bitmap(bmp);
    allegro_exit();
}
/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que insere um novo elemento na lista de coordenadas de estados do AFD
* @details Details to be written
* @return Novo
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/


t_leal *cria_nd_al(int x, int y, int e) // trocar para 0?
{
	t_leal *novo = malloc(sizeof(t_leal));
	novo->x = x;
	novo->y = y;
	novo->e = e;
	novo->prox = NULL;
	return novo;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que insere um novo elemento no final da lista de coordenadas.
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void inserir_estado_al(t_leal **lista, int x, int y, int e)
{
	t_leal *novo = cria_nd_al(x, y, e);
	if (*lista == NULL)
		*lista = novo;
	else
	{
		t_leal *atual = *lista;
		while (atual->prox != NULL)
			atual = atual->prox;
		atual->prox = novo;
	}
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Imprime as transicoes do estado inicial
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void estados_trans_ei_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int ei, int num_est)
{
	t_leal *busca = lista; // ponteiro que vai buscar pela lista buscando o estado desejado.
	t_delta *conf_trans = trans; // ponteiro para conferir as transicoes.

	while(busca != NULL && busca->e != ei)
		busca = busca->prox; // ponteiro de busca encontra o estado inicial
	while(conf_trans != NULL) // percorre todas as transições
	{
		if(conf_trans->ei == ei && conf_trans->ef != ei) // confere se o estado iniciaç de uma transicao eh o estado inicial do automato
	        estado_local_vago_al(bmp, lista, busca->x, busca->y, conf_trans->ef, num_est);
		conf_trans = conf_trans->prox; // passa para proximo nodo
	}
}
/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que insere estados restantes ao redor dos estados presentes na lista, de acordo com a disponibilidade de espaco nas posicoes ao lado
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void estados_restantes_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int num_est)
{
	int i = 0, j, x_ref, y_ref; // posiveis posicoes ao redor do estado para inserir novos estados.
    t_tral info;

	while(i < num_est)
	{
		for(j = 0; j < num_est; j++)
		{
			if(testa_estado_inserido_al(lista, j) == 0) // testa se o estado ja foi inserido.
			{
                info = info_transicoes_al(lista, trans, j);
                switch(info.num)
                {
                    case 0:
                        break;
                    case 1:
                            estado_local_vago_al(bmp, lista, info.e1x, info.e1y, j, num_est);
                            i++;
                            break;
                        case 2:
                            x_ref = (info.e1x + info.e2x)/2;
                            y_ref = (info.e1y + info.e2y)/2;
                        estado_local_vago_al(bmp, lista, x_ref, y_ref, j, num_est);
                        i++;
                        break;
                    default:
                        x_ref = (info.e1x + info.e2x + info.e3x)/3;
                        y_ref = (info.e1y + info.e2y + info.e3y)/3;
                        estado_local_vago_al(bmp, lista, x_ref, y_ref, j, num_est);
                        i++;
                        break;
                }
            }
            else
                i++;
        }
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que verifica as possiveis posicoes ao redor da referencia e verifica se alguma delas esta livre na lista de estados
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void estado_local_vago_al(BITMAP *bmp, t_leal *lista, int x_ref, int y_ref, int e, int num_est)
{
    int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, p5x, p5y, p6x, p6y; // posiveis posicoes ao redor do estado para inserir novos estados.

    posicoes_hex_al(num_est, x_ref, y_ref, &p1x, &p1y, &p2x, &p2y, &p3x, &p3y, &p4x, &p4y, &p5x, &p5y, &p6x, &p6y);
	if(local_ocupado_al(lista, p1x, p1y) == 0) // sequencia de ifs para saber em qual posicao inserir o estado.
		busca_e_insere_al(bmp, lista, e, p1x, p1y);
	else if(local_ocupado_al(lista, p2x, p2y) == 0)
		busca_e_insere_al(bmp, lista, e, p2x, p2y);
	else if(local_ocupado_al(lista, p3x, p3y) == 0)
		busca_e_insere_al(bmp, lista, e, p3x, p3y);
	else if(local_ocupado_al(lista, p4x, p4y) == 0)
		busca_e_insere_al(bmp, lista, e, p4x, p4y);
	else if(local_ocupado_al(lista, p5x, p5y) == 0)
		busca_e_insere_al(bmp, lista, e, p5x, p5y);
	else if(local_ocupado_al(lista, p6x, p6y) == 0)
		busca_e_insere_al(bmp, lista, e,  p6x, p6y);
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que busca o estado na lista e, se encontrado, atualiza suas coordenadas e é desenhado no bitmap
* @details Details to be written
* @return Void
* @author Ayrton Eleoteorio Marins Silva
* @version
* @date
*
*/

void busca_e_insere_al(BITMAP *bmp, t_leal *lista, int e, int x_centro, int y_centro)
{
	t_leal *busca = lista; // ponteiro que vai passar pela lista buscando o estado desejado.

    while(busca != NULL && busca->e != e)
		busca = busca->prox; // ponteiro de busca vai para o proximo nodo da lista
	if(busca)
	{
		busca->x = x_centro; // novo valor de x inserido no nodo referente ao estado.
		busca->y = y_centro; // novo valor de y inserido no nodo referente ao estado.
		circlefill(bmp, busca->x, busca->y, RAIO_ESTADO, CORAMARELO);
		circle(bmp, busca->x, busca->y, RAIO_ESTADO, CORPRETO);
		textprintf_ex(bmp, font, busca->x - (RAIO_ESTADO/9), busca->y - (RAIO_ESTADO/9), CORPRETO, -1, "%d", busca->e);
	}
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que atribui as possiveis posicoes em forma de hexagono ao redor de um ponto central
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/


void posicoes_hex_al(int num_estado, int x, int y , int *p1x, int *p1y, int *p2x, int *p2y, int *p3x, int *p3y, int *p4x, int *p4y, int *p5x, int *p5y, int *p6x, int *p6y)
{
    float aux = 1;

    if(num_estado > 5)
    {
        aux = 0.7;
    }
	*p1x = x + 150 * aux;
	*p1y = y - 87 * aux;
	*p2x = x + 150 * aux;
	*p2y = y + 87 * aux;
	*p3x = x * aux;
	*p3y = y + 173 * aux;
	*p4x = x - 150 * aux;
	*p4y = y + 87 * aux;
	*p5x = x - 150 * aux;
	*p5y = y - 87 * aux;
	*p6x = x * aux;
	*p6y = y - 173 * aux;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief  Funcao que retorna 1 se a posicao estiver ocupada e 0 se estiver disponivel.
* @details Details to be written
* @return Estado
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

int local_ocupado_al(t_leal *lista, int xb, int yb)
{
	t_leal *busca = lista;
		int estado = 0, xa, ya, xa1, xa2, ya1, ya2, xb1, xb2, yb1, yb2;

	while(busca != NULL && estado != 1)
	{
		xa = busca->x;
		ya = busca->y;
		xa1 = xa - 40;
		xa2 = xa + 40;
		ya1 = ya - 40;
		ya2 = ya + 40;
		xb1 = xb - 40;
		xb2 = xb + 40;
		yb1 = yb - 40;
		yb2 = yb + 40;

		if((((xa1 <= xb1 && xb1 <= xa2) || (xa1 <= xb2 && xb2 <= xa2)) && ((ya1 <= yb1 && yb1 <= ya2) || (ya1 <= yb2 && yb2 <= ya2))) || (xa == xb && ya == yb))
			estado = 1;// retorna 1 se tiver ocupado
		else
		{
			estado = 0; // retorna 0 se tiver disponivel
			busca = busca->prox;
		}
	}
	return estado;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que retorna 1 ou 0 se o estado ja foi inserido
* @details Details to be written
* @return Teste
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

int testa_estado_inserido_al(t_leal *lista, int e)
{
	t_leal *busca = lista;
	int teste = 0;
	while(busca != NULL && busca->e != e)
		busca = busca->prox;
	if(busca->x == 0) // confere se a coordenada dele esta zerada
		teste = 0; // retorna 0 se o estado ainda nao foi inserido no bitmap
	else
		teste = 1; // retorna 1 se o estado ja foi inserido no bitmap

	return teste;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que devolve o numero de transicoes com estados inseridos
* @details Details to be written
* @return Info
* @author Ayrton Eleoterios Marins Silva
* @version
* @date
*
*/

t_tral info_transicoes_al(t_leal *lista, t_delta *trans, int e)
{
    t_leal *busca = lista;
    t_delta *conf_trans = trans; // ponteiro que vai passar por todas as transicoes
    t_tral info; // struct com informacoes sobre a transicao do estado

    info.num = 0;
    info.e1 = 100;
    info.e2 = 100;
    info.e3 = 100;
    while(conf_trans)
    {
        if(conf_trans->ei == e && conf_trans->ef != e)
        {
	        if(testa_estado_inserido_al(lista, conf_trans->ef) == 1)
            {
                busca = lista;
                while(busca != NULL && busca->e != conf_trans->ef)
                    busca = busca->prox;
                if(info.e1 == 100)
                {
                    info.e1 = conf_trans->ef;
                    info.e1x = busca->x;
                    info.e1y = busca->y;
                    info.num++;
                }
                else if(info.e2 == 100 && conf_trans->ef != info.e1)
                {
                    info.e2 = conf_trans->ef;
                    info.e2x = busca->x;
                    info.e2y = busca->y;
                    info.num++;
                }
                else if(info.e3 == 100 && conf_trans->ef != info.e1 && conf_trans->ef != info.e2)
                {
                    info.e3 = conf_trans->ef;
                    info.e3x = busca->x;
                    info.e3y = busca->y;
                    info.num++;
                }
            }
        }
        if(conf_trans->ef == e && conf_trans->ei != e)
        {
	        if(testa_estado_inserido_al(lista, conf_trans->ei) == 1)
            {
                busca = lista;
                while(busca != NULL && busca->e != conf_trans->ei)
                    busca = busca->prox;
                if(info.e1 == 100)
                {
                    info.e1 = conf_trans->ei;
                    info.e1x = busca->x;
                    info.e1y = busca->y;
                    info.num++;
                }
                else if(info.e2 == 100 && conf_trans->ei != info.e1)
                {
                    info.e2 = conf_trans->ei;
                    info.e2x = busca->x;
                    info.e2y = busca->y;
                    info.num++;
                }
                else if(info.e3 == 100 && conf_trans->ei != info.e1 && conf_trans->ei != info.e2)
                {
                    info.e3 = conf_trans->ei;
                    info.e3x = busca->x;
                    info.e3y = busca->y;
                    info.num++;
                }
            }
        }
        conf_trans = conf_trans->prox;
    }
    return info;
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que desenha um circulo com um raio menor que o original indicando o estado final
* @details Details to be written
* @return Void
* @author Petra Baia De Lucena Queiroz
* @version
* @date
*
*/

void estados_finais_al(BITMAP *bmp, t_leal *lista, t_lef *finais)
{
    t_lef *ef = finais; // ponteiro que vai buscar pela lista os estados finais
    t_leal *busca = lista;

    while(busca) // laco de repeticao para percorrer toda a lista das coordenadas dos estados
    {
        ef = finais;
        while(ef) // laco de repeticao para percorrer toda a lista de estados finais
        {
            if(busca->e == ef->f) // confere se o estado apontado pelo ponteiro 'busca' eh um estado final
                circle(bmp, busca->x, busca->y, RAIO_ESTADO - 5, CORPRETO); // circulo com raio menor que o raio original
            ef = ef->prox;
        }
        busca = busca->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que cria as setas de transicao para transicao
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void transicoes_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int ei)
{
    t_leal *busca = lista;
    t_delta *conf_trans = trans, *rev = trans;
    int x1, x2, y1, y2, info = 0;

    while(busca != NULL && busca->e != ei) // criacao da seta do estado inicial
        busca = busca->prox;
    line(bmp, busca->x - RAIO_ESTADO - 40, busca->y , busca->x - RAIO_ESTADO, busca->y,  CORPRETO); // corpo da seta
    triangle(bmp, busca-> x - RAIO_ESTADO - 6, busca->y + 10, busca-> x - RAIO_ESTADO - 6, busca->y - 10, busca->x - RAIO_ESTADO - 1, busca->y, CORPRETO); // final da seta
    while(conf_trans) // laco para conferir todas as transicoes
    {
        if(conf_trans->ei != conf_trans->ef) // confere se a transicao nao eh um loop para o proprio estado
        {
            busca = lista;
            while(busca != NULL && busca->e != conf_trans->ei) // armazena a coordenada do estado inicial
                busca = busca->prox;
            x1 = busca->x;
            y1 = busca->y;
            busca = lista;
            while(busca != NULL && busca->e != conf_trans->ef) // armazena a coordenada do estado final
                busca = busca->prox;
            x2 = busca->x;
            y2 = busca->y;
            rev = trans;
            info = 0;
            while(rev)
            {
                if(rev->ei == conf_trans->ef && rev->ef == conf_trans->ei) // confere se a transicao eh reversivel
		            info = 1;
                rev = rev->prox;
            }
            if(info == 0) // se a transicao nao for reversivel, cria seta do ei para ef
                setas_al(bmp, trans, x1 ,x2 ,y1 ,y2, conf_trans->ei, conf_trans->ef);
            else
                setas_rev_al(bmp, trans, x1, y1, x2, y2, conf_trans->ei, conf_trans->ef); // se a trasicao for reversivel, a seta vai ser gerada pela funcao setas_rev_al
        }
        else
            setas_loop_al(bmp, lista, trans, conf_trans->ei); // se a transicao for de loop, a a seta vai ser gerada pela funcao setas_loop_al
        conf_trans = conf_trans->prox;
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que cria as setas
* @details
* @return Void
* @author Petra Baia De Lucena Queiroz
* @version
* @date
*
*/


void setas_al(BITMAP *bmp, t_delta *trans, int x1, int x2, int y1, int y2, int ei, int ef)
{
    float ang1, inter_x1, inter_y1, ang2, inter_x2, inter_y2, seta_x1, seta_y1, seta_x2, seta_y2;
    int meio_x, meio_y;

    ang1 = atan2(y2-y1, x2-x1);
	inter_x1 = x1 + RAIO_ESTADO * cos(ang1);
	inter_y1 = y1 + RAIO_ESTADO * sin(ang1);
	ang2 = atan2(y1 - y2, x1 -x2);
	inter_x2 = x2 + RAIO_ESTADO * cos(ang2);
	inter_y2 = y2 + RAIO_ESTADO * sin(ang2);
	seta_x1 = inter_x2 + 12 * cos(ang2 - PI / 3);
	seta_y1 = inter_y2 + 12 * sin(ang2 - PI / 3);
	seta_x2 = inter_x2 + 12 * cos(ang2  + PI / 3);
	seta_y2 = inter_y2 + 12 * sin(ang2 + PI / 3);
    meio_x = (inter_x1 + inter_x2)/2;
    meio_y = (inter_y1 + inter_y2)/2;

    line(bmp, inter_x1, inter_y1, inter_x2, inter_y2,  CORPRETO);
    texto_trans_al(bmp, trans, meio_x, meio_y - 12, ei, ef);
	triangle(bmp, seta_x1, seta_y1, seta_x2, seta_y2, inter_x2, inter_y2, CORPRETO);
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que cria as setas que possuem o mesmo estado igual a de outra seta
* @details
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void setas_rev_al(BITMAP *bmp, t_delta *trans, int x1, int y1, int x2, int y2, int ei, int ef)
{
    float ang1 = 0, ang2 = 0, ang3 = 0, ang4 = 0, inter_x1, inter_y1, inter_x2, inter_y2;
    int seta_x1, seta_y1, seta_x2, seta_y2, meio_x, meio_y;

    ang1 = atan2(y2 - y1, x2 - x1); // angulo em relacao ao primeiro estado
    ang2 = atan2(y1 - y2, x1 -x2);  // angulo em relacao ao segundo estado
    if(x1 < x2) // se a seta vai da esquerda para direita
    {
        ang3 = ang1 + 170;
        ang4 = ang2 - 170;
    }
    if(x1 > x2) // se a seta vai da direita para esquerda
    {
        ang3 = ang1 + 170;
        ang4 = ang2 - 170;
    }
    if(y1 == y2) // se os dois estados estao no mesmo y
    {
        ang3 = ang1 + 170;
        ang4 = ang2 - 170;
    }
	inter_x1 = x1 + RAIO_ESTADO * cos(ang3); // ponto de interseccao x do estado 1. inicio da seta
	inter_y1 = y1 + RAIO_ESTADO * sin(ang3); // ponto de interseccao y do estado 1. inicio da seta
	inter_x2 = x2 + RAIO_ESTADO * cos(ang4); // ponto de interseccao x do estado 2. final da seta
	inter_y2 = y2 + RAIO_ESTADO * sin(ang4); // ponto de interseccao y do estado 2. final da seta
	seta_x1 = inter_x2 + 12 * cos(ang2 - PI / 3); // pontos para triangulo representando final da seta
	seta_y1 = inter_y2 + 12 * sin(ang2 - PI / 3);
	seta_x2 = inter_x2 + 12 * cos(ang2  + PI / 3);
	seta_y2 = inter_y2 + 12 * sin(ang2 + PI / 3);
    meio_x = (inter_x1 + inter_x2)/2; // meio da seta para inserir a letra da transicao
    meio_y = (inter_y1 + inter_y2)/2;

    line(bmp, inter_x1, inter_y1, inter_x2, inter_y2,  CORPRETO); // corpo da seta
    triangle(bmp, seta_x1, seta_y1, seta_x2, seta_y2, inter_x2, inter_y2, CORPRETO); // final da seta
    texto_trans_al(bmp, trans, meio_x, meio_y - 12, ei, ef);
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que cria setas para o estado que retorna para ele mesmo
* @details Details to be written
* @return Void
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

void setas_loop_al(BITMAP *bmp, t_leal *lista, t_delta *trans, int e)
{
    t_leal *busca = lista;
    int quadrante, ex, ey, q1x1, q1x2, q2y1, q2y2, q3x1, q3x2, q4y1, q4y2;

    while(busca != NULL && busca->e != e)
        busca = busca->prox;
    ex = busca->x;
    ey = busca->y;
    q1x1 = ex + RAIO_ESTADO * sin(22.5); // Pontos do quadrante 1 | OBS: y = raio
    q1x2 = ex - RAIO_ESTADO * sin(22.5);
    q2y1 = ey + RAIO_ESTADO * sin(22.5); // Pontos do quadrante 2 | OBS: x = raio
    q2y2 = ey - RAIO_ESTADO * sin(22.5);
    q3x1 = ex - RAIO_ESTADO * sin(22.5); // Pontos do quadrante 3 | OBS: y = -raio
    q3x2 = ex + RAIO_ESTADO * sin(22.5);
    q4y1 = ey - RAIO_ESTADO * sin(22.5); // Pontos do quadrante 4 | OBS: x = -raio
    q4y2 = ey + RAIO_ESTADO * sin(22.5);

    quadrante = quadrante_vazio_al(lista, trans, e); // chamada de funcao para definir em qual quadrante a seta vai ficar
    switch(quadrante)
    {
        case 1:
            line(bmp, q1x1, ey - RAIO_ESTADO + 2, q1x1, ey - RAIO_ESTADO - 10,  CORPRETO);
            line(bmp, q1x1, ey - RAIO_ESTADO - 10, q1x2, ey - RAIO_ESTADO - 10,  CORPRETO);
            line(bmp, q1x2, ey - RAIO_ESTADO - 10, q1x2, ey - RAIO_ESTADO - 2,  CORPRETO);
            triangle(bmp, q1x2, ey - RAIO_ESTADO + 1, q1x2 - 5, ey - RAIO_ESTADO - 4, q1x2 + 5, ey - RAIO_ESTADO - 4, CORPRETO);
            texto_trans_al(bmp, trans, ex - 2, ey - RAIO_ESTADO - 20, e, e);
            break;
        case 2:
            line(bmp, ex + RAIO_ESTADO - 2, q2y1, ex + RAIO_ESTADO + 10, q2y1,  CORPRETO);
            line(bmp, ex + RAIO_ESTADO + 10, q2y1, ex + RAIO_ESTADO + 10, q2y2,  CORPRETO);
            line(bmp, ex + RAIO_ESTADO + 10, q2y2, ex + RAIO_ESTADO - 2, q2y2,  CORPRETO);
            triangle(bmp, ex + RAIO_ESTADO - 1, q2y2, ex + RAIO_ESTADO + 4, q2y2 - 5, ex + RAIO_ESTADO + 4, q2y2 + 5, CORPRETO);
            texto_trans_al(bmp, trans, ex + RAIO_ESTADO + 25, ey - 2, e, e);
            break;
        case 3:
            line(bmp, q3x1, ey + RAIO_ESTADO - 2, q3x1, ey + RAIO_ESTADO + 10,  CORPRETO);
            line(bmp, q3x1, ey + RAIO_ESTADO + 10, q3x2, ey + RAIO_ESTADO + 10,  CORPRETO);
            line(bmp, q3x2, ey + RAIO_ESTADO + 10, q3x2, ey + RAIO_ESTADO + 2,  CORPRETO);
            triangle(bmp, q3x2, ey + RAIO_ESTADO - 1, q3x2 - 5, ey + RAIO_ESTADO + 4, q3x2 + 5, ey + RAIO_ESTADO + 4, CORPRETO);
            texto_trans_al(bmp, trans, ex - 2, ey + RAIO_ESTADO + 20, e, e);
            break;
        case 4:
            line(bmp, ex - RAIO_ESTADO + 2, q4y1, ex - RAIO_ESTADO - 10, q4y1,  CORPRETO);
            line(bmp, ex - RAIO_ESTADO - 10, q4y1, ex - RAIO_ESTADO - 10, q4y2,  CORPRETO);
            line(bmp, ex - RAIO_ESTADO - 10, q4y2, ex - RAIO_ESTADO + 2, q4y2,  CORPRETO);
            triangle(bmp, ex - RAIO_ESTADO + 1, q4y2, ex - RAIO_ESTADO - 4, q4y2 - 5, ex - RAIO_ESTADO - 4, q4y2 + 5, CORPRETO);
            texto_trans_al(bmp, trans, ex - RAIO_ESTADO - 25, ey - 2, e, e);
            break;
    }
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que verifica quadrantes vazios
* @details Details to be written
* @return Quad
* @author Ayrton Eleoterio Marins Silva
* @version
* @date
*
*/

int quadrante_vazio_al(t_leal *lista, t_delta *trans, int e)
{
    t_leal *busca = lista;
    t_delta *conf_trans = trans;
    int quad = 1, ex, ey, x1 = 0, y1 = 0, inter_x, inter_y, q1x1, q1x2, q2y1, q2y2, q3x1, q3x2, q4y1, q4y2;
    float angulo;

    while(busca != NULL && busca->e != e)
        busca = busca->prox;
    ex = busca->x;
    ey = busca->y;
    q1x1 = ex + RAIO_ESTADO * sin(22.5); // Pontos do quadrante 1 | OBS: y = raio
    q1x2 = ex - RAIO_ESTADO * sin(22.5);
    q2y1 = ey + RAIO_ESTADO * sin(22.5); // Pontos do quadrante 2 | OBS: x = raio
    q2y2 = ey - RAIO_ESTADO * sin(22.5);
    q3x1 = ex - RAIO_ESTADO * sin(22.5); // Pontos do quadrante 3 | OBS: y = -raio
    q3x2 = ex + RAIO_ESTADO * sin(22.5);
    q4y1 = ey - RAIO_ESTADO * sin(22.5); // Pontos do quadrante 4 | OBS: x = -raio
    q4y2 = ey + RAIO_ESTADO * sin(22.5);
    while(conf_trans)
    {
        if(conf_trans->ei == e && conf_trans->ef != e) // variaveis x1 e y1 recebem as coordenadas do estado de transicao
        {
            busca = lista;
            while(busca != NULL && busca->e != conf_trans->ef)
                busca = busca->prox;
            x1 = busca->x;
            y1 = busca->y;
        }
        if(conf_trans->ef == e && conf_trans->ei != e) // variaveis x1 e y1 recebem as coordenadas do estado de transicao
        {
            busca = lista;
            while(busca != NULL && busca->e != conf_trans->ei)
                busca = busca->prox;
            x1 = busca->x;
            y1 = busca->y;
        }
        angulo = atan2(ey - y1,ex - x1);
        inter_x = ex + RAIO_ESTADO * cos(angulo); // encontrado o ponto que a seta foi inserida.
        inter_y = ey + RAIO_ESTADO * sin(angulo);
        if(conf_trans->ei == e && conf_trans->ef == e) // sequencias de ifs que testa se o quadrante esta ocupado por uma seta
        {
            quad = 1;
            if((q1x1 - 4 <= inter_x && inter_x <= q1x2 + 4) && (ey + RAIO_ESTADO - 8 <= inter_y && inter_y <= ey + RAIO_ESTADO + 8))
            {
                quad = 2;
                if((ex + RAIO_ESTADO - 4 <= inter_x && inter_x <= ex + RAIO_ESTADO + 4) && (q2y1 - 4 <= inter_y && inter_y <= q2y2 + 4))
                {
                    quad = 3;
                    if((q3x2 - 4 <= inter_x && inter_x <= q3x1 + 4) && (ey - RAIO_ESTADO - 8 <= inter_y && inter_y <= ey - RAIO_ESTADO + 8))
                    {
                        quad = 4;
                        if((ex - RAIO_ESTADO - 4 <= inter_x && inter_x < ex - RAIO_ESTADO + 4) && (q4y2 + 8 <= inter_y && inter_y < q4y1 + 8))
                            quad = 1;
                    }
                }
            }
        }
        conf_trans = conf_trans->prox;
    }
    return quad; // retorna qual quadrante esta disponivel para seta.
}

/* ---------------------------------------------------------------------- */
/**
* @ingroup GroupUnique
* @brief Funcao que insere a letra das transicoes
* @details Details to be written
* @return num
* @author Ayrton Eleoterio Marins Silva
* @author Marcio Andre Alves Goncalves Sobrinho
* @version
* @date 17/04/2023
*
*/

void texto_trans_al(BITMAP *bmp, t_delta *trans, int x, int y, int ei, int ef)
{
    t_delta *conf_trans = trans;
    char aux[SBUFF] = {"\0"};

    while(conf_trans)
    {
        if(conf_trans->ei == ei && conf_trans->ef == ef)
        {
            if(!strlen(aux))
                strcpy(aux, conf_trans->le);
            else
            {
                strcat(aux, ",");
                strcat(aux, conf_trans->le);
            }
        }
        conf_trans = conf_trans->prox;
    }
    strtok(aux, "\n");
    textprintf_ex(bmp, font, x - (5 * (strlen(aux) - 1)) , y, CORPRETO, -1, "%s", aux);
    aux[0] = '\0';
    return;
}

/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */
