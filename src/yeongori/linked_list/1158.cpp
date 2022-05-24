#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    list<int> L;

    for (int i = 1; i < n + 1; i++) // ..
        L.push_back(i);
    auto cur = L.begin();

    cout << "<";
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            cur++;
            if (cur == L.end())
                cur = L.begin();
        }

        cout << *cur << ", ";
        cur = L.erase(cur); // ..
        if (cur == L.end())
            cur = L.begin();
    }
    cout << *cur << ">";
}

// #include <bits/stdc++.h>

// using namespace std;

// int main(void)
// {
//     list<int> L;
//     int n, k;
//     cin >> n >> k;
//     for (int i = 1; i < n + 1; i++)
//         L.push_back(i);
//     auto cur = L.begin();

//     cout << "<";
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < k - 1; j++)
//         {
//             if (cur == L.end())
//                 cur = L.begin();
//             cur++;
//         }
//         cout << *cur << ' ';
//         if (cur == L.end())
//         {
//             L.pop_back();
//             cur = L.begin();
//         }
//         else
//             cur = L.erase(cur);
//     }
//     cout << *cur << ">";
// }