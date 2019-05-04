# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

#include "vec2.hpp"

// Rectangle data type definition
class Rectangle2
{
public:
  Rectangle2(){}
  Rectangle2(Vec2 const& min, Vec2 const& max, Color const& color):min_(min), max_(max), color_(color) {}
  float circumference() const { 
    return 2 * (max_.x_ - min_.x_ + max_.y_ + min_.y_);
  }

private:
  Vec2  min_{ 0.0,1.0 };
  Vec2  max_{ 1.0,0.0 };
  Color color_{ 0.5,0.5,0.5 };
};

# endif // RECTANGLE_HPP