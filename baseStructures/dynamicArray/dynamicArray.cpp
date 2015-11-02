#include <iostream>
#include <cstdlib>
#include "dynamicArray.h"
using namespace std;

template <typename T>
dynamicArray<T>::dynamicArray(){
    array = new T[1];
    currentSize = 1;
    maxSize = 1;
    currentIndex = 0; 
    key = "";
}
template <typename T>
dynamicArray<T>::~dynamicArray(){
    delete[] array;
}

template <typename T>
dynamicArray<T>::dynamicArray(int initialSize, string newKey){
    key = newKey;
    array = new T[initialSize];
    currentSize = initialSize;
    maxSize = currentSize;
    currentIndex = 0;
}
template <typename T>
void dynamicArray<T>::add(T newItem){
    if(currentIndex == currentSize - 1){
        checkSize();
    }
    
    array[currentIndex] = newItem;
    
    currentIndex = currentIndex + 1;
    return;
}

template <typename T>
void dynamicArray<T>::checkSize(){
    maxSize = currentSize*2;
    
    T* temp = new T[maxSize];

    for(int i = 0; i < currentSize;i++){
        temp[i] = array[i];
        
    }
    array = temp;
    currentSize = maxSize;
    return;
}

template <typename T>
void dynamicArray<T>::printAll(){
    for(int i = 0; i<currentIndex; i++)
        cout <<key << " "<< array[i] << endl;
}

template <typename T>
void dynamicArray<T>::removeVal(int index){
    for(int i = index; i < currentIndex; i++){
        swap(array[i], array[i + 1]);
    }
    array[currentIndex - 1] = 0;
    currentIndex -= 1;
}

//int main(){
//   return 0;
//}

