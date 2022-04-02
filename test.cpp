//
//  test.cpp
//  TT_cpp
//
//  Created by admin on 22/03/2022.
//

#include <stdio.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "circuitreader.h"
#include "doctest.h"
#include "nports.h"
#include "resistance.h"

TEST_CASE("intialisation nports") {
    vector<double> parameters;
    parameters.push_back(5);
    parameters.push_back(50);
    parameters.push_back(0.001);
    vector<string> connexions;
    connexions.push_back("1");
    connexions.push_back("2");
    string type = "V";
    string name = "s";
    Nports source(type, parameters, connexions, name);
    string actualName = source.getName();
    CHECK(actualName == name);  // should pass
}

TEST_CASE("initialisation resistance") {
    Resistance resistance = Resistance("3", "4", 77.0, "R");
    string name = resistance.getName();
    CHECK(name == "R");
    double r = resistance.getValue();
    CHECK(r == 77.0);
}

TEST_CASE("circuit reader") {  // ne fonctionnera pas quand il y aura les autres
                               // composantes
    CircuitReader cr;
    ifstream flux;
    flux.open("spice.txt");
    vector<Nports> composants;
    cr.read(flux, composants);
    CHECK(composants.size() == 6);
    Nports c0 = composants[0];
    CHECK(c0.getType() == "V");
    CHECK(c0.getName() == "s");
    Nports c1 = composants[1];
    CHECK(c1.getType() == "L");
    CHECK(c1.getName().empty());
}