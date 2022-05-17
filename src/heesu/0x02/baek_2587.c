#include <stdio.h>

int main()
{
	int num[5];
	int i, j;
	int result;
	int temp;

	i = 0;
	result = 0;
	while (i < 5)
	{
		scanf("%d", &num[i]);
		result += num[i];
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	printf("%d\n%d\n", result / 5, num[2]);
	return (0);
}
