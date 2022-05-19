#include <iostream>
using namespace std;
int dect[10];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int n = a * b * c;
    while (n)
    {
        dect[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << dect[i] << "\n";
    }

    return (0);
}
