#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


class hashMap{
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
    item* hashTable[tableSize];
   
    public:
        hashMap(); //constructor
        int hash(string key);
        void set(string key, int value);
        void removeHash(string key);
        int get(string key);
        void printTable();
        int& operator[](string key);
        void Test();
};
