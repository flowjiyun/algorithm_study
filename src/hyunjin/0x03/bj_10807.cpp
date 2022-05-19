#include <iostream>
using namespace std;

int main()
{
    int n, v, d[201] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        d[num + 100]++;
    }

    cin >> v;
    cout <<d[v + 100];
}
