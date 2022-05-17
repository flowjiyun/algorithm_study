#include <stdio.h>

int func1(int n)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (i % 3 == 0 || i % 5 == 0)
			result += i;
		i++;
	}
	return (result);
}

int main()
{
	printf("%d\n", func1(16));
	printf("%d\n", func1(34567));
	printf("%d\n", func1(27639));
}
