#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

void message1()
{
	puts("Here is the message returning from newFunctionOne.");
}
void message2()
{
	puts("Here is the message returning from newFunctionTwo.");
}
int main()
{
	atexit(message1);
	atexit(message2);
	printf("This is the message from main function.");
	
	return 0;
}

