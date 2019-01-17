#pragma warning(disable:4996)
#include <stdio.h>
int *get_bigger();
int biggest(int first, int second);

int main()
{
	int *largest = 0;
	largest = get_bigger();
	printf("\nThe number %d is larger", *largest);

	getch();
	return 0;
}
int *get_bigger()
{
	int *ptr;
	int largest = 0;
	int first = 0;
	int second = 0;

	printf("Input the first number : ");
	scanf("%d", &first);
	printf("Input the second number : ");
	scanf("%d", &second);

	largest = biggest(first, second);
	ptr = &largest;

	return ptr;

}
int biggest(int first, int second)
{

	if (first > second) return first;
	else return second;

}