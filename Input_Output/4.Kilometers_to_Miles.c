#pragma warning (disable:4996)

#include <math.h>
#include <stdio.h>
#define MILES  0.621371

double get_miles(int kilometers);
int get_kilometers();
void print_miles(double miles);


int main()
{
	int kilometers;
	double miles;

	kilometers = get_kilometers();
	miles = get_miles(kilometers);
	print_miles(miles);

	getch();
	return 0;
}
int get_kilometers()
{
	char kilometers1[5];
	int kilometers;

	fputs("Enter kilometers per hour: ",stdout);
	fgets(kilometers1, sizeof(kilometers1), stdin);

	sscanf(kilometers1, "%d", &kilometers);

	return kilometers;

}
double get_miles(int kilometers)
{

	double miles = kilometers * MILES;

	return miles;
}
void print_miles(double miles)
{
	printf("%lf per hour", miles);

}