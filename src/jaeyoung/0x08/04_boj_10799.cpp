#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int cnt = 0;
    int iron = 0;
    int i;

    cin >> str;
    i = 0;
    while (i + 1 < str.size())
    {
        if (str[i] == '(')
        {
            iron++;
            if (str[i+1] == ')')
            {
                iron--;
                cnt += iron;
            }
        }
        else 
        {
            if (str[i + 1] == ')')
            {
                iron--;
                cnt++;
            }
        }
        i++;
    }
    cout << cnt;
}