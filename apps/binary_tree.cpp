#include "grid.h"
#include "binary_tree.h"

#include <iostream>

int main()
{
  Grid g{ 8, 8 };
  binary_tree(g);
  std::cout << g << '\n';
}
