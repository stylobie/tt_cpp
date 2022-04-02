#ifndef tensionsource_h
#define tensionsource_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class TensionSource : public Nports {
   public:
    TensionSource(string noeud1, string noeud2, double ac, double frequency,
                  double dc, string name);
    double getAC();
    double getFrequency();
    double getDC();

   private:
};
#endif /* tensionsource_h */
