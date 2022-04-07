/**
 * @file capacitor.h
 * @author your name 
 * @brief .h of the capacitor
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef capacitor_h
#define capacitor_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class Capacitor : public Nports {
   public:
    Capacitor(int node1, int node2, double capacitance, string name);
    double getValue();

   private:
};
#endif /* capacitor_h */