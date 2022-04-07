/**
 * @file ground.cpp
 * @author your name (you@domain.com)
 * @brief the ground class
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ground.h"

/**
 * @brief Construct a new Ground:: Ground object
 * 
 * @param node1 only one node because it's the ground
 * @param name 
 */
Ground::Ground(int node1, string name) {
    this->name = name;
    this->connexions.push_back(node1);
    this->type = "T";
    this->connextionsCount = 1;
}