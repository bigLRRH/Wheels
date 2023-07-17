// https://www.cnblogs.com/LanrTabe/p/11305604.html
// 这个星球上最快的fft(Fastest Fourier Transform) http://fftw.org/
#include <complex>
#include <vector>
#include <numbers>
#include <stdexcept>
using std::vector, std::complex, std::numbers::pi;

class FourierTransformError : public std::runtime_error
{
public:
    FourierTransformError(const std::string &message) : std::runtime_error(message) {}
};

vector<complex<double>> discrete_fourier_transform(const vector<complex<double>> &x)
{
    const int N = x.size();
    if (N < 1)
        throw FourierTransformError("The order of a Fourier transform must be greater than 0");
    vector<complex<double>> X(N);

    for (int k = 0; k < N; ++k)
    {
        X[k] = 0.0;
        for (int n = 0; n < N; ++n)
        {
            double angle = 2 * pi * k * n / N;
            X[k] += x[n] * std::polar(1.0, -angle);
        }
    }
    return X;
}

vector<complex<double>> inverse_discrete_fourier_transform(const vector<complex<double>> &X)
{
    const int N = X.size();
    if (N < 1)
        throw FourierTransformError("The order of a Fourier transform must be greater than 0");
    vector<complex<double>> x(N);

    for (int n = 0; n < N; ++n)
    {
        x[n] = 0.0;
        for (int k = 0; k < N; ++k)
        {
            double angle = 2 * pi * k * n / N;
            x[n] += X[k] * std::polar(1.0, angle);
        }
        x[n] /= N;
    }
    return x;
}

vector<complex<double>> fast_fourier_transform(const vector<complex<double>> &x)
{
    discrete_fourier_transform(x);
}