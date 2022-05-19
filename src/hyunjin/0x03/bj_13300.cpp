#include <iostream>
using namespace std;

int main()
{
    int n, k, arr[2][7] = {};
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int s, y;
        cin >> s >> y;
        arr[s][y]++;
    }

    int cnt = 0;
    for (int a = 0; a < 2; a++) {
        for (int b = 1; b < 7; b++) {
            cnt += (arr[a][b] / k);
            if (arr[a][b] % k != 0) cnt++;
        }
    }
    
    cout << cnt;
}
