#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, cnt;

    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b >> c >> d;

        cnt = a + b + c + d;

        if (cnt == 3)
            cout << "A";
        else if (cnt == 2)
            cout << "B";
        else if (cnt == 1)
            cout << "C";
        else if (cnt == 0)
            cout << "D";
        else
            cout << "E";

        cout << "\n";
    }
    return 0;
}