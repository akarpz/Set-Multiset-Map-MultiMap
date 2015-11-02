/*How is this file different than linkedMap.cpp and why are there 2?*/

//This is basically done, can now be used on multimap
//The other linkedmap is incomplete, not sure why there are two

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

template<typename DataType>
Node<DataType>::Node(DataType inputData){
    data = inputData;
    next = NULL;
}

template<typename T>
class List {
    public:
    
        Node<T>* head;
        Node<T>* tail;
        int length;
    
        List(){
            head = NULL;
            tail = NULL;
            length = 0;
        }
        
        ~List(){
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
            } 
            else{
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
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
            length++;
        }
        
        void Append(T inputData, string key){
            Node<T>* newNode = new Node<T>(inputData);
            newNode->key = key;
            if(head == NULL){
                head=newNode;
                tail=newNode;
            }
            else{
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
            if(head->key == key){
                head=head->next;
                length--;
                return;
            }
            Node<T>* prevNode = head;
            Node<T>* removeNode = head->next;
            for(int j=0 ; removeNode->key != key ; j++){
                if(j>=length)
                    break;
                prevNode = prevNode->next;
                removeNode = removeNode->next;
            }
            if(removeNode->key == key){
                prevNode->next = removeNode->next;
                //delete removeNode;
                length--;
                return;
            }
            else{
                //cout << "KEY NOT FOUND";
                return;
            }
        }
        
        void printList(){
            Node<T>* newNode = head;
            cout << endl;
            cout << "Length: " << length << endl << "List: ";
            while(newNode != NULL){
                cout << newNode->data << " ";
                newNode=newNode->next;
            }
            cout << endl;
        }
};

class linkedMap{
    
    public:
    
        List<int> list;

        //Adds a given key value pair to the map
        void set(string key, int value){
            list.Append(value,key);
        }
        
        //Removes the given pair from the map based on given key
        void removeVal(string key){
            list.removeVal(key);
        }
        
        //Returns the corresponding value to the given key if it exists, or -999 if it doesnt
        int get(string key){
            Node<int>* temp = list.head;
            if(list.head->key == key){
                return list.head->data;
            }
            while(temp != NULL){
                if(temp->key == key){
                    return temp->data;
                }
                temp=temp->next;
            }
            //better solution here? possibly throw an exception
            throw exception();
            //return -999;
        }
        
        int& operator[](string key){
            Node<int>* temp = list.head;
            if(list.head->key == key){
                return list.head->data;
            }
            while(temp != NULL){
                if(temp->key == key){
                    int& result = temp->data;
                    return result;
                }
                temp=temp->next;
            }
            //better solution here? possibly throw an exception
            //cout << "KEY NOT FOUND";
            throw exception();
        }
};

int main(){
    linkedMap test;
    test.set("first",1);
    test.set("second",2);
    test.set("third",3);
    test.set("fourth",4);
    test.set("fifth",5);
    cout << test.get("first") << endl;
    cout << test.get("second") << endl;
    cout << test.get("third") << endl;
    test.removeVal("first");
    //test.removeVal("second");
    //test.removeVal("third");
    //test.removeVal("fifth");
    cout << test["second"] << endl;
    test.list.printList();
    //cout << test.get("this will generate an exception");
    clock_t begin = clock();
    return 0;
}