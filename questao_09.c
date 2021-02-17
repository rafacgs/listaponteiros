#include <stdio.h>

int main(){
	int vet[] = {4,9,13};
	int i;
		for(i=0;i<3;i++){
			printf("%d ",*(vet+i)); //Imprime o valor do vetor declarado de forma inteira
		}
		for(i=0;i<3;i++){
			printf("%X ",vet+i); //Imprime o valor do vetor declarado de forma hexadecimal
		}
	return 0;
}
