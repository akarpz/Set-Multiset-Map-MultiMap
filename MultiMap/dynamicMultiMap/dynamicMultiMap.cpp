#include <string>
#include <cstdlib>
#include <iostream>
#include "dynamicMultiMap.h"
using namespace std;


//The MultiMap acts just like the Map but allows inserting many values for each key. So you can have many values saved under the same key.

//The functions you should implement:

// void Map::set(string key, int value)
// void Map::removeAll(string key)
// int Map::count(string key)
// int* Map::getAll(string key)



dynamicMultiMap::dynamicMultiMap(){
    Map = new dynamicArray<dynamicArray <int> >();
    
}

dynamicMultiMap::~dynamicMultiMap(){
    delete Map;
}

void dynamicMultiMap::extend(int value, int index){
    Map->array[index].add(value);
    return;
}
    
int dynamicMultiMap::isIn(string check){
    for(int k = 0; k < Map->currentIndex; k++){
        if(check == Map->array[k].key){
            return k;
        }
    }
    return -1;
}

void dynamicMultiMap::set(string key, int value){
    if(isIn(key) != -1){
        extend(value,isIn(key));
    }
    else{
        dynamicArray<int>* New = new dynamicArray<int>();
        New->key = key;
        New->add(value);
        Map->add(*New);
    }
}

void dynamicMultiMap::printAll(){
    for(int i = 0; i < Map->currentIndex ; i++){
        Map->array[i].printAll();
    }
}

void dynamicMultiMap::removeAll(string key){
    for(int i=0 ; i < Map->currentIndex ; i++){
        if(Map->array[i].key == key){
            Map->array[i] = *(new dynamicArray<int>());
        }
    }
}

int dynamicMultiMap::count(string key){
    for(int i=0 ; i < Map->currentIndex ; i++){
        if(Map->array[i].key == key){
            return Map->array[i].currentIndex;
        }
    }
}
int* dynamicMultiMap::getAll(string key){
    for(int i=0 ; i < Map->currentIndex ; i++){
        if(Map->array[i].key == key){
            int* temp = new int[Map->array[i].currentIndex];
            for(int j=0; j<Map->array[i].currentIndex ; j++){
                temp[j] = Map->array[i].array[j];
            }
            return temp;
        }
    }
}

void dynamicMultiMap::Test(){

    dynamicMultiMap* dMultiMap = new dynamicMultiMap();
    
    dMultiMap->set("test", 1);
    dMultiMap->set("test", 2);
    dMultiMap->set("Test", 3);
    dMultiMap->set("Test", 4);
    dMultiMap->set("Test", 3);
    dMultiMap->set("test", 4);
    dMultiMap->set("test", 5);
    dMultiMap->set("Test", 7);
    dMultiMap->printAll();
    cout << "Count of test, 4 = " << dMultiMap->count("test") << endl;
    cout << endl;
    dMultiMap->removeAll("Test");
    cout << "Should be no Test "<<endl;
    dMultiMap->printAll();
    int* lst = dMultiMap->getAll("test");
    
    delete dMultiMap;

}

    

