#include <string>
using namespace std;

class hashSet{

    private:
        static const int tableSize = 100;
    
    //item is what the hashtable contains    
    struct item{
        string key;

    };
    
    /*
    hashtable structure is really just like an array
    each "bucket" has a pointer that points to the next 
    */
    item* hashTable[tableSize];
   
    public:
        hashSet(); //constructor
        int hash(string key);
        void insert(string key);
        bool isIn(string key);
        void removeKey(string key);
        bool isEmpty();
        void printTable();
        hashSet Union(hashSet otherSet);
        hashSet Intersection(hashSet otherSet);
        void Test();
};