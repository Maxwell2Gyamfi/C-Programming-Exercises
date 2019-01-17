#pragma warning(disable:4996)
#include <stdio.h>

int get_number();
void get_numberof_lines(int numbers);
int main()
{
	int numbers = 0;
	numbers = get_number();
	get_numberof_lines(numbers);
	getch();
	return 0;
}
void get_numberof_lines(int numbers)
{
	int count = 1;
	int i = 0;
	int j = 1;
	/*int lines = numbers * 3;
	for (i = 1; i <=lines; i++)
	{
		printf("%d ", i);
		if (i % 3 == 0)
		{
			printf("\n");
		}
	}*/
	while (i < 5)
	{
		int l = 0;
		while (l < 3)
		{
			printf("%d ",count);
			l++;
			count++;
		}
		printf("\n");
		i++;
	}
}
int get_number()
{
	int numbers = 0;

	printf("Enter the number of lines: ");
	scanf("%d", &numbers);

	return numbers;


}