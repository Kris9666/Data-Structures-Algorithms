// Search in Binary search tress 
// TimeComplexity = O(log n) 

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* searchinBST(Node* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (root->data == key){
        return root;
    }
    if (root->data > key){
        return searchinBST(root->left, key);
    }
    return searchinBST(root->right, key);
}
int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    if (searchinBST(root, 5) == NULL){
        cout<<"Key doesn't exist";
    }
    else{
        cout<<"Key exists";
    }
    return 0;
}