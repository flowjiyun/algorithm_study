#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nb;
    int k;
    int grade;
    int gender;
    int cnt = 0;
    int room[12] = {};
    cin >> nb >> k;
    for (int i = 0; i < nb; i++)
    {
        cin >> gender >> grade;
        room[(2 * grade - gender) - 1]++;
    } 
    for (int i = 0; i < 12; i++)
    {
        if (room[i] % k != 0)
            cnt += room[i] / k + 1;
        else
            cnt += room[i] / k;
    }
    cout << cnt;
    return (0);
}