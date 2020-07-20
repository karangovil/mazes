#pragma once

#include <random>
#include <chrono>

std::default_random_engine dre(std::chrono::steady_clock::now().time_since_epoch().count());// provide seed

inline int random(int lim)
{
  std::uniform_int_distribution<int> uid{ 0, lim };// help dre to generate nos from 0 to lim (lim included);
  return uid(dre);// pass dre as an argument to uid to generate the random no
}
