// Possible Binary Search Trees  

#include<iostream>
#include<vector>
#include<algorithm>
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
vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if (start > end){
        trees.push_back(NULL);
        return trees;
    }
    for (int i=start; i<=end; i++){
        vector<Node*> leftsubTrees = constructTrees(start, i-1);
        vector<Node*> rightsubTrees = constructTrees(i+1, end);

        for (int j=0; j<leftsubTrees.size(); j++){
            Node* left = leftsubTrees[j];
            for (int k=0; k<rightsubTrees.size(); k++){
                Node* right = rightsubTrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        } 
    }
    return trees;
}
void preorder(Node* root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<Node*> totalTrees = constructTrees(1,3);
    for (int i=0; i<totalTrees.size(); i++){
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}