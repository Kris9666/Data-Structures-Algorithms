// Height Balanced and Unbalanced tree 

// 1st Method 
// Time Complexity = O(n)^2 
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(Node* root){
    if (root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}
bool isBalance(Node* root){
    if (root == NULL){
        return true;
    }
    if (isBalance(root->left) == false){
        return false;
    }
    if (isBalance(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if(isBalance(root2)){
        cout<<"Balanced Tree";
    }
    else{
        cout<<"Unbalanced Tree";
    }
    return 0;
}

// 2nd Method 
// Time Complexity = O(n) 
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isBalance(Node* root, int* height){
    if (root == NULL){
        return true;
    }
    int lh = 0, rh = 0;
    if(isBalance(root->left,&lh) == false){
        return false;
    }
    if (isBalance(root->right,&rh) == false){
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    int height = 0;
    if(isBalance(root2, &height) == true){
        cout<<"Balanced Tree";
    }
    else{
        cout<<"Unbalanced Tree";
    }
    return 0;
}