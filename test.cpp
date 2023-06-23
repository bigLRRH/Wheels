#include <iostream>
using namespace std;
template <typename T>
T factorial(T n)
{
    T factorial = 1ll;
    for (T i(1); i <= n; ++i)
        factorial *= i;
    return factorial;
}
int main(){
    cout<<factorial<long long>(3);
}