#include <stdio.h>
#include <stdlib.h>


float *vetorcrescente(int x) // declara a fun��o "vetorcrescente" que recebe uma vari�vel int x que � necess�rio para alocar a mem�ria do ponteiro que ser� retornado.
{
	int i;// declarando vari�vel de controle para repeti��o (for).
	float *vet = (float *)malloc(x * sizeof(float));// inicia o ponteiro vet, alocando a mem�ria correspondente a x multiplicado pelo tamanho de um float (4 bytes).
	if(vet == NULL)// esse if � utilizado caso n�o possa ser alocada mem�ria, imprimindo na tela "memoria insuficiente" e saindo do programa.
	{
		printf("memoria insuficiente");
		exit(1);
	}
	for(i = 0; i < x; i++) // esse for � utilizado para preencher a mem�ria alocada do ponteiro declarado anteriormente, solicitando ao usu�rio os valores para preench�-lo.
	{
		printf("Indique o valor %i do vetor: ", i+1);
		scanf("%f", &vet[i]);
	}
	return vet;// retorna o ponteiro vet.
}

int compare (const void * a, const void * b) //fun��o "geral" de compara��o de valores encontrada no https://www.cplusplus.com/reference/cstdlib/qsort/.
{
	if ( *(float*)a <  *(float*)b ) return -1; // retorna -1 (elemento a fica na posi��o anterior � b) quando b > a.
	if ( *(float*)a == *(float*)b ) return 0; // retorna 0 (elementos mant�m suas posi��es) quando b = a.
	if ( *(float*)a >  *(float*)b ) return 1; // retorna 1 (elemento b fica na posi��o anterior � 'a') quando a > b.
} // essa fun��o � um dos argumentos da fun��o qsort() utilizada para organizar o array.

int main()
{
	int n,i; // declarando duas vari�veis: uma de controle de la�o de repeti��o (i para o for) e n para declarar o tamanho do vetor, que vai ser utilizada na fun��o vetorcrescente.
	printf("Indique o numero de valores: ");// pergunta ao usu�rio qual o numero de valores no vetor de floats.
	scanf("%d", &n);// armazena o valor pedido no endere�o de n.
	float *vetf = vetorcrescente(n);// chama a fun��o vetorcrescente e armazena o valor em um ponteiro float.
	qsort(vetf,n,sizeof(float),compare);// organiza o vetor de forma crescente, recebendo como argumentos o ponteiro desejado, o numero de vari�veis, o tamanho de cada vari�vel em byte e a fun��o de compara��o anteriormente declarada.
	for(i = 0; i < n;i++)// la�o de repeti��o utilizado para imprimir todos os elementos do ponteiro organizado, pulando uma linha.
	{
		printf("%f \n",vetf[i]);
	}
	free(vetf);// libera a mem�ria alocada pela fun��o vetorcrescente com o malloc.
	return 0;
}