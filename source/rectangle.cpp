#include "rectangle.hpp"

//Rectangle2(Vec2 const& min, Vec2 const& max, Color const& color) :min_(min), max_(max), color_(color) {}
float Rectangle2::circumference() const {
  return 2 * (max_.x_ - min_.x_ + max_.y_ + min_.y_);
}
