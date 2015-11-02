#include "../../baseStructures/dynamicArray/dynamicArray.cpp"
#include <cstdlib>
#include <iostream>

class mapHelp{
    public:
      string key;
      int num;
      
      mapHelp();
};

class dynamicMap{
    
    public:
        dynamicArray<mapHelp> *data;
        
        dynamicMap();
        ~dynamicMap();
        void set(string key, int value);
        void remove(string key);
        int get(string key);
        int& operator[](string key);
        void printAll();
        void Test();
};
