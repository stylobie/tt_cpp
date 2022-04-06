/**
 * @file switch.cpp
 * @author your name (you@domain.com)
 * @brief the switch class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "switch.h"

/**
 * @brief Construct a new Switch:: Switch object
 * 
 * @param node1 
 * @param node2 
 * @param onoff 
 * @param name 
 */
Switch::Switch(string node1, string node2, double onoff, string name) {
    this->name = name;
    this->connexions.push_back(node1);
    this->connexions.push_back(node2);
    this->type = "L";
    this->parameters.push_back(onoff);
    this->connextionsCount = 2;
}

/**
 * @brief return the value of the onoff (0 or 1)
 * 
 * @return double 
 */
double Switch::getValue() {
    double value = this->parameters[0];
    return value;
}