#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    deque<int> DQ;
    DQ.push_front(10);
    DQ.push_back(50);
    DQ.push_front(24);
    for (auto x : DQ)
        cout << x << '\n';
    cout << DQ.size() << '\n';
    if (DQ.empty())
        cout << "DQ is empty\n";
    else
        cout << "DQ is not empty\n";
    DQ.pop_front();
    DQ.pop_back();

    cout << DQ.back() << '\n';
    DQ.push_back(72);
    cout << DQ.front() << '\n';
    DQ.push_back(12);
    DQ[2] = 17;
    DQ.insert(DQ.begin() + 1, 33);
    DQ.insert(DQ.begin() + 4, 60);
    for (auto x : DQ)
        cout << x << ' ';
    cout << '\n';
    DQ.erase(DQ.begin() + 3);
    cout << DQ[3] << '\n';
    DQ.clear();
}

// const int MX = 1000005;
// int dat[2 * MX + 1];
// int head = MX, tail = MX;

// void push_front(int x)
// {
//     dat[head--] = x;
// }

// void push_back(int x)
// {
//     dat[tail++] = x;
// }

// void pop_front()
// {
//     head++;
// }

// void pop_back()
// {
//     tail--;
// }

// int front()
// {
//     return dat[head - 1];
// }

// int back()
// {
//     return dat[tail - 1];
// }

// void test()
// {
//     push_back(30);           // 30
//     cout << front() << '\n'; // 30
//     cout << back() << '\n';  // 30
//     push_front(25);          // 25 30
//     push_back(12);           // 25 30 12
//     cout << back() << '\n';  // 12
//     push_back(62);           // 25 30 12 62
//     pop_front();             // 30 12 62
//     cout << front() << '\n'; // 30
//     pop_front();             // 12 62
//     cout << back() << '\n';  // 62
// }

// int main(void)
// {
//     test();
// }