/**
 * @file nports.h
 * @author your name
 * @brief Create the Nports class, the mother class of the components
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef nports_h
#define nports_h
#include <complex>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Nports {
   public:
    Nports(string type, vector<double> &parameters, vector<int> &connexions,
           string name);
    string getType();
    vector<double> getParameters();
    vector<int> getConnexions();
    string getName();
    int getConnexionsCount();
    void fillNodes(set<int> &nodes);

   protected:
    Nports();
    string type;
    vector<double> parameters;
    vector<int> connexions;
    string name;
    int connextionsCount = 0;

   private:
};
#endif /* nports_h */
