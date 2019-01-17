#pragma warning(disable:4996)
#include <stdio.h>
void get_name(char *n);
void read_file(char *n);
int main()
{
	char n[50];
	get_name(n);
	read_file(n);

	getch();
	return 0;
}
void get_name(char *n)
{
	printf("Input the file name to be opened: ");
	scanf("%s", n);
}
void read_file(char *n)
{
	char k = 0;
	int count = 0;
	FILE	*file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	printf("\nThe contents of the file are : ");
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		printf("%c", k);
		k == '\n' ? count++ : count;
	}
	fclose(file);

	printf("\nThe lines in the file are : %d", count);
}