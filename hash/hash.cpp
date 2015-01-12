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
#include <cassert>

hash::hash() {
    for (int i = 0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}

void hash::AddItem(std::string name, std::string drink) {
    int index = Hash(name);
    
    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        
        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        
        Ptr->next = n;
    }
        
}

int hash::NumberOfItemsInIndex(int index) {
    int count = 0;
    
    if (HashTable[index]->name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        
        while (Ptr->next != NULL)
        {
            count ++;
            Ptr = Ptr->next;
        }
    }
    
    return count;
}

void hash::PrintTable() {
    int number;
    
    std::cout << "Max tablesize = " << tableSize << std::endl;
    
    for (int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        std::cout << "---------------\n";
        std::cout << "index = " << i << std::endl;
        std::cout << HashTable[i]->name << std::endl;
        std::cout << HashTable[i]->drink << std::endl;
        std::cout << "# of items = " << number << std::endl;
        std::cout << "---------------\n";
    }
}

void hash::PrintItemsInIndex(int index) {
    
    assert(index < tableSize && index >= 0); // Remove? Change into if then? Hmmm
    
    item* Ptr = HashTable[index];
    
    if (Ptr->name == "empty")
    {
        std::cout << "Bucket " << index << " is empty";
    }
    else
    {
        std::cout << "Bucket " << index << " contains:" << std::endl;
        
        while(Ptr != NULL) {
            std::cout << "---------------\n";
            std::cout << Ptr->name << std::endl;
            std::cout << Ptr->drink << std::endl;
            std::cout << "---------------\n";
            Ptr = Ptr->next;
        }
    }
}

void hash::FindDrink(std::string name) {
    int index = Hash(name);
    bool foundName = false;
    std::string drink;
    
    item* Ptr = HashTable[index];
    while(Ptr != NULL)
    {
        if (Ptr->name == name) {
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    
    if (foundName)
    {
        std::cout << "Favorite Drink = " << drink << std::endl;
    }
    else
    {
        std::cout << name << "'s info was not found in the hash table\n" << std::endl;
    }
}

void hash::RemoveItem(std::string name) {
    int index = Hash(name);
    
    item* delPtr;
    item* P1;
    item* P2;
    
    if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
    {
        std::cout << name << " was not found in the hash table\n";
    }
    else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        
        std::cout << name << " was removed from the hash table\n";
    }
    else if (HashTable[index]->name == name)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;
        
        std::cout << name << " was removed from the hash table\n";
    }
    
    // Bucket contains items but first item is not a match
    else
    {
        P1 = HashTable[index]->next;
        P2 = HashTable[index];
        
        while (P1 != NULL && P1->name != name)
        {
            P2 = P1;
            P1 = P1->next;
        }
        
        // No match was found
        if(P1 == NULL)
        {
            std::cout << name << " was not found in the hash table\n";
        }
        
        // Match is found
        else
        {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;
            
            delete delPtr;
            std::cout << name << " was removed from the hash table\n";
        }
    }
}

int hash::Hash(std::string key) {
    int hash = 0;
    
    for (int i = 0; i < key.length(); i++) {
        hash = hash + (int)key[i];
    }
    
    return hash % tableSize;
};