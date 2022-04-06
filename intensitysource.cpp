/**
 * @file intensitysource.cpp
 * @author your name (you@domain.com)
 * @brief intensity source class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "intensitysource.h"

/**
 * @brief Construct a new Intensity Source:: Intensity Source object
 * 
 * @param node1 
 * @param node2 
 * @param ac 
 * @param frequency 
 * @param dc 
 * @param name 
 */
IntensitySource::IntensitySource(string node1, string node2, double ac,
                             double frequency, double dc, string name) {
    this->name = name;
    this->connexions.push_back(node1);
    this->connexions.push_back(node2);
    this->type = "I";
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
double IntensitySource::getAC() {
    double value = this->parameters[0];
    return value;
}

/**
 * @brief rethrn the value of the DC
 * 
 * @return double 
 */
double IntensitySource::getDC() {
    double value = this->parameters[2];
    return value;
}

/**
 * @brief return the value of the frequency
 * 
 * @return double 
 */
double IntensitySource::getFrequency() {
    double value = this->parameters[1];
    return value;
}
