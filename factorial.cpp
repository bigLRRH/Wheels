#include "fastorial.h"
template <typename T>
T factorial(T n)
{
    T factorial = 1ll;
    for (T i(1); i <= n; ++i)
        factorial *= i;
    return factorial;
}

// https://www.luogu.com.cn/problem/solution/P5282
long long fast_factorial(int n, long long p)
{
}