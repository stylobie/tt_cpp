/**
 * @file resistance.h
 * @author your name (you@domain.com)
 * @brief resistance class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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
    Resistance(int node1, int node2, double resistance, string name);
    double getValue();

private:
};
#endif /* resistance_h */
