#pragma warning(disable:4996)

#include<stdio.h>
int get_maths_average();
int main()
{
	get_maths_average();
	getch();
	return 0;
}
int get_maths_average()
{
	float number = 0;
	float sum = 0;
	int input = 0;


	printf("Input Mathematics marks(0 to terminate: ");

	do
	{
		scanf("%f", &number);

		if (number > 0)
		{
			sum = sum + number;
			input++;
		}

	} while (number > 0);

	printf("Average marks in Mathematics: %2.2f", sum/input);

}