#include <stdio.h>
#include <stdlib.h>
#include "gc/gc.h"

int main(int argc, char **argv)
{
    int i;
    // int *k = malloc(5*sizeof(int)); da erro de compilacao core dump pois o for() abaixo ira ultrapassar o tamanho do ponteiro.
	int *k = GC_MALLOC(5*sizeof(int));/*Funcao basicamente identica ao do malloc, 
porem ele faz o uso do free (nao GC_FREE, utilizado para programas muito maiores)obsoleto (memoria nao utilizada ou nao alcancada e automaticamente "retraida"). 
Nesse caso, o for abaixo ainda e executado, mesmo que ultrapasse o tamanho do ponteiro, devido ao GC_MALLOC(que elimina o restante dos dados do ponteiro)*/
    for(i = 0; i < 50;i++)
    {
        k[i] += i;
    }
    for(i = 0; i < 5;i++)
    {
        printf("%d \n",k[i]);
    }
	return 0;
}
