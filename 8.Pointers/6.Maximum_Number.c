#pragma warning(disable:4996)
#include <stdio.h>
void get_numbers(int *first, int *second);
int get_maximum(int *first, int *second);

int main()
{
	int first = 0;
	int second = 0;
	int *k = 0;
	int *s = 0;
	int *q = 0;
	int bigger = 0;

	get_numbers(&first, &second);
	k = &first;
	s = &second;

	bigger = get_maximum(k, s);
	q = &bigger;
	printf("%d is the maximum number.", *q);

	getch();
	return 0;
}
void get_numbers(int *first, int *second)
{
	printf("Input the first number : ");
	scanf("%d", &(*first));
	printf("Input the second number : ");
	scanf("%d", &(*second));
}
int get_maximum(int *first, int *second)
{
	if (*first > *second)return *first;
	else return *second;
}