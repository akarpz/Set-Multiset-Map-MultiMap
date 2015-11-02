#include <iostream>
#include <string>
#include <cstdlib>
#include "linkedMultiMap.h"
using namespace std;


template<typename DataType>
Node<DataType>::Node(DataType inputData){
    data = inputData;
    next = NULL;
}



template<typename T>      
List<T>::List(){
    head = NULL;
    tail = NULL;
    length = 0;
}

template<typename T>
List<T>::List(T input){
    head = new Node<T>(input);
    tail = head;
    length = 0;
}

template<typename T>
List<T>::~List(){
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
    if(nextNode != NULL){
        delete nextNode;
    }
}

template<typename T>
void List<T>::Prepend(T inputData){
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

template<typename T>
void List<T>::Append(T inputData){
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

template<typename T>
void List<T>::Append(T inputData, string key){
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

template<typename T>
void List<T>::deleteLast(){
    Node<T>* temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    tail=temp;
    temp->next=NULL;
    length--;
}

template<typename T>
void List<T>::removeVal(string key){
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
        delete removeNode;
        length--;
        return;
    }
    else{
        cout << "KEY NOT FOUND";
        return;
    }
}

template<typename T>
void List<T>::printList(){
    Node<T>* newNode = head;
    cout << endl;
    cout << "Length: " << length << endl << "List: ";
    while(newNode != NULL){
        cout << newNode->data << " ";
        newNode=newNode->next;
    }
    cout << endl;
}



linkedMultiMap::linkedMultiMap(){
    list = new List<List<int>* >();
}

linkedMultiMap::~linkedMultiMap(){
    delete list;
}

//Adds a given key value pair to the map
void linkedMultiMap::set(string key, int value){
    if(isIn(key)){
        Node<List<int>* >* temp = list->head;
        while(temp != NULL){
            if(temp->data->head->key == key){
                temp->data->Append(value,key);
                return;
            }
            temp = temp->next;
        }
    }
    else{
        List<int>* temp = new List<int>();
        
        temp->Append(value,key);
        list->Append(temp,key);
    }
}

//returns true if the node with the given key exists in the list, or false if it doesnt
bool linkedMultiMap::isIn(string key){
    Node<List<int>* >* conductor = list->head;
    while(conductor != NULL){
        if(conductor->data->head->key == key){
            return true;
        }
        conductor = conductor->next;
    }
    return false;
    }


//Removes the given pair from the map based on given key
void linkedMultiMap::removeAll(string key){
    list->removeVal(key);
}

int linkedMultiMap::count(string key){
    Node<List<int>* >* conductor = list->head;
    while(conductor != NULL){
        if(conductor->data->head->key == key){
            return conductor->data->length;
        }
    }
}

//Returns all corresponding values to the given key if any exist, or throws an exception if it doesnt
int* linkedMultiMap::getAll(string key){
    Node<List<int>* >* temp = list->head;
    while(temp != NULL){
        if(temp->key == key){
            int *result = new int[count(key)];
            for(int i=0;i<count(key);i++){
                result[i] = 0;
            }
            Node<int>* ugh = temp->data->head;
            int i = 0;
            while(ugh != NULL){
                result[i] = ugh->data;
                ugh=ugh->next;
                i++;
            }
            return result;
        }
        temp=temp->next;
    }
    throw exception();
}

void linkedMultiMap::Test(){
    linkedMultiMap* test = new linkedMultiMap();
    test->set("first",1);
    cout << "isIn(first): " << test->isIn("first") << endl;
    test->set("second",2);
    test->set("second",3);
    test->set("second",4);
    test->set("fourth",4);
    test->set("fifth",5);
    cout << test->isIn("second") << endl;
    test->set("first",5);
    test->set("first",10);
    int* temp = test->getAll("first");
    for(int i=0;i<3;i++){
        cout << *(temp + i) << " ";
    }
    cout << endl;
    test->removeAll("first");
    test->removeAll("second");
    test->removeAll("fourth");
    test->removeAll("fifth");
    delete test;
    
    return;
}
