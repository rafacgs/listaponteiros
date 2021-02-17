#include <stdio.h>
#include <stdlib.h>

int *soma(int *vet1, int *vet2, int x){
	int i;
	int *sum = (int *) malloc(x * sizeof(int));
		if(sum == NULL){
		printf("Memoria insuficiente\n");
		exit(1);
		}		
		for(i = 0; i < x; i++){
		sum[i] = vet1[i] + vet2[i];
		}
	return sum;
}

int main(){
	int i, n, cont = 1, cont2 = 1, m, x;
	printf("Insira o tamanho dos vetor 1: ");
	scanf("%i", &n);
	printf("Insira o tamanho dos vetor 2: ");
	scanf("%i", &m);
		int vet1[n];
		int vet2[m];
		if(n > m){
			x = n;
		}else{
			if(m > n){
				x = m;
			}else{
				x = m;
			}
		}

			system("clear||cls");	
			printf("Os vetores 1 e 2 possuem %i e %i posicoe, respectivamente. ", n, m);
			printf("\n");
			printf("\n");
			for(i = 0; i < n; i++){
				printf("Insira a posicao: %i do (vetor 1): ", cont);	
				scanf("%i", &vet1[i]);
				cont++;
			}
			printf("-------------------------------------------------- \n");
			for(i = 0; i < m; i++){
				printf("Insira a posicao: %i do (vetor 2): ", cont2);
				scanf("%i", &vet2[i]);
				cont2++;
			}
			int *vet3 = soma(vet1, vet2, x);
			for(i = 0; i < x; i++){
				printf("%i ", vet3[i]);	
			}
		free(vet3);
	return 0;
}


