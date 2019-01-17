#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void save_to_file(char *n, char *mode);
void read_files(char *n);
int main()
{
	int n = 0;
	char buffer[50];
	save_to_file(buffer, "w");
	read_files(buffer);
	getch();
	return 0;
}


void save_to_file(char *n,char *mode)
{
	char buffer1[50];
	
	int i = 0;
	int s = 0;
	FILE *file;
	file = fopen("test.txt", mode);
	if (file == NULL)
	{
		printf("Error creating file");
		exit(0);
	}
	for (i = 0; i < 4; i++)
	{
		fgets(buffer1, sizeof(buffer1), stdin);
		fputs(buffer1, file);
	}
	fclose(file);
}
void read_files(char *n)
{
	char k = 0;
	int s = 0;
	char buffer[50];
	FILE *file;
	file = fopen("test.txt", "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	while (!feof(file))
	{
		k = fgetc(file);
		buffer[s] = k;
		s++;
		
	}
	printf("%s", buffer);
	fclose(file);
	
}