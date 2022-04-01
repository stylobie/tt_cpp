#ifndef nports_h
#define nports_h
#include <string>
#include <complex>
#include <vector>

using namespace std;

class Nports {
public:
    Nports(string type, vector<complex<double>>& parameters, vector<string>& connexions, string name);
    string getType();
    vector<complex<double>> getParameters();
    vector<string> getConnexions();
    string getName();
protected: 
    Nports();
    string type;
    vector<complex<double>> parameters;
    vector<string> connexions;
    string name;
private:
    
};
#endif /* nports_h */
