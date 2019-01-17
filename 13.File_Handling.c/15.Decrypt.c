#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
char *getname();
void open_file(char *n);
void readfile(char *n);
void memseting(char *n, int size, int character);
int main()
{
	char *name = getname();
	open_file(name);
	readfile(name);
	free(name);
	getch();
	return 0;
}
char *getname()
{
	char *name = (char*)calloc(20, sizeof(char));
	if (name == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	printf("Input the name of the file: ");
	scanf("%s", name);

	return name;
}
void open_file(char *n)
{
	char buffer[100];
	memseting(buffer, sizeof(buffer), 0);
	int i = 0; int s = 0;	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	while (!feof(file))
	{
		k = fgetc(file);
		if (k == EOF)
		{
			break;
		}
		buffer[i] = k - 100;
		i++;
	}
	fclose(file);
	file = fopen(n, "w");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	fputs(buffer, file);
	fclose(file);
	printf("File %s successfully decrypted", n);
}
void readfile(char *n)
{
	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	printf("\nIf you read the file %s you will see the following : ", n);
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		if (k == EOF)
		{
			break;
		}
		printf("%c", k);
	}
	fclose(file);

}
void memseting(char *n, int size, int character)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		n[i] = character;
	}
}