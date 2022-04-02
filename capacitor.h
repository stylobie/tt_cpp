#ifndef capacitor_h
#define capacitor_h
#include "nports.h"
#include <string>
#include <complex>
#include <vector>

using namespace std;

class Capacitor : public Nports
{
public:
    Capacitor(string noeud1, string noeud2, double capacitance, string name);
    double getValue();

private:
};
#endif /* capacitor_h */
