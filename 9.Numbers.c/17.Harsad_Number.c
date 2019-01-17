#pragma warning(disable:4996)
#include <stdio.h>
int get_sum(int n);
void harshad(int n);
int get_number();
int main()
{
	int n = get_number();
	harshad(n);
	getch();
	return 0;
}
int get_number()
{
	int n;
	printf("Enter a number : ");
	scanf("%d", &n);
	return n;
}
void harshad(int n)
{
	int sum = get_sum(n);
	if (n%sum == 0)printf("\nThe given number is a Harshad Number.");
	else printf("\nThe given number is not a Harshad Number.");
}
int get_sum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n = n/10;
	}
	return sum;
}