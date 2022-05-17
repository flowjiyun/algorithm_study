#include <stdio.h>

int main()
{
	int n;
	int x, y;

	scanf("%d", &n);
	y = n;
	while (y > 0)
	{
		x = y;
		while (x < n)
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
