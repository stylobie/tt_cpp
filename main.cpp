//
//  main.cpp
//  TT_cpp
//
//  Created by admin on 16/03/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include "helloworld.h"

using namespace std;

void retourneStringComposante() { //print pour l'instant pour test
    ifstream flux;
    flux.open("spice.txt");
    string ligne;
    getline(flux,ligne);
    cout<<ligne;
}




int main()
{
    retourneStringComposante();
    
    return 0;
}
