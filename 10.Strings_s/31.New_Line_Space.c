#pragma warning(disable:4996)
#include <stdio.h>
#include<string.h>
void replacem(char *n, int lenght);
int main()
{
	char buffer[30];
	fgets(buffer, sizeof buffer, stdin);
	replacem(buffer, strlen(buffer));

	getch();
	return 0;
}
void replacem(char *n,int lenght)
{
	int r = 0;
	char *s = &n[0];
	int i = 0;
	for (i = 0;i < lenght;i++)
	{
		n[i] == ' ' ? n[i] = '\n' : r;
	
	}
	
	printf("Strings or words after split by space are :\n%s", n);

}