#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>
void calculate_coordinate();
int main()
{
	calculate_coordinate();
	getch();
	return 0;
}

void calculate_coordinate()
{
	float x1 =0;
	float y1=0;
	float x2 = 0;
	float y2= 0;
	float distance_coordinate = 0;
	float distance_coordinate1 = 0;
	printf("Input x1 and y1 ");
	scanf("%f%f", &x1, &y1);

	printf("\nInput x2 and y2 ");
	scanf("%f%f", &x2, &y2);

	distance_coordinate = sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
	distance_coordinate1 = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
	printf("Distance between the said points: %2.4f\n", distance_coordinate);
	printf("Distance between the said points: %2.4f\n", distance_coordinate1);
}