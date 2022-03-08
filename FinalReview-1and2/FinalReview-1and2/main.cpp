//
//  main.cpp
//  FinalReview-1and2
//
//  Created by Anika Sood on 3/5/22.
//



/*
 
In this project, I will implement a single & double linked list. Look at comments for notes about everything.
These two types of lists are some of the main takeaways of weeks 1 and 2 of cs010c.
 Will also include an activity review file.
 
 
 */
#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

void testSingle(){
    int input;
    SingleLinkedList sll;
    
    cout<<"Chose function:\n";
    cout<<"1. void print()\n";
    cout<<"2. void insert_front(int value)\n";
    cout<<"3. void insert_back(int value)\n";
    cout<<"4. void delete_first()\n";
    cout<<"5. void delete_last()\n";
    cout<<"6. Node* find_at_pos(int pos)\n";
    cout<<"7. void delete_at_pos(int pos)\n";
    cout<<"8. bool empty()\n";
    cout<<"9. void reverse()\n";
    cout<<"10. void remove_duplicates()\n";
    cout<<"0. QUIT  \n";
    
    
    do{
        cout<<"----> Enter Choice: ";
        cin>>input;
        
        switch(input){
            case 1:
                sll.print();
                break;
            case 2:
                int val;
                cout<<"\nEnter val: ";
                cin>>val;
                sll.insert_front(val);
                break;
            case 3:
                int value;
                cout<<"\nEnter val: ";
                cin>>value;
                sll.insert_back(value);
                break;
            case 4:
                sll.delete_first();
                break;
            case 5:
                sll.delete_last();
                break;
            case 6:
                int v;
                cout<<"\nEnter pos: ";
                cin>>v;
                sll.find_at_pos(v);
                break;
            case 7:
                int pos;
                cout<<"\nEnter pos: ";
                cin>>pos;
                sll.delete_at_pos(pos);
                break;
            case 8:
                cout<<sll.is_empty()<<endl;
                break;
            case 9:
                sll.reverse();
                break;
            case 10:
                sll.print();
                sll.remove_duplicates();
                sll.print();
                break;
        }
        
        cout<<"\n\n";
    }
    while(input !=0);
}

int main() {
    //Single Linked List Test
    testSingle();
    
    return 0;
}
