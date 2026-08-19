#pragma once
#include <array>
#include <cmath>

std::array <float, 3> f(std::array <float, 3> mu, std::array <float, 2> u, float dt);

std::array <float, 2> g(std::array <float, 3> mu, std::array <float, 2> l);