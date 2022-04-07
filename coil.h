/**
 * @file coil.h
 * @author your name (you@domain.com)
 * @brief the coil class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef coil_h
#define coil_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class Coil : public Nports {
   public:
    Coil(int node1, int node2, double inductance, string name);
    double getValue();

   private:
};
#endif /* coil_h */
