#include <stdio.h>

int main()
{
	int num[7];
	int i;
	int result;
	int min;

	i = 0;
	result = 0;
	min = 100;
	while (i < 7)
	{
		scanf("%d", &num[i]);
		if (num[i] % 2 != 0)
		{
			result += num[i];
			if (min > num[i])
				min = num[i];
		}
		i++;
	}
	if (result == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n", result, min);
	return (0);
}
