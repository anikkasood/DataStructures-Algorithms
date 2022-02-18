//
//  Heap.cpp
//  Lab5cs10c
//
//  Created by Anika Sood on 2/8/22.
//

#include <iostream>
#include "Heap.h"
#include "PrintJob.h"
using namespace std;

/*
 PrintJob* arr[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
 int numItems;  //current number of items in heap
 */

/*Initializes an empty heap.*/
Heap::Heap(){
    numItems = 0;
}

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue ( PrintJob* toAdd){
    //if the heap is not full
    if(numItems < MAX_HEAP_SIZE) {
        //add the number to the end
        arr[numItems] = toAdd;
       
        int pos = numItems;
        //adjust until it is not in violation of max heap property:
        while(pos >= 1 && arr[pos]->getPriority() > arr[(pos-2)/2]->getPriority()) {
            //swap element with its parent
            PrintJob* temp = arr[pos];
            arr[pos] = arr[(pos-1)/2];
            arr[(pos-1)/2] = temp;
            
            pos= (pos-1)/2;
        }
    
        numItems++;
}
}


void Heap::dequeue ( ){
    //removing the only item in the heap
    if(numItems == 1) {
        arr[0]= 0; //empty first position
        numItems--; //set size of heap to 0
        return;
    }

    //heap has more than 1 element
    if(numItems > 1) {
        //set new root to the last element & empty last element
        arr[0] = arr[numItems-1];
        arr[numItems-1] = 0;
        numItems--;
        
        //use trickle down to swap elements until there is no max heap violation
        trickleDown(0);
    }
}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest( ){
    if(numItems>0) return arr[0];
    else return 0;
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print ( ){
    if(numItems>0)
        cout<<"Priority: "<<highest()->getPriority()<<", Job Number: "<<highest()->getJobNumber()<<", Number of Pages: "<< arr[0]->getPages()<<"\n";
}

/*This function is called by dequeue function
to move the new root down the heap to the
appropriare location.*/
void Heap::trickleDown(int root){
    
    //traverse through the heap
    for(int j = 0; j < numItems; j++) {
        //if a value is greater than the root, swap it (root will always store the greatest val)
        if(arr[root]->getPriority() < arr[j]->getPriority())
        {
            PrintJob* temp = arr[root];
            arr[root] = arr[j];
            arr[j] = temp;
        }
    }
}
