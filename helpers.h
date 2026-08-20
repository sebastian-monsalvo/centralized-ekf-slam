#pragma once
#include <array>
#include <cmath>
#include "eigen-5.0.0/Eigen/Dense"

std::array <float, 3> f(std::array <float, 3> mu, std::array <float, 2> u, float dt);

std::array <float, 2> g(std::array <float, 3> mu, std::array <float, 2> l);

Eigen::Matrix <float, 3, 3> A(std::array <float, 3> mu, std::array <float, 2> u, float dt);