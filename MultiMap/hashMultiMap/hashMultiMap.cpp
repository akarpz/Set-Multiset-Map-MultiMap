#include <cstdlib>
#include <iostream>
#include <string>
#include "hashMultiMap.h"
using namespace std;



hashMultiMap::hashMultiMap(){
    for (int i = 0; i < tableSize; i++){
        hashTable[i].add(new item); //each pointer points to a new item
        hashTable[i].array[0]->key = "empty"; //default value
    }
}

void hashMultiMap::printTable(){
    for (int i = 0; i < tableSize; i++){
        if(hashTable[i].array[0]->key != "empty"){
            for(int j = 0; j < hashTable[i].currentIndex;j++){
                cout << hashTable[i].array[j]->key << ": "<< hashTable[i].array[j]->value << endl;
            }
        
        }
    }
}

void hashMultiMap::set(string key, int newValue){
    int index = hash(key);
    
    if (hashTable[index].array[0]->key == "empty"){ //checks for default, overwrites
        hashTable[index].array[0]->key = key;
        hashTable[index].array[0]->value = newValue;
    }
    else{
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
            }
            if(i == index && loops == 1){
                cout << "Hash map full" << endl;
                break;
            }
            if(hashTable[i].array[0]->key == key){
                hashTable[i].add(new item);
                hashTable[i].array[hashTable[i].currentIndex - 1]->key = key;
                hashTable[i].array[hashTable[i].currentIndex - 1]->value = newValue;
                break;
            }
            if(hashTable[i].array[0]->key == "empty"){
                hashTable[i].add(new item);
                hashTable[i].array[0]->key = key;
                hashTable[i].array[0]->value = newValue;
                break;
            }
        }
    }
}


int hashMultiMap::hash(string key){
    
    int hash = 0;
    int index;
   
    for (int i = 0; i < key.length(); i++){
        hash = hash + (int)key[i];
    }
    
    index  = hash%tableSize;
    
    return index;
    
}

void hashMultiMap::removeAll(string key){
    int index = hash(key);
    int loops = 0;
    for (int i = index;; i++){
        if(i == tableSize){
            i = 0;
            loops = 1;
        }
        if(i == index && loops == 1){
            cout << "Hash map full" << endl;
            break;
        }
        if(hashTable[i].array[0]->key == key){
            hashTable[i] = *(new dynamicArray<item*>);
            hashTable[i].add(new item);
            hashTable[i].array[0]->key = "empty";
            break;
        }
    }
}


int hashMultiMap::count(string key){
    int index = hash(key);
    int loops = 0;
    for (int i = index;; i++){
        if(i == tableSize){
            i = 0;
            loops = 1;
        }
        if(i == index && loops == 1){
            cout << "Key not found" << endl;
            break;
        }
        if(hashTable[i].array[0]->key == key){
            return hashTable[i].currentIndex;
        }
    }
}

int* hashMultiMap::getAll(string key){
    int index = hash(key);
    int loops = 0;

    for (int i = index;; i++){
        if(i == tableSize){
            i = 0;
            loops = 1;
        }
        if(i == index && loops == 1){
            cout << "Key not found" << endl;
            return 0;
        }
        if(hashTable[i].array[0]->key == key){
            int* ints = new int[hashTable[i].currentIndex];
            for(int j = 0; j < hashTable[i].currentIndex; j++){
                ints[j] = hashTable[i].array[j]->value;
            }
                return ints;
        }
    }
}

void hashMultiMap::Test(){
    hashMultiMap* hashObj = new hashMultiMap(); 
    hashObj->set("A", 1);
    hashObj->set("A", 3);
    hashObj->set("Andy is cool", 2);
    
    cout << hashObj->count("A")<< endl;
    
    hashObj->printTable();
    hashObj->removeAll("A");
    delete hashObj;
}



