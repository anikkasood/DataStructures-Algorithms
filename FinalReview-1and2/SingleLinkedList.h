//
//  SingleLinkedList.h
//  FinalReview-1and2
//
//  Created by Anika Sood on 3/5/22.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h
#include <iostream>
using namespace std;

//The struct is defined in the header file itself!!
struct Node{
    int data;
    Node* next;
    
    //struct constructor!!!!
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class SingleLinkedList{
private:
    Node* head;
    Node* tail;
public:
    SingleLinkedList(); // constructor --> NOTE HOW YOU NEED TO DEFINE THIS!! U should do this in general
    ~SingleLinkedList(); // destructor
    void print(); //print out whole list
    void insert_front(int value); //insert val at start of list
    void insert_back(int value); //insert val at end of list
    void delete_first(); //delete the first val
    void delete_last(); //delete the last val
    Node* find_at_pos(int pos); //find the node at a given position
    void delete_at_pos(int pos); //delete the node at a given position
    bool is_empty(); //check if the list is empty
    void reverse(); //reverse the list
    void remove_duplicates(); //remove all duplicates in the list
};
#endif /* SingleLinkedList_h */
