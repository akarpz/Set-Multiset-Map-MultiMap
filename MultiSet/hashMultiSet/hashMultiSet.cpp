#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include "hashMultiSet.h"

using namespace std;


hashMultiSet::hashMultiSet(){
    for (int i = 0; i < tableSize; i++){
        hashTable[i] = new item; //each pointer points to a new item dont forget a delete
        hashTable[i]->key = "empty"; //default value
    }
}

void hashMultiSet::insert(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
                
            } if(i == index && loops == 1){
                cout << "Hash map full" << endl;
                break;
                
            } if(hashTable[index]->key == key){
                hashTable[i]->count++;
                break;
                
            } if(hashTable[i]->key == "empty"){
                hashTable[i]->key = key;
                hashTable[i]->count++;
                break;
            }
                
        }
}

    
bool hashMultiSet::isIn(string key){
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

unsigned long hashMultiSet::count(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
            }
            
            if(i == index && loops == 1){
                cout << "count is 0" << endl;
                return 0;
            }
            
            if (hashTable[i]->key == key){
                cout << "count is " << hashTable[i]->count<<endl;;
                return hashTable[i]->count;
            }
            
        }
        return 0;
}

void hashMultiSet::removeOne(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
                
            } if(i == index && loops == 1){
                cout << "not in hash multi set" << endl;
                break;
                
            } if (hashTable[i]->key == key){
                hashTable[i]->count--;
                break;
            }
            
        }
}

void hashMultiSet::removeAll(string key){
    int index = hash(key);
    
        int loops = 0;
        for (int i = index;; i++){
            if(i == tableSize){
                i = 0;
                loops = 1;
                
            } if(i == index && loops == 1){
                cout << "Hash Map Full" << endl;
                break;
                
            } if (hashTable[i]->key == key){
                hashTable[i]->count = 0;
                hashTable[i]->key = "empty";
                break;
            }
            
        }
}

bool hashMultiSet::isEmpty(){
    
    for (int i = 0; i < tableSize; i++){
        if (hashTable[i]->key != "empty"){
            return false;
        }
    }
    
    return true;
}

void hashMultiSet::printTable(){
   
}


string hashMultiSet::draw_random(){
    int random;
    srand(time(NULL));
    random  = rand()%tableSize;
    
    while(hashTable[random]->key == "empty"){
        random  = rand()%tableSize;
    }
    
    return hashTable[random]->key;
    
}


//hash function we can do a different one
int hashMultiSet::hash(string key){
    
    int hash = 0;
    int index;
   
    for (int i = 0; i < key.length(); i++){
        hash = hash + (int)key[i];
        
    }
    
    index  = hash%tableSize;
    
   // cout << "hash = " << hash << endl;
    
    return index;
    
}

void hashMultiSet::Test(){
    
    //int index;
    hashMultiSet hashObj;
    
    //isempty test
    if (hashObj.isEmpty()){
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    
    
    hashObj.insert("Andy");
    hashObj.insert("CISC220 rox");
    hashObj.insert("Cats r cute");
    
    //is in test
    if (hashObj.isIn("Andy")){
        cout << "key is in hashmultiset" << endl;
    } else{
        cout << "not in hashmultiset" << endl;
    }
    
    hashObj.insert("Andy");
    
    //isempty test 2
    if (hashObj.isEmpty()){
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    
   //isin test 2
    if (hashObj.isIn("Dog")){
        cout << "key is in hashmultiset" << endl;
    } else{
        cout << "not in hashmultiset" << endl;
    }

    hashObj.insert("Andy");
    
    //count test
    hashObj.count("Andy");//3 Andys
    
    //removeOne test
    hashObj.removeOne("CISC220 rox");
    
    //count test 2
    hashObj.count("CISC220 rox");
    
    //removeall test
    hashObj.removeAll("Andy");
    
    //count test 3
    hashObj.count("Andy");

}
