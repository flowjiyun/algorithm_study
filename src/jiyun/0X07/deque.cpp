#include <bits/stdc++.h>

using namespace std;
// implement dequeue with array
const int MX = 1000004;
int q[2 * MX + 1];
int head = MX;
int tail = MX;

void push_front(int data)
{
    q[head] = data;
    head--;
}

void push_back(int data)
{
    q[tail] = data;
    tail++;
}

void pop_front()
{
    head++;
}
void pop_back()
{
    tail--;
}
int front()
{
    return (q[head + 1]);
}
int back()
{
    return (q[tail - 1]);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return (0);
}