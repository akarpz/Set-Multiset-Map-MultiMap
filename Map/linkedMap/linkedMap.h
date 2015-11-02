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
      cout << "I deleted: "<< data << endl;
    };
};

template<typename T>
class List {
    public:
    
        Node<T>* head;
        Node<T>* tail;
        int length;
    
        List();
        ~List();
        void Prepend(T inputData);
        void Append(T inputData);
        void Append(T inputData, string key);
        void deleteLast();
        void removeVal(string key);
        void printList();
};

class linkedMap{
    public:
        List<int> list;
        void set(string key, int value);
        void removeVal(string key);
        int get(string key);
        int& operator[](string key);
        void Test();
};
