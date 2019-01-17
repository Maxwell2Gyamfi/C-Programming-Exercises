#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_line();
void get_file_name(char *n);
void delete_file(int line, char *n);
void read_file(char *n);
int main()
{
	int line = 0;
	char n[20];
	get_file_name(n);
	line = get_line();
	delete_file(line, n);
	read_file(n);

	getch();
	return 0;
}
void get_file_name(char *n)
{
	printf("Input the name of the file to be opened: ");
	scanf("%s", n);
}
int get_line()
{
	int line = 0;
	printf("Input the line to be deleted: ");
	scanf("%d", &line);
	return line;
}
void delete_file(int line,char *n)
{
	int flag = 0;
	int s = 0;
	int i = 0;
	char k = 0;
	int count = 0;
	FILE *file;
	char buffer[60];
	memset(buffer, 0, sizeof(buffer));
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	while (!feof(file))
	{
		k = fgetc(file);	
		if (k == '\n')
		{
			count++;
		}
		if (count == line - 1)
		{
			k = fgetc(file);
			while ((k!='\n'))
			{
				k = fgetc(file);
				s = k ;
				if (s == EOF)
				{
					flag = 1;
					break;
				}
			}
			count++;
		}
		if (flag == 1)
		{
			break;
		}
		else
		{
			buffer[i] = k;
			i++;
		}
	}
	fclose(file);
	file = fopen(n, "w");
	fputs(buffer,file);
	fclose(file);
}
void read_file(char *n)
{
	char buffer[50];
	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
	}
	printf("The content of the file %s", n);
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		printf("%c", k);
	}
	fclose(file);

}