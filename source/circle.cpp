#include "circle.hpp"
#include "vec2.hpp"
#include "vec2.cpp"
#include "mat2.hpp"
#include "mat2.cpp"

float Circle2::circumference() const {
  return 2 * 3.14159265359* radius_;
}

void Circle2::draw(Window const& win)const {
  Vec2 o;
  Vec2 r{ 0.0,radius_ };
  o += mid_;
  o += r;
  float piece = circumference() / 360;
  Mat2 rotate = make_rotation_mat2(3);//0.01745329251

  win.draw_line(o.x_, o.y_, o.x_ + piece, o.y_, color_.r_, color_.g_, color_.b_, 1.0);
  
  o = o + (rotate* o);

  win.draw_line(o.x_, o.y_, o.x_ + piece, o.y_, 0.0, 0.0, 0.0, 1.0);
}

void Circle2::draw(Window const& win, float t)const {
  win.draw_line(mid_.x_, mid_.y_, mid_.x_, mid_.y_, color_.r_, color_.g_, color_.b_, t);

}
