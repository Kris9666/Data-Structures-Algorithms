// Deletion in Linked List (from head as well from tail)

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
void insertatTail(node* &head, int val){
    
    node* n = new node(val);
    if (head==NULL){
        head = n;
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
void deleteAtHead(node* &head){     //detetion for head element
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node* &head, int val){     //deletion from last element
    if (head==NULL){      //if list is null
        return;
    }
    if (head->next==NULL){    //if list has a only 1 element
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}
int main(){
    node* head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,4);
    insertatTail(head,3);
    display(head);
    deletion(head,3);
    // deleteAtHead(head);
    display(head);
    return 0;
}