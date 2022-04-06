/**
 * @file intensitysource.h
 * @author your name (you@domain.com)
 * @brief intensity source class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef intensitysource_h
#define intensitysource_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class IntensitySource : public Nports {
   public:
    IntensitySource(string node1, string node2, double ac, double frequency,
                  double dc, string name);
    double getAC();
    double getFrequency();
    double getDC();

   private:
};
#endif /* intensitysource_h */
