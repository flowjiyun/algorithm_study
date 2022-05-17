#include <stdio.h>

int main()
{
    int n, x, num; 
	int i = 1;

    scanf("%d %d", &n, &x);
    while(i <= n){
        scanf("%d", &num);
        if(num < x) 
			printf("%d\n", num); 
        i++;
    }
    return (0);
}
