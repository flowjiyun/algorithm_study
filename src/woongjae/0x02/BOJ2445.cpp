#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int n;

    cin >> n;
    i = 1;
    while (i <= n)
    {
        j = 0;
        while (j < i)
        {
            cout << "*";
            j++;
        }
        j = 0;
        while (j < 2 * n - 2 * i)
        {
            cout << " ";
            j++;
        }
        j = 0;
        while (j < i)
        {
            cout << "*";
            j++;
        }
        cout << "\n";
        i++;
    }
    i = 1;
    while (i < n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << "*";
            j++;
        }
        j = 1;
        while (j <= 2 * i)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= n - i)
        {
            cout << "*";
            j++;
        }
        cout << "\n";
        i++;
    }
}