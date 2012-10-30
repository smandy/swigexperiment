#pragma once

class Complex {
  int x;
  int y;


public:

  inline int getX() { return x; }
  inline int getY() { return y; }

  explicit Complex( int x_ = 0, int y_ = 0) : x(x_), y(y_) {};

  Complex operator+( const Complex &rhs );
  Complex operator-( const Complex &rhs );

};
