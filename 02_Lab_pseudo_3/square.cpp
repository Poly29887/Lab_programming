#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int side, i, j;
	printf("Enter number : ");
	scanf("%d", &side);
	for (i = 1; i <= side; i++)
	{
		printf("*");
	}
	printf("\n");
	for (i = 1; i <= side-2; i++)
	{
		printf("*");
		for (j = 1; j <= side - 2; j++)
		{
			printf(" ");
		}
		printf("*\n");	
	}
	for (i = 1; i <= side; i++)
	{
		printf("*");
	}

}