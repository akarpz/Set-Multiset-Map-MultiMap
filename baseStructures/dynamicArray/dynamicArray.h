#include <string>
template <typename T> 
class dynamicArray{
    public:
        int currentSize;
        int maxSize;
        std::string key;
        int currentIndex;    
    
        dynamicArray<T>();
        dynamicArray<T>(int,std::string);
        ~dynamicArray<T>();
        T* array;
        void add(T);
        void checkSize();
        void printAll();
        void removeVal(int);
        
};