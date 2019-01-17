#pragma warning(disable:4996)
#include <stdio.h>
int elements(int *n);
int main()
{
	int n[20];
	int biggest = 0;

	biggest = elements(n);
	printf("The biggets element is %d", biggest);

	getch();
	return 0;
}
int elements(int *n)
{
	int bigger = 0;
	int number = 0;
	int i = 0;

	printf("Input the number of elements to be stored in array: ");
	scanf("%d", &number);

	for (i = 0; i < number; i++)
	{
		printf("Element - %d : ", i);
		scanf("%d", &n[i]);
		n[i] > bigger ? bigger = n[i] : 0;
	}
	return bigger;

}