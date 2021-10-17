#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int ncount = 0;
    int left = 1;
    int right = n;
    while (n > 1)
    {
        n /= 2;
        ncount++;
    }
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (a <= mid and b <= mid)
            right = mid - 1;
        else if (a > mid and b > mid)
            left = mid + 1;
        else
            break;
        ncount--;
    }
    return ncount;
}