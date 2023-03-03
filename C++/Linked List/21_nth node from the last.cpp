// nth node from the last
// Given the head of a linked list, remove the nth node from the end of the list 
// and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output : [1,2,3,5]

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
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head = n;
        return ;
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
node* nthNode(node* head, int n){
    node* start = new node(n);
    start->next = head;
    node* slowptr = start;
    node* fastptr = start;
    for (int i=0; i<n; i++){
        fastptr = fastptr->next;
    }
    while(fastptr->next!=NULL){
        fastptr = fastptr->next;
        slowptr = slowptr->next; 
    }
    slowptr->next = slowptr->next->next;
    return start->next;
}
int main(){
    node* head = NULL;
    int m;
    cin>>m;
    int arr[m];
    for (int i=0; i<m; i++){
        cin>>arr[i];
        insertAtTail(head, arr[i]);
    }
    display(head);
    int n;
    cin>>n;
    node* newhead = nthNode(head,n);
    display(newhead);
    return 0;
}