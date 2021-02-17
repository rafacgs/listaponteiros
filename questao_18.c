#include <stdio.h>
#include <stdlib.h>

float **matC(float** a, float** b,int lA,int cA, int cB)
{
	float **matrizC;
	int i,j,k;
	matrizC = malloc(lA*sizeof(float*));
	for(i = 0; i < cB;i++)
	{
		matrizC[i] = malloc(cB*sizeof(float));
	}
	for(i = 0; i < lA;i++)
	{
		for(j = 0; j < cB;j++)
		{
			for(k = 0; k < cA;k++)
			{
				matrizC[i][j] = matrizC[i][j] + a[i][k]*b[k][j];
			}
		}
	}
	return matrizC;
}

float **decMatriz(int liA,int coA,int coB)
{
	int i,j,liB = coA;
	float **matrizalocA, **matrizalocB;
	matrizalocA = malloc(liA*sizeof(float*));
	for(i = 0; i < liA;i++)
	{
		matrizalocA[i] = malloc(coA*sizeof(float));
	}
	for(i = 0; i < liA;i++)
	{
		for(j = 0; j < coA;j++)
		{
			printf("Digite o elemento da linha %d e coluna %d da matriz A:",i+1,j+1);
			scanf("%f",&matrizalocA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	matrizalocB = malloc(liB*sizeof(float*));
	for(i = 0; i < liB;i++)
	{
		matrizalocB[i] = malloc(coB*sizeof(float));
	}
	for(i = 0; i < liB;i++)
	{
		for(j = 0; j < coB; j++)
		{
			printf("Digite o elemento da linha %d e coluna %d da matriz B:",i+1,j+1);
			scanf("%f",&matrizalocB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return matC(matrizalocA,matrizalocB,liA,coA ,coB);
}

int main()
{
	int lA,cA,cB,i,j;
	float **matF;
	printf("Insira o número de linhas da matriz A: ");
	scanf("%d",&lA);
	printf("Insira o número de colunas da matriz A: ");
	scanf("%d", &cA);
	printf("Insira o número de colunas da matriz B: ");
	scanf("%d", &cB);
	matF = decMatriz(lA,cA,cB);
	for(i = 0; i < lA;i++)
	{
		for(j = 0; j < cB;j++)
		{
			printf("%f       ",matF[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < lA;i++)
	{
		free(matF[i]);
	}
	free(matF);
	return 0;
}