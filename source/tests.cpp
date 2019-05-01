#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("describe_Vec2", "[Vec2]") {
  //2.2
  Vec2 a;
  REQUIRE(a.x_ == 0.0f);
  REQUIRE(a.y_ == 0.0f);

  Vec2 b{ 5.1f, -9.3f };
  REQUIRE(b.x_ == Approx(5.1f));
  REQUIRE(b.y_ == Approx(-9.3f));
  
  Vec2 c{ 1.0f, 1.0f };
  c += b;
  REQUIRE(c.x_ == Approx(6.1f));
  REQUIRE(c.y_ == Approx(-8.3f));

  c -= b;
  REQUIRE(c.x_ == Approx(1.0f));
  REQUIRE(c.y_ == Approx(1.0f));

  c *= 5;
  REQUIRE(c.x_ == Approx(5.0f));
  REQUIRE(c.y_ == Approx(5.0f));

  c /= 5;
  REQUIRE(c.x_ == Approx(1.0f));
  REQUIRE(c.y_ == Approx(1.0f));

  c /= 0;
  REQUIRE(c.x_ == Approx(1.0f));
  REQUIRE(c.y_ == Approx(1.0f));

  //2.3
  Vec2 d = b + c;
  REQUIRE(d.x_ == Approx(6.1f));
  REQUIRE(d.y_ == Approx(-8.3f));

  d = b - c;
  REQUIRE(d.x_ == Approx(4.1f));
  REQUIRE(d.y_ == Approx(-10.3f));

  d = 5 * c;
  REQUIRE(d.x_ == Approx(5.0f));
  REQUIRE(d.y_ == Approx(5.0f));

  d = c * 5;
  REQUIRE(d.x_ == Approx(5.0f));
  REQUIRE(d.y_ == Approx(5.0f));

  d = c / 5;
  REQUIRE(d.x_ == Approx(0.2f));
  REQUIRE(d.y_ == Approx(0.2f));
  
  d = c / 0;
  REQUIRE(d.x_ == Approx(1.0f));
  REQUIRE(d.y_ == Approx(1.0f));
}

TEST_CASE("describe_Mat2", "[Mat2]") {
  //2.5
  Mat2 a;
  REQUIRE(a.e_00 == 1.0f);
  REQUIRE(a.e_10 == 0.0f);
  REQUIRE(a.e_01 == 0.0f);
  REQUIRE(a.e_11 == 1.0f);

  Mat2 b{ 1.0,2.0,3.0,4.0 };
  a *= b;
  REQUIRE(a.e_00 == 1.0f);
  REQUIRE(a.e_10 == 2.0f);
  REQUIRE(a.e_01 == 3.0f);
  REQUIRE(a.e_11 == 4.0f);

  Mat2 c = { 2.0,2.0,2.0,2.0 };
  c *= b;
  REQUIRE(c.e_00 == 8.0f);
  REQUIRE(c.e_10 == 12.0f);
  REQUIRE(c.e_01 == 8.0f);
  REQUIRE(c.e_11 == 12.0f);

  Mat2 d = a * c;
  REQUIRE(d.e_00 == 24.0f);
  REQUIRE(d.e_10 == 36.0f);
  REQUIRE(d.e_01 == 56.0f);
  REQUIRE(d.e_11 == 84.0f);

  d = c * a;
  REQUIRE(d.e_00 == 44.0f);
  REQUIRE(d.e_10 == 64.0f);
  REQUIRE(d.e_01 == 44.0f);
  REQUIRE(d.e_11 == 64.0f);
}

TEST_CASE("describe_2.6", "[2.6]") {
  Mat2 a;
  Mat2 b{ 1.0,2.0,3.0,4.0 };
  Vec2 c;
  Vec2 d{ 2.0,3.0 };

  Vec2 e = a * c;
  REQUIRE(e.x_ == 0.0f);
  REQUIRE(e.y_ == 0.0f);
  e = b * d;
  REQUIRE(e.x_ == 8.0f);
  REQUIRE(e.y_ == 18.0f);
  e = d * b;
  REQUIRE(e.x_ == 11.0f);
  REQUIRE(e.y_ == 16.0f);

  a = transpose(b);
  REQUIRE(a.e_00 == 1.0f);
  REQUIRE(a.e_10 == 3.0f);
  REQUIRE(a.e_01 == 2.0f);
  REQUIRE(a.e_11 == 4.0f);

  a = inverse(b);
  REQUIRE(a.e_00 == Approx((4.0f)/(-10.0f)));
  REQUIRE(a.e_10 == Approx((-2.0f) / (-10.0f)));
  REQUIRE(a.e_01 == Approx((-3.0f) / (-10.0f)));
  REQUIRE(a.e_11 == Approx((1.0f) / (-10.0f)));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
