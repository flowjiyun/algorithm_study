#include <bits/stdc++.h>

using namespace std;
int que[500000];
int head = 0;
int tail= 0;

void push(int data)
{
    que[tail] = data;
    tail++;
}
void pop()
{
    head++;
}
int front()
{
    return que[head];
}
int back()
{
    return que[tail - 1];
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    return (0);
}