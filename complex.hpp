#pragma once

#include <iostream>
#include <sstream>

class Complex {
  int x;
  int y;

public:
  inline int getX() const { return x; }
  inline int getY() const { return y; }

  explicit Complex( int x_ = 0, int y_ = 0) : x(x_), y(y_) {};

  Complex operator+( const Complex &rhs );
  Complex operator-( const Complex &rhs );

  std::string toString() const;

  friend std::ostream &operator<<( std::ostream &os, const Complex &rhs);

private:
  void append( std::ostream &os) const;
};

std::ostream &operator<<( std::ostream &os, const Complex &rhs);
