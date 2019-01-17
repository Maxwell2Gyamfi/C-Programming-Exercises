
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_string(char *name);
void add_space(char *n, int lenght, int *lenght3);
void print_name(char *n, int lenght);
void easy_way(char *n, int lenght);
int main()
{
	int lenght2 = 0;
	char string[30];
	char buffer[30];

	get_string(string);
	strcpy(buffer, string);

	int lenght = strlen(string);
	add_space(string, lenght,&lenght2);
	print_name(string,lenght2);
	easy_way(buffer, lenght);

	getch();
	return 0;
}
void get_string(char *name)
{

	printf("Input a string: ");
	scanf("%s", name);

}
void add_space(char *n, int lenght,int *lenght3)
{
	int lenght2 = lenght;
	int s = 0;
	int start = 1;
	char temp = 0;
	char *k = &n[0];

	for (s = 0;s < lenght2;s++)
	{
		k[lenght] = ' ';
		int i = lenght;
		while (i != start)
		{
			temp = k[i - 1];
			k[i - 1] = k[i];
			k[i] = temp;
			i--;
		}
		start= start+2;
		lenght++;
	}
	*lenght3 = lenght;
}
void print_name(char *n,int lenght)
{
	int i = 0;
	printf("The characters of the string are : ");
	for (i = 0;i < lenght;i++)
	{
		printf("%c", n[i]);
	}
}
void easy_way(char *n,int lenght)
{
	int i = 0;
	printf("\nThe characters of the string are : ");
	for (i = 0;i < lenght;i++)
	{
		printf("%c ", n[i]);
	}

}