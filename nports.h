#ifndef nports_h
#define nports_h
#include <complex>
#include <string>
#include <vector>

using namespace std;

class Nports {
   public:
    Nports(string type, vector<double> &parameters, vector<string> &connexions,
           string name);
    string getType();
    vector<double> getParameters();
    vector<string> getConnexions();
    string getName();
    int getConnexionsCount();

   protected:
    Nports();
    string type;
    vector<double> parameters;
    vector<string> connexions;
    string name;
    int connextionsCount = 0;

   private:
};
#endif /* nports_h */
