#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i, j;

    cin >> n;
    i = n;
    while (i > 0)
    {
        j = i;
        while (j > 0)
        {
            cout << "*";
            j--;
        }
        cout << "\n";
        i--;
    }
    return (0);
}