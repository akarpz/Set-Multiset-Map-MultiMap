#include "linkedSet.h"
#include <cstdlib>



linkedSet::linkedSet(){
    list = new linkedList<string>();
}

linkedSet::~linkedSet(){
    //cout << "Idiedlol" << endl;
    delete list;
}

bool linkedSet::isIn(string key){
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

void linkedSet::insert(string key){
    if(!isIn(key)){
        list->Append(key);
    }
    else{
        //cout << "Already Inserted. Remove then reinsert" << endl;
    }
}

linkedSet linkedSet::Union(linkedSet input){
    linkedSet* result = new linkedSet();
    Node<string>* temp = input.list->head;
    while(temp != NULL){
        result->insert(temp->data);
        temp=temp->next;
    }
    temp = this->list->head;
    while(temp != NULL){
        result->insert(temp->data);
        temp=temp->next;
    }
    return *result;
}

linkedSet* linkedSet::Intersection(linkedSet* input){
    linkedSet* result = new linkedSet();
    Node<string>* temp = input->list->head;
    if(input->list->head == NULL || this->list->head == NULL){
        return this;
    }
    while(temp != NULL){
        if(this->isIn(temp->data)){ // this line segfaults
            result->insert(temp->data);
        }
        temp=temp->next;
    }
    return result;
}

void linkedSet::removeVal(string key){
    Node<string>* conductor = list->head;
    while(conductor != NULL){
        if(conductor->data == key){
            list->removeVal(key);
            return;
        }
        conductor = conductor->next;
    }
}

bool linkedSet::isEmpty(){
    if(list->length==0){
        return true;
    }
    else{
        return false;
    }
}
        
void linkedSet::Test(){
    linkedSet* setl = new linkedSet();
    setl->insert("first");
    setl->insert("second");
    cout << "Add 1" << endl << "Add 2" << endl;
    cout << "isEmpty: " << setl->isEmpty() << endl;
    cout << "isIn(1): " << setl->isIn("first") << endl;
    cout << "isIn(2): " << setl->isIn("second") << endl;
    cout << "Remove 2" << endl;
    setl->removeVal("second");
    cout << "isEmpty: " << setl->isEmpty() << endl;
    cout << "isIn(1): " << setl->isIn("first") << endl;
    cout << "isIn(2): " << setl->isIn("second") << endl;
    cout << "Remove 1" << endl;
    setl->removeVal("first");
    cout << "isIn(1): " << setl->isIn("first") << endl;
    cout << "isEmpty: " << setl->isEmpty() << endl;
    
    linkedSet* tester1 = new linkedSet();
    linkedSet* tester2 = new linkedSet();
    tester1->insert("1");
    tester1->insert("2");
    tester1->insert("3");
    tester1->insert("4");
    tester2->insert("3");
    tester2->insert("4");
    tester2->insert("5");
    tester2->insert("6");
    linkedSet unionResult = tester1->Union(*tester2);
    unionResult.list->printList();
    
    linkedSet* tester3 = new linkedSet();
    linkedSet* tester4 = new linkedSet();
    tester3->insert("1");
    tester3->insert("2");
    tester3->insert("3");
    tester3->insert("4");
    tester4->insert("3");
    tester4->insert("4");
    tester4->insert("5");
    tester4->insert("6");
    linkedSet* intersectionResult = tester3->Intersection(tester4);
    intersectionResult->list->printList();
}

