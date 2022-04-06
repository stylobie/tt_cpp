//
//  main.cpp
//  TT_cpp
//
//  Created by admin on 16/03/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void retourneStringComposante() { //print pour l'instant pour test
    ifstream flux;
    flux.open("spice.txt");
    string ligne;
    getline(flux,ligne);
    cout<<ligne;
}

void test(){
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

int main()
{
    test();
    return 0;
}

