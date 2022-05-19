#include <stdio.h>
//일곱 난쟁이
int main()
{
    int arr[9];
    int sum=0;
    int over;

    for(int i=0; i<9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    over = sum - 100;
    int a;
    int b;
    for (int i=0; i<9; i++)
    {
        for (int j=i+1; j<9; j++)
        {
            if(arr[i] + arr[j] == over)
            {
                a = i;
                b = j;
                break ;
            }
        }
    }
    int true[7];
    int j=0;
    for (int i=0; i<9; i++)
    {
        if (i != a && i != b)
        {
            true[j] = arr[i];
            j++;
        }
    }
    int tmp;
    for (int i=0; i<7; i++)
    {
        for (int j=0; j<7; j++)
        {
            if (true[i] < true[j])
            {
                tmp = true[i];
                true[i] = true[j];
                true[j] = tmp;
            }
        }
    }
    for (int i=0; i<7; i++)
        printf("%d\n", true[i]);
}