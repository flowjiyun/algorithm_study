#include <iostream>

using namespace std;

int a[10];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nb;
    int set = 0;
    cin >> nb;
    if (nb == 0)
        a[0] = 1;
    while (nb != 0)
    {
        a[nb % 10]++;
        nb /= 10;
    }
    set = (a[6] + a[9]) / 2 + (a[6] + a[9]) % 2;
    for (int i = 0; i < 10; i++)
    {
        if (set < a[i] && i != 6 && i != 9)
            set = a[i];
    }
    cout << set;
    return (0);
}