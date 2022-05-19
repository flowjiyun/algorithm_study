#include <iostream>
using namespace std;

int main(void)
{
    string s;
    cin >> s;

    for (char a = 'a'; a <= 'z'; a++)
    {
        int cnt = 0;
        for (auto e : s)
            if (a == e) cnt++;
        cout << cnt << ", ";
    }
}
