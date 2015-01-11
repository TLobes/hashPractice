//
//  main.cpp
//  hash
//
//  Created by Tim Lobes on 1/11/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include <iostream>
#include <string>

#include "hash.h"

int main(int argc, const char * argv[]) {
    
    int index;
    hash hashObj;
    
    index = hashObj.Hash("Tim");
    
    std::cout << "index = " << index << std::endl;
    
    return 0;
}
