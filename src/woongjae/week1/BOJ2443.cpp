#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i, j;
    i = 1;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i - 1)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= 2 * n - (2 * i - 1))
        {
            cout << "*";
            j++;
        }
        cout << "\n";
        i++;
    }
    return (0);
}