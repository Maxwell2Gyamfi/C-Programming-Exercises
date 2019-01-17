#pragma warning(disable:4996)

#include <stdio.h>
int get_decimal();
void get_octal(int n);

int main()
{
	
	int n = get_decimal();
	get_octal(n);

	getch();
	return 0;
}
int get_decimal()
{
	int n = 0;

	printf("Enter a number to convert: ");
	scanf("%d", &n);

	return n;
}
void get_octal(int n)
{

	int i = 0;
	int numbers[10];
	int counter = 0;
	int j = 0;
	

	for (i = 0; n > 0; i++)
	{
		numbers[i] = n % 8;
		n = n / 8;
		counter++;
	}
	for (j = sizeof(numbers)/sizeof(int); j >= 0; j--)
	{
		if(numbers[j]<0){}

		else printf("%d", numbers[j]);
	}
}