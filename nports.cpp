#include "nports.h"

Nports::Nports(){
    
}
Nports::Nports(string type, vector<complex<double>>& parameters, vector<string>& connexions, string name){
    this->type = type;
    this->parameters = parameters;
    this->connexions = connexions;
    this->name = name;
}

string Nports::getType(){
    return this->type;
}

vector<complex<double>> Nports::getParameters(){
    return this->parameters;
}

vector<string> Nports::getConnexions(){
    return this->connexions;
}

string Nports::getName(){
    return this->name;
}