#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void read_file(char *n, struct Sales x[], int *s);
void print_biggest_sale(struct Sales k[], int numrecords);
int compare(struct Sales k[], char *buffer, int numrecords, int *s);
void get_file_name(char *n);
void save_records(struct Sales k[], int numrecords);
void read_files();
typedef struct Sales {

	char name[20];
	int sold;
	int money;

}sales;

int main()
{
	int s = 0;
	char n[20];
	sales m[20];

	get_file_name(n);
	read_file(n, m, &s);
	print_biggest_sale(m, s);
	read_files(s);
	getch();
	return 0;
}
void get_file_name(char *n)
{
	printf("Input the name of the file: ");
	scanf("%s", n);
}
void read_file(char *n,struct Sales x[],int *s)
{
	int flag = 0;
	FILE *file;
	int sold = 0;int money = 0;int count = 0;
	int i = 0;char k = 0;char name[20];char temp[20];
	memset(temp, 0, sizeof(temp));
	memset(name, 0, sizeof(name));
	int numrecords = 0;
	file = fopen(n, "r");
	if (file == NULL)
	{
		perror("Error");
		exit(0);
	}
	while (!feof(file))
	{
		k = fgetc(file);
		if (k == EOF)
		{
			break;
		}
		while (k != '\n')
		{
			if (count == 1)
			{
				if (flag ==0)
				{
					strcpy(temp, name);
					i = 0;
					memset(name, 0, sizeof(name));
					flag++;
				}
			}
			if (count == 2)
			{
				if (flag == 1)
				{
					sscanf(name, "%d", &sold);
					i = 0;
					memset(name, 0, sizeof(name));
					flag++;
				}
			}
			if (k == ' ')
			{
				count++;
			}
			else
			{
				name[i] = k;
				i++;
			}	
			k = fgetc(file);
		}
		flag = 0;
		sscanf(name, "%d", &money);
		i = 0;
		count = 0;
		memset(name, 0, sizeof(name));
		if (compare(x, temp, numrecords,s))
		{
			x[*s].money += money;
			x[*s].sold += sold;
		}
		else
		{
			strcpy(x[numrecords].name, temp);
			x[numrecords].money = money;
			x[numrecords].sold = sold;
			numrecords++;
		}
	}
	*s = numrecords;
	save_records(x, numrecords);
}
int compare(struct Sales k[], char *buffer, int numrecords,int *s)
{
	int i = 0;
	for (i = 0; i < numrecords; i++)
	{
		if (strcmp(buffer, k[i].name) == 0)
		{
			*s = i;
			return 1;
		}
	}
	return 0;
}
void print_biggest_sale(struct Sales k[], int numrecords)
{
	int money = 0;
	int i = 0;
	int biggest = 0;
	for (i = 0; i < numrecords; i++)
	{
		if (k[i].money > money)
		{
			money = k[i].money;
			biggest = i;
		}
	}
	printf("Out of all the person who made money was %s", k[biggest].name);
	printf("\n%s made %d", k[biggest].name, k[biggest].money);
}
void save_records(struct Sales k[], int numrecords)
{
	int i = 0;
	FILE*file;
	
	file = fopen("sales.txt", "wb");
	if (file == NULL)
	{
		perror("Error");
		exit(0);
	}
	for (i = 0; i < numrecords; i++)
	{
		fwrite(&k[i], sizeof(struct Sales), 1, file);
	}
	fclose(file);
}
void read_files()
{
	sales temp;
	sales s[20];
	int i = 0;

	FILE*file;
	file = fopen("sales.txt", "rb");
	if (file == NULL)
	{
		perror("Error");
		exit(0);
	}
	while (!feof(file))
	{
		fread(&s[i], sizeof(struct Sales), 1, file);
		i++;
	}
	fclose(file);
	printf("\n%s", s[2].name);
}