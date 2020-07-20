#include "catch2/catch.hpp"
#include "cell.h"

using namespace Catch::literals;
// using namespace Mazes;

TEST_CASE("Cell should work")
{
  Cell c1 {{1, 2}};
  REQUIRE(c1.pos.first == 1);
  REQUIRE(c1.pos.second == 2);
  REQUIRE_FALSE(c1.neighbors[0].has_value());
  REQUIRE_FALSE(c1.neighbors[1].has_value());
  REQUIRE_FALSE(c1.neighbors[2].has_value());
  REQUIRE_FALSE(c1.neighbors[3].has_value());

  Cell c2 {{3,4}};
  c1.link(c2);
  REQUIRE(c1.links[0] == c2.pos);
  REQUIRE(c2.links[0] == c1.pos);
  REQUIRE(c1.is_linked(c2) == true);
  REQUIRE(c2.is_linked(c1) == true);

  c1.neighbors[0] = c2.pos;
  REQUIRE(c1.neighbors[0].value() == c2.pos);

  Cell c3 {{5,6}};
  c1.link(c3);
  c1.unlink(c2);
  REQUIRE_FALSE(c1.is_linked(c2));
  REQUIRE_FALSE(c2.is_linked(c1));
}
