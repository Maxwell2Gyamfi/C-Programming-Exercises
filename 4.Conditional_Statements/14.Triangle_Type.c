#pragma warning (disable:4996)

#include <stdio.h>
int get_angles();
void decide_triangle_type(int *angles);

int main()
{
	get_angles();
	getch();
	return 0;
}
int get_angles()
{

	int angles[3];
	size_t i;

	printf("Test data: ");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &angles[i]);
	}
	decide_triangle_type(angles);
}
void decide_triangle_type(int *angles)
{

	size_t i;
	size_t j;
	size_t l;


	for (i = 0; i < 3 - 2; i++)
	{
		for (j = i+1; j < 3 - 1; j++)
		{
			for (l = i+2; l < 3; l++)
			{
				if (angles[i] == angles[j] && angles[i] == angles[l])
				{
					puts("This is an Equilateral triangle");
				}
				else if (angles[i] == angles[j] || angles[i] == angles[l])
				{
					puts("This is an isosceles triangle.");
				}
				else if (angles[j] == angles[i] || angles[j] == angles[l])
				{
					puts("This is an isosceles triangle.");
				}
				else
				{
					puts("This is a scalene triangle.");
				}
			}
		}
	}

}