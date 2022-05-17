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
		while (x < n - y)
		{
			printf(" ");
			x++;
		}
		while (x < n)
		{
			printf("*");
			x++;
		}
		printf("\n");
		y++;
	}
	return (0);
}
