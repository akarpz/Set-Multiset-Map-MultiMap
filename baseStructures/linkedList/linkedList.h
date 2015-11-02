#include <iostream>
#include <string>
using namespace std;

//Squad Goals: Make this work for all the stuff we need it to
//Doubly linked? - possibly needed tbd

template<typename DataType>
struct Node {
    Node* next;
    DataType data;
    Node();
    Node(DataType inputData);
    ~Node();
};


//Wrap up the Node
template<typename T>
class linkedList {
    public:
        Node<T>* head;
        Node<T>* tail;
        int length;
    
        linkedList();
        ~linkedList();
        void Prepend(T inputData);
        void Append(T inputData);
        void deleteLast();
        void removeVal(int i);
        void removeVal(string key);
        T index(int i);
        void printList();
};

/*
int main(){
    List<int> test;
    test.Append(5);
    test.Prepend(900);
    test.Append(49);
    test.printList();
    test.deleteLast();
    test.printList();
}
*/