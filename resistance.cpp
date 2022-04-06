/**
 * @file resistance.cpp
 * @author your name (you@domain.com)
 * @brief the resistance class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "resistance.h"

Resistance::Resistance(string node1, string node2, double resistance, string name)
{
    this->name = name;
    this->connexions.push_back(node1);
    this->connexions.push_back(node2);
    this->type = "R";
    this->parameters.push_back(resistance);
    this->connextionsCount = 2;
}

/**
 * @brief return the value of the resistance
 * 
 * @return double 
 */
double Resistance::getValue()
{
    double value = this->parameters[0];
    return value;
}