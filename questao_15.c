#include <stdio.h>
#include <stdlib.h>


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

float *vetor(int x, float* (*t) (float*,int))
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
}


int main()
{
	int n, i;
	printf("Indique o numero de valores: ");
	scanf("%d", &n);
	float *vetf = vetor(n, vetortrocado);
	for(i = 0; i < n; i++)
	{
		printf("%f \n", vetf[i]);
	}
	free(vetf);
	return 0;
}
