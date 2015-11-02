#include <cstdlib>
#include "../../baseStructures/dynamicArray/dynamicArray.cpp"
#include "../../baseStructures/multiSetHelp/multiSetHelp.cpp"
#include <iostream>

template <typename T> class dynamicMultiSet{
    
    public:
        dynamicArray< multiSetHelp<T> > *data;
        dynamicMultiSet();
        ~dynamicMultiSet();
        int find(T key);
        bool isIn(T key);
        void insert(T key);
        void removeAll(T key);
        void removeOne(T key);
        bool isEmpty();
        unsigned long count(T key);
        void printAll();
        void Test();
};

        