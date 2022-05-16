#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int n;

    i = 1;
    cin >> n;
    while (i <= n)
    {
        j = 0;
        while (j < i)
        {
            cout << "*";
            j++;
        }
        cout << "\n";
        i++;
    }
}