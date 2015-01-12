//
//  hash.h
//  hash
//
//  Created by Tim Lobes on 1/11/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#ifndef HASH_H
#define HASH_H

#include <string>

class hash {
    
private:
    static const int tableSize = 10;
    
    struct item{
        std::string name;
        std::string drink;
        item* next;
    };
    
    item* HashTable[tableSize];
    
public:
    hash();
    int Hash(std::string key);
    void AddItem(std::string name, std::string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
};

#endif
