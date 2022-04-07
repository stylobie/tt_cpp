
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

#include "circuit.h"
#include "circuitreader.h"
#include "mat.h"
//#include "mataij.h"
#include "nports.h"
#include "resistance.h"
#include "ij.h"
#include "x.h"
using namespace std;

void retourneStringComposante() {  // print pour l'instant pour test
    ifstream flux;
    flux.open("spice.txt");
    string ligne;
    getline(flux, ligne);
    cout << ligne;
}

void test() {
    string line = "Vs 1 2 5 50 0.001";
    string delimiter = " ";
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = line.find(delimiter)) != string::npos) {
        string token = line.substr(0, pos);
        tokens.push_back(token);
        cout << token << endl;
        line.erase(0, pos + delimiter.length());
    }
}
template class MatAij<double>;
void test2() {
    
    MatAij<double> A(1,1);

}

int main() {
    //test();
    test2();
    return 0;
}
