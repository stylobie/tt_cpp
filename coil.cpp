/**
 * @file coil.cpp
 * @author your name (you@domain.com)
 * @brief the coil class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "coil.h"

/**
 * @brief Construct a new Coil:: Coil object
 * 
 * @param node1 
 * @param node2 
 * @param inductance 
 * @param name 
 */
Coil::Coil(string node1, string node2, double inductance, string name) {
    this->name = name;
    this->connexions.push_back(node1);
    this->connexions.push_back(node2);
    this->type = "L";
    this->parameters.push_back(inductance);
    this->connextionsCount = 2;
}

/**
 * @brief return the value of the inductance
 * 
 * @return double 
 */
double Coil::getValue() {
    double value = this->parameters[0];
    return value;
}