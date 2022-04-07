/**
 * @file circuit.h
 * @author your name (you@domain.com)
 * @brief class of the circuit
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef circuit_h
#define circuit_h
#include <complex>
#include <string>
#include <vector>
#include <set>
#include "nports.h"

using namespace std;


class Circuit {
   public:
    Circuit();
    void read(string spiceFileName);
    void clear();
    void fillNodes(set<string> &node); 
    void fillComponents(string node,vector<Nports> &nodeComponents);

   private:
    vector<Nports> components;
};
#endif /* circuit_h */
