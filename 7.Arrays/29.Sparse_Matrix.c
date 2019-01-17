#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

void get_matrix_size(int *row, int *column);
void allocate_memory(int row, int column, int ***matrix, int sit);
void decide_sparse(int **matrix, int row, int column);

int main()
{
	int row, column = 0;
	int **matrix = 0;

	get_matrix_size(&row, &column);
	allocate_memory(row, column, &matrix, 1);
	decide_sparse(matrix, row, column);

	getch();

	return 0;
}
void get_matrix_size(int *row, int *column)
{
	printf("Input the number of rows of the matrix : ");
	scanf("%d", &(*row));
	printf("Input the number of columns of the matrix : ");
	scanf("%d", &(*column));
}
void allocate_memory(int row, int column, int ***matrix,int sit)
{
	int i,j = 0;

	*matrix = (int**)calloc(row, sizeof(int*));
	for (i = 0; i < column; i++)
	{
		(*matrix)[i]= (int*)calloc(column, sizeof(int));
	}
	switch (sit)
	{
	case 1:
		printf("\nInput elements in the first matrix : ");
		printf("\n");
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				printf("element - [%d],[%d] : ", i, j);
				scanf("%d", &((*matrix)[i][j]));
			}
		}
		break;
	default:
		break;
	}
}
void decide_sparse(int **matrix, int row, int column)
{
	int sparse = 0;
	int not_sparse = 0;
	int i, j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (matrix[i][j] == 0) sparse++;
			else not_sparse++;
		}
	}
	if (sparse > not_sparse)
	{
		printf("\nThe given matrix is sparse matrix. ");
		printf("\nThere are 3 number of zeros in the matrix", sparse);
	}
	else
	{
		printf("\nThe given matrix is not a sparse matrix. ");
		printf("\nThe number of zero's are less than the number of non-zero elements");
	}
}