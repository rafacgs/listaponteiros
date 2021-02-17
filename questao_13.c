#include <stdio.h>
#include <stdlib.h>


void troca(float *tmin, float *ti) 
{ 
    float temp = *tmin; 
    *tmin = *ti; 
    *ti = temp; 
} 

float *vetorcrescente(int x)
{
	int i,j;
	float *vet = (float *)malloc(x * sizeof(float));
	if(vet == NULL)
	{
		printf("memoria insuficiente");
		exit(1);
	}
	for(i = 0; i < x; i++)
	{
		printf("Indique o valor %i do vetor: ", i+1);
		scanf("%f", &vet[i]);
	}
	for(i = 0; i < x-1;i++)
	{
		int min = i;
		for(j = i + 1; j < x;j++)
		{
			if(vet[j] < vet[min])
			{
				min = j;
			}
		}
        troca(&vet[min], &vet[i]); 
	}
	return vet;
}


int main()
{
	int n,i;
	printf("Indique o numero de valores: ");
	scanf("%d", &n);
	float *vetf = vetorcrescente(n);
	for(i = 0; i < n;i++)
	{
		printf("%f \n",vetf[i]);
	}
	free(vetf);
	return 0;
}