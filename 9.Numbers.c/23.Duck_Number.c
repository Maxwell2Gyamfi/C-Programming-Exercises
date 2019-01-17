#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_n();
int get_duck(int n);
int has0(char *n);
int main()
{
	int n = 1;
	//int n = get_n();
	while (n < 500)
	{
		get_duck(n);
		n++;
	}
	getch();
	return 0;
}
int get_n()
{
	int n = 0;
	printf("Input a number: ");
	scanf("%d", &n);
	return n;
}
int get_duck(int n)
{
	char buffer[10];
	sprintf(buffer, "%d", n);

	//if(has0(buffer)) printf("The given number is a Duck Number.");
	if (has0(buffer)) printf("%d ",n);
	//else printf("The given number is  not a Duck Number.");

}
int has0(char *n)
{
	int lenght = strlen(n);
	int i = 0;
	for (i = 0;i < lenght;i++)
	{
		if (n[i] == '0')
		{
			if (n[0] != '0')
			{
				return 1;
			}
		}
	}
	return 0;
}
