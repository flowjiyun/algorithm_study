#include <iostream>
using namespace std;

int arr[2000005];
int n, num;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

   cin >> n;
   for (int i = 0; i < n; i++)
   {
        cin >> num;
        arr[num + 1000000]++;
   }
    for (int i = 2000000; i >= 0; i--)
   {
        if (arr[i])
            cout << i - 1000000 << '\n';
   }

}