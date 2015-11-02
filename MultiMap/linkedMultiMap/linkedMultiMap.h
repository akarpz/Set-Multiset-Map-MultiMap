#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


template<typename DataType>
struct Node {
    Node* next;
    DataType data; // value
    string key;
    Node(DataType inputData);
    ~Node(){
      cout << "I deleted" << endl;
    };
};

template<typename T>
class List {
    public:
    
        Node<T>* head;
        Node<T>* tail;
        int length;
    
        List();
        List(T input);
        ~List();
        void Prepend(T inputData);
        void Append(T inputData);
        void Append(T inputData, string key);
        void deleteLast();
        void removeVal(string key);
        void printList();
};

class linkedMultiMap{
    
    public:
    
        List<List<int>* >* list;

        linkedMultiMap();
        ~linkedMultiMap();
        void set(string key, int value);
        bool isIn(string key);
        void removeAll(string key);
        int count(string key);
        int* getAll(string key);
        void Test();
};
