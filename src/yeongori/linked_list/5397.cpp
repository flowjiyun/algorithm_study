#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        list<char> pw;
        string str;

        cin >> str;
        auto cur = pw.begin();
        for (auto c : str)
        {
            if (c == '<' && cur != pw.begin())
                cur--;
            else if (c == '>' && cur != pw.end())
                cur++;
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                pw.insert(cur, c);
            else if (c == '-' && cur != pw.begin())
                cur = pw.erase(--cur);
        }
        for (auto c : pw)
            cout << c;
        cout << '\n';
    }
}

// #include <bits/stdc++.h>

// using namespace std;

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int ca;
//     string str;
//     list<char> pw, tmp;
//     cin >> ca;
//     for (int i = 0; i < ca; i++)
//     {
//         pw.clear();
//         tmp.clear();
//         cin >> str;
//         for (auto c : str)
//             pw.push_back(c);
//         auto cur = tmp.begin();
//         for (auto c : pw)
//         {
//             if (c == '<' && cur != tmp.begin())
//                 cur--;
//             else if (c == '>' && cur != tmp.end())
//                 cur++;
//             else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//                 tmp.insert(cur, c);
//             else if (c == '-' && cur != tmp.begin())
//                 cur = tmp.erase(--cur);
//         }
//         for (auto i : tmp)
//             cout << i;
//         cout << '\n';
//     }
// }