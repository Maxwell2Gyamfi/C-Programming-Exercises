#pragma warning (disable: 4996)
#include <stdio.h>

struct numbers numberstriangle();
struct numbers bubblesort(struct numbers u);
struct numbers
{
	float numbers1[3];
	float perimeter;
	int error;
	float largest;

};

int main()
{
	int i = 0;
	struct numbers p;

	p = numberstriangle();
	if (p.error == 1)
	{

		printf("Numbers in sorted order: ");
		for (i = 0; i < 3; i++)
		{
			printf("\n%.2f", p.numbers1[i]);
		}
		printf("\nPerimeter is %.2f", p.perimeter);
	}
	getch();
	return 0;
}
struct numbers numberstriangle()
{
	struct numbers p;


	int perimeter = 0;
	int i = 0;
	int j = 0;
	float temp = 0;


	printf("Enter 3 numbers: ");
	for (i = 0; i < 3; i++)
	{
		scanf("%f", &p.numbers1[i]); 
		perimeter = perimeter + p.numbers1[i];
	}

	p = bubblesort(p);

	if (p.numbers1[2] < (p.numbers1[0] + p.numbers1[1]))
	{
		p.perimeter = perimeter;
		p.error = 1;
		return p;

	}
	else
	{
		printf("It is not possible to create a triangle");
		p.error = 0;
		return p;
	}
}
struct numbers bubblesort(struct numbers u)
{
	int j = 0;
	int i = 0;
	float temp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = i; j < 3; j++)
		{
			if (u.numbers1[i] > u.numbers1[j])
			{
				temp = u.numbers1[i];
				u.numbers1[i] = u.numbers1[j];
				u.numbers1[j] = temp;
				
			}
		}
	}
	return u;
}


