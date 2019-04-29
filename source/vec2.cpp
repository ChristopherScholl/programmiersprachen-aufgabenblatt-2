#include "vec2.hpp"

Vec2& Vec2::operator +=(Vec2 const& v) {
  x_ += v.x_;
  y_ += v.y_;
  return *this;
}

Vec2& Vec2::operator -=(Vec2 const& v) {
  x_ -= v.x_;
  y_ -= v.y_;
  return *this;
}

Vec2& Vec2::operator *=(float s){
  x_ *= s;
  y_ *= s;
  return *this;
}

Vec2& Vec2::operator /=(float s) {
  x_ /= s;
  y_ /= s;
  return *this;
}

Vec2 operator +(Vec2 const& u, Vec2 const& v) {
  Vec2 w = u;
  w += v;
  return w;
}

Vec2 operator -(Vec2 const& u, Vec2 const& v) {
  Vec2 w = u;
  w -= v;
  return w;
}

Vec2 operator *(Vec2 const& v, float s) {
  Vec2 w = v;
  w *= s;
  return w;
}

Vec2 operator /(Vec2 const& v, float s) {
  Vec2 w = v;
  w /= s;
  return w;
}

Vec2 operator *(float s, Vec2 const& v) {
  Vec2 w = v;
  w *= s;
  return w;
}
