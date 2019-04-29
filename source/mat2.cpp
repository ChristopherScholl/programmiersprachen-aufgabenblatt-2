#include "mat2.hpp"

Mat2& Mat2::operator *=(Mat2 const& m) {
  float h_00 = e_00;
  float h_10 = e_10;
  float h_01 = e_01;
  float h_11 = e_11;

  e_00 = h_00 * m.e_00 + h_10 * m.e_01;
  e_10 = h_00 * m.e_10 + h_10 * m.e_11;
  e_01 = h_01 * m.e_00 + h_11 * m.e_01;
  e_11 = h_01 * m.e_10 + h_11 * m.e_11;
  return *this;
}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2) {
  Mat2 n;
  n *= m1;
  n *= m2;
  return n;
}
