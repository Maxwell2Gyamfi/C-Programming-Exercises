#pragma warning (disable:4996)

#include <math.h>
#include <stdio.h>


int get_lenght();
int get_width();
void print_perimeter(int lenght, int width);

int main()
{
	int height;
	int width;


	height = get_lenght();
	width = get_width();
	print_perimeter(height, width);

	getch();
	return 0;
}
int get_lenght()
{
	int lenght;
	printf("Input the height of the Rectangle : ");
	scanf("%d", &lenght);

	return lenght;

}
int get_width()
{

	int width;
	printf("Input the height of the Rectangle : ");
	scanf("%d", &width);

	return width;


}
void print_perimeter(int lenght, int width)
{

	double perimeter1;
	int perimeter = (lenght + width) * 2;

	printf("Perimeter of the Rectangle is : %lf",(double)perimeter);

}