#include <stdio.h>

int main()
{
    int mat[4],*p,x;
	p = mat+1;// essa expressão é válida e ela toma o endereço de mat[1] = p.
	p = mat;`// essa expressão é inválida pois tem um acento depois do ponto e vírgula. Se não, seria uma expressão válida e p seria igual ao endereço de mat[0].
	p = `mat;// novamente, é inválida pois há um acento no meio da expressão. Se não, teria o mesmo valor da expressão anterior (p = mat[0]).
	x = (*mat);`// expressão inválida devido ao acento. Caso funcionasse, daria ao x o valor do último endereço possível à 4 bytes anteriores ao mat[0] (porque um inteiro tem 4 bytes).
	
	return 0;
}