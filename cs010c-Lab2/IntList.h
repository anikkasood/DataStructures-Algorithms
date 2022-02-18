//
//  IntList.h
//  cs010c-Lab2
//
//  Created by Anika Sood on 1/21/22.
//

#ifndef IntList_h
#define IntList_h

#include <iostream>
using namespace std;
//IntNode class definition
struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};


class IntList{
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    friend ostream &operator<<(ostream &out, const IntList &rhs);
    void printReverse() const;
private:
    IntNode* head;
    IntNode* tail;
    
};


#endif /* IntList_h */
