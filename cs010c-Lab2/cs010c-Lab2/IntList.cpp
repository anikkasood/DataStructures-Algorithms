//
//  IntList.cpp
//  cs010c-Lab2
//
//  Created by Anika Sood on 1/21/22.
//

#include "IntList.h"

IntList::IntList(){ //Initializes an empty list with dummy head and dummy tail.
    head = new IntNode(0);
    tail = new IntNode(0);
    
    head->next = tail;
    head->prev = tail;
    tail->next = head;
    tail->prev = head;
}
IntList::~IntList(){ //Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
    IntNode* curr = head;
    IntNode* temp;
    while(curr!=tail){
        temp = curr->next;
        delete curr;
        curr = temp;
    }
}
void IntList::push_front(int value){
    IntNode* toPush = new IntNode(value);
    IntNode* afterHead = head->next; //node after head
    toPush->prev = head;
    toPush->next = afterHead;
    head->next = toPush;
    afterHead->prev = toPush;
    
    
}
void IntList::pop_front(){
    if(!empty()){
        IntNode* toPop = head->next; //point to node to pop
        head->next = toPop->next; //update dummy head next
        (toPop->next)->prev = head; //set new head previous to dummy head
        delete toPop;
    }
}
void IntList::push_back(int value){
    IntNode* toPush = new IntNode(value);
    IntNode* last = tail->prev;
    toPush->prev = last;
    toPush->next = tail;
    tail->prev = toPush;
    last->next = toPush;
}
void IntList::pop_back(){
    if(!empty()){
        IntNode* toPop = tail->prev; //point to node to pop
        tail->prev = toPop->next; //update dummy tail next
        (toPop->prev)->next = tail; //set new head previous to dummy head
        delete toPop;
    }
    
}
bool IntList::empty() const{
    if(head->next == nullptr){
        return true;
    }
    else{
        return false;
    }
    
}

void IntList::printReverse() const{
    if(!empty()){
        IntNode* currptr = tail->prev;
        
        while(currptr->prev != head){
            cout<<(currptr->data)<<" ";
            currptr = currptr->prev;
        }
        cout<<(currptr->data);
    }
}
