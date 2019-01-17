#pragma warning(disable:4996)

#include <stdio.h>


int get_n();
int main()
{
	get_n();
	getch();


	return 0;
}
int get_n()
{
	int n = 0;
	printf("Test data: ");
	scanf("%d", &n);
	get_factorial(n);
	

}
int get_factorial(int n)
{
	int i = 1;
	long int sum = 1;

	for (i = 1; i <= n; i++)
	{
		sum *= i;
	}
	printf("Factorial is %ld ", sum);


}