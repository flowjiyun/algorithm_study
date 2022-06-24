#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;

struct People
{
    int age;
    string name;
};
People people[100001];

bool compare(const People& p1, const People& p2)
{
        return p1.age < p2.age;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> people[i].age >> people[i].name;
    stable_sort(people, people + n, compare);
    for (int i = 0; i < n; i++)
        cout << people[i].age << ' ' << people[i].name << '\n';
}
