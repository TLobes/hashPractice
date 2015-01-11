//
//  hash.h
//  hash
//
//  Created by Tim Lobes on 1/11/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#ifndef __hash__hash__
#define __hash__hash__

#include <string>

class hash {
    
private:
    int tableSize;
    
public:
    hash();
    int Hash(std::string key);
};

#endif /* defined(__hash__hash__) */
