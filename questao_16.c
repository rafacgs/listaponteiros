#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


float *vetortrocado(float *vet, int x)
{
	float temp;
	int i,j;
	float *vetort = vet;
	for(i = 0; i < x - 1; i++)
	{
		int min = i;
		for(j = i + 1; j < x; j++)
		{
			if(vet[j] < vet[min])
			{
				min = j;
			}
		}
		temp = vetort[min];
		vetort[min] = vetort[i];
		vetort[i] = temp;
	}
	return vetort;
}

/*float *vetor(int x, float* (*t) (float*,int))
{
	int i;
	float *vet = (float *)malloc(x * sizeof(float));
	if(vet == NULL)
	{
		printf("memoria insuficiente");
		exit(1);
	}
	for(i = 0; i < x; i++)
	{
		printf("Indique o valor %i do vetor: ", i + 1);
		scanf("%f", &vet[i]);
	}
	return t(vet,x);
}*/

int compare (const void * a, const void * b) //função "geral" de comparação de valores encontrada no https://www.cplusplus.com/reference/cstdlib/qsort/.
{
	if ( *(float*)a <  *(float*)b ) return -1; // retorna -1 (elemento a fica na posição anterior à b) quando b > a.
	if ( *(float*)a == *(float*)b ) return 0; // retorna 0 (elementos mantêm suas posições) quando b = a.
	if ( *(float*)a >  *(float*)b ) return 1; // retorna 1 (elemento b fica na posição anterior à 'a') quando a > b.
}

int main()
{
	clock_t tempo,t;
	srand(time(NULL));
	int n, i;
	printf("Indique o numero de valores: ");
	scanf("%d", &n);
	float *vet = malloc(n*sizeof(float));
	float *vetf = malloc(n*sizeof(float));
	for(i = 0; i < n; i++) // esse for é utilizado para preencher a memória alocada do ponteiro declarado anteriormente, solicitando ao usuário os valores para preenchê-lo.
	{
		vet[i] = rand()%10000;
	}
	//float *vetf = vetor(n, vetortrocado);
	tempo = clock();
	vetf = vetortrocado(vet,n);
	tempo = clock() - tempo;
	printf("tempo de execucao da funcao criada com numeros pseudoaleatorios: %lf \n",((double)tempo)/(CLOCKS_PER_SEC/1000));
	/*for(i = 0; i < n; i++)
	{
		printf("%.2f \n", vetf[i]);
	}*/
	t = clock();
	qsort(vet,n,sizeof(float),compare);
	t = clock() - t;
	printf("tempo de execucao da funcao qsort() com numeros pseudoaleatorios: %lf \n",((double)t)/(CLOCKS_PER_SEC/1000));
	/*for(i = 0; i < n; i++)
	{
		printf("%.2f \n", vet[i]);
	}*/
	free(vetf);
	free(vet);
	return 0;
}
