#pragma warning(disable:4996)

#include <stdio.h>
#define Y 10

void get_numbers(int matrix[][Y], int row, int column);
void print_matrix(int matrix[][Y], int row, int column);

int main()
{

	int matrix[10][Y];
	int row = 3;
	int column = 3;

	get_numbers(matrix, row, column);
	print_matrix(matrix, row, column);

	getch();

	return 0;
}
void get_numbers(int matrix[][Y], int row,int column)
{

	int i, j;

	printf("Input elements in the matrix: ");
	printf("\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Element - [%d],[%d] : ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}
void print_matrix(int matrix[][Y], int row, int column)
{
	int i, j = 0;

	
	printf("\nThe matrix is: ");
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}