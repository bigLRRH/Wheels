#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <execution>
using namespace std;
int main()
{
    // 输入实数序列
    vector<double> input = {1.0, 2.0, 3.0, 4.0, 5};

    // 将实数序列转换为复数序列
    vector<complex<double>> complexInput;
    for (const auto &value : input)
    {
        complexInput.push_back(complex<double>(value, 0));
    }

    vector<complex<double>> transformed(complexInput.size());
    complex<double> result = accumulate(
        complexInput.begin(), complexInput.end(),
        complex<double>(0, 0),
        [&](const complex<double> init, const complex<double> &x)
        {
            cout << x << endl;
            auto k = &x - &complexInput[0] + 1;
            cout << k << endl;
            return init + x;
        });
    cout << result;
}