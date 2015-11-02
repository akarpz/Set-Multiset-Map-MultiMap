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
    ~Node(){
    };
};

template<typename DataType>
Node<DataType>::Node(DataType inputData){
    data = inputData;
    next = NULL;
}

//Wrap up the Node
template<typename T>
class linkedList {
    public:
        Node<T>* head;
        Node<T>* tail;
        int length;
    
        linkedList(){
            head = NULL;
            tail = NULL;
            length = 0;
        }
        
        ~linkedList(){
            if (head == NULL){
                return;
            };

            Node<T>* nextNode = head;
            Node<T>* deleteNode = nextNode;

            while (nextNode->next != NULL){
                deleteNode = nextNode;
                nextNode = nextNode->next;
                delete deleteNode;
            }
            delete nextNode;
            cout << "Cleaned Linked List" << endl;
        }
        
        void Prepend(T inputData){
            Node<T>* p2newNode = new Node<T>(inputData);
            if (head == NULL){
                head = p2newNode;
                tail = p2newNode;
            } else {
                p2newNode->next = head;
                head = p2newNode;
            }
            length++;
        }
        
        void Append(T inputData){
            Node<T>* newNode = new Node<T>(inputData);
            if(head == NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
            length++;
        }
        
        void deleteLast(){
            Node<T>* temp = head;
            while(temp->next->next != NULL){
                temp=temp->next;
            }
            tail=temp;
            temp->next=NULL;
            length--;
            
        }
        
        void removeVal(string key){
            if(head->data == key){
                head=head->next;
                length--;
                return;
            }
            if(length==0){
                head=NULL;
                tail=NULL;
                return;
            }
            Node<T>* prevNode = head;
            Node<T>* removeNode = head->next;
            for(int j=0 ; removeNode->data != key ; j++){
                if(j>=length)
                    break;
                prevNode = prevNode->next;
                removeNode = removeNode->next;
            }
            if(removeNode->data == key){
                prevNode->next = removeNode->next;
                delete removeNode;
                length--;
                return;
            }
            else{
                cout << "KEY NOT FOUND";
                return;
            }
        }
        
        T index(int i){
            Node<T>* ref = head;
            for(int j=0 ; j < i ; j++){
                ref = ref->next;
            }
            return ref->data;
        }
        
        void printList(){
            Node<T>* newNode = head;
            cout << "Length: " << length << endl << "List: ";
            if(newNode == NULL){
                cout << "Empty" << endl;
            }
            while(newNode != NULL){
                cout << newNode->data << " ";
                newNode=newNode->next;
            }
            cout << endl;
        }
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