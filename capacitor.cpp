/**
 * @file capacitor.cpp
 * @author your name 
 * @brief .cpp of the capacitor class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "capacitor.h"

/**
 * @brief Construct a new Capacitor:: Capacitor object
 * 
 * @param node1 the first node
 * @param node2 the second node
 * @param capacitance the capacitance of the capacitor
 * @param name the name of the capacitor
 */
Capacitor::Capacitor(int node1, int node2, double capacitance,
                     string name) {
    this->name = name;
    this->connexions.push_back(node1);
    this->connexions.push_back(node2);
    this->type = "C";
    this->parameters.push_back(capacitance);
    this->connextionsCount = 2;
}

/**
 * @brief return the value of the capacitance
 * 
 * @return double 
 */
double Capacitor::getValue() {
    double value = this->parameters[0];
    return value;
}