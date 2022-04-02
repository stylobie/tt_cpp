#ifndef resistance_h
#define resistance_h
#include "nports.h"
#include <string>
#include <complex>
#include <vector>

using namespace std;

class Resistance : public Nports
{
public:
    Resistance(string noeud1, string noeud2, double resistance, string name);
    double getValue();

private:
};
#endif /* resistance_h */
