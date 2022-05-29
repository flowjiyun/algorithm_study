#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    deque<int> D;
    D.push_front(10); //{10}
    D.push_back(50); //{10, 50}
    D.push_front(24);
    for (auto x : D)
        cout << x << ' ';
    cout << D.size() << '\n';
    if (D.empty())
        cout << "D is empty\n";
    else
        cout << "D is not empty\n";
    D.pop_front();
    D.pop_back();
    cout << D.back() << '\n';
    D.push_back(72);
    cout << D.front() << '\n';
    D.push_back(12);
    D[2] = 17;
    D.insert(D.begin() + 1, 33);
    D.insert(D.begin() + 4, 60);
    for (auto x : D)
        cout << x << ' ';
    cout << '\n';
    D.erase(D.begin() + 3);
    cout << D[3] << '\n';
    D.clear();
    return (0);

}