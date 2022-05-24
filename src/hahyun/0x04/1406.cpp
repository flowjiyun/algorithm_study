#include <iostream>
using namespace std;

char dat[1000005];
int nxt[1000005];
int pre[1000005];
int unused = 1;

void insert(int addr, char c)
{
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    nxt[addr] = unused;
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void traverse()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + 1000005, -1);
    fill(nxt, nxt + 1000005, -1);
    char arr[100001] = "";
    int cursor = 0;
    int M;
    char x, y;
    cin >> arr;
    for (int i = 0; arr[i]; i++)
    {
        insert(cursor, arr[i]);
        cursor++;
    }
    cin >> M;
    while (M--)
    {
        cin >> x;
        if (x == 'L')
        {
            if (pre[cursor] != -1)
                cursor = pre[cursor];
        }
        else if (x == 'D')
        {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];
        }
        else if (x == 'B')
        {
            if (cursor != 0)
            {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
        else if (x == 'P')
        {
            cin >> y;
            insert(cursor, y);
            cursor = nxt[cursor];
        }
    }
    traverse();
}