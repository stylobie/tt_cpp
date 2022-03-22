//
//  test.cpp
//  TT_cpp
//
//  Created by admin on 22/03/2022.
//

#include <stdio.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "helloworld.h"

TEST_CASE("Helloworld sayHello") {
    Helloworld h;
    string actual = h.sayHello();
    string expected = "Hello world";
    CHECK(actual == expected); // should pass
}

TEST_CASE("Helloworld sayHello with name") {
    Helloworld h;
    string name = "macron";
    string actual = h.sayHello(name);
    string expected = "Hello macron";
    CHECK(actual == expected); // should pass
}
