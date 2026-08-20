#include <array>
#include <iostream>
#include <cmath>
#include "eigen-5.0.0/Eigen/Dense"

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

    float d = std::sqrt(std::pow(l_x - r_x, 2) + std::pow(l_y - r_y, 2));
    float b = std::atan( (l_y - r_y) / (l_x - r_x) );
    result[0] = d;
    result[1] = b;
    return result;
}

Eigen::Matrix <float, 3, 3> A(std::array <float, 3> mu, std::array <float, 2> u, float dt) {
    Eigen::Matrix <float, 3, 3> result;
    result.setIdentity();
    float v = u[0];
    float th = mu[2];
    result(0, 2) = -v * dt * std::sin(th);
    result(1, 2) = v * dt * std::cos(th);
    return result;
}

Eigen::Matrix <float, 2, 3> C(std::array <float, 3> mu, std::array <float, 2> l){
    Eigen::Matrix <float, 2, 3> result;
    result.setZero();
    float l_x = l[0];
    float l_y = l[1];
    float r_x = mu[0];
    float r_y = mu[1];

    std::cout << "l_x: " << l_x << std::endl;
    std::cout << "r_x: " << r_x << std::endl;
    
    // 0.5 super important here!! 1/2 returns 0 and 3/2 returns 1
    float dg1_dr_x = 0.5 * 1 / std::sqrt(std::pow(l_x - r_x, 2) + std::pow(l_y - r_y, 2)) * 2 * (l_x - r_x) * (-1);
    float dg1_dr_y = 0.5 * 1 / std::sqrt(std::pow(l_x - r_x, 2) + std::pow(l_y - r_y, 2)) * 2 * (l_y - r_y) * (-1);
    std::cout << "dg1_dr_x: " << dg1_dr_x << std::endl;
    std::cout << "dg1_dr_y: " << dg1_dr_y << std::endl;
    
    float dg2_dr_x = 1 / (1 + std::pow((l_y - r_y) / (l_x - r_x), 2)) * (l_y - r_y) / std::pow(l_x - r_x, 2);
    float dg2_dr_y = 1 / (1 + std::pow((l_y - r_y) / (l_x - r_x), 2)) * (-1 / (l_x - r_x));

    result(0,0) = dg1_dr_x;
    result(0, 1) = dg1_dr_y;
    result(1, 0) = dg2_dr_x;
    result(1, 1) = dg2_dr_y;

    return result;
}