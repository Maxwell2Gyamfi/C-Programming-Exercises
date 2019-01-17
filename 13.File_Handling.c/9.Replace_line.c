#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_line();
void get_name(char *k);
void get_new_line(char *n);
void read_file(char *n, int line, char *n2);
void write_to_temp(FILE *file2);
int main()
{
	char k[60];
	int line = 0;
	char replace[60];
	get_name(k);
	get_new_line(replace);
	line = get_line();
	read_file(k, line, replace);

	getch();
	return 0;
}
int get_line()
{
	int n = 0;
	printf("Input the line you want to replace: ");
	scanf("%d", &n);
	return n;

}
void get_name(char *k)
{
	printf("Input the file name to be opened : ");
	scanf("%s%*c", k);
}
void get_new_line(char *n)
{
	char buffer[60];
	printf("Input the content of the new line : ");
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(n, buffer);
}
void read_file(char *n2, int line, char *n)
{
	int x = 0;
	int i = 0;
	int s = 0;
	int flag = 0;
	int count = 0;
	char k = 0;
	char buffer[100];
	memset(buffer, 0, sizeof(buffer));
	FILE *file;
	file = fopen(n2, "r");

	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}

	write_to_temp(file);
	fclose(file);

	file = fopen(n2, "r");

	while (!feof(file))
	{
		k = fgetc(file);
		s = k;
		if (k == '\n')
		{
			count++;
		}
		if (s == EOF)
		{
			break;
		}
		if (count == line - 1)
		{
			if (count != 0)
			{
				buffer[i] = '\n';
				i++;
			}
			k = fgetc(file);
			while ((k != '\n'))
			{
				k = fgetc(file);
				while (n[x] != '\n')
				{
					buffer[i] = n[x];
					i++;
					x++;
				}
			}
			buffer[i] = '\n';
			i++;
			count++;
		}
		else
		{
			buffer[i] = k;
			i++;
		}
	}
	fclose(file);
	file = fopen(n2, "w");
	fputs(buffer, file);
	fclose(file);
	printf("Replacement did succesfully");

}
void write_to_temp(FILE *file2)
{
	int lenght = 0;
	int i = 0;
	char buffer[60];
	memset(buffer, 0, sizeof(buffer));
	FILE *file;
	file = fopen("temp.txt", "w");
	if (file == NULL)
	{
		printf("Error creating file");
		exit(0);
	}
	while (!feof(file2))
	{
		char k = fgetc(file2); 
		int s = k;
		if (s == EOF)
		{
			break;
		}
		buffer[i] = k;
		i++;
	}
	fputs(buffer, file);
	fclose(file);
}