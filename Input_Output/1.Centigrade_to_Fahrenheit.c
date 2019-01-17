#pragma warning (disable:4996)

#include <stdio.h>

int get_centigrade();
double get_fahrenheit(int centigrade);
void print_fahrenheit(double fahrenheit);

int main()
{
	int centigrade;
	double fahrenheit;

	centigrade = get_centigrade();
	fahrenheit = get_fahrenheit(centigrade);
	print_fahrenheit(fahrenheit);

	return 0;
}
int get_centigrade()
{
	int temperature = 0;

	printf("Input a temperature (in Centigrade):");
	scanf("%d", &temperature);

	return temperature;
}
double get_fahrenheit(int centigrade)
{
	double fahrenheit;

	fahrenheit = ((double)centigrade * 9/5) + 32;

	return fahrenheit;
}
void print_fahrenheit(double fahrenheit)
{

	printf("%lf degrees Fahrenheit ", fahrenheit);

}