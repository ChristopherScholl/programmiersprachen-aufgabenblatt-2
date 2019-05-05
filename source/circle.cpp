#include "circle.hpp"
#include "vec2.hpp"
#include "vec2.cpp"
#include "mat2.hpp"
#include "mat2.cpp"

#include <cmath>

float Circle2::circumference() const {
  return 2 * 3.14159265359* radius_;
}

bool Circle2::is_inside(Vec2 v) const {
  v -= mid_;
  if (sqrt(pow(v.x_, 2) + pow(v.y_, 2)) > radius_) {
    return false;
  }
  else {
    return true;
  }
}

void Circle2::draw(Window const& win)const {
  Vec2 start;
  Vec2 rad{ 0.0,-radius_ };
  start += mid_;
  start += rad;

  for (int i = 0; i < 360; i++) {
    float stox = (radius_ / 50.0) * cos(6.28318530718 / 360 * i) + start.x_;
    float stoy = (radius_ / 50.0) * sin(6.28318530718 / 360 * i) + start.y_;
    Vec2 stop{ stox,stoy };
    win.draw_line(start.x_, start.y_, stop.x_, stop.y_, color_.r_, color_.g_, color_.b_, 1.0);
    start = stop;
  }
}

void Circle2::draw(Window const& win, float t)const {
  Vec2 start;
  Vec2 rad{ 0.0,-radius_ };
  start += mid_;
  start += rad;

  for (int i = 0; i < 360; i++) {
    float stox = (radius_ / 50.0) * cos(6.28318530718 / 360 * i) + start.x_;
    float stoy = (radius_ / 50.0) * sin(6.28318530718 / 360 * i) + start.y_;
    Vec2 stop{ stox,stoy };
    win.draw_line(start.x_, start.y_, stop.x_, stop.y_, color_.r_, color_.g_, color_.b_, t);
    start = stop;
  }
}
