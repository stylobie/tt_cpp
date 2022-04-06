/**
 * @file circuit.cpp
 * @author your name
 * @brief the circuit
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <fstream>
#include "circuit.h"
#include "circuitreader.h"

using namespace std;

/**
 * @brief read a a file
 * 
 * @param spiceFileName 
 */
void Circuit::read(string spiceFileName){
    CircuitReader cr;
    ifstream flux;
    flux.open(spiceFileName);
    cr.read(flux, components);
}

/**
 * @brief delete the circuit
 * 
 */
void Circuit::clear(){
    components.clear();
}