#include "catch2/catch.hpp"
#include "grid.h"

using namespace Catch::literals;
// using namespace Mazes;

TEST_CASE("Grid should work")
{
  Grid g{ 4, 4 };

  SECTION("Grid initialization should work")
  {
    REQUIRE(g.rows == 4);
    REQUIRE(g.cols == 4);
    REQUIRE(g.size() == 16);
  }

  SECTION("Grid left bottom corner should work")
  {
    auto c = g.get_cell(0, 0);
    REQUIRE(c.pos == coord(0, 0));
    REQUIRE(c.neighbors[0] == coord(1, 0));
    REQUIRE_FALSE(c.neighbors[1].has_value());
    REQUIRE(c.neighbors[2] == coord(0, 1));
    REQUIRE_FALSE(c.neighbors[3].has_value());
  }

  SECTION("Grid right bottom should work")
  {
    auto c = g.get_cell(0, 3);
    REQUIRE(c.pos == coord(0, 3));
    REQUIRE(c.neighbors[0] == coord(1, 3));
    REQUIRE_FALSE(c.neighbors[1].has_value());
    REQUIRE_FALSE(c.neighbors[2].has_value());
    REQUIRE(c.neighbors[3] == coord(0, 2));
  }

  SECTION("Grid left top corner should work")
  {
    auto c = g.get_cell(3, 0);
    REQUIRE(c.pos == coord(3, 0));
    REQUIRE_FALSE(c.neighbors[0].has_value());
    REQUIRE(c.neighbors[1] == coord(2, 0));
    REQUIRE(c.neighbors[2] == coord(3, 1));
    REQUIRE_FALSE(c.neighbors[3].has_value());
  }

  SECTION("Grid right top should work")
  {
    auto c = g.get_cell(3, 3);
    REQUIRE(c.pos == coord(3, 3));
    REQUIRE_FALSE(c.neighbors[0].has_value());
    REQUIRE(c.neighbors[1] == coord(2, 3));
    REQUIRE_FALSE(c.neighbors[2].has_value());
    REQUIRE(c.neighbors[3] == coord(3, 2));
  }
}
