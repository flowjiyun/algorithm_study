#include <stdio.h>

int func4(int n)
{
	int i;

	i = 1;
	while (i * 2 <= n)
		i *= 2;
	return (i);
}

int main()
{
	printf("%d\n", func4(5));
	printf("%d\n", func4(97615282));
	printf("%d\n", func4(1024));
}
