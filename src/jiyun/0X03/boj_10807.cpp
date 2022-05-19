#include <iostream>

using namespace std;

int ar[201];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int length;
    int nb;
    int v;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> nb;
        ar[nb + 100]++;
    }
    cin >> v;
    cout << ar[v + 100];
    return (0);
}