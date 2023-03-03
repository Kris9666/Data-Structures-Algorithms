// Given a non-empty, singly linked list with head node head, return a middle node of 
// linked list.
// If there are two middle nodes, return the second middle node.
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
    if(head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp =  temp->next;
    }
    temp->next = n;
}
void display (node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void middleNode (node* head){
    node* slowptr = head;
    node* fastptr = head;

    if (head!=NULL){
        while(fastptr!=NULL && fastptr->next!=NULL){
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }
        cout<<"The middle element is ["<<slowptr->data<<"]"<<endl;
    }
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
    middleNode(head);
    return 0;
}