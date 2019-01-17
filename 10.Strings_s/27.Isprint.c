#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
int main()
{
	int i = 0;
	char string[] = " The quick brown fox \n jumps over the \n lazy dog. \n";
	while (isprint(string[i]))
	{
		printf("%c", string[i]);
		i++;
	}

	getch();
	return 0;
}