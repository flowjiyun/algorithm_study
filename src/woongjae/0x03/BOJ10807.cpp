#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    int n;
    int v;
    int cnt;
    int arr[100];

    i = 0;
    cnt = 0;
    cin >> n;
    while (i < n)
    {
        cin >> arr[i];
        i++;
    }
    cin >> v;
    i = 0;
    while (i < n)
    {
        if (arr[i] == v)
            cnt++;
        i++;
    }
    cout << cnt;
    return (0);
}