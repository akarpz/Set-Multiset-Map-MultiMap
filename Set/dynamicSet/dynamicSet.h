#include "../../baseStructures/dynamicArray/dynamicArray.cpp"
template <typename T>
class dynamicSet{
    public:
        dynamicArray<T> *data;
        dynamicSet();
        ~dynamicSet();
        bool isIn(T key);
        void insert(T key);
        void removeVal(T key);
        bool isEmpty();
        dynamicSet<T>* Union(dynamicSet<T>* set);
        dynamicSet<T>* Intesection(dynamicSet<T>* set);
        void Test();
};