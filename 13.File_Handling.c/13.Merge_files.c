#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void open_files(char *n1, char *n2, char *n3);
void get_names(struct names *n);
void read_file(char *n);

typedef struct names
{
	char name1[20];
	char name2[20];
	char name3[20];
}lss;

int main()
{
	lss k;
	get_names(&k);
	open_files(k.name1, k.name2, k.name3);
	read_file(k.name3);

	getch();
	return 0;
}
void get_names(struct names *n)
{
	printf("Input the first file name: ");
	scanf("%s%*c", n->name1);
	printf("Input the second file name: ");
	scanf("%s%*c", n->name2);
	printf("Input the new file name where to merge the above two files: ");
	scanf("%s%*c", n->name3);
}
void open_files(char *n1,char *n2,char *n3)
{
	int i = 0;
	char *merge;
	char k = 0;
	int s = 0;
	int count1 = 0;
	int count2 = 0;
	FILE *file1, *file2,*file3;
	file1 = fopen(n1, "r");
	file2 = fopen(n2, "r");
	file3 = fopen(n3, "w");

	if (file1 == NULL || file2 == NULL ||file3==NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	while (!feof(file1))
	{
		k = fgetc(file1);
		s = k;
		if (s == EOF)
		{
			break;
		}
		count1++;
	}
	while (!feof(file2))
	{
		k = fgetc(file2);
		s = k;
		if (s == EOF)
		{
			break;
		}
		count1++;
	}
	merge = (char*)calloc((count1+10), sizeof(char));
	if (merge == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	rewind(file1);
	rewind(file2);
	while (!feof(file1))
	{
		k = fgetc(file1);
		s = k;
		if (s== EOF)
		{
			break;
		}
		merge[i] = k;
		i++;
	}
	while (!feof(file2))
	{
		k = fgetc(file2);
		s = k;
		if (s == EOF)
		{
			break;
		}
		merge[i] = k;
		i++;
	}
	fputs(merge, file3);
	fclose(file1);
	fclose(file2);
	fclose(file3);
	free(merge);
	printf("\nThe two files merged into mergefile");
}
void read_file(char *n)
{
	int s = 0;
	char k = 0;
	FILE *file;
	file = fopen(n, "r");
	if (file == NULL)
	{
		printf("Error reading file");
		exit(0);
	}
	printf("\nThe contents of the file %s: ", n);
	printf("\n");
	while (!feof(file))
	{
		k = fgetc(file);
		s = k;
		if (s == EOF)
		{
			break;
		}
		printf("%c", k);
	}
	fclose(file);
}