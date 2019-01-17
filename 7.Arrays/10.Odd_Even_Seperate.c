#pragma warning(disable:4996)

#include <stdio.h>
int get_numbers(int *numbers);
void get_odd_even(int *numbers, int size);
void print_odd_even(int *arrayodd, int odd, int *arrayeven, int even);
void print_elements(int *numbers, int size);
int iseven(int number);

int main()
{
	int size = 0;
	int numbers[30];

	get_numbers(numbers, &size);
	get_odd_even(numbers, size);

	getch();

	return 0;
}

int get_numbers(int *numbers,int *size)
{
	int n = 0;
	int i = 0;

	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &n);

	printf("Input %d elements in the array : ", n);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
	}
	*size = n;

}
void get_odd_even(int *numbers, int size)
{
	int i = 0;
	int arrayeven[20];
	int odd = 0;
	int even = 0;
	int arrayodd[20];

	printf("\n");

	for (i = 0; i < size; i++)
	{
		if (iseven(numbers[i]))arrayeven[even++] = numbers[i];
		else arrayodd[odd++] = numbers[i];
	}
	print_odd_even(arrayodd, odd, arrayeven, even);

}
void print_odd_even(int *arrayodd, int odd, int *arrayeven, int even)
{
	printf("The Even elements are : ");
	print_elements(arrayeven, even);

	printf("The Odd elements are : ");
	print_elements(arrayodd, odd);
}
void print_elements(int *numbers, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}

	printf("\n");
}
int iseven(int number)
{
	if (number % 2 == 0)return 1;
	else return 0;
}