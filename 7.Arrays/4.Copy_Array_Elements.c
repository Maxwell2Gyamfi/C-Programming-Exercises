#pragma warning(disable:4996)
#include <stdio.h>
//#include <string.h>

int get_n_numbers();
int get_numbers_and_sum(int n, int *numbers);
void print(int *n1, int *n2, int n);
void copy_array(int *numbers1, int *numbers2, int n);

int main()
{
	int n = 0;
	int sum = 0;
	int numbers[50];
	int numbers2[50];

	n = get_n_numbers();
	get_numbers(n, numbers);
	copy_array(numbers, numbers2, n);

	//memcpy(numbers2, numbers, n * sizeof(numbers));
	print(numbers, numbers2, n);

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
int get_numbers(int n,int *numbers)
{
	int i = 0;
	printf("\nInput %d elements in array\n", n);

	for (i = 0; i < 3; i++)
	{
		printf("Element - %d: ", i + 1);
		scanf("%d", &numbers[i]);
	}
}
void copy_array(int *numbers1, int *numbers2,int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		numbers2[i] = numbers1[i];
	}
}
void print(int *n1, int *n2,int n)
{
	int i = 0;

	printf("\nThe elements stored in the first array are : ");
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%d ", n1[i]);
	}

	printf("\nThe elements copied in the second array are : ");
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", n2[i]);
	}

}