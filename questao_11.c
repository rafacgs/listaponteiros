#include<stdio.h>

int main(){
float aloha[10], coisas[10][5], *pf, value = 2.2;
aloha[2] = value;
scanf("%f", &aloha);// Ok
//aloha = value;// Atribuição incorreta
printf("%f", aloha);// Atribuição correta
coisas[4][4] = aloha[3];// Atribuição correta
//coisas[5] = *aloha;// Atribuição é incorreta
//pf = value;// Atribuição é incorreta 
pf = aloha;// Atribuição correta
return 0;
}
