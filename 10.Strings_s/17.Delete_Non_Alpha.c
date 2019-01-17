#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void remove_non_alpha(char *n, int lenght);
int main()
{

	char buffer[50];
	fgets(buffer, sizeof(buffer), stdin);
	remove_non_alpha(buffer, strlen(buffer));

	getch();
	return 0;
}
void remove_non_alpha(char *n,int lenght)
{
	int l = 0;
	int s = lenght - 2;
	int i = 0;
	for (i = 0;i < lenght-1;i++)
	{
		int l = i;
		if (!isalpha(n[i]))
		{
			while (s > l)
			{
				n[l] = n[l + 1];
				l++;
			}
			lenght = lenght - 1;
		}
		s = lenght;
	}
	strcpy(n, n);
	printf("%s", n);
}