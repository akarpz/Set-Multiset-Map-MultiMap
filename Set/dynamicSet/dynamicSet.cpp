#include "dynamicSet.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
dynamicSet<T>::dynamicSet(){
    data = new dynamicArray<T>();
};
template <typename T>
dynamicSet<T>::~dynamicSet(){
    cout << "Data deleted " << endl;
    delete data;
};
template <typename T>
bool dynamicSet<T>::isIn(T key){
    for(int i=0 ; i<data->currentIndex ; i++){ //Check each item of the dynamic array until the specific key if found
        if(key==data->array[i]){
            return true;
        }
    }
    return false; //If the key isnt found return False
}
template <typename T>
void dynamicSet<T>::insert(T key){
    if(!isIn(key)){
        data->add(key);
    }
}
template <typename T>
void dynamicSet<T>::removeVal(T key){
    for(int i=0 ; i<data->currentIndex ; i++){
        if(key==data->array[i]){
            data->removeVal(i);
        }
    }
}
template <typename T>
bool dynamicSet<T>::isEmpty(){
    if(data->currentIndex==0){
        return true;
    }
    else{
        return false;
    }
}
template <typename T>
dynamicSet<T>* dynamicSet<T>::Union(dynamicSet<T>* set){
    dynamicSet<T> *temp = new dynamicSet<T>();
    for(int i=0 ; i < data->currentIndex ; i++){
        temp->insert(data->array[i]);
    }
    for(int i=0 ; i < set->data->currentIndex ; i++){
        temp->insert(set->data->array[i]);
    }
    return temp;
}
template <typename T>
dynamicSet<T>* dynamicSet<T>::Intesection(dynamicSet<T>* set){
    dynamicSet<T> *temp = new dynamicSet<T>();
    for(int i=0 ; i < data->currentIndex ; i++){
        if(set->isIn(data->array[i])){
            temp->insert(data->array[i]);
        }
    }
    return temp;
}

template <typename T>
void dynamicSet<T>::Test(){
    dynamicSet<int> *setd;
    setd = new dynamicSet<int>();
    setd->insert(1);
    setd->insert(2);
    cout << "Add 1" << endl << "Add 2" << endl;
    cout << "isEmpty: " << setd->isEmpty() << endl;
    cout << "isIn(1): " << setd->isIn(1) << endl;
    cout << "isIn(2): " << setd->isIn(2) << endl;
    cout << "Remove 2" << endl;
    setd->removeVal(2);
    cout << "isEmpty: " << setd->isEmpty() << endl;
    cout << "isIn(1): " << setd->isIn(1) << endl;
    cout << "isIn(2): " << setd->isIn(2) << endl;
    cout << "Remove 1" << endl;
    setd->removeVal(1);
    cout << "isIn(1): " << setd->isIn(1) << endl;
    cout << "isEmpty: " << setd->isEmpty() << endl;
    cout << "setd becomes " << endl;
    setd->insert(2);
    setd->insert(5);
    setd->insert(4);
    setd->insert(10);
    setd->data->printAll();
    
    cout << "Make setd2" << endl;
    dynamicSet<int> *setd2;
    setd2 = new dynamicSet<int>();
    setd2->insert(5);
    setd2->insert(6);
    setd2->insert(7);
    setd2->insert(2);
    setd2->data->printAll();
    
    cout << "Union of the two sets: " << endl;
    dynamicSet<int> *setdU;
    setdU = setd->Union(setd2);
    setdU->data->printAll();
    
    std::cout << "Intersection of the two sets: " << endl;
    dynamicSet<int> *setdI;
    setdI = setd->Intesection(setd2);
    setdI->data->printAll();
    
    delete setd;
    delete setd2;
    delete setdU;
    delete setdI;
}


