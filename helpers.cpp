#include <array>
#include <iostream>
#include <cmath>

std::array <float, 3> f(std::array <float, 3> mu, std::array <float, 2> u, float dt) {
    std::array <float, 3> result = {0, 0, 0};
    result[0] = mu[0] + dt * u[0] * std::cos(mu[2]); //angles are in rad already. no need to convert
    result[1] = mu[1] + dt * u[0] * std::sin(mu[2]);
    result[2] = mu[2] + dt * u[1];

    return result;
}

int main(){
    std::array <float, 3> mu = {0, 0, 0};
    std::array<float, 2> u = {3.3, 5.2};
    mu = f(mu, u, 0.1);
    std::cout << "x changed to: " << mu[0] << "\n";
    std::cout << "the angular velocity is: " << u[1];
    return 0;
}

std::array <float, 3> mu = {0.0, 0.0, 0.0};
std::array <float, 2> u = {0.0, 0.0};

