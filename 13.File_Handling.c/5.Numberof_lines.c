#pragma warning(disable:4996)
#include <stdio.h>
void get_file_name(char *n);
int read_file(char *n);
int main()
{
	int s = 0;
	char n[50];
	get_file_name(n);
	s = read_file(n);
	printf("The lines in the file %s are %d", n, s);
	getch();
	return 0;
}
void get_file_name(char *n)
{

	printf("Input the name of the file to be opened: ");
	scanf("%s", n);

}
int read_file(char *n)
{
	int newline = 0;
	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	while (!feof(file))
	{
		k = fgetc(file);
		k == '\n' ? newline++ : newline;
	}
	fclose(file);
	return newline;
}