#include <iostream>
#include <array>
#include "helpers.h"


int main() {
    std::cout << "Hello, World! \n";
    std::array <float, 3> mu = {0, 0, 0};
    std::array <float, 2> u = {3.3, 0.0};
    mu = f(mu, u, 0.1);
    std::cout << "main function ran successfully \n";
    std::cout << "The new position of the robot is: \n";
    std::cout << "x: " << mu[0] << "\ny: " << mu[1] << "\nth: " << mu[2];
    return 0;
}