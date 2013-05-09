#include "complex.hpp"



Complex Complex::operator+( const Complex &rhs ) {
    return Complex( x + rhs.x, y + rhs.y);
};

Complex Complex::operator-( const Complex &rhs ) {
    return Complex( x + rhs.x, y + rhs.y);
};

std::string Complex::toString() const {
  std::stringstream ss;
  append(ss);
  return ss.str();
};

void Complex::append( std::ostream &os) const {
  os << "Complex(" << getX() << "," << getY() << ")";
};

std::ostream &operator<<( std::ostream &os, const Complex &rhs) {
  rhs.append( os );
  return os;
};
