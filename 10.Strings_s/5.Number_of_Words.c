#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_name(char *n);
int get_words(char *n);
int main()
{
	int words = 0;
	char name[50];
	get_name(name);
	words = get_words(name);

	getch();
	return 0;
}
void get_name(char *n)
{
	char buffer[50];
	fputs("Input the string : ",stdout);
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(n, buffer);
}
int get_words(char *n)
{
	int count = 1;
	int i = 0;
	for (i = 0;i <strlen(n);i++)
	{
		if (n[i] == ' ')
		{
			count++;
		}
	}
	return count;

}