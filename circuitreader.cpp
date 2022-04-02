#include "circuitreader.h"

#include <stdlib.h>

#include "capacitor.h"
#include "coil.h"
#include "ground.h"
#include "resistance.h"
#include "tensionsource.h"

using namespace std;

void CircuitReader::read(istream &input, vector<Nports> &composants) {
    string line;
    while (getline(input, line)) {
        if (line.empty()) {
            break;
        }
        vector<string> tokens;
        tokenize(line, " ", tokens);
        if (tokens.empty()) {
            continue;
        }
        string composantAndName = tokens[0];
        char type = composantAndName[0];
        string name;
        switch (type) {
            case 'R': {
                double r = atof(tokens[3].c_str());
                getName(composantAndName, name);
                composants.push_back(Resistance(tokens[1], tokens[2], r, name));
                break;
            }
            case 'L': {
                double l = atof(tokens[3].c_str());
                getName(composantAndName, name);
                composants.push_back(Coil(tokens[1], tokens[2], l, name));
                break;
            }
            case 'C': {
                double c = atof(tokens[3].c_str());
                getName(composantAndName, name);
                composants.push_back(Capacitor(tokens[1], tokens[2], c, name));
                break;
            }
            case 'V': {
                double ac = atof(tokens[3].c_str());
                double frequency = atof(tokens[4].c_str());
                double dc = atof(tokens[5].c_str());
                getName(composantAndName, name);
                composants.push_back(TensionSource(tokens[1], tokens[2], ac,
                                                   frequency, dc, name));
                break;
            }
            case 'T': {
                getName(composantAndName, name);
                composants.push_back(Ground(tokens[1], name));
                break;
            }
            default:
                break;
        }
    }
}

void CircuitReader::tokenize(string line, string delimiter,
                             vector<string> &tokens) {
    size_t pos;
    while (line.length() > 0) {
        pos = line.find(delimiter);
        string token;
        if (pos == string::npos) {
            token = line;
        } else {
            token = line.substr(0, pos);
        }
        tokens.push_back(token);
        line.erase(0, pos + delimiter.length());
        if (pos == string::npos) {
            break;
        }
    }
}

void CircuitReader::getName(string &token, string &name) {
    name = token.length() > 1 ? token.substr(1, string::npos) : "";
}