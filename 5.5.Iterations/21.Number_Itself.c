#pragma warning(disable:4996)

#include <stdio.h>
struct number get_number();
void get_result();
typedef struct number
{
	int n;
	int number;
}m;


int main()
{
	m k;
	k = get_number();
	get_result(k);
	getch();

	return 0;
}
struct number get_number()
{
	m p;
	printf("Enter the number: ");
	scanf("%d", &p.number);
	printf("Enter n terms: ");
	scanf("%d", &p.n);
	return p;
}
void get_result(struct number k)
{
	int i = 0;
	int repeated_number = 0;
	int sum = k.number;
	

	for (i = 1; i <= k.n; i++)
	{
		if (i == 1)
		{
			repeated_number = k.number;
			printf("%d ", repeated_number);
		}
		else
		{
			repeated_number = repeated_number * 10 + k.number;
			sum += repeated_number;
			printf("%d ", repeated_number);
		}
	}
	printf("\nThe sum of the series is %d", sum);
	 
}