template <typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
class matrix
{
public:
    int rows() const {return RowsAtCompileTime};            //
    int columns() const {return ColsAtCompileTime};         //
    Scalar &operator()(int i, int j) const;                 //
    matrix<Scalar> &operator=(const matrix<Scalar> &);      //
    matrix<Scalar> operator+() const;                       // unary +
    matrix<Scalar> operator+(const matrix<Scalar> &) const; //
    matrix<Scalar> operator-() const;                       // unary minus
    matrix<Scalar> operator-(const matrix<Scalar> &) const; //
    matrix<Scalar> operator*(const matrix<Scalar> &) const; //
    matrix<Scalar> &operator+=(const Scalar &);             //
};