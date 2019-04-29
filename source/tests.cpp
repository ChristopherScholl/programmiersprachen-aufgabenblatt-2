#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
