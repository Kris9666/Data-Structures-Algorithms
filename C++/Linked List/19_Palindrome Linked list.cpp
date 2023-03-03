// Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome.
// Input: head = [1,2,2,1]
// Output: true

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next=NULL;
    }
};
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
bool isPalindrome(node* head, node* newhead){
    node* inc = head;
    node* dec = newhead;
    while(inc!=NULL && dec!=NULL){
        if (inc->data == dec->data){
            return true;
        }
        inc = inc->next;
        dec = dec->next;
    }
    return false;
}
int main(){
    node* head = NULL;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
        insertAtTail(head, arr[i]);
    }
    display(head);
    node* newhead = reverse(head);
    display(newhead);
    cout<<isPalindrome(head, newhead)<<endl;
    return 0;
}