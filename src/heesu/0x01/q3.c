#include <stdio.h>

int func3(int n)
{
	int i;

	i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	printf("%d\n", func3(9));
	printf("%d\n", func3(693953651));
	printf("%d\n", func3(756580036));
}
