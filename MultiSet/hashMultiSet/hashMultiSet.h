#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
using namespace std;

class hashMultiSet{
    private:
        static const int tableSize = 100;
    
    //item is what the hashtable contains    
    struct item{
        string key;
        unsigned long count;
    };
    
    /*
    hashtable structure is really just like an array
    each "bucket" has a pointer that points to the next 
    */
    item* hashTable[tableSize];
   
    public:
        hashMultiSet(); //constructor
        int hash(string key);
        void insert(string key);
        bool isIn(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool isEmpty();
        void printTable();
        string draw_random();
        void Test();
        //~hashMultiSet();
};