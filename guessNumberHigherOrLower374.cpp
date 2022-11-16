#include <iostream>

int guess(long long g, int n)
{
    if (g > n)
        return -1;
    if (g < n)
        return 1;
    return 0;
}

int main()
{
    int n = 32;
    long long low = 1;
    long long high = 100;
    long long mid = (low + high) / 2;
    while (guess(mid, n) != 0)
    {
        if (guess(mid, n) == -1)
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    std::cout << mid;

    return 0;
}