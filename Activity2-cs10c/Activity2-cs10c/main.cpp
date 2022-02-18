/*
 Activity 2 Work- Anika Sood
 
 */
//____________________________________PROBLEM 2____________________________________//
/*
 Get the height of a tree
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;
struct tree_node{
    int value;
    tree_node *left, *right;
};

tree_node* root = NULL;
/*
 Tree operations
 */
tree_node* insert(tree_node* node_ptr, int data) {
    if (node_ptr == NULL) {
        node_ptr = new tree_node;
        node_ptr->value  = data;
        node_ptr->left  = NULL;
        node_ptr->right = NULL;
        if(root == NULL)
            root = node_ptr;
        return node_ptr;
    }
    if (data >  node_ptr->value) {
        node_ptr->right = insert(node_ptr->right, data);
        return node_ptr;
    }
    if (data <= node_ptr->value) {
        node_ptr->left  = insert(node_ptr->left, data);
        return node_ptr;
    }
    return nullptr;
}

void traverse_preorder(tree_node* node_ptr) {
    if(node_ptr == NULL) return;
    cout << node_ptr->value;
    traverse_preorder(node_ptr->left);
    traverse_preorder(node_ptr->right);
}

/*
 Get the height of a tree
 Complexity: O(n)
 */
int height(tree_node* curr){
    
    //if the current node is null return -1
    if(curr == NULL)
        return -1;
    else{
        int leftH = height(curr->left); //calculate height of left subtree
        int rightH = height(curr->right); //calculate the height of right subtree
        
        //return whichever subtree is larger
        if(leftH>rightH)
            return(leftH +1);
        else
            return (rightH +1);
    }
}

/*
 Get the sum of all values in the tree
 Complexity: O(n)
 */
int sum(tree_node* curr){
    if(curr == NULL)
        return -1;
    
    //root + left subtree + right subtree
    return (curr->value + sum(curr->left) +sum(curr->right));
}

/*
 Search for an int x and return true or false
 Complexity: O(n)
 */
bool search(tree_node* curr, int x){
    //false if not found & reached null ptr
    if(curr == NULL)
        return false;
    
    //true if found
    if(curr->value == x)
        return true;
    //search left and right subtrees
    bool LHS = search (curr->left, x);
    bool RHS = search(curr->right, x);
    
    //return result of searching both subtrees
    if(LHS == true || RHS == true)
        return true;
    else
        return false;
}
/*
 Get # of nodes at each level
 Complexity: O(H*n)
 */
int getWidth(tree_node* node, int level){
    if(node == NULL)
        return 0;
    if(level == 0)
        return 1;
    if(level>0)
        return (getWidth(node->left, level-1) + getWidth(node->right, level-1));
    return 0;
}

vector<int> getList(tree_node* root){
    vector<int> myList;
    int width;
    int myHeight = height(root);
    
    //get the width of each level and add each to the list
    for(int i = 0; i<myHeight; i++){
        width = getWidth(root, i);
        myList.push_back(width);
    }
    
    return myList;
}

//____________________________________PROBLEM 3____________________________________//
/*
 Convert infix to postfix
 ex: (2 + 3) ∗ 5 + 7 − 10
 in postfix is
 2 3 + 5 * 7 + 10 -


 */
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;
}

int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(stack<char> s, string infix)
{
    string postfix;
    for(int i=0; i<infix.length(); i++)
    {
        if(isdigit(infix[i]))
            postfix+=infix[i];
        else if(infix[i] == '(')
            s.push(infix[i]);
        else if(infix[i] == ')')
        {
            while((s.top()!='(') && (!s.empty())){
                char temp=s.top();
                postfix+=temp;
                s.pop();
            }
            
            if(s.top()=='('){
                s.pop();
            }
        }
        else if(isOperator(infix[i])){
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if(precedence(infix[i])>precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
                    {
                        postfix+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    
    return postfix;
}


double evalPost(string post){
    
    stack<int> myStack;
    
    for(int i = 0; i<post.length(); i++){
        if(isdigit(post[i]))
            myStack.push((int)(post[i]));
        else {
           int a = myStack.top();
            myStack.pop();

           int b = myStack.top();
            myStack.pop();

           // evaluate the expression 'x op y', and push the
           // result back to the stack
           if (post[i] == '+') {
               myStack.push(a + b);
           }
           else if (post[i] == '-') {
               myStack.push(b - a);
           }
           else if (post[i] == '*') {
               myStack.push(b * a);
           }
           else if (post[i] == '/') {
               myStack.push(b / a);
           }
        }
    }
    
    return myStack.top();
}

int main(){
    
    int input;
    do{
        cout<<"Enter an int to add to tree: ";
        cin>>input;
        if(input != -1)
            insert(root, input);
        
    }
    while(input != -1);
    
    cout<<"Preorder traversal: ";
    traverse_preorder(root);
    cout<<endl<<endl;
    
    cout<<"Tree height: ";
    cout<<height(root);
    cout<<endl<<endl;
    
    int find;
    cout<<"Enter value to search for: ";
    cin>>find;
    cout<<"\n Result: "<<search(root, find)<<endl<<endl;
    
    cout<<"List of widths: [";
    vector<int> list = getList(root);
    for(int i = 0; i< list.size(); i++){
        cout<<list.at(i);
    }
    cout<<"]"<<endl<<endl;
    
    return 0;
}

