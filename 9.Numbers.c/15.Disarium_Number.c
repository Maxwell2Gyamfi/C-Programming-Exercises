#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

int get_number();
int calculate_lenght(int n);
void get_disarium_number(int n);
int main()
{
	int n = get_number();
	get_disarium_number(n);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Enter n: ");
	scanf("%d", &n);
	return n;
}
int calculate_lenght(int n)
{
	int count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return count;
}
void get_disarium_number(int n)
{
	int s = n;
	int remainder = 0;
	int sum = 0;
	int i = 0;
	int count = calculate_lenght(n);

	while (s)
	{
		remainder = s % 10;
		remainder = pow((double)remainder, (double)count);
		sum += remainder;
		s = s / 10;
		count--;

	}

	if (sum == n) printf("The given number %d is a Disarium Number.", n);
	else printf("The given number %d is not a Disarium Number.", n);
}