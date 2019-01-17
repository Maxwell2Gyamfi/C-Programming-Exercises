#pragma warning(disable:4996)


#include <math.h>
#include <stdio.h>
#define PI 3.14

void menu();
float get_result();


int main()
{
	float result = 0;

	result = get_result();
	if (get_result != 0)
	{
		printf("The area is %f", result);
	}
	getch();
	return 0;
}


float get_result()
{
	double testdata[3];
	int choice = 0;
	float area = 0;

	menu();
	scanf("%d", &choice);

	switch (choice)
	{ 
	case 1:
		printf("Input the radius: ");
		scanf("%lf", &testdata[0]);

		area = PI * pow(testdata[0], 2);
		return area;
		break;
	case 2:
		printf("Input width and lenght: ");

		for (int i = 0; i < 2; i++)
		{
			scanf("%lf", &testdata[i]);
		}
		for (int i = 0; i < 2 - 1; i++)
		{
			for (int j = i+1; j < 2; j++)
			{
				area = testdata[i] * testdata[j];
			}
		}
		return area;
		break;
	case 3:
		printf("Input the base and height: ");
		for (int i = 0; i < 2; i++)
		{
			scanf("%lf", &testdata[i]);
		}
		for (int i = 0; i < 2 - 1; i++)
		{
			for (int j = i + 1; j < 2; j++)
			{
				area = (testdata[i] * testdata[j])/2;
			}
		}
		return area;
		break;
	default:
		printf("Incorrect input\n");
		return 0;
		break;
	}
}
void menu()
{
	printf("\nInput 1 for area of circle");
	printf("\nInput 2 for area of rectangle");
	printf("\nInput 3 for area of triangle\n");
}
