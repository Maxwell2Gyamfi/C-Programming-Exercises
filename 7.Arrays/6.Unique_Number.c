#pragma warning(disable:4996)

#include <stdio.h>

void print_uniques(int *numbers, int size);
void getnumbers(int *numbers, int *amount);
void get_unique(int *numbers, int size);

int main()
{
	int amount = 0;
	int numbers[20];

	getnumbers(numbers, &amount);
	get_unique(numbers, amount);

	getch();
	return 0;
}
void getnumbers(int *numbers, int *amount)
{
	int i = 0;
	int size = 0;
	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &size);

	printf("Input %d elements in the array : ", size);
	printf("\n");
	for (i = 0; i < size; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
	}

	*amount = size;
}
void get_unique(int *numbers, int size)
{
	int i, j = 0;
	int temp = 0;
	int s = 0;
	
	int unique = 0;
	int unique_numbers[20];

	for (i = 0; i < size; i++)
	{
		temp = numbers[i];
		for (j = 0; j < size; j++)
		{
			if (temp == numbers[j])
			{
				unique++;
			}
		}
		if (unique == 1)
		{
			unique_numbers[s++] = temp;
			
		}
		unique = 0;
	}
	print_uniques(unique_numbers, s);
}
void print_uniques(int *numbers, int size)
{
	int i = 0;

	printf("The unique elements found in the array are : ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}