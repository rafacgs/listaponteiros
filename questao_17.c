#include <stdio.h>
#include <stdlib.h>

float *vetsoma(float *vet1,float *vet2,int x)
{
	int i;
	float *vetr3 = malloc(x*sizeof(float));
	for(i = 0; i < x;i++)
	{
		vetr3[i] = vet1[i] + vet2[i];
	}
	free(vet1);
	free(vet2);
	return vetr3;
}

float *decvet(int t1,int t2)
{
	int x,i;
	if(t1 > t2)
	{
		x = t1;
	}else
	{
		x = t2;
	}
	float *vet1 = malloc(x*sizeof(float));
	float *vet2 = malloc(x*sizeof(float));
	for(i = 0; i < x;i++)
	{
		vet1[i] = 0;
		vet2[i] = 0;
	}
	for(i = 0; i < t1;i++)
	{
		printf("Insira o elemento %d do vetor 1: ", i+1);
		scanf("%f",&vet1[i]);
	}
	printf("\n");
	for(i = 0; i < t2;i++)
	{
		printf("Insira o elemento %d do vetor 2: ", i + 1);
		scanf("%f",&vet2[i]);
	}
	return vetsoma(vet1,vet2,x);
}



int main(void)
{
	int t1,t2,i;
	printf("Insira o tamanho do vetor 1: ");
	scanf("%d",&t1);
	printf("---------------------------------------------- \n");
	printf("Insira o tamanho do vetor 2: ");
	scanf("%d",&t2);
	printf("---------------------------------------------- \n \n \n \n");
	float *vet3 = decvet(t1,t2);
	for(i = 0; vet3[i];i++)
	{
		printf("%.2f ", vet3[i]);
	}
	free(vet3);
	return 0;
}