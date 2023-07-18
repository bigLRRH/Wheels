// references：
// https://en.wikipedia.org/wiki/Discrete_Fourier_transform
// https://oi-wiki.org/math/poly/fft/
// https://www.cnblogs.com/LanrTabe/p/11305604.html
// http://fftw.org/
// etc

#include <complex>
#include <vector>
#include <numbers>
#include <algorithm>
#include <execution>
using std::vector, std::complex, std::numbers::pi, std::size_t, std::polar;

// warning: This is a quick prototype requiring language optimization.
template <typename T>
vector<complex<T>> discrete_fourier_transform(
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

// 并行优化版
// todo 使用reduce替代accumulate
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
            return (inverse ? T(1) / T(N) : T(1)) *
                   std::accumulate(
                       sequence.begin(), sequence.end(),
                       complex<T>(0, 0),
                       [&](const complex<T> &init, const complex<T> &x_n)
                       {
                           auto n = &x_n - &sequence[0];
                           T angle = (inverse ? 1 : -1) * 2 * pi * k * n / N;
                           return init + x_n * polar(T(1), angle);
                       });
        });

    return result;
}
template <typename T>
vector<complex<T>> fast_fourier_transform(const vector<T> &x, const bool inverse = false)
{
    return discrete_fourier_transform(x, inverse);
}