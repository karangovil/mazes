#pragma once

#include <cstdint>
#include <utility>
#include <optional>
#include <vector>
#include <array>

using loc_t = std::pair<int, int>;
using loc_o_t = std::optional<loc_t>;

inline auto coord(int const &row, int const &col)
{
  return std::make_pair(row, col);
}

struct Cell
{
  loc_t pos;
  std::vector<loc_t> links;
  std::array<loc_o_t, 4> neighbors;

  Cell(loc_t pos);

  void link(Cell &cell, bool bidi = true);
  void unlink(Cell &cell, bool bidi = true);

  bool is_linked(Cell const &cell) const;
};
