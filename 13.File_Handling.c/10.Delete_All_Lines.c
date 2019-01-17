#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_line();
void get_file_name(char *n, char *temp);
void delete_file(int line, char *n, char *temp, int line2, int *count1);
void read_file(char *n);
int read_file2(char *n);
int write_to_temp(FILE *file2, char *temp, char *n);
int count_words(char *n, FILE *file);

int main()
{
	int count1;
	int line = 0;
	int line2 = 0;
	char n[20];
	char temp[20];

	get_file_name(n,temp);
	line = read_file2(n);
	line2 = line;
	
	printf("-----------------Delete all lines of text file-----------------------");

	while (line >0)
	{
		delete_file(line, n,temp,line2,&count1);
		line--;
	}
	read_file(n);
	read_file(temp);

	getch();
	return 0;
}
int read_file2(char *n)
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
void get_file_name(char *n,char *temp)
{
	printf("Input the name of the file to be opened: ");
	scanf("%s", n);
	printf("Input the name of the backup file: ");
	scanf("%s", temp);
}
int get_line()
{
	int line = 0;
	printf("Input the line to be deleted: ");
	scanf("%d", &line);
	return line;
}
void delete_file(int line, char *n,char *temp,int line2,int *count1)
{
	int flag = 0;
	int s = 0;
	int i = 0;
	char k = 0;
	int count = 0;
	static int count2 = 0;
	FILE *file;
	char *buffer;

	file = fopen(n, "r");
	if (line == line2)
	{
		count2 = write_to_temp(file, temp,n);
		*count1 = count2;
	}
	buffer = (char*)calloc(count2, sizeof(char));
	if (buffer == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	rewind(file);
	while (!feof(file))
	{
		k = fgetc(file);
		s = k;
		if (s == EOF)
		{
			break;
		}
		if (k == '\n')
		{
			count++;
		}
		if (count == line - 1)
		{
		
			k = fgetc(file);
			while ((k != '\n'))
			{
				k = fgetc(file);
				s = k;
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
	fputs(buffer, file);
	fclose(file);
	free(buffer);
}
void read_file(char *n)
{
	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
	}
	printf("\nThe content of the file %s : ", n);
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		printf("%c", k);
	}
	fclose(file);
}
int count_words(char *n,FILE *file)
{
	char k = 0;
	int count = 0;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error opening file");
		exit(0);
	}
	while (!feof(file))
	{
		k = fgetc(file);
		count++;
	}
	fclose(file);
	return count;
}
int write_to_temp(FILE *file2,char *temp,char *n)
{
	int count = 0;
	int lenght = 0;
	int i = 0;
	char *buffer;
	FILE *file;
	
	count = count_words(n, file2);
	file = fopen(temp, "w");
	if (file == NULL)
	{
		printf("Error creating file");
		exit(0);
	}
	buffer = (char*)calloc(count, sizeof(char));
	if (buffer == NULL)
	{
		printf("Error allocating memory");
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
	free(buffer);
	return count;
}