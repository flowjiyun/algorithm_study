#include <iostream>

using namespace std;

int main()
{
    int year;

    cin >> year;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                cout << "1";
            else
                cout << "0";
        }
        else
            cout << "1";
    } 
    else
        cout << "0";
    return (0);
}