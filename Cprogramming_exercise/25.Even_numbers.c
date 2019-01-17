#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int *save_all_numbers(int *lenght);
void print_all_numbers(int *numbers, int lenght);
int save_all_numbers_malloc(int *lenght);

int main()
{
	int *numbers_array = 0;
	int *numbers_array_malloc = 0;
	int lenght = 0;
	int lenght2 = 0;

	numbers_array = save_all_numbers(&lenght);
	numbers_array_malloc = save_all_numbers_malloc(&lenght2);
	print_all_numbers(numbers_array_malloc, lenght2);
	print_all_numbers(numbers_array, lenght);
	free(numbers_array_malloc);

	getch();
	return 0;
}
int *save_all_numbers(int *lenght)
{
	int i = 0;
	static int numbers[51];
	
	
	for (i = 0; i < 51; i++)
	{
		numbers[i] = i;
	}
	*lenght = sizeof(numbers) / sizeof(int);//the correct lenght can ONLY be found in the main function 
										   //where data is saved in array;

	return numbers;

}
int save_all_numbers_malloc(int *lenght)
{
	int i = 0;
	int size = 50;
	int *numbers = 0;

	*lenght = size;

	numbers = (int*)malloc(size * sizeof(int));
	
	if (size == NULL)
	{
		printf("Error no memory allocated");
		exit(0);
	}

	for (i = 0; i < size; i++)
	{
		*(numbers + i) = i;
	}
	return numbers;
}
void print_all_numbers(int *numbers, int lenght)
{
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		if(i==0){}

		else
		{
			if (i % 2 == 0)
			{
				printf("%d ", numbers[i]);
			}
		}
	}
}


