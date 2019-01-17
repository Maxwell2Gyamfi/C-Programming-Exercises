#pragma warning(disable:4996)
#include <stdio.h>

int get_n_numbers();
int get_numbers_and_sum(int n, int *numbers);
int main()
{
	int n = 0;
	int sum = 0;
	int numbers[50];

	n = get_n_numbers();
	sum = get_numbers_and_sum(n, numbers);

	printf("Sum of all elements stored in the array is : %d",sum);

	getch();
	return 0;
}
int get_n_numbers()
{
	int n = 0;
	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &n);
	return n;
}
int get_numbers_and_sum(int n,int *numbers)
{
	int i = 0;
	int sum = 0;

	printf("\nInput %d elements in array: ",n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("Element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
		sum += numbers[i];
	}
	return sum;
}
