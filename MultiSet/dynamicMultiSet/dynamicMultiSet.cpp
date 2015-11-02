#include "dynamicMultiSet.h"
//#include "../../baseStructures/multiSetHelp/multiSetHelp.h"
#include <cstdlib>
#include <iostream>

template <typename T>
dynamicMultiSet<T>::dynamicMultiSet(){
    data = new dynamicArray<multiSetHelp<T> >();
    //multiSetHelp has a key of type T and a num attribute that is an int
}
template <typename T>
dynamicMultiSet<T>::~dynamicMultiSet(){
    cout << "Data deleted " << endl;
    delete data;
}
template <typename T>
int dynamicMultiSet<T>::find(T key){
    for(int i=0 ; i<data->currentIndex ; i++){
        if(key==data->array[i].key){
            return i;
        }
    }
}
template <typename T>
bool dynamicMultiSet<T>::isIn(T key){
    for(int i=0 ; i<data->currentIndex ; i++){
        if(key==data->array[i].key){
            return true;
        }
    }
    return false;
}
template <typename T>
void dynamicMultiSet<T>::insert(T key){
    if(!isIn(key)){
        multiSetHelp<T> *temp;
        temp = new multiSetHelp<T>(key);
        data->add(*temp);
        delete temp;
    }
    else{
        data->array[find(key)].num ++;
    }
}
template <typename T>
void dynamicMultiSet<T>::removeAll(T key){
    for(int i=0 ; i<data->currentIndex ; i++){
        if(key==data->array[i].key){
            data->removeVal(i);
        }
    }
}
template <typename T>
void dynamicMultiSet<T>::removeOne(T key){
    for(int i=0 ; i<data->currentIndex ; i++){
        if(key==data->array[i].key){
            data->array[i].num--;
        }
    }
}
template <typename T>
bool dynamicMultiSet<T>::isEmpty(){
    if(data->currentIndex==0){
        return true;
    }
    else{
        return false;
    }
}
template <typename T>
unsigned long dynamicMultiSet<T>::count(T key){
    if(isIn(key)){
        return data->array[find(key)].num;
    }
    else{
        return 0;
    }
}
template <typename T>
void dynamicMultiSet<T>::printAll(){
    for(int i=0 ; i<data->currentIndex ; i++){
        cout << data->array[i].key << " has: " << count(data->array[i].key) << endl;
    }
}
template <typename T>
void dynamicMultiSet<T>::Test(){
    dynamicMultiSet<string>* test;
    test = new dynamicMultiSet<string>();
    test->insert("one");
    test->insert("one");
    test->insert("one");
    
    
    test->insert("two");
    test->insert("two");
    
    test->insert("one");
    test->insert("three");
    test->insert("four");
    
    test->printAll();
    
    delete test;
}
        