#include "complex.hpp"

Complex Complex::operator+( const Complex &rhs ) {
    return Complex( x + rhs.x, y + rhs.y);
};

Complex Complex::operator-( const Complex &rhs ) {
    return Complex( x + rhs.x, y + rhs.y);
};
