#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int alphaexits(struct maximum_occurance s[], char n, int numrecords);
void counts(struct maximum_occurance characters[], int count, char *n, int *numberrecords);
int count(struct maximum_occurance s[], int numrecords);

typedef struct maximum_occurance
{
	char character;
	int occurance;
}k;
int main()
{
	int numberrecords = 0;
	k s[50];
	int lenght = 0;
	char string[50];

	printf("Enter a string: ");
	fgets(string, sizeof(string), stdin);

	lenght = strlen(string);
	counts(s, lenght, string, &numberrecords);
	count(s, numberrecords);

	getch();
	return 0;
}
void counts(struct maximum_occurance characters[], int count,char *n,int *numberrecords)
{
	int loop = 0;
	int i = 0;
	int numrecords = 0;
	int countsofn = 0;
	int s = 0;
	do
	{
		if (alphaexits(characters, n[countsofn], numrecords)){}
		else
		{
			characters[s].character = n[countsofn];
			characters[s].occurance = 1;
			numrecords++;
		}
		s++;
		countsofn++;

	} while (s < count);

	*numberrecords = numrecords;
}
int count(struct maximum_occurance s[],int numrecords)
{
	int i = 0;
	int bigger = 0;
	int position = 0;

	for (i = 0;i < numrecords;i++)
	{
		if (s[i].occurance > bigger)
		{
			bigger = s[i].occurance;
			position = i;
		}
	}
	printf("The Highest frequency of character '%c' appears number of times : %d", s[position].character,s[position].occurance);
	
}
int alphaexits(struct maximum_occurance s[], char n,int numrecords)
{
	k *x = &s[0];

	int i = 0;
	for (i = 0;i < numrecords;i++)
	{
		if (n == s[i].character)
		{
			x->occurance = x->occurance + 1;
			return 1;
		}
		x++;
	}
	return 0;
}

