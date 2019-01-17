#pragma warning (disable: 4996)

#include <string.h>
#include <stdio.h>

int *get_cordinate_numbers();
void get_coordinates(int *numbers, int *x, int *y);
char * decide_quadrant(int x, int y);
void print_decision(char *decision);

int main()
{
	int x = 0;
	int y = 0;
	int *numbers = 0;
	char *decision = 0;
    
	numbers = get_cordinate_numbers();
	get_coordinates(numbers, &x, &y);
	decision = decide_quadrant(x, y);
	print_decision(decision);

	getch();
	return 0;
}
int *get_cordinate_numbers()
{
	static int numbers[3];

	int i = 0;

	printf("Enter coordinates x and y: ");
	for (i = 0; i < 2; i++)
	{
		scanf("%d", &numbers[i]);
	}
	return numbers;

}
void get_coordinates(int *numbers, int *x, int *y)
{
	*x = numbers[0];
	*y = numbers[1];
}
char * decide_quadrant(int x, int y)
{
	static char quadrants[23];

	if ((x > 0) && y > 0)
	{
		strcpy(quadrants, "Quadrant - I(+, +)");
		return quadrants;
	}
	else if ((x < 0) && y > 0)
	{
		strcpy(quadrants, "Quadrant - II(-, +)");
		return quadrants;
	}
	else if ((x < 0) && y < 0)
	{
		strcpy(quadrants, "Quadrant - III(-, -)");
		return quadrants;
	}
	else
	{
		strcpy(quadrants, "Quadrant - IV(+, -)");
		return quadrants;
	}
}
void print_decision(char *decision)
{
	printf("%s", decision);
}