#include <iostream>

using namespace std;

int nb[100001];
int list[2000000];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int length;
    int set = 0;
    int x;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> nb[i];
        list[nb[i] - 1]++;
    }
    cin >> x;
    for (int i = 0; i < length; i++)
    {
        if ((x >= (nb[i] + 1)) && list[x - nb[i] - 1] == 1)
        {
            set++;
        }
    }
    cout << set / 2;
    return (0);
}