#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_contents(char *n);
void get_file_name(char *n);
void read_file(char *n);
void write_file(static char *n, char *buffer);
void get_contents(char *n);
int main()
{
	char n[20];
	get_file_name(n);
	get_contents(n);
	read_file(n);
	getch();
	return 0;
}
void get_file_name(char *n)
{
	printf("Input the name of the file to be opened: ");
	scanf("%s", n);
}
void read_file(char *n)
{
	char k = '\0';
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	printf("The contents of the file %s are: ", n);
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		printf("%c", k);

	}
	fclose(file);

}
void write_file(static char *n,char *buffer)
{
	FILE *file;
	file = fopen(n,"a");
	if (file == NULL)
	{
		fputs("Error aopening new file", stderr);
		exit(0);
	}
	fputs(buffer, file);
	fclose(file);
}
void get_contents(static char *n)
{
	char buffer[50];
	int lines = 0;
	int i = 0;
	printf("Input the amount of lines: ");
	scanf("%d%*c", &lines);

	for (i = 0; i < lines; i++)
	{
		printf("Input %d element: ", i);
		fgets(buffer, sizeof(buffer), stdin);
		write_file(n,buffer);
	}
	
}
