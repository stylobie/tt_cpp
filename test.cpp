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
#include <set>
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
    vector<int> connexions;
    connexions.push_back(1);
    connexions.push_back(2);
    string type = "V";
    string name = "s";
    Nports source(type, parameters, connexions, name);
    string actualName = source.getName();
    CHECK(actualName == name);  // should pass
}

TEST_CASE("initialisation resistance") {
    Resistance resistance = Resistance(3, 4, 77.0, "R");
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
    CHECK(c0.getName() == "v1");
    Nports c1 = composants[1];
    CHECK(c1.getType() == "L");
    CHECK(c1.getName()=="l1");
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

/**
 * @brief return 0 if set s1 == s2, 1 if not for a set of int
 *
 * @param s1
 * @param s2
 * @return int
 */
int compareSet(set<int> &s1, set<int> &s2) {
    if (s1.size() == s2.size()) {
        set<int>::iterator it1;
        set<int>::iterator it2;
        for (it1 = s1.begin(), it2 = s2.begin(); it1 == s1.end(); it1++, it2++) {
            if (*it1 != *it2) {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
}

/**
 * @brief return 0 if set s1 == s2, 1 if not for a set of string
 *
 * @param s1
 * @param s2
 * @return int
 */
int compareSet(set<string> &s1, set<string> &s2) {
    if (s1.size() == s2.size()) {
        set<string>::iterator it1;
        set<string>::iterator it2;
        for (it1 = s1.begin(), it2 = s2.begin(); it1 == s1.end(); it1++, it2++) {
            if (*it1 != *it2) {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
}

TEST_CASE("circuit") {
    Circuit c;
    c.read("spice.txt");
    set<int> nodes;
    c.fillNodes(nodes);
    set<int> expected;
    expected.insert(1);
    expected.insert(2);
    expected.insert(3);
    expected.insert(4);
    CHECK(compareSet(nodes, expected)==0);

    vector<Nports> componentsNode1;
    c.fillComponents(1, componentsNode1);
    CHECK(componentsNode1.size() == 4);
    cout<<componentsNode1.size()<<endl;
    set<string> names;
    names.insert("v1");
    names.insert("r2");
    names.insert("c1");
    names.insert("t1");
    set<string> actualNames;
    vector<Nports>::iterator it;
    for (it = componentsNode1.begin(); it != componentsNode1.end(); it++) {
        string name = (*it).getName();
        actualNames.insert(name);
    }
    CHECK(compareSet(names, actualNames)==0);
}
