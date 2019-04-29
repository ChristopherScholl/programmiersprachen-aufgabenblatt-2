#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.cpp"

//2.2
Vec2 a; // requires that 0.0 f == a.x and 0.0 f == a.y
Vec2 b{ 5.1f, -9.3f }; /* requires that 5.1 f == Approx (b.x)
and -9.3f == Approx (b.y)*/
Vec2 c{ 1.0f, 1.0f };
a += b;

TEST_CASE("describe_Vec2", "[Vec2]") {
  REQUIRE(a.x_ == 0.0f);
  REQUIRE(a.y_ == 0.0f);
  REQUIRE(b.x_ == Approx(5.1f));
  REQUIRE(b.y_ == Approx(-9.3f));
  REQUIRE(c.x_ == Approx(6.1f));
  REQUIRE(c.y_ == Approx(-8.3f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
