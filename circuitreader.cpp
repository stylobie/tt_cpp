#include "circuitreader.h"
#include "resistance.h"
#include <stdlib.h>


using namespace std;

void CircuitReader::read(istream &input, vector<Nports> &composants) {
    string line;
    while(getline(input, line)){
        if(line.empty()){
            break;
        }
        vector<string> tokens;
        tokenize(line, " ", tokens);
        if(tokens.empty()){
            continue;
        }
        string composantAndName = tokens[0];
        if(composantAndName[0] == 'R'){
            double r = atof(tokens[3].c_str());
            string name = composantAndName.length() > 1 ? composantAndName.substr(1,string::npos) : "";
            composants.push_back(Resistance(tokens[1],tokens[2], r, name));
        }
    }
}

void CircuitReader::tokenize(string line, string delimiter, vector<string> &tokens) {
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
