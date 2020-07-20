#pragma once

#include "grid.h"
#include "cell.h"
#include "random.h"

inline void binary_tree(Grid &grid)
{
  int index;
  std::vector<Cell *> nbrs;
  for (auto &c : grid.cells) {
    nbrs.clear();
    if (auto north = c.neighbors[0]; north.has_value())
      nbrs.emplace_back(&grid.get_cell(north.value().first, north.value().second));
    if (auto east = c.neighbors[2]; east.has_value())
      nbrs.emplace_back(&grid.get_cell(east.value().first, east.value().second));

    if (nbrs.size()) {
      index = random(nbrs.size() - 1);
      c.link(*nbrs[index]);
    }
  }
}
