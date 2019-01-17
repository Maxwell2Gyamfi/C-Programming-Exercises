#pragma warning(disable:4996)

#include <stdio.h>
void get_number(int *number);
int isprime(int n);
int main()
{

	int number = 0;
	get_number(&number);
	isprime(number) ? printf("%d is a prime number",number) :
		printf("%d is not a prime number",number);

	getch();
	return 0;
}
void get_number(int *number)
{

	printf("Input a number: ");
	scanf("%d", number);

}
int isprime(int n)
{
	int prime = 0;
	int i = 0;

	for (i = 1; i <= n/2; i++)
	{
		n%i == 0 ? prime++ : 0;
	}
	return (prime == 1 ? 1 : 0);

}