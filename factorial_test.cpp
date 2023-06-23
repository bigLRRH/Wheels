#include <iostream>
using namespace std;
template <typename T>
T factorial(const T &&n)
{
    T factorial(1);
    for (T i(1); i <= n; ++i)
        factorial *= i;
    return std::move(factorial);
}
int main(){
    cout<<factorial<int>(3);
}