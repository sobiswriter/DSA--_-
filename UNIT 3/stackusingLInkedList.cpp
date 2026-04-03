#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* perv;
};

// push: insert at front
void push(Node** head, Node** tale, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = *head;
    // set next to current head
    newnode->perv = NULL;
    
    if((*head) != NULL){
        (*head)->perv = newnode;
        // update prev of old head
    } else {
        (*tale) = newnode;
        // if empty, set tail
    }
    (*head) = newnode;
    // update head
    cout<<"Pushed "<<newdata<<"\n";
}

// pop: delete front
void pop(Node** head){
    if((*head) == NULL) {
        cout<<"Stack empty\n";
        return;
    }
    cout<<"Popped "<<(*head)->data<<"\n";
    Node* temp = (*head);
    (*head) = (*head)->next;
    // move head to next
    delete temp;
}

//printStack in place of printList
void printList(Node* node){
    cout<<"Stack:";
    while(node != NULL){
        cout<<node->data<<" ";
        node= node->next;
    }
    cout<<"\n";
}

int main(){
    
    Node* head = NULL;
    Node* tale = NULL;
    push(&head, &tale, 10);
    push(&head, &tale, 20);
    push(&head, &tale, 30);
    printList(head);
    pop(&head);
    printList(head);
    
    return 0;
}