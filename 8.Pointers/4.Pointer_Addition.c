#pragma warning(disable:4996)

#include <stdio.h>
int main()
{
	int sum = 0;
	int first, second=0;
	int *s = 0;
	int *k = 0;

	printf("Input the first number : ");
	scanf("%d",&first);

	printf("Input the second number : ");
	scanf("%d", &second);

	s = &first;
	k = &second;

	sum = *k + *s;

	printf("The sum of the entered numbers is : %d", sum);

	getch();
	return 0;
}