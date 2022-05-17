#include <stdio.h>

int main()
{
	int num[9];
	int i;
	int max;
	int count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 9)
	{
		scanf("%d", &num[i]);
		if (num[i] > max)
		{
			max = num[i];
			count = i + 1;
		}
		i++;
	}
	printf("%d\n", max);
	printf("%d\n", count);
	return (0);
}
