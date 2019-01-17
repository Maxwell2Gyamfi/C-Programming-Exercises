#pragma warning(disable:4996)


#include <math.h>
#include <stdio.h>
#define PI 3.14

void calculation();
void menu();
int main()
{

	calculation();
	getch();
	return 0;
}
void calculation()
{
	int testdata[3];
	int choice = 0;
	int result = 0;



	menu();
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("Enter first and second number: ");
		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &testdata[i]);
		}
		for (int i = 0; i < 2 - 1; i++)
		{
			for (int j = i + 1; j < 2; j++)
			{
				result = testdata[i] + testdata[j];
				printf("The addition of %d and %d is %d", testdata[i], testdata[j], result);
			}
		}
		break;
	case 2:
		printf("Enter first and second number: ");
		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &testdata[i]);
		}
		for (int i = 0; i < 2 - 1; i++)
		{
			for (int j = i + 1; j < 2; j++)
			{
				result = testdata[i] - testdata[j];
				printf("The subtraction of %d and %d is %d", testdata[i], testdata[j], result);
			}
		}
		break;
	case 3:
		printf("Enter first and second number: ");
		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &testdata[i]);
		}
		for (int i = 0; i < 2 - 1; i++)
		{
			for (int j = i + 1; j < 2; j++)
			{
				result = testdata[i] * testdata[j];
				printf("The moltiplication of %d and %d is %d", testdata[i], testdata[j], result);
			}
		}
		break;
	case 4:
		printf("Enter first and second number: ");
		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &testdata[i]);
		}
		if (testdata[1] == 0)
		{
			printf("Infinity");
		}
		else
		{
			for (int i = 0; i < 2 - 1; i++)
			{
				for (int j = i + 1; j < 2; j++)
				{
					result = testdata[i] / testdata[j];
					printf("The division of %d and %d is %d", testdata[i], testdata[j], result);
				}
			}
		}
		break;
	case 5:
		return 0;
		break;
	default:
		printf("Incorrect input");
		break;
	}

}
void menu()
{
	printf("1.Addition\n2.Subtraction\n3.Moltiplication\n4.Division\n5.Quit\n");
}