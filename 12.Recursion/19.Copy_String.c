#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int copy_string(char*n, char*k);
int main()
{
	char str[20];
	char str1[20];

	printf("Input the string to copy: ");
	scanf("%s", str);

	copy_string(str, str1);
	printf("The first string is %s", str);
	printf("\nThe second string is %s", str1);

	getch();
	return 0;
}
int copy_string(char*n, char*k)
{
	static int i = 0;
	if (n[i] == '\0')
	{
		k[i] = '\0';
		return 1;
	}
	else
	{
		k[i] = n[i];
		i++;
		copy_string(n, k);
	}
}