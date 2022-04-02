#include "capacitor.h"

Capacitor::Capacitor(string noeud1, string noeud2, double capacitance,
                     string name) {
    this->name = name;
    this->connexions.push_back(noeud1);
    this->connexions.push_back(noeud2);
    this->type = "C";
    this->parameters.push_back(capacitance);
    this->connextionsCount = 2;
}

double Capacitor::getValue() {
    double value = this->parameters[0];
    return value;
}