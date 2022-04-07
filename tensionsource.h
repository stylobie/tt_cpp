/**
 * @file tensionsource.h
 * @author your name (you@domain.com)
 * @brief tension source class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef tensionsource_h
#define tensionsource_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class TensionSource : public Nports {
   public:
    TensionSource(int node1, int node2, double ac, double frequency,
                  double dc, string name);
    double getAC();
    double getFrequency();
    double getDC();

   private:
};
#endif /* tensionsource_h */
