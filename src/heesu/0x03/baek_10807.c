#include <stdio.h>

int main()
{
	int n, num[100], v;
	int i;
	int cnt;

	scanf("%d", &n);
	i = 0;
	cnt = 0;
	while (i < n)
	{
		scanf("%d", &num[i]);
		i++;
	}
	scanf("%d", &v);
	i = 0;
	while (i < n)
	{
		if (v == num[i])
			cnt++;
		i++;
	}
	printf("%d", cnt);
	return (0);
}
