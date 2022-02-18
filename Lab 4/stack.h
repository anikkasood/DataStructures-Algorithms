//
//  stack.h
//  Lab 4
//
//  Created by Anika Sood on 2/4/22.
//

#ifndef stack_h
#define stack_h
#include <stdexcept>
using namespace std;

template<typename T>
class stack{
private:
    T data[20]; //array of integer or strings
    int size; //current # of elements in the stack

public:
    const int MAX_SIZE = 20; //store array size
    
    stack(){ //make an empty stack (constructor)
        size = 0;
    }
    
    bool empty(){ //is the stack empty
        return (size==0);
    }
    
    void push(T val){ //add val of T to data
        if(size == MAX_SIZE)
            throw std::overflow_error("Called push on full stack.");
        data[size] = val; //add value to end of array
        size++; //increase size counter
    }
    void pop(){ //remove last element from the data
        if(empty())
            throw std::overflow_error("Called pop on empty stack.");
        size--; //decrease size of stack
            
    }
    void pop_two(){ //remove the last two elements
        if(empty())
            throw std::out_of_range("Called pop_two on empty stack.");
        if(size == 1)
            throw std::out_of_range("Called pop_two on a stack of size 1.");
        size-=2; //decrease size of stack by 2
    }
    T top(){ //return top element of the stack
        if(empty())
            throw std::underflow_error("Called top on empty stack.");
        return data[size-1]; //return top
    }

};


#endif /* stack_h */
