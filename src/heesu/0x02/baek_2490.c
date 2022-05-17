#include <stdio.h>

int main()
{
	int i, j;

	i = 0;
	while (i < 3)
	{
		int yut[4];
		int count;
	
		j = 0;
		count = 0;
		while (j < 4)
		{
			scanf("%d", &yut[j]);
			if (yut[j] == 1)
				count++;
			j++;
		}
		if (count == 0)
			printf("D\n");
		else if (count == 1)
			printf("C\n");
		else if (count == 2)
			printf("B\n");
		else if (count == 3)
			printf("A\n");
		else if (count == 4)
			printf("E\n");
		i++;
	}
	return (0);
}
