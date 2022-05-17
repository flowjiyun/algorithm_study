#include <stdio.h>

int main()
{
	int a, b, c;
	int num = 0;
	int price = 0;
	int max = 0;

	scanf("%d %d %d", &a, &b, &c);
	if (a == b && b == c)
		price = 10000 + (a * 1000);
	else if (a == b || b == c || c == a)
	{
		if (a == b || c == a)
			num = a;
		else if (b == c)
			num = b;
		price = 1000 + (num * 100);
	}
	else
	{
		if (a > b && a > c)
			max = a;
		else if (b > a && b > c)
			max = b;
		else
			max = c;
		price = max * 100;
	}

	printf("%d", price);
	return (0);
}
