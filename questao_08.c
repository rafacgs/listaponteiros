#include <stdio.h>

int main()
{
    int mat[4],*p,x;
	p = mat+1;// essa express�o � v�lida e ela toma o endere�o de mat[1] = p.
	p = mat;`// essa express�o � inv�lida pois tem um acento depois do ponto e v�rgula. Se n�o, seria uma express�o v�lida e p seria igual ao endere�o de mat[0].
	p = `mat;// novamente, � inv�lida pois h� um acento no meio da express�o. Se n�o, teria o mesmo valor da express�o anterior (p = mat[0]).
	x = (*mat);`// express�o inv�lida devido ao acento. Caso funcionasse, daria ao x o valor do �ltimo endere�o poss�vel � 4 bytes anteriores ao mat[0] (porque um inteiro tem 4 bytes).
	
	return 0;
}