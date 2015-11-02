#include "../../baseStructures/dynamicArray/dynamicArray.cpp"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class dynamicMultiMap{
    dynamicArray<dynamicArray<int> >* Map;
    
    public:
        dynamicMultiMap();
        ~dynamicMultiMap();
        void extend(int value, int index);   
        int isIn(string check);
        void set(string key, int value);
        void printAll();
        void removeAll(string key);
        int count(string key);
        int* getAll(string key);
        void Test();
};
