#pragma warning(disable:4996)
#include <stdio.h>
int get_numbers(int *n);
int binary_search(int s, int n[], int start, int end);
int main()
{
	int s = 0;
	int amount = 0;
	int k[20];

	amount = get_numbers(k);
	printf("Input the number to search: ");
	scanf("%d", &s);
	binary_search(s, k, 0, amount-1);

	getch();
	return 0;
}
int get_numbers(int *n)
{
	int i = 0;
	int amount = 0;

	printf("Input the number of elements to store in array: ");
	scanf("%d", &amount);
	printf("Input %d elements in the array in ascending order: ",amount);
	printf("\n");
	for (i = 0; i < amount; i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &n[i]);
	}
	return amount;
}
int binary_search(int s,int n[],int start,int end)
{
	static int middle = 0;
	static int i = 0;
	if (s == n[middle])
	{
		printf("The search number is found in array");
		return;
	}
	if (start > end)
	{
		printf("The search number is not found in array");
	}
	if (start <=end)
	{
		middle = (start + end) / 2;
		s > n[middle] ? binary_search(s, n, middle + 1, end) : binary_search(s, n, start, middle);
	}
	
}