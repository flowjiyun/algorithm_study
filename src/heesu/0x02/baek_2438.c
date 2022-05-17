#include <stdio.h>

int main()
{
	int n;
	int x, y;

	y = 1;
	scanf("%d", &n);
	while (y <= n)
	{
		x = 0;
		while (x < y)
		{
			printf("*");
			x++;
		}
		printf("\n");
		y++;
	}

	return (0);
}
