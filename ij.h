
#ifndef IJ_H_
#define IJ_H_
#include <iostream>
using namespace std;

class ij {
   public:
    // constructeurs et destructeur :

    ij(int = 0, int = 0);  // construteur par defaut
    virtual ~ij();         // destructeur
    ij(const ij &other);   // constructeur par copie

    // surcharge de l'operateur =
    ij &operator=(const ij &other);  // surcharge de l'opérateur =, bien mettre "&"
    bool operator==(const ij &other) const;
    friend inline bool operator<(const ij &ij1, const ij &ij2);  // surcharge de la fonction amie
    int geti() const;
    int getj() const;
    ij swap();                                              // méthode swap pour changer les lignes en colonnes et vice versa
    friend std::ostream &operator<<(std::ostream &, ij &);  // surcharge de l'operateur <<
   private:
    int i;
    int j;
};

inline bool operator<(const ij &ij1, const ij &ij2) {
    if (ij1.i < ij2.i) {
        return 1;
    } else {
        if (ij1.i == ij2.i) {
            if (ij1.j < ij2.j) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}

#endif /* IJ_H_ */
