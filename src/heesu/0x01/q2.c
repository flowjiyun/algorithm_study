#include <stdio.h>

int func2(int arr[], int n)
{
	int	i;
	int j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] + arr[j] == 100)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main()
{
	int arr1[] = {1, 52, 48};
	int arr2[] = {50, 42};
	int arr3[] = {4, 13, 63, 87};
	printf("arr1 : %d\n", func2(arr1, 3));
	printf("arr2 : %d\n", func2(arr2, 2));
	printf("arr3 : %d\n", func2(arr3, 4));
}
