/*How is this file different than linkedMap.cpp and why are there 2?*/

//This is basically done, can now be used on multimap
//The other linkedmap is incomplete, not sure why there are two

#include <iostream>
#include <string>
#include <cstdlib>
#include "linkedMap.h"
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
    delete nextNode;
    cout << "Cleaned Linked List" << endl;
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
        //delete removeNode;
        length--;
        return;
    }
    else{
        //cout << "KEY NOT FOUND";
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

    

//Adds a given key value pair to the map
void linkedMap::set(string key, int value){
    list.Append(value,key);
}

//Removes the given pair from the map based on given key
void linkedMap::removeVal(string key){
    list.removeVal(key);
}

//Returns the corresponding value to the given key if it exists, or -999 if it doesnt
int linkedMap::get(string key){
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
    throw exception();
}

int& linkedMap::operator[](string key){
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

void linkedMap::Test(){
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
}