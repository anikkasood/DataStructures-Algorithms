//
//  main.cpp
//  cs010c-Lab2
//
//  Created by Anika Sood on 1/21/22.
//

#include "IntList.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream &out, const IntList &rhs){
    if(!rhs.empty()){
        IntNode* currptr = rhs.head->next;
        
        while(currptr->next != rhs.tail){
            out<<(currptr->data)<<" ";
            currptr = currptr->next;
        }
        out<<(currptr->data);
    }
    return out;
}

int main() {
    IntList mylist;
    mylist.push_front(5);
    mylist.push_front(2);
    mylist.push_front(3);
   
    mylist.printReverse();
    cout<<"\n";
    mylist.pop_back();
    cout<<mylist;

    return 0;
}
