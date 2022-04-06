/**
 * @file currentsource.h
 * @author your name (you@domain.com)
 * @brief intensity source class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef currentsource_h
#define currentsource_h
#include <complex>
#include <string>
#include <vector>

#include "nports.h"

using namespace std;

class CurrentSource : public Nports {
   public:
    CurrentSource(string node1, string node2, double ac, double frequency,
                  double dc, string name);
    double getAC();
    double getFrequency();
    double getDC();

   private:
};
#endif /* currentsource_h */
