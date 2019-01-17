#pragma warning(disable:4996)

#include <stdio.h>

int get_numbers(int *numbers);
void get_occurance(int *numbers, int size);
void print_occurance(int number, int occurance);

int main()
{   
	int numbers[20];
	int size = 0;
	size = get_numbers(numbers);
	get_occurance(numbers, size);

	getch();
	return 0;
}
int get_numbers(int *numbers)
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
	return size;
}
void get_occurance(int *numbers,int size)
{
	int i, j, l= 0;
	int temp = 0;
	int occurance = 0;
	int occurance2 = 0;
	int seen_numbers[20];
	int k = 0;

	printf("\n");
	for (i = 0; i < size; i++)
	{
		temp = numbers[i];
		seen_numbers[k++] = temp;

		for (j = 0; j < size; j++)
		{
			if (temp == numbers[j]) occurance++;
		}

		for (l = 0; l < k; l++)
		{
			if (temp == seen_numbers[l]) occurance2++;
		}

		if(occurance2 < 2) print_occurance(numbers[i], occurance);
		
		occurance = 0;
		occurance2 = 0;
	}
}
void print_occurance(int number, int occurance)
{
	printf("%d occurs %d times\n", number, occurance);
}
