#include <stdio.h>
#include <stdlib.h>
#include "gc/gc.h"
#include <time.h>


int main(int argc, char **argv)
{
    clock_t tempo,t;
    int i;
    tempo = clock();
    int *k = malloc(250*sizeof(int));// tempo menor em armazenar menos variaveis (testado com 250, 250.000 e 250.000.000, em 250 mil ainda e uma diferenca enorme de tempo).
    for(i = 0; i < 250;i++)
    {
        k[i] = 100;
    }
    free(k);
    tempo = clock() - tempo;
    t = clock();
    int *j = GC_MALLOC(250*sizeof(int));// tempo menor em armazenar mais variaveis (testado com 250, 250.000 e 250.000.000, em 250 milhoes a diferenca finalmente diminui e o GC_MALLOC fica mais rapido).
    for(i = 0; i < 250;i++)  
    { 
        j[i] = 100;  
    }
    //GC_FREE(t); so faz diferenca em projetos enormes.
    t = clock() - t;
    printf("Tempo (ms) do GC_MALLOC: %lf \nTempo (ms) do malloc: %lf \n",(double)t/(CLOCKS_PER_SEC/1000),(double)tempo/(CLOCKS_PER_SEC/1000));
	return 0;
}
