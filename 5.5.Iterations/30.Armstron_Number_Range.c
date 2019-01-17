#pragma warning (disable:4996);
#include <stdio.h>
#include <math.h>
#include <string.h>

void get_ranges(int *start, int *end);
void get_armstrong_numbers(int start, int end);

int main()
{
	int start=0;
	int end=0;
	get_ranges(&start, &end);
	get_armstrong_numbers(start, end);

	getch();
	return 0;
}
void get_ranges(int *start, int *end)
{
	printf("Input starting number of range: ");
	scanf("%d", &(*start));

	printf("Input ending number of range :");
	scanf("%d", &(*end));

}
void get_armstrong_numbers(int start, int end)
{
	int j = 0;
	int i = 0;
	char buffer[10];
	int lenght = 0;
	int sum = 0;
	
	printf("\nArmstrong values in given ranges are: ");

	for (i = start; i < end; i++)
	{
		sprintf(buffer, "%d", i);
		lenght = strlen(buffer);

		for (j = 0; j < lenght; j++)
		{
			sum += pow((double)buffer[j] - '0', lenght);
		}
		if (sum == i)
		{
			if(lenght==1 && i!=1){}
			else printf("%d ", i);
		}
		sum = 0;
		memset(buffer, 0, sizeof(buffer));
	}
}

