#include <stdio.h>
#include <stdlib.h>


float *vetorcrescente(int x) // declara a função "vetorcrescente" que recebe uma variável int x que é necessário para alocar a memória do ponteiro que será retornado.
{
	int i;// declarando variável de controle para repetição (for).
	float *vet = (float *)malloc(x * sizeof(float));// inicia o ponteiro vet, alocando a memória correspondente a x multiplicado pelo tamanho de um float (4 bytes).
	if(vet == NULL)// esse if é utilizado caso não possa ser alocada memória, imprimindo na tela "memoria insuficiente" e saindo do programa.
	{
		printf("memoria insuficiente");
		exit(1);
	}
	for(i = 0; i < x; i++) // esse for é utilizado para preencher a memória alocada do ponteiro declarado anteriormente, solicitando ao usuário os valores para preenchê-lo.
	{
		printf("Indique o valor %i do vetor: ", i+1);
		scanf("%f", &vet[i]);
	}
	return vet;// retorna o ponteiro vet.
}

int compare (const void * a, const void * b) //função "geral" de comparação de valores encontrada no https://www.cplusplus.com/reference/cstdlib/qsort/.
{
	if ( *(float*)a <  *(float*)b ) return -1; // retorna -1 (elemento a fica na posição anterior à b) quando b > a.
	if ( *(float*)a == *(float*)b ) return 0; // retorna 0 (elementos mantêm suas posições) quando b = a.
	if ( *(float*)a >  *(float*)b ) return 1; // retorna 1 (elemento b fica na posição anterior à 'a') quando a > b.
} // essa função é um dos argumentos da função qsort() utilizada para organizar o array.

int main()
{
	int n,i; // declarando duas variáveis: uma de controle de laço de repetição (i para o for) e n para declarar o tamanho do vetor, que vai ser utilizada na função vetorcrescente.
	printf("Indique o numero de valores: ");// pergunta ao usuário qual o numero de valores no vetor de floats.
	scanf("%d", &n);// armazena o valor pedido no endereço de n.
	float *vetf = vetorcrescente(n);// chama a função vetorcrescente e armazena o valor em um ponteiro float.
	qsort(vetf,n,sizeof(float),compare);// organiza o vetor de forma crescente, recebendo como argumentos o ponteiro desejado, o numero de variáveis, o tamanho de cada variável em byte e a função de comparação anteriormente declarada.
	for(i = 0; i < n;i++)// laço de repetição utilizado para imprimir todos os elementos do ponteiro organizado, pulando uma linha.
	{
		printf("%f \n",vetf[i]);
	}
	free(vetf);// libera a memória alocada pela função vetorcrescente com o malloc.
	return 0;
}