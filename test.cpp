#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <execution>
#include <complex>

using std::vector, std::complex, std::numbers::pi, std::size_t, std::polar;
using namespace std;

template <typename T>
vector<complex<T>> discrete_fourier_transform1(
    const std::vector<complex<T>> &sequence, const bool inverse = false)
{
    const size_t N = sequence.size();

    vector<complex<T>> result(N);

    for (size_t k = 0; k < N; ++k)
    {
        complex<T> sum = 0;

        for (size_t n = 0; n < N; ++n)
        {
            T angle = (inverse ? 1 : -1) * 2 * pi * k * n / N;
            sum += sequence[n] * polar(T(1), angle);
        }
        result[k] = sum * (inverse ? T(1) / T(N) : T(1));
    }

    return result;
}

template <typename T>
vector<complex<T>> discrete_fourier_transform(
    const std::vector<complex<T>> &sequence, const bool inverse = false)
{
    const size_t N = sequence.size();
    vector<complex<T>> result(N);

    std::transform(
        std::execution::par_unseq, sequence.begin(), sequence.end(), result.begin(),
        [&](const complex<T> &sequence_k)
        {
            auto k = &sequence_k - &sequence[0];
            cout <<"k:"<< k << endl;
            return (inverse ? T(1) / T(N) : T(1)) *
                   std::accumulate(
                       sequence.begin(), sequence.end(),
                       complex<T>(0, 0),
                       [&](const complex<T> &init, const complex<T> &x_n)
                       {
                           auto n = &x_n - &sequence[0];
                           cout <<"n:"<< n << endl;
                           T angle = (inverse ? 1 : -1) * 2 * pi * k * n / N;
                           return init + x_n * polar(T(1), angle);
                       });
        });

    return result;
}
int main()
{
    // 输入实数序列
    vector<double> input = {1.0, 2.0, 3.0, 4.0};

    // 将实数序列转换为复数序列
    vector<complex<double>> complexInput;
    for (const auto &value : input)
    {
        complexInput.push_back(complex<double>(value, 0));
    }

    // 执行离散傅里叶变换
    vector<complex<double>> transformed1 = discrete_fourier_transform1(complexInput);
    vector<complex<double>> transformed2 = discrete_fourier_transform(complexInput);

    // 输出变换结果
    std::cout << "Transformed1 sequence: ";
    for (const auto &value : transformed1)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Transformed2 sequence: ";
    for (const auto &value : transformed2)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}