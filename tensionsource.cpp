/**
 * @file tensionsource.cpp
 * @author your name (you@domain.com)
 * @brief tension source class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "tensionsource.h"

TensionSource::TensionSource(int node1, int node2, double ac,
                             double frequency, double dc, string name) {
    this->name = name;
    this->connexions.push_back(node1);
    this->connexions.push_back(node2);
    this->type = "V";
    this->parameters.push_back(ac);
    this->parameters.push_back(frequency);
    this->parameters.push_back(dc);
    this->connextionsCount = 2;
}

/**
 * @brief return the value of the AC
 * 
 * @return double 
 */
double TensionSource::getAC() {
    double value = this->parameters[0];
    return value;
}

/**
 * @brief return the value of the DC
 * 
 * @return double 
 */
double TensionSource::getDC() {
    double value = this->parameters[2];
    return value;
}

/**
 * @brief return the value of the frequency
 * 
 * @return double 
 */
double TensionSource::getFrequency() {
    double value = this->parameters[1];
    return value;
}
