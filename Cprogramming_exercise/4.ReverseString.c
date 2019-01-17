#pragma warning(disable :4996)

#include<stdio.h>
#include<string.h>

int swap(int index, int size, char character[]);
void arrayreverse(char character[], int size);

int main()
{
	char temporary[15];
	char character[15];
	int size = 0;
	int index = 0;
	int i = 0;
	

	printf("Enter a character: ");
	scanf("%s", character);
	strcpy(temporary, character);//copy string into temporary array
	size = strlen(character);

	swap(index, size - 1, character);//size is -1 because it deletes the null character
	//index is 0 because it reads the first character in position 0

	//arrayreverse(character,size);//function which prints array in reverse order

	printf("The reverse of %s is %s",temporary, character);
	getch();
	return 0;
}
int swap(int index, int size, char character[])
{
	char temp;
	int stop = 1;
	
	//checks if character is only 1
	if (size <= 1)
	{
		return character;
	}
	else
	{
		//place first character in index in temp
		//swap with the last character which is size -1 as last character is null
		//place temp in size

		temp = character[index];
		character[index] = character[size];
		character[size] = temp;

		//checks if index has reached half of the character 
		//(size/2+1) in case the character is even so it can find the half 
		++index;
		--size;
		if (index / size >= 1)
		{
			return;
		}
	}
	swap(index, size, character);//recursive so repeats until it returns 1

	while (stop)//while loop which does the same as recursive
	{
		temp = character[index];
		character[index] = character[size];
		character[size] = temp; 
		++index;
		--size;
		if (index/size >=1)							
		{
			stop = 0;
		}
		
	}
}
void arrayreverse(char character[],int size)
{
	
	int i = 0;
	for (i = size -1; i >= 0; i--)
	{
		printf("%c",character[i]);
	}
	
}
