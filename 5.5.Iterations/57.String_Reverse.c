#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
void get_string_reverse(char *n);
int get_lenght(char *n);

int main()
{
	int ch = 0;
	char letter[20];

	printf("Input a string to reverse :");
	fgets(letter, sizeof(letter), stdin);
	
	get_string_reverse(letter);
	printf("Reversed string is:%s",letter);

	getch();
	return 0;
}
void get_string_reverse(char *n)
{
	int i = 0;
	char temp = 0;
	int lenght = 0;
	int stop = 1;

	lenght = get_lenght(n);
	n[lenght] = '\0';
	int k = lenght-1;
	

	if (lenght == 1)
	{
		strcpy(n, n);
	}
	else
	{
		/*while (stop)
		{
			temp=n[i];
			n[i] = n[k];
			n[k] = temp;
			
			i++;
			k--;
			if (k / i <= 1)
			{
				stop = 0;
			}
		}
		strcpy(n, n);*/

		for (i = 0; i < k; i++)
		{
			temp = n[i];
			n[i] = n[k];
			n[k] = temp;

			k--;
		}
		strcpy(n, n);
	}

}
int get_lenght(char *n)
{
	int i = 0;
	int count = 0;
	int j = 0;

	while (n[i] != '\n')
	{
		count++;
		i++;
	}
	return count;
}