#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

char* get_string(int a);
int copy(char *source, char *destination, int lenght);
void printstuff(char *n1, char *n2, int lenght, int count);
int main()
{
	int count = 0;
	int lenght = 0;

	char *n = get_string(1);
	char *s = get_string(0);
	lenght = strlen(n);
	count = copy(n, s, lenght);

	printstuff(n, s, lenght, count);
	getch();

	free(n);
	free(s);
	return 0;
}
char* get_string(int a)
{
	int lenght = 0;
	char buffer[50];
	char * n = (char *)calloc(50, sizeof(char));
	if (n == NULL)
	{
		printf("Error allocating memory");
		exit(0);
	}
	if (a == 1)
	{
		printf("Input the string : ");
		fgets(buffer, sizeof(buffer), stdin);
		lenght = strlen(buffer);
		copy(buffer, n, lenght);
	}
	
	return n;
}
int copy(char *source, char *destination, int lenght)
{
	int count = 0;
	char *k = &destination[0];
	int i = 0;
	for (i = 0;i < lenght;i++)
	{
		k[i] = source[i];
		count++;
	}
	return count;
}
void printstuff(char *n1, char *n2,int lenght,int count)
{
	int i = 0;
	printf("\nThe First string is : ");
	for (i = 0;i < lenght;i++)
	{
		printf("%c", n1[i]);
	}
	printf("The Second string is : ");
	for (i = 0;i < lenght;i++)
	{
		printf("%c", n2[i]);
	}
	printf("Number of characters copied : %d", count);

}
