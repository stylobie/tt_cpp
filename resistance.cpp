#include "resistance.h"

Resistance::Resistance(string noeud1, string noeud2, double resistance, string name)
{
    this->name = name;
    this->connexions.push_back(noeud1);
    this->connexions.push_back(noeud2);
    this->type = "R";
    this->parameters.push_back(resistance);
    this->connextionsCount = 2;
}

double Resistance::getValue()
{
    double value = this->parameters[0];
    return value;
}