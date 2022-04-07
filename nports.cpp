/**
 * @file nports.cpp
 * @author your name
 * @brief implement the .h functions of Nports
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "nports.h"
#include <set>
using namespace std;
/**
 * @brief Construct a new Nports:: Nports object
 *
 */
Nports::Nports() {}
/**
 * @brief Construct a new Nports:: Nports object
 *
 * @param type "T", "R", "L" etc depending of the type of the component
 * @param parameters a vector of parameters such as the inductance for the coil
 * @param connexions number of connexions of a port. 2 for a resistance for
 * example
 * @param name the specific name of a port for example "s" for "Vs"
 */

Nports::Nports(string type, vector<double> &parameters, vector<int> &connexions, string name) {
    this->type = type;
    this->parameters = parameters;
    this->connexions = connexions;
    this->name = name;
}

/**
 * @brief return the type of the port
 *
 * @return string
 */
string Nports::getType() { return this->type; }

/**
 * @brief return the parameters of the port
 *
 * @return vector<double>
 */
vector<double> Nports::getParameters() { return this->parameters; }

/**
 * @brief return the vector with the numbers of the connexions
 *
 * @return vector<int>
 */
vector<int> Nports::getConnexions() { return this->connexions; }

/**
 * @brief return the name of the port
 *
 * @return string
 */
string Nports::getName() { return this->name; }

/**
 * @brief return the count of the connexions
 *
 * @return int
 */
int Nports::getConnexionsCount() { return this->connextionsCount; }

/**
 * @brief fill distinct nodes into a set
 * 
 * @param nodes 
 */
void Nports::fillNodes(set<int> &nodes) {
    vector<int>::iterator it;
    for (it = connexions.begin(); it != connexions.end(); it++) {
        nodes.insert(*it);
    }
}