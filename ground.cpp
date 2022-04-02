#include "ground.h"

Ground::Ground(string noeud1, string name) {
    this->name = name;
    this->connexions.push_back(noeud1);
    this->type = "T";
    this->connextionsCount = 1;
}
