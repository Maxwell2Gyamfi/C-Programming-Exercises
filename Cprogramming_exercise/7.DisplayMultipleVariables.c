#pragma warning(disable:4996)

#include <stdio.h>

int main()
{
	
	int a = 125, b = 12345;
	long ax = 1234567890;
	short s = 4043;
	float x = 2.13459;
	double dx = 1.1415927;
	char c = 'W';
	unsigned long ux = 2541567890;

	double dxx = dx + ((double)x);
	long adx = ((int)dx) + ax;
	float axx = ((float)a) + x;
	int bs = b + s;
	long axb = ax + b;
	unsigned long axux = ux + ((unsigned)ax);

	//a+ c, x + c,dx + x, ((int) dx) + ax, a + x, s + b, ax + b, s + c, ax + c, ax + ux 
	printf("%d\n", a + c);
	printf("%f\n", x + c);
	printf("%lf\n", dxx);
	printf("%li\n", adx);
	printf("%lf\n", axx);
	printf("%d\n", bs);
	printf("%li\n", axb);
	printf("%hi\n", s+c);
	printf("%li\n", ax+c);
	printf("%lu\n", axux);

	getchar();

	return 0;
}