#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
int get_number();
int pefect(int n);
int armstrong(int n);
int get_lenght(int n, int *arr);
int main()
{
	int number = 0;
	number = get_number();
	(armstrong(number) ? printf("\nThe %d is an Amstrong number", number) :
		printf("\nThe %d is not an Amstrong number", number)), pefect(number) ?
		printf("\nThe %d is a perfect number", number) :
		printf("\nThe %d is not a perfect number", number);
	

	getch();
	return 0;
}
int get_number()
{

	int numb = 0;
	printf("Input a number: ");
	scanf("%d", &numb);
	return numb;

}
int pefect(int n)
{
	int i = 0;
	int sum = 0;

	for (i = 1; i < n / 2; i++)
	{
		n%i == 0 ? sum += i : 0;
	}
	return(sum == n ? 1 : 0);
}
int armstrong(int n)
{
	int sum = 0;
	int i = 0;
	int arr[20];
	int lenght = get_lenght(n,arr);
	
	for (i = 0; i < lenght; i++)
	{
		sum += pow((double)arr[i], (double)lenght);
	}
	return(sum == n ? 1 : 0);

}
int get_lenght(int n,int *arr)
{
	int digit = 0;
	int lenght = 0;
	while (n > 0)
	{
		digit = n % 10;
		arr[lenght]=digit;
		n = n / 10;
		lenght++;
	}
	return lenght;
}