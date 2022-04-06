/**
 * @file switch.h
 * @author your name (you@domain.com)
 * @brief the switch class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef switch_h
#define switch_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class Switch : public Nports {
   public:
    Switch(string node1, string node2, double onoff, string name);
    double getValue();

   private:
};
#endif /* switch_h */
