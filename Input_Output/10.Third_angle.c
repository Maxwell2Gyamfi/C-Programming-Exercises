#pragma warning(disable:4996)

#include <stdio.h>
int get_third_angle(int *number);
int get_angles(int *numbers1);
void print_third(int third);

int main()
{
	int third;
	int numbers[3];
	get_angles(numbers);
	third = get_third_angle(numbers);
	print_third(third);

	getch();
	return 0;
}
int get_angles(int *numbers1)
{
	int numbers[2];
	char comma[2];
	int i = 0;

	printf("Input two angles of triangle separated by comma: ");
	for (i = 0; i < 2; i++)
	{
		scanf("%d%c", &numbers[i], &comma[i]);
		if ((comma[i] == ',') || (comma[1] == '\n')){}
		else
		{
			printf("Incorrect input but i'll let pass\n");
		}
		numbers1[i] = numbers[i];
	}
	//return numbers;
}
int get_third_angle(int *number)
{
	int third = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < 2 - 1; i++)
	{
		for (j = i + 1; j < 2; j++)
		{
			third = 180 - (number[i] + number[j]);
		}
	}
	return third;

}
void print_third(int third)
{
	printf("Third angle of the triangle : %d", third);
}