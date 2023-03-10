// Diameter of a Binary Tree 
// Time Complexity = O(n)^2  

// 1st Method 
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
int calcHeight(Node* root){
    if (root == NULL){
        return 0;
    }
    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}
int calcDiameter(Node* root){
    if (root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<calcDiameter(root)<<endl;
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
int calcDiameter(Node* root, int* height){
    if (root == NULL){
        *height = 0;
        return 0;
    }
    int lh=0, rh=0;
    int lDiameter = calcDiameter(root->left, &lh);
    int rDiameter = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    cout<<calcDiameter(root, &height)<<endl;
    return 0;
}