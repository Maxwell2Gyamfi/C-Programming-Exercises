#pragma warning (disable :4996)

#include <stdio.h>

void calculate_area_perimter_circle(int radius);

int main()
{
	int radius = 0;
	
	printf("Enter radius: ");
	scanf("%d", &radius);

	calculate_area_perimter_circle(radius);
	getch();
	return 0;
}
void calculate_area_perimter_circle(int radius)
{
	float perimeter = 0.0;
	float area = 0.0;
	float pi = 3.14;

	perimeter = 2 * radius * pi;
	area = (radius*radius) * pi;
		
	printf("Perimeter of the Circle = %f\n",perimeter);
	printf("Area of the Circle = %f", area);
}