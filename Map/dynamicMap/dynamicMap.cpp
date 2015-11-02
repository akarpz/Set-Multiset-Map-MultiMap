#include "dynamicMap.h"
#include <cstdlib>
#include <iostream>

using namespace std;

mapHelp::mapHelp(){
  key = "";
  num = 0;
}

    
dynamicMap::dynamicMap(){
    data = new dynamicArray<mapHelp>();
    //mapHelp has a key of type string and a num attribute that is an int
}
dynamicMap::~dynamicMap(){
    cout << "Data deleted " << endl;
    delete data;
}

void dynamicMap::set(string key, int value){
    mapHelp temp;
    temp.key = key;
    temp.num = value;
    for(int i=0 ; i < data->currentIndex ; i++){
        if(data->array[i].key == key){
            data->array[i] = temp;
            return;
        }
    }
    data->add(temp);
}

void dynamicMap::remove(string key){
    for(int i=0 ; i < data->currentIndex ; i++){
        if(data->array[i].key == key){
            data->array[i].key = "d3LEt3D!";
        }
    }
}

int dynamicMap::get(string key){
    for(int i=0 ; i < data->currentIndex ; i++){
        if(data->array[i].key == key){
            return data->array[i].num;
        }
    }
}

int& dynamicMap::operator[](string key){
    int answer = get(key);
    int& returner = answer;
    return returner;
}

void dynamicMap::printAll(){
    for(int i=0 ; i < data->currentIndex ; i++){
        if(data->array[i].key != "d3LEt3D!"){
            cout << "Key is: " << data->array[i].key << " Data is: " << data->array[i].num << endl;
        }
    }
}

void dynamicMap::Test(){
    dynamicMap* test;
    test = new dynamicMap();
    cout << "Add 1,2,3 as 'one', 'two', 'three'" << endl;
    test->set("one",1);
    test->set("two",2);
    test->set("three",3);
    test->printAll();
    
    cout << "Remove 'one'" << endl;
    test->remove("one");
    test->printAll();
    
    cout << "print what 'two' is" << endl;
    //cout << test["two"] << endl;
    cout << test->get("two") << endl;
    
    cout << "Set 'two' to 20" << endl;
    test->set("two", 20);
    test->printAll();
    
    delete test;
}

        