//
//  test.cpp
//  TT_cpp
//
//  Created by admin on 22/03/2022.
//

#include <stdio.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "nports.h"

TEST_CASE("intialisation nports") {
    vector<complex<double>> parameters;
    parameters.push_back(5);
    parameters.push_back(50);
    parameters.push_back(0.001);
    vector<string> connexions;
    connexions.push_back("1");
    connexions.push_back("2");
    string type = "V";
    string name = "s";
    Nports source(type , parameters, connexions, name);
    string actualName = source.getName();
    CHECK(actualName == name); // should pass
}
