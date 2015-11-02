#include "../../baseStructures/linkedList/linkedList.cpp"
#include <cstdlib>

class linkedMultiSet{
    
    public:
        linkedList<string>* list;
        linkedMultiSet();
        ~linkedMultiSet();
        bool isIn(string key);
        void insert(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool isEmpty();
        void Test();
};

