#include <iostream>
#include <array>
#include "helpers.h"
#include "eigen-5.0.0/Eigen/Dense"


int main() {
    std::cout << "Hello, World! \n";
    std::array <float, 3> mu = {0, 0, 0};
    std::array <float, 2> u = {3.3, 0.0};
    mu = f(mu, u, 0.1);
    std::cout << "main function ran successfully \n";
    std::cout << "The new position of the robot is: \n";
    std::cout << "x: " << mu[0] << "\ny: " << mu[1] << "\nth: " << mu[2] << "\n";

    mu = {0.0, 0.0, 0.0};
    u = {3.0, 0};
    std::array <float, 2> r_and_b = g(mu, {3.0, 4.0});
    std::cout << "The previous range and bearing are: \n";
    std::cout << "Range: " << r_and_b[0] << "\n" << "Bearing: " << r_and_b[1] << "\n";

    mu = f(mu, u, 1.0);
    r_and_b = g(mu, {3.0, 4.0});
    std::cout << "The NEW range and bearing are: \n";
    std::cout << "Range: " << r_and_b[0] << "\n" << "Bearing: " << r_and_b[1] << "\n";

    std::array <std::array <float, 3>, 3> my_array = {{{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}}};
    std::cout << "first element of first row?... " << my_array[0][0] << std::endl;

    mu = {0.0, 0.0, 0.0};
    u = {1.0, 0.0};
    Eigen::Matrix <float, 3, 3> my_A;
    my_A.setZero();
    std::cout << my_A << std::endl;

    my_A = A(mu, u, 1.0);
    std::cout << "The Jacobian calculated was: \n";
    std::cout << my_A << std::endl;
    return 0;
}