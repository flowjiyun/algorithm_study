#include <iostream>
using namespace std;
int arr[100000];
int dect[2000000];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (x - arr[i] > 0 && dect[x - arr[i]] == 1) cnt++;
        dect[arr[i]]++;
    }
    cout << cnt;
}
