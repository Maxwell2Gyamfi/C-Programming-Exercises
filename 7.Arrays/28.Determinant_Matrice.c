#pragma warning (disable:4996)

#include <stdio.h>
void get_numbers(int matrix[][10], int size);
int get_determinant(int matrix[][10], int size);
void print_matrix(int matrix[][10], int size);

int main()
{
	int determinant = 0;
	int matrix[10][10];
	get_numbers(matrix, 3);
	determinant = get_determinant(matrix, 3);

	print_matrix(matrix, 3);
	printf("\nThe determinant of the matrix is : %d", determinant);

	getch();
	return 0;
}
void get_numbers(int matrix[][10], int size)
{
	int i, j = 0;

	printf("Input elements in the first matrix : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("element - [%d],[%d] : ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}
int get_determinant(int matrix[][10], int size)
{
	int determinant = 0;
	int a, b, c, d, e, f, g, h, i = 0;
	a = matrix[0][0];
	b = matrix[0][1];
	c = matrix[0][2];
	d = matrix[1][0];
	e = matrix[1][1];
	f = matrix[1][2];
	g = matrix[2][0];
	h = matrix[2][1];
	i = matrix[2][2];
	
    determinant = (a*(e*i - f * h)) - (b*(d*i - f * g)) + (c*(d*h - e * g));

	return determinant;

}
void print_matrix(int matrix[][10], int size)
{
	int i, j = 0;

	printf("\nThe matrix is : ");
	printf("\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
