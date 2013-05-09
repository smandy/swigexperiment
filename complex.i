%module complexmodule

%{

#include "sstream"

#include <string>

#include "complex.hpp"

%}


%include "std_string.i"

%include "stl.i"

%include "complex.hpp"



%rename(__repr__)  Complex::toString() const;
