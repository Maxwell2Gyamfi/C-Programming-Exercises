#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void read_file(char *n);
int main()
{
	char k[50];
	memset(k, 0, sizeof(k));
	read_file(k);
	printf("The contents of the file test.txt\n");
	printf("%s", k);
	getch();
	return 0;
}
void read_file(char *n)
{
	int i = 0;
	FILE *file;
	file = fopen("test.txt", "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	while (!feof(file))
	{
		n[i] = fgetc(file);
		i++;
	}
	fclose(file);
}