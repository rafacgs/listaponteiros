#include <stdio.h>

int main()
{
    int mat[4],*p,x;
	p = mat+1;// Essa expressão é válida e ela toma o endereço de mat[1] = p.
	p = mat;// É uma expressão válida e p é igual ao endereço de mat[0].
	p = mat;// Tem o mesmo valor da expressão anterior (p = mat[0]).
	x = (*mat);// Expressão válida, atribuindo ao x o valor do último endereço possível à 4 bytes anteriores ao mat[0] (porque um inteiro tem 4 bytes).
	return 0;
}
