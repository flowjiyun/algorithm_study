#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;
    pair <int, string> people[n];
    for (auto& a : people)
        cin >> a.first >> a.second;
    stable_sort(people, people + n, [&](pair<int, string> a, pair<int, string> b) {
        return a.first < b.first;});
    for (auto& p : people)
        cout << p.first << ' ' << p.second << '\n';
}