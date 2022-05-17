#include <stdio.h>

int main()
{
	int n;
	int x, y;

	scanf("%d", &n);
	y = 1;
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

	return (0);
}
