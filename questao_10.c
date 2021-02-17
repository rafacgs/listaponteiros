/*	


char x[4]: Se o endereço é 4092, x+1 = 4093, x+2 = 4094 e x+3 = 4095. 
int x[4]: Se o endereço é 4092, x+1 = 4094, x+2 = 4096 e x+3 = 4098.
float x[4]: Se o endereço é 4092, x+1 = 4096, x+2 = 4100 e x+3 = 4104.
double x[4]: Se o endereço é 4092, x+1 = 4100, x+2 = 4108 e x+3 = 4116.

*/

#include <stdio.h>

int main()
{
	char cx[4];
	short int ix[4], i;
	float fx[4];
	double dx[4];
	for(i = 0; i < 4;i++){
	
	printf("x + %i = %i,%i,%i,%i\n",i,cx+i,ix+i,fx+i,dx+i);
	
	}
	return 0;
}