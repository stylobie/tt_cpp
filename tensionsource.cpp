#include "tensionsource.h"

TensionSource::TensionSource(string noeud1, string noeud2, double ac,
                             double frequency, double dc, string name) {
    this->name = name;
    this->connexions.push_back(noeud1);
    this->connexions.push_back(noeud2);
    this->type = "V";
    this->parameters.push_back(ac);
    this->parameters.push_back(frequency);
    this->parameters.push_back(dc);
    this->connextionsCount = 2;
}

double TensionSource::getAC() {
    double value = this->parameters[0];
    return value;
}

double TensionSource::getDC() {
    double value = this->parameters[2];
    return value;
}

double TensionSource::getFrequency() {
    double value = this->parameters[1];
    return value;
}
