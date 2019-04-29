#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 data type definition
struct Vec2
{
  float  x_ = 0.0f;
  float  y_ = 0.0f;

  /*Vec2() {}

  Vec2(float x, float y) : x_(x), y_(y) {}*/

  Vec2& operator+=(Vec2 const& v);
  /*Vec2& operator -=(Vec2 const& v);
  Vec2& operator *=(float s);
  Vec2& operator /=(float s);*/
};

# endif // VEC2_HPP