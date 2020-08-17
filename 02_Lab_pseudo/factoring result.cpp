#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num, i, j, x,div, count, round, ans;
	printf("Enter number : ");
	scanf("%d",&num);
	i = 1;
	x = num;
	round = 0;
	ans = 0;
	while (i <= num)
	{
		count = 0;
		if (x % i == 0)
		{
			div = i;
			for (j = 1; j <= div; j++)
			{
				if (div % j == 0)
				{
					count++;
				}
			}
		}
		if (count == 2)
		{
			do {
				if (ans == 1)
				{
					i = num;
					break;
				}
				round++;
				if (round == 1)
				{
					printf("Factoring Result : %d ", div);
				}
				else {
					printf("x %d ", div);
				}
				ans = x / div;
				x = ans;

				
			} while (ans % div == 0);
		}
		i++;
	}

}