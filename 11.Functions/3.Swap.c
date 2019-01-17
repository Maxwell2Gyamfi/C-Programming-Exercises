#pragma warning(disable:4996)
#include <stdio.h>
void get_numbers(int *first, int *second);
void swap(int *first, int *second);

int main()
{

	int first, second = 0;
	get_numbers(&first, &second);
	printf("Before swapping: n1 = %d, n2 = %d", first, second);
	swap(&first, &second);
	printf("\nAfter swapping: n1 = %d, n2 = %d", first, second);

	getch();
	return 0;
}
void get_numbers(int *first, int *second)
{

	printf("Input first number: ");
	scanf("%d", first);
	printf("Input second number: ");
	scanf("%d", second);

}
void swap(int *first, int *second)
{
	int temp = 0;

	temp = *first;
	*first = *second;
	*second = temp;
}