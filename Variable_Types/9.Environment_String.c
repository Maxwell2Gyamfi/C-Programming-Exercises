#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char *envp[])
{
	/*while (*envp)
	{
		printf("%s", *envp);
		*envp++;
	}*/
	char *ptr;

	ptr = getenv("path");

	if (ptr != NULL)
	{
		printf("%s", ptr);
	}



	getch();

	return 0;
}