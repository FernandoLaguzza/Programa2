/***************************************************************************
 *   auto3.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert ER into AFND                                                  *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
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
 * @file auto3.c
 * @ingroup GroupUnique
 * @brief Converte ER para AFND
 * @details diga algo detalhado
 * @version 20160609.110101
 * @date 2016-06-09
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
 *   $gcc auto3.c -o auto3.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 * ou preferencialmente use o:
 *   $make
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto3.h */

#include "auto3.h" /* To be created for this template if needed */

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
 *    $./auto3 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-09
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    unsigned short K = 0, S = 0;
    char A;
    char *sfile = NULL, *expressao = NULL;
    t_folha *topo = NULL;
    t_delta *D = NULL, *lt_kleene = NULL;
    t_lef *F = NULL, *F_kleene = NULL;
    t_quintupla AFND;
    int ei = 0, ef = 1, e = 0;


    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhcf:e")) != EOF)
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
            case 'f':
                sfile = malloc(strlen(optarg) * sizeof(char*));
                strcpy(sfile, optarg);
                break;
            case 'e':
                e++;
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);
    if(!e)
    {
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    auto3_init(); /* global initialization function: ainda a saber para que usar se precisar */

    /* ...and we are done */
    /* Write your code here... */

	expressao = s_entrada(sfile , expressao);
    criar_arvore(&topo, expressao);
    cria_D(topo, &D, &lt_kleene, &F_kleene, ei, ef);
    K = cria_K(D);
    S = cria_S(D);
    F = cria_F(D);
    une_e_ordena_trans(D, lt_kleene);
    A = cria_A(D);
    une_ef(F, F_kleene);
    AFND = cria_quintupla(K, A, S, F, D);
    imprimir(AFND);
    derruba_arvore(topo);
    free(topo);
    clean_Q(&AFND);
    free(sfile);
    free(expressao);


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
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "auto3", VERSION, "Convert ER into AFND");
    printf("\nUsage: %s [-h|-v|-c]\n", "auto3");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-e): input data is a RE (Regular Expression) string to be converted to a NFA (Nondeterministic Finite Automata) 5-tuple.\n");
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
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto3", VERSION);
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
void auto3_init(void)
{
    IFDEBUG("auto3_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 *@brief This function does bla bla bla
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

char *s_entrada(char *sfile, char *expressao)
{
    FILE *entrada;
    char aux[SBUFF] = {'\0'};

	IFDEBUG("s_entrada()");
    if(sfile != NULL)
    {
        entrada = fopen(sfile, "r");
        if(entrada == NULL)
        {
            printf("ops, nao consigo encontrar o arquivo\n");
            exit(1);
        }
        fscanf(entrada,"%s", aux);
        fclose(entrada);
    }
    else
        scanf("%s", aux);
    expressao = malloc(strlen(aux) * sizeof(char*));
    strcpy(expressao, aux);

    return expressao;
}

/**
@ingroup GroupUnique
@brief
@details
@return void
@author
@version
@date
*
*/

void criar_arvore(t_folha **topo, char *expressao)
{
    int i, tam = strlen(expressao);
    t_folha *novo = NULL, *aux = NULL;
    IFDEBUG("criar_arvore()");
	for (i = 0; i < tam; i++)
    {
		novo = malloc(sizeof(t_folha));
        novo->carac = expressao[i];
        novo->ant = NULL;
        novo->esq = NULL;
        novo->dir = NULL;
		if(*topo == NULL)
			*topo = novo;
		else
		{
			aux = *topo;
            while(aux->dir != NULL)
                aux = aux->dir;
            novo->ant = aux;
            if(expressao[i] == '(' || expressao[i] == ')' || expressao[i] == '|' || expressao[i] == '.' || expressao[i] == '*')
                aux->dir = novo;
            else
                aux->esq = novo;
		}
    }
}

/**
@ingroup GroupUnique
@brief
@details
@return Void
@author
@version
@date
*
*/

unsigned short cria_K(t_delta *trans)
{
    unsigned short K = 0;
    t_delta *pl = trans;

    IFDEBUG("cria_K()");
    while(pl != NULL)
    {
        if(pl->ei > pl->ef)
            K= pl->ei;
        else
            K = pl->ef;

        pl = pl->prox;

    }
    return K;
}

char cria_A(t_delta *D)
{
    char letra = 'a', aux[10] = {'\0'};
    t_delta *pl = D;

    while(pl != NULL)
    {
        strcpy(aux, pl->le);
        if(letra <= aux[0] && strcmp(pl->le, "E"))
            letra = aux[0];
        pl = pl->prox;
    }

    return letra;
}

int cria_S(t_delta *trans)
{
    t_delta *conf_trans = trans;
    int ei = 0;

    IFDEBUG("cria_S()");
    while(conf_trans != NULL)
    {
        if(conf_trans->ef == ei)
        {
            ei = conf_trans->ei;
            conf_trans = trans;
        }
        conf_trans = conf_trans->prox;
    }
    return ei;
}


/**
@ingroup GroupUnique
@brief
@details
@return NULL
@author
@version
@date
*
*/

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

/**
@ingroup GroupUnique
@brief This function initializes some operations before start
@details Details to be written
@return void
@todo Need to implement it. Its empty now.
@author Marcio Andre Alves goncalves sobrinho
@version
@date
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

/**
@ingroup GroupUnique
@brief
@details
@return remover
@author
@version
@date
*
*/

t_lef *remove_ef(t_lef **F, int num)
{
    t_lef *aux, *remover = NULL;
    if(*F)
    {
        if((*F)->f == num)
        {
            remover = *F;
            *F = remover->prox;
        }
        else
        {
            aux = *F;
            while(aux->prox && aux->prox->f != num)
                aux = aux->prox;
            if(aux->prox)
            {
            remover = aux->prox;
            aux->prox = remover->prox;
            }
        }
    }
    return remover;
}

/**
@ingroup GroupUnique
@brief
@details
@return F
@author
@version
@date
*
*/

t_lef *cria_F(t_delta *trans)
{
    t_delta *conf_trans = trans;
    t_lef *F = NULL;

    IFDEBUG("cria_lista_ef()")
    while(conf_trans != NULL)
    {
        if(conf_trans->ei != conf_trans->ef)
            remove_ef(&F, conf_trans->ei);
        if(info_trans(trans, conf_trans->ef) == 0)
            inserir_ef(&F, conf_trans->ef);

        conf_trans = conf_trans->prox;
    }

    return F;
}

/**
@ingroup GroupUnique
@brief
@details
@return num
@author
@version
@date
*|a.(a.b|b)*
*/

int info_trans(t_delta *trans, int x)
{
    int num = 0;
    t_delta *conf_trans = trans;

    IFDEBUG("info_tans_ef()");
    while(conf_trans != NULL)
    {
        if(conf_trans->ei == x && conf_trans->ef != x)
            num = 1;
        conf_trans = conf_trans->prox;
    }
    return num;
}

int info_ef(t_lef *lista, int x)
{
    int num = 0;
    t_lef *busca = lista;

    while(busca != NULL)
    {
        if(busca->f == x)
            num = 1; //ja inserido
        busca = busca->prox;
    }
    return num;
}

/**
@ingroup GroupUnique
@brief
@details
@return void
@author
@version
@date
*
*/

void cria_D(t_folha *topo, t_delta **trans, t_delta **lt_kleene,t_lef **lista, int ei, int ef)
{
    char aux[SBUFF] = {'\0'};
    IFDEBUG("cria_D()");

    if(topo)
    {
	    if(topo->carac != '(' && topo->carac != ')')
        {
            switch(topo->carac)
            {
                case '|':
					pipe(trans, topo, &ei, &ef);
                    break;
                case '*':
                    trans_kleene(topo, trans, lt_kleene, lista, &ei, &ef);
                    break;
                case '.':
                    if(topo->dir != NULL)
                    {
                        if(topo->dir->carac != '*')
                        {
                            ei++;
                            ef++;
                        }
                    }
                    inserir_delta(trans,ei, "E", ef);
                    ei++;
                    ef++;
                    break;
                default:
                    sprintf(aux, "%c", topo->carac);
                    inserir_delta(trans, ei, aux, ef);
                    aux[0] = '\0';
                    ei++;
                    ef++;
                    break;
            }
        }
        cria_D(topo->esq, trans, lt_kleene, lista, ei, ef);
        cria_D(topo->dir, trans, lt_kleene, lista, ei, ef);
    }
}

/**
@ingroup GroupUnique
@brief
@details
@return void
@author
@version
@date
*
*/

void inserir_delta(t_delta **cabeca, int ei, char *le, int ef)
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
    pl->le = malloc(strlen(le) * sizeof(char*));
    pl->ei = ei;
    strcpy(pl->le, le);
    pl->ef = ef;
    pl->prox = NULL;
    pl->ant = plant;
    if(plant != NULL)
        plant->prox = pl;
    else
        *cabeca = pl;
}

/**
@ingroup GroupUnique
@brief
@details
@return void
@author
@version
@date
*
*/

void pipe(t_delta **trans, t_folha *topo, int *ei, int *ef) //o "topo" que ele recebe eh a propria posicao do pipe
{
    t_folha *busca = topo;
    int  abre=0, fecha = 0, conta = 0;

    IFDEBUG("pipe()");
    busca = busca->ant;
    while(busca->ant != NULL && abre != fecha + 1 && !(busca->carac == '|' && abre == fecha)) //arrumar p saber qual parenteses eh o certo. colocar o "busca != '('" dentro do while
    {
        switch(busca->carac)
        {
            case ')':
                fecha++;
                break;
            case '(':
                abre++;
                break;
            default:
                conta++;
                break;
        }
        if(busca->esq != NULL)
            conta++;
        if(abre == fecha + 1)
	        pipe_parenteses(trans, conta, ei, ef);
        busca = busca->ant;
        if(busca->carac == '|' && abre == fecha) //Quando o pipe encontra outro pipe sem estar em um parenteses. 3 caminhos
            pipe_pipe(trans, conta, ei, ef);
    }
    if(busca->ant == NULL)
    {
        inserir_delta(trans, *ef, "E", 0); //Quando volta para o inicio
        inserir_delta(trans, *ef, "E", *ef + 1);
    }
    *ei = *ef + 1;
    *ef = *ef + 2;
}

/**
@ingroup GroupUnique
@brief
@details
@return void
@author
@version
@date
*
*/

void pipe_parenteses(t_delta **trans, int conta, int *ei, int *ef)
{
    t_delta *conf_trans = *trans;
    int i, aux, novo_ef;

    IFDEBUG("pipe_parenteses()");
    while(conf_trans->prox != NULL)
        conf_trans = conf_trans->prox;
    novo_ef = conf_trans->ef + 2;
    for(i = 0; i < conta; i++)
    {
	    conf_trans->ei++;
        conf_trans->ef++;
        conf_trans = conf_trans->ant;
    }
    *ei = conf_trans->ef;
    aux = conf_trans->ef + 1;
    inserir_delta(trans, *ei, "E", aux); //Quando volta para o inicio
    inserir_delta(trans, *ei, "E", novo_ef);
    *ei = novo_ef - 1;
    *ef = novo_ef - 1;
}

void pipe_pipe(t_delta **trans, int conta, int *ei, int *ef)
{
    t_delta *conf_trans = *trans;
    int i, aux, novo_ef;

    IFDEBUG("pipe_pipe()");
    while(conf_trans->prox != NULL)
        conf_trans = conf_trans->prox;
    novo_ef = conf_trans->ef + 1;
    for(i = 0; i <= conta; i++)
        conf_trans = conf_trans->ant;
    aux = conf_trans->ei;
    inserir_delta(trans, aux, "E", novo_ef); //Quando volta para o inicio
    *ei = novo_ef - 1;
    *ef = novo_ef - 1;
}

void trans_kleene(t_folha *topo, t_delta **trans, t_delta **lt_kleene, t_lef **lista, int *ei, int *ef)
{
    t_delta *conf_trans = *trans;
    t_folha *busca = topo;
    int e1, abre = 0, fecha = 0, conta = 0;

    IFDEBUG("trans_kleene()");
    if(topo->ant->carac != ')')
    {
        while(conf_trans->prox != NULL)
            conf_trans = conf_trans->prox;
        e1 = conf_trans->ei;
        conf_trans->ei++;
        conf_trans->ef++;
        inserir_delta(lt_kleene, e1, "E", e1 + 1); //Quando volta para o inicio
        inserir_delta(lt_kleene, e1, "E", e1 + 3); //Quando volta para o inicio
        inserir_delta(lt_kleene, conf_trans->ef, "E", conf_trans->ei); //Quando volta para o inicio
        inserir_delta(lt_kleene, conf_trans->ef, "E", e1 + 3); //Quando volta para o inicio
        *ei = e1 + 3;
        *ef = e1 + 4;
    }
    else
    {
        if(topo->dir == NULL)
        {
            conf_trans = *trans;
            while(busca->ant != NULL && !(busca->carac == '|' && abre - 1 == fecha))
            {
                switch(busca->carac)
                {
                    case ')':
                        fecha++;
                        break;
                    case '(':
                        abre++;
                        break;
                    default:
                        conta++;
                        break;
                }
                if(busca->esq != NULL)
                    conta++;
                if(abre == fecha && abre != 0)
                {
                    kleene_parenteses(trans, lt_kleene, lista, conta);
                    break;
                }
                busca = busca->ant;
                if(busca->carac == '|' && abre + 1 == fecha)
                {
                    kleene_pipe(trans, lt_kleene, lista, conta);
                    break;
                }
            }
        }
    }
}

void kleene_parenteses(t_delta **trans, t_delta **lt_kleene, t_lef **lista, int conta)
{
    t_delta *conf_trans = *trans;
    int i, aux_ei, aux_ef;

    IFDEBUG("kleene_parenteses()");
    while(conf_trans->prox != NULL)
        conf_trans = conf_trans->prox;
    aux_ei = conf_trans->ef;
    for(i = 0; i <= conta; i++)
        conf_trans = conf_trans->ant;
    aux_ef = conf_trans->ei;
    inserir_delta(lt_kleene, aux_ei, "E", aux_ef); //Quando volta para o inicio
    if(info_ef(*lista, aux_ef) == 0)
        inserir_ef(lista, aux_ef);
}

void kleene_pipe(t_delta **trans, t_delta **lt_kleene, t_lef **lista, int conta)
{
    t_delta *conf_trans = *trans;
    int i, aux_ei, aux_ef;

    IFDEBUG("kleene_pipe()");
    while(conf_trans->prox != NULL)
        conf_trans = conf_trans->prox;
    aux_ei = conf_trans->ef;
    for(i = 0; i <= conta; i++)
        conf_trans = conf_trans->ant;
    aux_ef = conf_trans->ei;
    inserir_delta(lt_kleene, aux_ei, "E", aux_ef); //Quando volta para o inicio
    if(info_ef(*lista, aux_ef) == 0)
        inserir_ef(lista, aux_ef);
}

t_quintupla cria_quintupla(unsigned short K, char A, unsigned short S, t_lef *F, t_delta *D)
{
    t_quintupla aut;
    aut.F = NULL;
    aut.D = NULL;

    IFDEBUG("cria_quintupla()");
    aut.K = K;
    aut.A = A;
    aut.S = S;
    aut.F = F;
    aut.D = D;

    return aut;
}

/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return void
 * @todo Need to implement it. Its empty now.
 * @author Marcio Andre Alves goncalves sobrinho
 * @version
 * @date
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

void une_e_ordena_trans(t_delta *lista1, t_delta *lista2)
{
    t_delta *atual, *prox, *prox_prox, *ant;
    int trocou;

    while (lista1->prox != NULL)
        lista1 = lista1->prox;
    lista1->prox = lista2;
    lista2->ant = lista1;
    do
    {
        trocou = 0;
        atual = lista1;

        while (atual != NULL && atual->prox != NULL)
        {
            prox = atual->prox;
            if (atual->ei > prox->ei)
            {
                ant = atual->ant;
                prox_prox = prox->prox;
                if (ant != NULL)
                    ant->prox = prox;
                else
                    lista1 = prox;
                prox->ant = ant;
                prox->prox = atual;
                atual->ant = prox;
                atual->prox = prox_prox;
                if (prox_prox != NULL)
                    prox_prox->ant = atual;
                trocou = 1;
            }
            atual = prox;
        }
    } while(trocou);
}


void une_ef(t_lef *lista1, t_lef *lista2)
{
    while (lista1->prox != NULL)
        lista1 = lista1->prox;
    lista1->prox = lista2;
}

void clean_Q(t_quintupla *aut)
{

    clean_ef(&aut->F);
    clean_delta(&aut->D);
    aut->K = 0;
    aut->S = 0;
    aut->A = 'a';

    return;
}

void clean_delta(t_delta **cabeca)
{
    t_delta *pl = *cabeca, *plant = NULL;

    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
        free(plant->le);
        free(plant);
    }
    *cabeca = NULL;

    return;
}

void clean_ef( t_lef **cabeca)
{
    t_lef *pl = *cabeca, *plant = NULL;

    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
        free(plant);
    }
    *cabeca = NULL;

    return;
}

void derruba_arvore(t_folha *topo)
{
    if(topo)
    {
        derruba_arvore(topo->esq);
        derruba_arvore(topo->dir);
        free(topo->esq);
        free(topo->dir);
    }

    return;
}

/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */
