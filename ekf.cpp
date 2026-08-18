#include <iostream>
#include <array>
#include "helpers.h"


int main() {
    std::cout << "Hello, World!";
    std::array <float, 3> mu = {0, 0, 0};
    std::array<float, 2> u = {3.3, 5.2};
    mu = f(mu, u, 0.1);
    std::cout << "main function ran successfully";
    return 0;
}