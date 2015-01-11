//
//  hash.cpp
//  hash
//
//  Created by Tim Lobes on 1/11/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include "hash.h"
#include <iostream>
#include <string>

hash::hash() {
    tableSize = 100;
}

int hash::Hash(std::string key) {
    int hash = 0;
    //int index;
    
    for (int i = 0; i < key.length(); i++) {
        hash = hash + (int)key[i];
        std::cout << "hash = " << hash << std::endl;
    }
    
    return hash % tableSize;
};