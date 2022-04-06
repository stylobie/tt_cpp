/**
 * @file circuitReader.h
 * @author your name (you@domain.com)
 * @brief read the circuit spice txt
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef circuitreader_h
#define circuitreader_h
#include "nports.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CircuitReader
{
public:
    void read(istream &input, vector<Nports> &composants);

private:
    void tokenize(string line, string delimiter, vector<string> &tokens);
    void getName(string &token, string &name);
};
#endif /* circuitreader_h */
