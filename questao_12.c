#include <stdio.h>
#include <stdlib.h>

int *soma(int *vet1, int *vet2, int n){
	int i;
	int *sum = (int *) malloc(n * sizeof(int));
		if(sum == NULL){
		printf("Memoria insuficiente\n");
		exit(1);
		}		
		for(i = 0; i < n; i++){
		sum[i] += vet1[i] + vet2[i];
		}
	return sum;
}

int main(){
	int i, n, cont = 1, cont2 = 1;
	printf("Insira o tamanho dos vetores a serem somados: ");
	scanf("%d", &n);
		int vet1[n];
		int vet2[n];
			system("clear||cls");	
			printf("Os vetores 1 e 2 possuem %i posicoes: ", n);
			printf("\n");
			for(i = 0; i < n; i++){
				printf("Insira a posicao: %i do (vetor 1): ", cont);	
				scanf("%d", &vet1[i]);
				cont++;
			}
			printf("-------------------------------------------------- \n");
			for(i = 0; i < n; i++){
				printf("Insira a posicao: %i do (vetor 2): ", cont2);
				scanf("%d", &vet2[i]);
				cont2++;
			}
			int *vet3 = soma(vet1, vet2, n);
			for(i = 0; i < n; i++){
				printf("%i ", vet3);
			}
		free(vet3);
	return 0;
}
