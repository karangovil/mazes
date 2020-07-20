#include "grid.h"
#include "random.h"

#include <ctime>
#include <cstdlib>

Grid::Grid(int r, int c)
  : rows{ r }, cols{ c }
{
  cells.reserve(rows * cols);
  prepare_grid();
  configure_cells();
}

void Grid::prepare_grid()
{
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      cells.emplace_back(Cell{ { r, c } });
    }
  }
}

void Grid::configure_cells()
{
  for (auto &c : cells) {
    auto row = c.pos.first;
    auto col = c.pos.second;
    if (row < rows - 1)
      c.neighbors[0] = { { row + 1, col } };
    if (row > 0)
      c.neighbors[1] = { { row - 1, col } };
    if (col < cols - 1)
      c.neighbors[2] = { { row, col + 1 } };
    if (col > 0)
      c.neighbors[3] = { { row, col - 1 } };
  }
}

long int Grid::size() const
{
  return rows * cols;
}

Cell &Grid::get_cell(int row, int col)
{
  return cells[row * cols + col];
}

Cell &Grid::random_cell()
{
  int row = random(rows - 1);
  int col = random(cols - 1);
  return get_cell(row, col);
}

std::ostream &operator<<(std::ostream &os, Grid g)
{
  os << "+";
  for (int i = 0; i < g.cols; ++i)
    os << "---+";
  os << '\n';
  auto top = '|';
  auto bottom = '+';
  for (int r = g.rows - 1; r >= 0; --r) {
    os << top;
    for (int c = 0; c < g.cols - 1; ++c) {
      os << "   ";
      const Cell cell = g.get_cell(r, c);
      auto east = cell.neighbors[2];
      if (east.has_value()) {
        if (!cell.is_linked(Cell{ east.value() }))
          os << top;
        else
          os << " ";
      }
    }
    os << "   " << top;
    os << '\n';
    os << bottom;

    for (int c = 0; c < g.cols; ++c) {
      const Cell cell = g.get_cell(r, c);
      auto south = cell.neighbors[1];
      if (south.has_value()) {
        if (cell.is_linked(Cell{ south.value() })) {
          os << "   ";
        }
        else {
          os << "---";
        }
      }
      else {
        os << "---";
      }
      os << bottom;
    }
    os << '\n';
  }

  return os;
}
