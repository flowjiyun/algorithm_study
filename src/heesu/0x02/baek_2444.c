#include <stdio.h>

int main()
{
	int	n;
	int x, y;

	y = 1;
	scanf("%d", &n);
	while (y <= n)
	{
		x = 0;
		while (x < n - y)
		{
			printf(" ");
			x++;
		}
		x = 1;
		while (x < y * 2)
		{
			printf("*");
			x++;
		}
		printf("\n");
		y++;
	}

	y = n - 1;
	while (y > 0)
	{
		x = n - y;
		while (x > 0)
		{
			printf(" ");
			x--;
		}
		x = 0;
		while (x < y * 2 - 1)
		{
			printf("*");
			x++;
		}
		printf("\n");
		y--;
	}
	return (0);
}
