#pragma warning(disable:4996)
#include <stdio.h>
#include <stdio.h>

int get_size();
void allocate_memory_matrix(int ***matrix, int size, int option);
int **copy_array(int **matrix, int size);
void get_upper_triangular(int ***upper_triangular, int size);
void print_matrix(int **matrix, int size, int option);
void free_memory(int **matrix, int size);

int main()
{
	int **matrix = 0;
	int **upper_triangular = 0;
	int size = get_size();

	allocate_memory_matrix(&matrix, size, 1);
	allocate_memory_matrix(&upper_triangular, size, 0);
	upper_triangular = copy_array(matrix, size);
	get_upper_triangular(&upper_triangular, size);
	print_matrix(matrix, size, 1);
	print_matrix(upper_triangular, size, 0);


	free_memory(upper_triangular,size);
	free_memory(matrix,size);

	free(upper_triangular);
	free(matrix);


	getch();
	return 0;
}
int get_size()
{
	int size = 0;
	printf("Input the size of the square matrix : ");
	scanf("%d", &size);

	return size;
}
void allocate_memory_matrix(int ***matrix,int size,int option)
{
	int i = 0;
	int j = 0;
	*matrix = (int**)calloc(size, sizeof(int *));

	for (i = 0; i < size; i++)
	{
		(*matrix)[i]= (int*)calloc(size, sizeof(int ));
	}
	if (option == 1)
	{
		printf("\nInput elements in the first matrix : ");
		printf("\n");

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				printf("element [%d],[%d] : ", i, j);
				scanf("%d", &((*matrix)[i][j]));
			}
		}
	}
}
int **copy_array(int **matrix, int size)
{
	int i, j = 0;
	int **upper_triangular = 0;
	allocate_memory_matrix(&upper_triangular, size, 0);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			upper_triangular[i][j] = matrix[i][j];
		}
	}
	return upper_triangular;
}
void get_upper_triangular(int ***upper_triangular, int size)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = size-1; j > i; j--)
		{
			(*upper_triangular)[i][j] = 0;
		}
	}
}
void print_matrix(int **matrix, int size,int option)
{
	int i, j = 0;

	switch (option)
	{
	case 1:
		printf("\nThe matrix is : ");
		break;
	default:
		printf("\nSetting zero in upper triangular matrix : ");
		break;
	}
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
void free_memory(int **matrix, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
}