#include<stdio.h>

int main(){
float aloha[10], coisas[10][5], *pf, value = 2.2;
aloha[2] = value;
scanf("%f", &aloha);// Ok
//aloha = value;// Atribui��o incorreta
printf("%f", aloha);// Atribui��o correta
coisas[4][4] = aloha[3];// Atribui��o correta
//coisas[5] = *aloha;// Atribui��o � incorreta
//pf = value;// Atribui��o � incorreta 
pf = aloha;// Atribui��o correta
return 0;
}
