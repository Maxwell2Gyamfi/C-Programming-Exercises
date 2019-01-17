#pragma warning(disable:4996)
void get_numbers(int *numbers, int *size);
void sort_array(int *numbers, int size);
void print(int *numbers, int size);
#include <stdio.h>
int main()
{
	int size = 0;
	int numbers[20];
	get_numbers(numbers, &size);
	sort_array(numbers, size);
	print(numbers, size);
	getch();


	return 0;
}
void get_numbers(int *numbers, int *size)
{
	int i = 0;
	printf("Input the number of elements to store in the array :");
	scanf("%d", &(*size));

	for (i = 0; i < *size; i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &(*numbers));
		numbers++;
	}
}
void sort_array(int *numbers, int size)
{
	int temp = 0;
	int i = 0;
	int j = 0;

	for (i = 1; i < size; i++)
	{
		temp = numbers[i];
		j = i - 1;
		
		while (temp < numbers[j] && j >=0)
		{
			numbers[j+1] = numbers[j];
			j--;
		}
		
		numbers[j+1] = temp;
	}
}
void print(int *numbers, int size)
{

	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}