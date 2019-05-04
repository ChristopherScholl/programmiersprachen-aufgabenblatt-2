# ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

// Circle data type definition
class Circle2
{
public:
  Circle2() {}
  Circle2(Vec2 const& mid, float const& radius, Color const& color) :mid_(mid), radius_(radius), color_(color) {}
  float circumference() const;
  void draw(Window const& win) const;
  void draw(Window const& win, float t) const;

private:
  Vec2  mid_{ 1.0,1.0 };
  float  radius_ = 1.0;
  Color color_{ 0.5,0.5,0.5 };
};

# endif // CIRCLE_HPP