#include <stdio.h>

int main()
{
	int n;
	int x, y;

	scanf("%d", &n);
	y = n;
	while (y >= 1)
	{
		x = y;
		while (x > 0)
		{
			printf("*");
			x--;
		}
		printf("\n");
		y--;
	}

	return (0);
}
