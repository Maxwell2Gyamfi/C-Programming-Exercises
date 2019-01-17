#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int row, int column, int situation);
int **get_transpose(int **matrix, int row, int column);
void get_array_elements(int **matrix, int row, int column);
void get_row_column(int *row, int *column);
int **get_matrix(int row, int column);

int main()
{
	int row = 0; int column = 0;
	int **matrix1 = 0;
	int **transpose = 0;
	int situation = 0;

	get_row_column(&row, &column);
	matrix1 = get_matrix(row, column);
	get_array_elements(matrix1, row, column);
	transpose = get_transpose(matrix1, row, column);
	print_matrix(matrix1, row, column,1);
	print_matrix(transpose, row, column, 0);
	getch();
	return 0;
}
void get_row_column(int *row,int *column)
{
	printf("Input the rows and columns of the matrix : ");
	scanf("%d%d", &(*row), &(*column));
}
int **get_matrix(int row, int column)
{
	int i = 0;
	int **matrix = (int**)calloc(row, sizeof(int*));
	
	for (i = 0; i < column; i++)
	{
		matrix[i]= (int*)calloc(row, sizeof(int));
	}
	return matrix;
}
void get_array_elements(int **matrix,int row,int column)
{
	int i = 0;
	int j = 0;

	printf("Input elements in the first matrix : ");
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("element - [%d],[%d] : ",i,j);
			scanf("%d", &matrix[i][j]);
		}
	}
}
int **get_transpose(int **matrix, int row, int column)
{
	int i, j = 0;
	int k = 0;
	int **transpose = get_matrix(row, column);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			transpose[j][i] = matrix[i][j];
		}
	}
	return transpose;
}
void print_matrix(int **matrix, int row, int column,int situation)
{
	int i, j = 0;

	switch (situation)
	{
	case 1: 
		printf("\nThe matrix is : ");
		break;
	default:
		printf("\nThe transpose of a matrix is : ");
		break;
	}
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