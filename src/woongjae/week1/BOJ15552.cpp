#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int a, b;
    int result[1000000];

    i = 0;
    cin >> n;
    while(i < n)
    {
        cin >> a >> b;
        cout << a + b << "\n";
        i++;
    }

    return (0);
}