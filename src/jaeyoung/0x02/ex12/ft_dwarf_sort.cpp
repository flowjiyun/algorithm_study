#include <bits/stdc++.h>
using namespace std;

void    ft_print_dwarf(int *arr, int x, int y)
{
    int i;

    i = 0;
    while (i < 9)
    {
        if (i != x || i != y)
            cout << arr[i] << '\n';
        i++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9];
    int i;
    int j;
    int sum;
    int tmp;
    
    i = 0;
    sum = 0;
    while (i < 9)
    {
         cin >> arr[i];
         sum += arr[i];
         i++;
    }
    i = 0;
    while (i < 9)
    {
        j = i + 1;
        while (j < 9)
        {
            if (arr[i] >= arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 9)
    {
        j = i + 1;
        while (j < 9)
        {
            if (sum - (arr[i] + arr[j]) == 100)
            {
                ft_print_dwarf(arr, i, j);
            }
            j++;
        }
        i++;
    }
}