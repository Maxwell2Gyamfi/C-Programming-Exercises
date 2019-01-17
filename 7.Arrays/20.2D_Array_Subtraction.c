#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int row, int column, int situation);
int get_matrix_size();
void get_matrix_elements(int **matrix, int row, int column, int situation);
void subtract_matrix(int **matrix1, int **matrix2, int**result, int row, int column);
int **set_matrix_size(int row, int column);
void free_array(int **matrix, int size);

int main()
{
	int size, row, column,situation = 0;
	int **matrix1=0;
	int **matrix2=0;
	int **result=0;

	size = get_matrix_size();
	row = size; column = size;

	matrix1 = set_matrix_size(row,column);
	matrix2 = set_matrix_size(row,column);
	result = set_matrix_size(row, column);
	get_matrix_elements(matrix1, row, column,1);
	get_matrix_elements(matrix2, row, column, 2);
	subtract_matrix(matrix1, matrix2, result, row, column);
	print_matrix(matrix1, row,column,1);
	print_matrix(matrix2, row, column,2);
	print_matrix(result, row, column, situation);
	free_array(matrix1, size);
	free_array(matrix2, size);
	free_array(result, size);
	free(matrix1);
	free(matrix2);
	free(result);


	getch();
	return 0;
}
int get_matrix_size()
{
	int size = 0;
	printf("Input the size of the square matrix (less than 5): ");
	scanf("%d", &size);
	return size;
}
int **set_matrix_size(int row, int column)
{
	int i = 0;
	int j = 0;

	int **matrix = (int **)calloc(row, sizeof(int*));

	for (i = 0; i < row; i++)
	{
		matrix[i] = (int *)calloc(column, sizeof(int));
	}
	return matrix;
}
void get_matrix_elements(int **matrix, int row, int column,int situation)
{
	int i = 0;
	int j = 0;

	if (situation == 1) printf("Input elements in the first matrix : ");
	else printf("\nInput elements in the second matrix : ");
	printf("\n");
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("element - [%d],[%d] : ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}
void subtract_matrix(int **matrix1, int **matrix2, int**result,int row,int column)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}
void print_matrix(int **matrix, int row, int column, int situation)
{
	int i, j = 0;

	if (situation == 1)printf("\nThe First matrix is : ");
	else if (situation == 2)printf("\nThe Second matrix is : ");
	else printf("\nThe Subtraction of two matrix is : ");
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
void free_array(int **matrix, int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
}