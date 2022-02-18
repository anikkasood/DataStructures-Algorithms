//
//  main.cpp
//  cs010c_Lab3
//
//  Created by Anika Sood on 1/28/22.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>


using namespace std;


vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <typename T>//string, double, or int
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned min = index;
    
    for (unsigned j = index; j < vals.size(); ++j)
    {
        if (vals.at(j) < vals.at(min)){
            min = j;
        }
    }
    return min;
    
}



template <typename T>
void selection_sort(vector<T> &vals){
    if(vals.empty()) return;
    for(unsigned i = 0; i <vals.size(); ++i){
        //find min
        unsigned min = min_index(vals, i);
        
        // swap value at index with min
        T temp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = temp;
    }
}

template <typename T>
T getElement(vector<T> vals, int index){
    return vals.at(index);
}

template <typename T>
void print(vector<T> vals){
    unsigned i = 0;
    cout<<"[ ";
    while(i<vals.size()){
        cout<<vals.at(i)<<" ";
        i++;
    }
    cout<<"]"<<endl;
}

int main() {
    
    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;

    //test selection sort
    vals.push_back('a');
    print(vals);
    selection_sort(vals);
    print(vals);


     while(--numOfRuns >= 0){
         try{
             cout << "Enter a number: " << endl;
             cin >> index;
             
             if(index>=int(vals.size()) || index<0)
             {
                 throw std::out_of_range("out of range exception occured");
             }
             
             curChar = getElement(vals,index);
             cout << "Element located at " << index << ": is " << curChar << endl;
         }
         catch(const std::out_of_range& excpt){
             //print error msg
             cout<<excpt.what()<<"\n";
         }
    }

    
    return 0;
}
