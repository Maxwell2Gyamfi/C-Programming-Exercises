#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
void get_fermants();
int main()
{
	get_fermants();
	getch();


	return 0;
}
void get_fermants()
{
	int i = 0;
    double  firstpower = 0;
	double secondpower=0;
	double sum = 0;
	int count = 0;
	while (count < 10)
	{
		firstpower = pow(2.0, i);
		secondpower = pow(2.0, firstpower);
		sum = secondpower + 1;
		printf("%lf\n", sum);
		count++;
		i++;

	}
}