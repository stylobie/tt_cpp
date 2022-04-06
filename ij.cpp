
#include "ij.h"
using namespace std;

ij::ij(int i, int j) {  // constructeur par défaut
    this->i = i;
    this->j = j;
}

ij::~ij() {  // destructeur
}

ij::ij(const ij& other) {  // constructeur par copie
    this->i = other.i;
    this->j = other.j;
}

ij& ij::operator=(const ij& other) {  // surcharge de l'operateur =
    this->i = other.i;
    this->j = other.j;
    return (*this);  // tjrs mettre "return (*this)" dans le constructeur par copie
}

int ij::geti() { return this->i; }
int ij::getj() { return this->j; }

ij ij::swap() {  // code de la méthode swap
    ij I;
    I.i = this->j;
    I.j = this->i;  // car on veut trasposer
    return I;
}

bool ij::operator==(const ij& other) const {  // const doit empecher la méthode de modifier l'objet
    if ((this->i == other.i) && (this->j == other.j)) {
        return 1;
    }
    return 0;
}

std::ostream& operator<<(std::ostream& sortie, ij& I) {
    sortie << "(" << I.i << "," << I.j << ")";
    return sortie;
}