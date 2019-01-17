#pragma warning (disable: 4996)
#include <stdio.h>

#define SIGN 167 
int sum_odd_numbers();

int main()
{
	int sum_odd = 0;
	sum_odd = sum_odd_numbers();
	printf("\nSum of all odd numbers %d", sum_odd);
	getch();

	return 0;
}
int sum_odd_numbers()
{
	int i = 0;
	int numbers[5];
	char numbers2[6][8] = { "first","second","third","fourth","fifth" };
	int result = 0;

	printf("Enter five numbers\n");
	
	for (i = 0; i < 5; i++)
	{
		printf("\nEnter %s number: ",numbers2[i]);
		scanf("%d", &numbers[i]);

		if (numbers[i] % 2 != 0)
		{
			result = result + numbers[i];
		}
	}
	return result;
}