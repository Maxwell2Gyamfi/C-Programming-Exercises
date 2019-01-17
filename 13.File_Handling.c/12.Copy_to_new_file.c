#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_file(char *n);
char * get_names(char *k);
void copy_file(char *k, char*s);

int main()
{
	char *s;
	char k[50];
	s = get_names(k);
	copy_file(k, s);
	read_file(s);
	getch();
	return 0;
}
char * get_names(char *k)
{
	char *n = (char*)calloc(50, sizeof(char));
	if (n == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	printf("Input the source file name: ");
	scanf("%s%*c", k);
	printf("Input the new file name : ");
	scanf("%s%*c", n);
	return n;

}
void copy_file(char *k, char*s)
{
	int q = 0;
	int i = 0;
	char buffer[150];
	memset(buffer, 0, sizeof(buffer));
	char x = 0;
	FILE *file1, *file2;
	file1 = fopen(k, "r");
	file2 = fopen(s, "w");
	if (file1 == NULL || file2 == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	while (!feof(file1))
	{
		x = fgetc(file1);
		q = x;
		if (q == EOF)
		{
			break;
		}
		buffer[i] = x;
		i++;
		
		
	}
	fputs(buffer, file2);
	fclose(file1);
	fclose(file2);
	printf("The file %s copied successfully in the file %s.", k, s);

}
void read_file(char *n)
{
	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file: ");
		exit(0);
	}
	printf("\nIf you read the new file you will see the content of the file : ");
	printf("\n\n");
	while (!feof(file))
	{
		k = fgetc(file);
		printf("%c", k);
	}

}