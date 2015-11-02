#include "../../baseStructures/linkedList/linkedList.cpp"
class linkedSet{
    
    public:
        linkedList<string>* list;
        linkedSet();
        ~linkedSet();
        bool isIn(string key);
        linkedSet Union(linkedSet input);
        linkedSet* Intersection(linkedSet* input);
        void insert(string key);
        void removeVal(string key);
        bool isEmpty();
        void Test();
};

