/**
 * @file test.cpp
 * @author your name (you@domain.com)
 * @brief test the program with unitary tests
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>

#include "circuit.h"
#include "circuitreader.h"
#include "doctest.h"
#include "ij.h"
#include "mat.h"
#include "mataij.h"
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

TEST_CASE("circuit reader") {
    CircuitReader cr;
    ifstream flux;
    flux.open("spice.txt");
    vector<Nports> composants;
    cr.read(flux, composants);
    // Circuit circ;
    // circ.read("spice.txt");
    CHECK(composants.size() == 6);
    Nports c0 = composants[0];
    CHECK(c0.getType() == "V");
    CHECK(c0.getName() == "s");
    Nports c1 = composants[1];
    CHECK(c1.getType() == "L");
    CHECK(c1.getName().empty());
}

void innerTest() { mat z(15, 15); }

TEST_CASE("mat") {
    mat x;
    CHECK(x.getRow() == 1);
    CHECK(x.getColumn() == 1);
    mat y(2, 5);
    CHECK(y.getRow() == 2);
    CHECK(y.getColumn() == 5);
    x = y;
    CHECK(x.getRow() == 2);
    CHECK(x.getColumn() == 5);
    innerTest();
    mat z = y;
    z = x.transpose();
    CHECK(z.getRow() == 5);
    CHECK(z.getColumn() == 2);
}

TEST_CASE("krylov") {
    MatAij<double> A(3, 3);
    vector<double> x;
    x.push_back(0);
    x.push_back(0);
    x.push_back(0);
    vector<double> b;
    b.push_back(4);
    b.push_back(-12);
    b.push_back(17);

    A.insert(0, 0, 2);
    A.insert(0, 1, -1);
    A.insert(0, 2, 0);

    A.insert(1, 0, -6);
    A.insert(1, 1, 5);
    A.insert(1, 2, -4);

    A.insert(2, 0, 3);
    A.insert(2, 1, 4);
    A.insert(2, 2, 0);
    // x should be 3 2 1
    vector<double> y;
    y = A.solve(b, x);
    CHECK(y[0] > 2.97);
    CHECK(y[0] < 3.03);
    CHECK(y[1] > 1.97);
    CHECK(y[1] < 2.03);
    CHECK(y[2] > 0.97);
    CHECK(y[2] < 1.03);
}
