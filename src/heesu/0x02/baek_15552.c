#include <stdio.h>

int main()
{
	int t, a, b;
	int i = 0;

	scanf("%d", &t);
	while (i < t)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
		i++;
	}
	return (0);
}
