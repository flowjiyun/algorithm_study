#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int i;
    int x;
    int n;
    int arr[10000];

    std::cin >> n >> x;
    i = 0;
    while (i < n)
    {
        std::cin >> arr[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        if (arr[i] < x)
            std::cout << arr[i] << ' ';
        i++;
    }
}