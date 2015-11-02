#include <cstdlib>
#include <iostream>
#include <string>
#include "../../baseStructures/dynamicArray/dynamicArray.cpp"
using namespace std;


class hashMultiMap{
    private:
        static const int tableSize = 100;
    
    //item is what the hashtable contains    
    struct item{
        string key;
        int value;
    };
    
    
    /*
    hashtable structure is really just like an array
    each "bucket" has a pointer that points to the next 
    */
    dynamicArray<item*> hashTable[tableSize];
   
    public:
        hashMultiMap(); //constructor
        int hash(string key);
        void set(string key, int value);
        void removeAll(string key);
        int count(string key);
        int* getAll(string key);
        void printTable();
        void Test();
};

