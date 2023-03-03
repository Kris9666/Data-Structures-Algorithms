// Write a function to delete a node in a singly-linked list. You will not be given 
// access to the head of the list, instead you will be given access to the node to be 
// deleted directly.
// It is guaranteed that the node to be deleted is not a tail node in the list.
// Input =  head = [4,5,1,9], node = 5
// Output: [4,1,9]

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head=n;
        return ;
    }
    node* temp=head;
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
void deleteAtHead(node* head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node* &head, int val){
    if (head==NULL){
        return;
    }
    if (head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main(){
    node* head = NULL;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
        insertAtTail(head,arr[i]);
    }
    display(head);
    int p;
    cin>>p;
    deletion(head,p);
    display(head);
    return 0;
}
 