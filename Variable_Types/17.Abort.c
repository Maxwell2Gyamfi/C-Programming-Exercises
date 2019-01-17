#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;

	fp = fopen("maxwell.txt", "r");
	if (fp == NULL)
	{
		fputs("File does not exist or error, in opening the file.",stderr);
	
		abort();
	}
	fclose(fp);
	return 0;
}