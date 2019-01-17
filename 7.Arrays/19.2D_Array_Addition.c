#pragma warning(disable:4996)

#include <stdio.h>

#define Y 10
void get_matrix_size(int *size);
void get_matrix(int matrix[][Y], int row, int column, int situation);
void print_matrix(int matrix[][Y], int row, int column, int situation);
void add_matrix(int matrix[][Y], int matrix1[][Y], int matrix2[][Y], int row, int column);

int main()
{
	int addition[10][Y];
	int numbers1[10][Y];
	int numbers2[10][Y];
	int size = 0;

	get_matrix_size(&size);
	get_matrix(numbers1, size, size, 1);
	get_matrix(numbers2, size, size, 2);
	add_matrix(addition, numbers1, numbers2, size, size);
	print_matrix(numbers1, size, size, 1);
	print_matrix(numbers2, size, size, 2);
	print_matrix(addition, size, size, 0);

	getch();
	return 0;
}
void get_matrix_size(int *size)
{
	printf("Input the size of the matrix: ");
	scanf("%d", &(*size));

}
void get_matrix(int matrix[][Y], int row, int column,int situation)
{
	int i, j = 0;

	if (situation == 1) printf("\nInput elements in the first matrix : ");
	else printf("\nInput elements in the second matrix : ");
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
void print_matrix(int matrix[][Y], int row, int column, int situation)
{
	int i,j = 0;

	if (situation==1)printf("\nThe First matrix is : ");
	else if (situation==2) printf("\nThe Second matrix is : ");
	else printf("\nThe Addition of two matrix is :");
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
void add_matrix(int matrix[][Y],int matrix1[][Y], int matrix2[][Y], int row, int column)
{

	int i, j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}