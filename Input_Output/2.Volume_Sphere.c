#pragma warning (disable:4996)

#include <math.h>
#include <stdio.h>
#define PI 3.14159

double get_radius();
double get_volume(double radius);
void print_volume(double volume);

int main()
{
	double radius;
	double volume;
	

	radius = get_radius();
	volume = get_volume(radius);
	print_volume(volume);

	getch();
	return 0;
}
double get_radius()
{
	double radius;

	printf("Enter radius of sphere: ");
	scanf("%lf", &radius);

	return radius;
}
double get_volume(double radius)
{
	double volume = 0;
	float value = 4.0 / 3.0;
	
	volume = value * PI * pow(radius, 3.0);

	return volume;
}
void print_volume(double volume)
{

	printf("The volume of sphere is %lf", volume);

}