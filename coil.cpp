#include "coil.h"

Coil::Coil(string noeud1, string noeud2, double inductance, string name) {
    this->name = name;
    this->connexions.push_back(noeud1);
    this->connexions.push_back(noeud2);
    this->type = "L";
    this->parameters.push_back(inductance);
    this->connextionsCount = 2;
}

double Coil::getValue() {
    double value = this->parameters[0];
    return value;
}