//
//  helloworld.cpp
//  TT_cpp
//
//  Created by admin on 22/03/2022.
//

#include <stdio.h>
#include "helloworld.h"

string Helloworld::sayHello(){
    return "Hello world";
}

string Helloworld::sayHello(string& name){
        string resultat = "Hello " + name;
        return resultat;
}
