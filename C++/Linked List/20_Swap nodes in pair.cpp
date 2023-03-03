// Swap nodes in pair.
// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes 
// (i.e., only nodes themselves may be changed.)
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
 
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAttail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reverseTwo(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr!=NULL){
        head->next = reverseTwo(nextptr,k);
    }
    return prevptr;
}
int main(){
    node* head = NULL;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
        insertAttail(head,arr[i]);    
    }
    display(head);
    int k = 2;
    node* newhead = reverseTwo(head,k);
    display(newhead);
    return 0;
}