#ifndef circuitreader_h
#define circuitreader_h
#include "nports.h"
#include <vector>
#include <string>
#include <iostream>



using namespace std;

class CircuitReader {
public:
    void read(istream &input, vector<Nports> &composants);
private:
    void tokenize(string line, string delimiter, vector<string> &tokens);
};
#endif /* circuitreader_h */
