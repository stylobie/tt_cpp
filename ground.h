/**
 * @file ground.h
 * @author your name (you@domain.com)
 * @brief the ground class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ground_h
#define ground_h
#include "nports.h"
#include <string>

using namespace std;

class Ground : public Nports
{
public:
    Ground(int node1, string name);

private:
};
#endif /* ground_h */
