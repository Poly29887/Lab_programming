#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num1, num2, i, keep;
	printf("Enter first number : ");
	scanf("%d", &num1);
	printf("Enter second number : ");
	scanf("%d", &num2);
	if (num1 < num2)
	{
		for (i = 1; i <= num2; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				keep = i;
			}
		}
	}
	else
	{
		for (i = 1; i <= num1; i++)
		{
			if (num1 % i == 0 && num2 % i == 0)
			{
				keep = i;
			}
		}
	}
	printf("Greatest common divisor : %d",keep);
}