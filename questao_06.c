#include <stdio.h>


int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  printf("contador/valor/valor/endereco/endereco");
  for(i = 0 ; i <= 4 ; i++){
  printf("\ni = %d",i);// valor de i (0 a 4).
  printf("vet[%d] = %.1f",i, vet[i]);// valor de vet[i] (de 1.1 a 5.5).
  printf("*(f + %d) = %.1f",i, *(f+i));// valor guardado no endere�o apontado por f+i; nesse caso, 1.1 a 5.5, j� que *(f+i) = vet[i].
  printf("&vet[%d] = %X",i, &vet[i]);// endere�o de vet[i] em hexadecimal.
  printf("(f + %d) = %X",i, f+i);// endere�o de f + i em hexadecimal (endere�o de vet[i]).
  }
}