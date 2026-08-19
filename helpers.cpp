#include <array>
#include <iostream>
#include <cmath>

std::array <float, 3> f(std::array <float, 3> mu, std::array <float, 2> u, float dt) {
    std::array <float, 3> result = {0.0, 0.0, 0.0};
    result[0] = mu[0] + dt * u[0] * std::cos(mu[2]); //angles are in rad already. no need to convert
    result[1] = mu[1] + dt * u[0] * std::sin(mu[2]);
    result[2] = mu[2] + dt * u[1];

    return result;
}

std::array <float, 2> g(std::array <float, 3> mu, std::array <float, 2> l) {
    std::array <float, 2> result = {0.0, 0.0};
    float l_x = l[0];
    float l_y = l[1];
    float r_x = mu[0];
    float r_y = mu[1];

    float d = sqrt(pow(l_x - r_x, 2) + pow(l_y - r_y, 2));
    float b = atan( (l_y - r_y) / (l_x - r_x) );
    result[0] = d;
    result[1] = b;
    return result;
}

