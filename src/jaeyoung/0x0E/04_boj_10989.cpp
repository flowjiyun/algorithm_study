#include <iostream>
using namespace std;

int n;
int arr[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[num]++;
    }
  
    for (int i = 0; i < 10005; i++)
    {
        while (arr[i])
        {
            cout << i << '\n';
            arr[i]--;
        }
    }
}