#include <stdio.h>

int main()
{
	int n;
	int x, y;
	
	scanf("%d", &n);
	y = 1;
	while (y < n)
	{
		x = 0;
		while (x < y)
		{
			printf("*");
			x++;
		}
		x = 0;
		while (x < (2 * n) - (2 * y))
		{
			printf(" ");
			x++;
		}
		x = 0;
		while (x < y)
		{
			printf("*");
			x++;
		}
		printf("\n");
		y++;
	}

	y = n;
	while (y > 0)
	{
		x = 0;
		while (x < y)
		{
			printf("*");
			x++;
		}
		x = 0;
		while (x < (2 * n) - (2 * y))
		{
			printf(" ");
			x++;
		}
		x = 0;
		while (x < y)
		{
			printf("*");
			x++;
		}
		printf("\n");
		y--;
	}

	return (0);
}
