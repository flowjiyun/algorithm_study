#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i, j;

    cin >> n;
    i = 1;
    while (i <= n)
    {
        j = 1;
        while (j <= i - 1)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= n - i + 1)
        {
            cout << "*";
            j++;
        }
        cout << "\n";
        i++;
    }
    return (0);
}