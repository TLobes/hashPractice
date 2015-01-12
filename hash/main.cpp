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

void createData(hash myHash) {
    myHash.AddItem("Tim", "Jack & Coke");
    myHash.AddItem("Annie", "Boba");
    myHash.AddItem("Reza", "Muscle Milk");
    myHash.AddItem("Haris", "Hot Tea");
    myHash.AddItem("Ryan", "Ice Water");
    myHash.AddItem("Eddie", "Not Sure");
    myHash.AddItem("Calin", "Soylent");
    myHash.AddItem("Robyn", "Pearl Tea");
    myHash.AddItem("The Doc", "Pepper");
    myHash.AddItem("Tapper", "Root Beer");
    myHash.AddItem("Phil", "Coffee");
}

void searchData(hash myHash) {
    std::string name;
    
    while (name != "exit")
    {
        std::cout << "Search for ";
        std::cin >> name;
        if(name != "exit")
        {
            myHash.FindDrink(name);
        }
    }
}

void removeItem(hash myHash) {
    std::string name;
    
    while (name != "exit")
    {
        std::cout << "Remove item ";
        std::cin >> name;
        if(name != "exit")
        {
            myHash.RemoveItem(name);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    hash myHash;
    
    createData(myHash);
    myHash.PrintItemsInIndex(2);
    //searchData(myHash);
    removeItem(myHash);
    
    
    
    //myHash.PrintTable();
    
    myHash.PrintItemsInIndex(2);

    return 0;
}
