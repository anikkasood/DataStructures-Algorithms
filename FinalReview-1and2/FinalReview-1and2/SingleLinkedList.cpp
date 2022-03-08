//
//  SingleLinkedList.cpp
//  FinalReview-1and2
//
//  Created by Anika Sood on 3/5/22.
//

#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

//constructor
SingleLinkedList::SingleLinkedList(){
    head = nullptr;
    tail = nullptr;
}

//destructor
SingleLinkedList::~SingleLinkedList(){
    while(!is_empty()){
        delete_first();
    }
}

//print out whole list
void SingleLinkedList::print(){
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->data << "\t";
        tmp = tmp->next;
    }
}

//insert val at start of list
void SingleLinkedList::insert_front(int value){
    Node* temp = new Node(value);
    temp -> next = head;
    head = temp;
}


//insert val at end of list
void SingleLinkedList::insert_back(int value){
    
    if(is_empty()){
        head = new Node(value);
        tail = head;
        return;
    }
    
    Node* temp = new Node(value);
    temp -> next = nullptr;
    tail->next = temp;
    tail = temp;
}

//delete the first val
void SingleLinkedList::delete_first(){
    if (is_empty()) return;
    Node* toDel = head;
    head = head->next;
    delete toDel;
}

//delete the last val --> TEST THIS
void SingleLinkedList::delete_last(){
    if (is_empty()) return;
    Node* newTail = head;
    while(newTail->next != tail){
        newTail = newTail->next;
    }
    
    tail = newTail;
    delete tail->next;
}


//find at pos (assumes list isnt empty)
Node* SingleLinkedList::find_at_pos(int pos){
    int i = 0;
    Node* curr = head;
    while(i != pos-1){
        curr = curr->next;
        i++;
    }
    return curr;
}

//delete the node at a given position
void SingleLinkedList::delete_at_pos(int pos){
    if(pos == 0){
        delete_first();
        return;
    }
    
    Node* prev = nullptr;
    Node* curr = head;
    
    for (int i = 0; i <pos; i++){
        prev = curr;
        curr = curr -> next;
    }
    
    prev -> next = curr->next;
    delete curr;
}

//check if the list is empty
bool SingleLinkedList::is_empty(){
    return (head == nullptr);
}

//reverse the list
void SingleLinkedList::reverse(){
    if(is_empty()||head==tail) return;
    
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    tail = head;
    head = prev;
}


void SingleLinkedList::remove_duplicates() {
    Node* curr = head; // iterator starts from list’s head
    Node* next_dup; // iterator for next duplicate
    
    while (curr != NULL) { // keep going until end of list
        next_dup = curr->next; // assume next element is duplicate
        while ( next_dup != NULL && next_dup->data == curr->data){
            curr->next = next_dup->next; // deletion (a): adjust curr’s next
            delete next_dup; // deletion (b): deallocate memory
            next_dup = curr->next; // prepare for next iteration
        }
        curr = curr->next; // move to the next unique element
        if (curr != NULL) tail = curr; // last non-NULL curr is the new tail
    }
}
