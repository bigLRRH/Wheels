#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum{0};
    int i{n};
    // 趋近符号 -->
    while (i --> 0)
    {
        sum += i;
        cout << i;
    }
    cout << sum;
    return 0;
}