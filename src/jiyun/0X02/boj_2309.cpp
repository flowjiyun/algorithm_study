#include <iostream>

using namespace std;

void    SortUp(int* a)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    int a[9];

    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    SortUp(a);
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (a[i] + a[j]) == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                    {
                        cout << a[k] << '\n';
                    }
                }
                return (0);
            }
        }
    }
    return (0);
}