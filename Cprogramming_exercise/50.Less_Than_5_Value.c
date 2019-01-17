#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

float *get_numbers();
int decide_smaller(float *numbers);

int main()
{
	float *numbers = 0;
	numbers = get_numbers();
	decide_smaller(numbers);
	getch();
	return 0;
}
float *get_numbers()
{
	static float numbers[6];
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%f", &numbers[i]);
	}
	return numbers;
}
int decide_smaller(float *numbers)
{
	int i = 0;
	int smaller = 0;

	for (i = 0; i < 5; i++)
	{
		if (numbers[i] < 5)
		{
			printf("A[%d] = %1.1f", i, numbers[i]);
		}
	}
}