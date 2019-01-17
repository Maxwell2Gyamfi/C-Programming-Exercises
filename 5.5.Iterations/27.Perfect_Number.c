#pragma warning(disable:4996)
#include <stdio.h>
void get_number();
void get_perfect_number(int n);
int main()
{
	get_number();
	
	getch();
	return 0;
}
void get_number()
{
	int n = 0;
	printf("Enter the number: ");
	scanf("%d", &n);
	get_perfect_number(n);
}
void get_perfect_number(int n)
{
	int sum = 0;
	size_t i = 1;

	printf("The positive divisor: ");
	
	for (i = 1; i < n; i++)
	{
		if (n%i == 0)
		{
			printf("%d ", i);
			sum += i;
		}
	}
	
	printf("\nThe sum of the divisor is %d", sum);
	if (sum == n)printf("\nSo its a perfect number");
	else printf("\nSo its not a perfect number");
}