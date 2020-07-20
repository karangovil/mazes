#include "cell.h"

#include <algorithm>

Cell::Cell(loc_t p)
  : pos{ p },
    neighbors{ std::nullopt }
{}

void Cell::link(Cell &c, bool bidi)
{
  if (auto it = std::find(links.begin(), links.end(), c.pos); it == links.end()) {
    links.emplace_back(c.pos);
    if (bidi) { c.link(*this, false); }
  }
}

void Cell::unlink(Cell &c, bool bidi)
{
  if (auto it = std::find(links.begin(), links.end(), c.pos); it != links.end()) {
    links.erase(it);
    if (bidi) { c.unlink(*this, false); }
  }
}

bool Cell::is_linked(Cell const &c) const
{
  auto it = std::find(links.begin(), links.end(), c.pos);
  return it != links.end();
}
