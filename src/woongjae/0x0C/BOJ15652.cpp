#include <iostream>
using namespace std;
int n,m;
int arr[9];
bool visited[9];

void func(int num, int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++)
    {
        visited[i] = true;
        arr[cnt] = i;
        func(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    func(1,0);
}