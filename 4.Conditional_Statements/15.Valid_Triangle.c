#pragma warning(disable:4996)

#include <stdio.h>
void decide_valid_triangle(int *angles);
int get_angles();
int main()
{
	get_angles();
	getch();

	return 0;
}
int get_angles()
{

	static int angles[3];
	size_t i;

	for (i = 0; i < 3; i++)
	{
		scanf("%d", &angles[i]);
	}
	decide_valid_triangle(angles);
}
void decide_valid_triangle(int *angles)
{

	size_t i;
	size_t j;
	size_t l;


	for (i = 0; i < 3 - 2; i++)
	{
		for (j = i + 1; j < 3 - 1; j++)
		{
			for (l = i + 2; l < 3; l++)
			{

				if (angles[i] + angles[j] + angles[l] == 180)
				{
					fputs("Triangle can be formed", stdout);
				}
				else
				{
					fputs("Triangle cannot be formed", stdout);
				}

			}
		}
	}


}