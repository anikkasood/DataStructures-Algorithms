//
//  arithmeticExpression.cpp
//  Lab6-cs010c
//
//  Created by Anika Sood on 2/18/22.
// internal nodes == operator
// external nodes == operand
//

#include "arithmeticExpression.h"
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


/* Initializes an empty tree and sets the infixExpression
to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string & str){
    root = NULL;
    infixExpression = str;
}


/* Converts the infixExpression to its equivalent postfix string
  and then generates the tree and assigns the root node to the
  root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree(){
    string post = infix_to_postfix(); // converts infix to postfix
           
   stack<TreeNode*> stack;
   
   TreeNode *a = NULL;
   TreeNode *b = NULL;
   
   char key = 'a';
   
   for (unsigned i = 0; i < post.size(); i++) {

       //if curr character is an operator
       if (post.at(i) == '*' || post.at(i) == '+' || post.at(i) == '-' || post.at(i) == '/') {
          
           //pop top 2 chars in stack & store in a and b
           a = stack.top();
           stack.pop();
           b = stack.top();
           stack.pop();
           
           //make a new node with the curr operator and make the key one greater
           TreeNode *toAdd = new TreeNode(post.at(i), key + i);
           
           //new nodes left and right to the 2 chars we popped from stack
           toAdd->left = b;
           toAdd->right = a;
           
           //add the new node to the stack
           stack.push(toAdd);
       }
       else {
           //if its a number push it to the stack
           TreeNode *num = new TreeNode(post.at(i), key + i);
           stack.push(num);
       }
   }

   root = stack.top();
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix(){
    infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix(){
    prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix(){
    postfix(root);
}

/* Calls the recursive visualizeTree function and generates the .png file using system call. */
void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}


/* Helper function that returns an integer according to
  the priority of the given operator. */
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

/* Helper function that returns the postfix notation equivalent
  to the given infix expression */
string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream out;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' ')
            continue;
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    out << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    out << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            out << c;
        }
    }
    while(!s.empty()){
        out << s.top();
        s.pop();
    }
    return out.str();
}

/* Helper function that outputs the infix notation of the arithmetic expression tree
  by performing the inorder traversal of the tree.
  An opening and closing parenthesis must be added at the
  beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode * node){
    //if its a external node display its data
    if(node->left==NULL || node->right== NULL){
        cout<<node->data;
    }
    //if its an internal node traverse subtrees and display them
    else{
        if(priority(node->data)){
            cout<<"(";
            infix(node->left);
            cout<<node->data;
            infix(node->right);
            cout << ")";
        }
    }
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
  by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode *node){
    if(node == NULL) return;
    else{
        cout<<node->data;
        prefix(node->left);
        prefix(node->right);
    }
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
  by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode * node){
    
    if(node->left == NULL || node->right == NULL) cout<<node->data;
    else{
        postfix(node->left);
        postfix(node->right);
        
        cout << node->data;
    }
}

/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream &oF, TreeNode *node){
    if (node!=NULL) {
        oF << node->key << "[ label = " << "\"" << node->data << "\"" << " ]" <<endl;
        
        if (node->left != NULL) {
            oF  << node->key <<  "->" << node->left->key << "[ label = " << "\"" << node->left->data << "\"" << " ]\n";
            visualizeTree(oF, node->left);
        }
        if (node->right) {
            oF<< node->key << " -> " << node->right->key << "[ label =  " << "\"" << node->right->data << "\"" << " ]\n";
            visualizeTree(oF, node->right);
        }

        oF << "\n";
    }
}
