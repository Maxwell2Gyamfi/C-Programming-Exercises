#pragma warning(disable:4996)
#include <stdio.h>
int get_numbers(int *n);
void print_reverse(int *n, int size);
int main()
{
	int size = 0;
	int *k = 0;
	int numbers[20];

	size = get_numbers(numbers);
	k = &numbers[0];
	print_reverse(k,size);

	getch();
	return 0;
}
int get_numbers(int *n)
{
	int i = 0;
	int size = 0;
	printf("Input the number of elements to store in the array (max 15) :  ");
	scanf("%d", &size);

	printf("Input %d elements in the array : ", size);
	printf("\n");


	for (i = 0; i < size; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &(*n));
		n++;
	}
	return size;
}
void print_reverse(int *n, int size)
{
	int i = 0;
	printf("\nThe elements of the array in reverse order are : ");
	printf("\n");
	for (i = size - 1; i >= 0; i--)
	{
		printf("element - %d : %d\n", i + 1,n[i]);
	}
}