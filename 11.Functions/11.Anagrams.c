#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct anagram
{
	char a;
	int b;
}k;

int get_strings(char *first, char*second);
int compare(struct anagram s[], int count, char *anagram_array);
int last_compare(struct anagram array1[], struct anagram array2[], int lenght);

int main()
{
	
	int count = 0;
	char first[20];
	char second[20];
	k s[20];
	k w[20];

	count = get_strings(first, second);

    (count!=0)?
		compare(s, count, first),
		compare(w, count, second):0;
	
	(count == 0 || !last_compare(s, w, count))?
		printf("%s and %s are not anagrams", first, second):
		printf("%s and %s are anagrams", first, second);
	
	getch();
	return 0;
}
int get_strings(char *first, char*second)
{
	int count1,count2 =0;
	printf("Input first string: ");
	scanf("%s", first);
	printf("Input second string: ");
	scanf("%s", second);

	count1 = strlen(first);
	count2 = strlen(second);

	return(count1 == count2) ? count1 : 0;

}
int compare(struct anagram s[],int count,char *anagram_array)
{
	int record = 0;
	int k = 0;
	int i = 0;
	for (i = 0; i < count; i++)
	{
	
		s[i].a = anagram_array[i];
		s[i].b = 1;
		for (k = 0; k < record; k++)
		{
			if (anagram_array[i] == s[k].a)
			{
				s[k].b = s[k].b + 1;
			}
		}
		record++;
	}
}
int last_compare(struct anagram array1[], struct anagram array2[],int lenght)
{
	int flag = 1;
	int k = 0;
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		for (k = 0; k < lenght; k++)
		{
			if(array1[i].a == array2[k].a && array1[i].b == array2[k].b)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			return 0;
		}

	}
	return 1;

}
