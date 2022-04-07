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
#include "circuit.h"

#include <fstream>

#include "circuitreader.h"
#include "nports.h"

using namespace std;
/**
 * @brief Construct a new Circuit:: Circuit object
 *
 */
Circuit::Circuit() {}

/**
 * @brief read a a file
 *
 * @param spiceFileName
 */
void Circuit::read(string spiceFileName) {
    CircuitReader cr;
    ifstream flux;
    flux.open(spiceFileName);
    cr.read(flux, components);
}

/**
 * @brief delete the circuit
 *
 */
void Circuit::clear() { components.clear(); }

/**
 * @brief fill distinct the nodes into a set
 *
 * @param nodes
 */
void Circuit::fillNodes(set<string> &nodes) {
    typename vector<Nports>::iterator it;
    for (it = components.begin(); it != components.end(); it++) {
        Nports component = *it;
        component.fillNodes(nodes);
    }
}

/**
 * @brief fill the components that are connected to the node node
 * 
 * @param node 
 * @param nodeComponents 
 */
void Circuit::fillComponents(string node,vector<Nports> &nodeComponents){
    typename vector<Nports>::iterator componentIt;
    for (componentIt = components.begin(); componentIt != components.end(); componentIt++) {
        Nports component = *componentIt;
        vector<string> componentConnexion = component.getConnexions();
        vector<string>::iterator connexionIt;
        for (connexionIt = componentConnexion.begin(); connexionIt != componentConnexion.end(); connexionIt++){
            string connexion = *connexionIt;
            if(node ==  connexion){
                nodeComponents.push_back(component);
            }
        }
    }
}

