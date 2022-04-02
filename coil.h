#ifndef coil_h
#define coil_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class Coil : public Nports {
   public:
    Coil(string noeud1, string noeud2, double inductance, string name);
    double getValue();

   private:
};
#endif /* coil_h */
