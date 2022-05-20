#include <bits/stdc++.h>
using namespace std;

void    ft_rev_sort(int arr[], int a, int b)
{
    int tmp;
    int i;

    i = 0;
    while (i < (b - a + 1) / 2)
    {
        tmp = arr[a + i];
        arr[a + i] = arr[b - i];
        arr[b - i] = tmp;
        i++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[20];
    int input[20];
    int i;
    int j;

    i = 0;
    while (i < 20)
    {
        arr[i] = i + 1;
        cin >> input[i];
        i++;
    }
    i = 0;
    while (i < 10)
    {
        i = 2 * i;
        j = input[i];
        ft_rev_sort(arr, arr[j], arr[j + 1]);
        i++;
    }
    i = 0;
    while (i < 20)
        cout << arr[i++] << ' ';
}