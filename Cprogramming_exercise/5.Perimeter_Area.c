#pragma warning (disable:4996)

#include <stdio.h>
void calculate_area_perimeter(int height, int width);

int main()
{

	int height = 0;
	int width = 0;

	printf("Enter height and width: ");
	scanf("%d%d", &height,&width);

	calculate_area_perimeter(height, width);
	getchar();
	return 0;
}

void calculate_area_perimeter(int height, int width)
{
	int area = 0;
	int perimeter = 0;

	area = height * width;
	perimeter = (height + width) * 2;

	printf("Perimeter of the rectangle = %d\n", perimeter);
	printf("Area of the rectangle = %d\n", area);

}