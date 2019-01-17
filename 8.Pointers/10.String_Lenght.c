#pragma warning(disable:4996)
#include <stdio.h>
int calculate_lenght(char *name);
int main()
{
	int count = 0;
	char name[20];
	printf("Input a string : ");
	scanf("%s", name);
    
	count = calculate_lenght(name);
	printf("\nThe length of the given string %s is: %d",name, count);

	getch();
	return 0;
}
int calculate_lenght(char *name)
{
	int i = 0;
	int count = 0;
	while (*(name+i)!= '\0')
	{
		count++;
		i++;
	}
	return count;

}