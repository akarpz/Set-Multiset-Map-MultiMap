#include <cstdlib>
#include <iostream>
#include <string>
#include "hashSet.h"


using namespace std;


hashSet::hashSet(){
    for (int i = 0; i < tableSize; i++){
        hashTable[i] = new item; //each pointer points to a new item dont forget a delete
        hashTable[i]->key = "empty"; //default value
    }
}

void hashSet::insert(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
                
            } if(i == index && loops == 1){
                cout << "insert full" << endl;
                break;
                
            }if(hashTable[index]->key == key){
                break;
                
            } if(hashTable[i]->key == "empty"){
                hashTable[i]->key = key;
                break;
            }
                
        }
            
}


bool hashSet::isIn(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
                
            } if(i == index && loops == 1){
                return false;
                
            } if(hashTable[index]->key == key){
                return true;
            }
        } 
    
}


void hashSet::removeKey(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
                
            } if(i == index && loops == 1){
                cout << "remove full" << endl;
                break;
                
            } if (hashTable[i]->key == key){
                hashTable[i]->key = "empty";
                break;
            }
            
        }
}

bool hashSet::isEmpty(){
    for (int i = 0; i < tableSize; i++){
        if (hashTable[i]->key != "empty"){
            return false;
        }
        
    }
    return true;
}

void hashSet::printTable(){
  for (int i = 0; i < tableSize; i++){
        if (hashTable[i]->key != "empty"){
            cout << hashTable[i]->key<< endl;
        }
        
    }
}


int hashSet::hash(string key){
    
    int hash = 0;
    int index;
   
    for (int i = 0; i < key.length(); i++){
        hash = hash + (int)key[i];
    }
    
    index  = hash%tableSize;
    
    return index;
    
}

hashSet hashSet::Union(hashSet otherSet){
    hashSet newHashSet;
    
    for (int i = 0; i < tableSize; i++){
        if(hashTable[i]->key != "empty"){
            newHashSet.insert(hashTable[i]->key);
        }
        if(otherSet.hashTable[i]->key != "empty"){
            newHashSet.insert(otherSet.hashTable[i]->key);
        }
    }
    
    return newHashSet;
}

hashSet hashSet::Intersection(hashSet otherSet){
    hashSet newHashSet;
    
    for (int i = 0; i < tableSize; i++){
        if (isIn(otherSet.hashTable[i]->key)){
            newHashSet.insert(otherSet.hashTable[i]->key);
        }
    }
    
    return newHashSet;

}

void hashSet::Test(){

    hashSet A;
    hashSet B;
    hashSet C;
    
    A.insert("Baby");
    B.insert("Baby");
    C.insert("Not Baby");
    cout << "intersection of A and B is Baby: ";
    A.Intersection(B).printTable();
    cout << "intersection of A and C is Not Baby, Baby: ";
    A.Union(C).printTable();
    cout << "A pre: "; A.printTable();
    if(A.isIn("Baby")){
        cout << "baby is in A"<< endl;
    }
    A.removeKey("Baby");
    cout << "A after: "; A.printTable();
    if(!A.isIn("Baby")){
        cout << "baby is not A"<< endl;
    }
    
}

