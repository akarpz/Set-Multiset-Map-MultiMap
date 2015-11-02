#include <cstdlib>
#include <iostream>
#include <string>
#include "hashMap.h"

using namespace std;

/*
void Map::set(string key, int value)
void Map::remove(string key)
int Map::get(string key)
int& Map::operator[](string key)
*/

hashMap::hashMap(){
    for (int i = 0; i < tableSize; i++){
        hashTable[i] = new item; //each pointer points to a new item
        hashTable[i]->key = "empty"; //default value
    }
}

void hashMap::printTable(){
    int numInBucket;
    
    for (int i = 0; i < tableSize; i++){
        if(hashTable[i]->key != "empty"){
        cout << hashTable[i]->key << ": "<< hashTable[i]->value << endl;
        }
    }
}

void hashMap::set(string key, int newValue){
    int index = hash(key);
    
    if (hashTable[index]->key == "empty"){ //checks for default, overwrites
        hashTable[index]->key = key;
        hashTable[index]->value = newValue;
        
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
            if(hashTable[index]->key == key){
                hashTable[index]->value = newValue;
                break;
            }
            if(hashTable[i]->key == "empty"){
                hashTable[i]->key = key;
                hashTable[i]->value = newValue;
                break;
            }
        }
    }
}

//hash function we can do a different one
int hashMap::hash(string key){
    
    int hash = 0;
    int index;
   
    for (int i = 0; i < key.length(); i++){
        hash = hash + (int)key[i];
    }
    
    index  = hash%tableSize;
    
    return index;
    
}

void hashMap::removeHash(string key){
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
        if(hashTable[i]->key == key){
            hashTable[i]->key = "empty";
            break;
        }
    }
}

int hashMap::get(string key){
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
        if(hashTable[i]->key == key){
            return hashTable[i]->value;
        }
    }
}
int& hashMap::operator[](string key){
    int answer = get(key);
    int& returner = answer;
    return returner;
}

void hashMap::Test(){
    hashMap A;
    hashMap B;
    
    A.set("Dog", 1);
    A.set("Cat", 2);
    A.set("Bird", 3);
    
    cout << "should be 1: ";
    cout << A.get("Dog");
    cout <<endl<< "should be 1: ";
    cout <<A["Dog"];
    A.removeHash("Cat");
    
    
}