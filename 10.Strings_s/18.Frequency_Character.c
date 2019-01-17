#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_frequency(char *n, int lenght, char k);
int main()
{
	int frequency = 0;
	char character = '\0';
	char buffer[50];

	printf("Input the string : ");
	fgets(buffer, sizeof(buffer), stdin);

	printf("Input the character to find frequency: ");
	scanf("%c", &character);

	frequency = get_frequency(buffer, strlen(buffer),character);
	printf("The frequency of '%c' is : %d ", character, frequency);

	getch();
	return 0;
}
int get_frequency(char *n,int lenght,char k)
{
	int frequency = 0;
	int i = 0;
	for (i = 0;i < lenght;i++)
	{
		if (n[i] == k)
		{
			frequency++;
		}
	}
	return frequency;

}