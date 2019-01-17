#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>

void get_row_column(struct row_column m[]);
void get_elements(struct row_column *m, int number);
void compare_matrix(struct row_column *m);
void print_matrices(struct row_column m[], int number);

typedef struct row_column
{
	int row;
	int column;
	int matrix[10][10];

}matrix;



int main()
{
	int number = 0;
	matrix matrix1[2];

    get_row_column(&matrix1);

	get_elements(matrix1, 0);
	print_matrices(matrix1, 0);
	print_matrices(matrix1, 1);

	compare_matrix(matrix1);

	getch();
	return 0;
}
void get_row_column(struct row_column m[])
{
	int i = 0;

	for (i = 0; i < 2; i++)
	{
		printf("Enter row and column of matrix %d : ", i+1);
		scanf("%d%d", &m[i].column, &m[i].row);
	}
}

void get_elements(struct row_column *m,int number)
{
	int s = 0;
	int i = 0;
	int j = 0;

	matrix *k = m;

	for (s = 0; s < 2; s++)
	{
		printf("\nInput elements in matrix %d", s + 1);
		printf("\n");

		for (i = 0; i < k->row; i++)
		{
			for (j = 0; j < k->column; j++)
			{
				printf("Element - [%d],[%d] : ", i, j);
				scanf("%d", &(k->matrix[i][j]));
			}
		}
		k++;
	}
}
void compare_matrix(struct row_column *m)
{
	int i, j = 0;
	int flag = 0;

	if (m->column == (m + 1)->column &&m->row == (m + 1)->row)
	{
		printf("\nThe matrices can be compared");

		for (i = 0; i < m->row; i++)
		{
			for (j = 0; j < m->column; j++)
			{
				if (m->matrix[i][j] != (m + 1)->matrix[i][j])
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)printf("\nThe two matrices are not equal");
		else printf("\nThe two matrices are equal");
	}
	else printf("\nThe matrices cannot be compared");
}
void print_matrices(struct row_column m[],int number)
{
	int i, j = 0;

	if (number == 0)printf("\nThe first matrix is : ");
	else printf("\nThe second matrix is : ");
	printf("\n");

	for (i = 0; i < m[number].row; i++)
	{
		for (j = 0; j < m[number].column; j++)
		{
			printf("%d ", m[number].matrix[i][j]);
		}
		printf("\n");
	}
}