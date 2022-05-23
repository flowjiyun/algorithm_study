#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pre[MX];
int nxt[MX];

int unused = 1; // 0번 째는 dummy node

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) // 삭제할 node가 마지막 node 가 아니라면
        pre[nxt[addr]] = pre[addr];
}