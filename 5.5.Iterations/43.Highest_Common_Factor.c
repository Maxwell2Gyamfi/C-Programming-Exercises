#pragma warning(disable:4996)

#include <stdio.h>
void get_numbers(int *first, int *second);
void get_hcf(int first, int second);
int main()
{
	int first = 0;
	int second = 0;

	get_numbers(&first, &second);
	get_hcf(first, second);

	getch();
	return 0;
}
void get_numbers(int *first, int *second)
{
	printf("Input 1st number of HCF: ");
	scanf("%d", &(*first));

	printf("Input 2nd number of HCF: ");
	scanf("%d", &(*second));

}
void get_hcf(int first, int second)
{
	int i = 0;
	int lenght = 0;
	int hcf = 0;
	int lcf = 0;

	if (first > second) lenght = first / 2;
	else if (first < second)lenght = second / 2;
	else lenght = first;
	
	for (i = 1; i <= lenght; i++)
	{
		if (first%i == 0 && second%i == 0)
		{
			hcf = i;
		}
	}
	lcf = (first*second) / hcf;
	printf("HCF of %d and %d is: %d", first, second, hcf);
}