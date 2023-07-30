#ifndef _fourier_h
#define _fourier_h

#include <vector>
#include <complex>
using std::vector, std::complex;

template <typename T>
vector<complex<T>> discrete_fourier_transform(
    const vector<complex<T>> &sequence, const bool inverse = false);

template <typename T>
vector<complex<T>> discrete_fourier_transform_parallel(
    const vector<complex<T>> &sequence, const bool inverse = false);

template <typename T>
vector<complex<T>> fast_fourier_transform(
    const vector<complex<T>> &sequence, const bool inverse = false);

#endif