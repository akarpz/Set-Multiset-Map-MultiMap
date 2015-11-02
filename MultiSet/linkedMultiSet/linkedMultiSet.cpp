#include "linkedMultiSet.h"
#include <cstdlib>

    


linkedMultiSet::linkedMultiSet(){
    list = new linkedList<string>();
}

linkedMultiSet::~linkedMultiSet(){
    delete list;
}

bool linkedMultiSet::isIn(string key){
    if(list->length>0 && list->head->data == key){
        return true;
    }
    
    Node<string>* conductor = list->head;
    while(conductor != NULL){
        if(conductor->data == key){
            return true;
        }
        conductor = conductor->next;
    }
    return false;
}

void linkedMultiSet::insert(string key){
        list->Append(key);
}

unsigned long linkedMultiSet::count(string key){
    unsigned long result = 0;
    Node<string>* conductor = list->head;
    while(conductor != NULL){
        if(conductor->data == key){
            result++;
        }
        conductor = conductor->next;
    }
    return result;
}

void linkedMultiSet::removeOne(string key){
    Node<string>* conductor = list->head;
    while(conductor != NULL){
        if(conductor->data == key){
            list->removeVal(key);
            return;
        }
        conductor = conductor->next;
    }
}

void linkedMultiSet::removeAll(string key){
    int counter = count(key);
    for(int i=0;i<counter;i++){
        removeOne(key);
    }
}

bool linkedMultiSet::isEmpty(){
    if(list->length==0){
        return true;
    }
    else{
        return false;
    }
}
        
void linkedMultiSet::Test(){
    linkedMultiSet *setl = new linkedMultiSet();
    setl->insert("first");
    setl->insert("second");
    setl->insert("second");
    cout << "Add first" << endl << "Add second" << endl;
    cout << "isEmpty: " << setl->isEmpty() << endl;
    cout << "isIn(first): " << setl->isIn("first") << endl;
    cout << "isIn(second): " << setl->isIn("second") << endl;
    cout << "Length: " << setl->list->length << endl;
    cout << "Number of Seconds: " << setl->count("second") << endl;
    cout << "Remove second" << endl;
    setl->removeAll("second");
    cout << "Number of Seconds: " << setl->count("second") << endl;
    cout << "Length: " << setl->list->length << endl;
    cout << "isEmpty: " << setl->isEmpty() << endl;
    cout << "isIn(first): " << setl->isIn("first") << endl;
    cout << "isIn(second): " << setl->isIn("second") << endl;
    cout << "Remove first" << endl;
    setl->removeOne("first");
    cout << "isIn(first): " << setl->isIn("first") << endl;
    cout << "isEmpty: " << setl->isEmpty() << endl;
    cout << "Length: " << setl->list->length << endl;
}
