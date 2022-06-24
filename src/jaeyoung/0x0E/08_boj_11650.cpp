#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct MAP
{
    int x, y;
};

MAP map[100001];

bool compare(const MAP& m1, const MAP& m2)
{
    if (m1.x == m2.x)
        return m1.y < m2.y;
    else
        return m1.x < m2.x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> map[i].x >> map[i].y;
    sort(map, map + n, compare);
    for (int i = 0; i < n; i++)
        cout << map[i].x << ' ' << map[i].y << '\n';
}