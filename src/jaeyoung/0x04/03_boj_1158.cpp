#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);

    int n;
    int k;
    int i;
    int j;

    cin >> n >> k;
    list<int> arr;
    i = 1;
    while (i <= n)
        arr.push_back(i++);
    list<int>::iterator idx = arr.begin();
    cout << "<";
    i = 1;
    while (i <= n)
    {
        j = 1;
        while (j < k)
        {
            idx++;
            if (idx == arr.end())
                idx = arr.begin();
            j++;
        }
        cout << *idx;
        if (i != n)
            cout << ", ";
        idx = arr.erase(idx);
        if (idx == arr.end())
            idx = arr.begin();
        i++;
    }
    cout << ">";
}