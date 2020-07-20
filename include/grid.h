#pragma once

#include "cell.h"

#include <ostream>

struct Grid
{
  int rows, cols;
  std::vector<Cell> cells;

  Grid(int rows, int cols);

  void prepare_grid();
  void configure_cells();

  long int size() const;
  Cell &get_cell(int row, int col);
  Cell &random_cell();
};

std::ostream &operator<<(std::ostream &os, Grid g);
