#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    int n;

    i = 1;
    cin >> n;
    while (i <= n)
    {
        j = n;
        while (j > i)
        {
            cout << " ";
            j--;
        }
        while (j > 0)
        {
            cout << "*";
            j--;
        }
        cout << '\n';
        i++;
    }
    return (0);
}