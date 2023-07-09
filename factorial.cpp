#include "factorial.h"
template <typename T>
T factorial(const T &&n)
{
    T factorial(1);
    for (T i(1); i <= n; ++i)
        factorial *= i;
    return std::move(factorial);
}

// https://www.luogu.com.cn/problem/solution/P5282
long long fast_factorial(int n, long long p)
{
    
}