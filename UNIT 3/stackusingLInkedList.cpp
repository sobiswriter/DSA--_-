#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* perv;
};

//push in place of insertFront
void push(Node** head, Node** tale, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = *head;
    newnode->perv = NULL;
    
    if((*head) != NULL){
        (*head)->perv = newnode;
    } else {
        (*tale) = newnode;
    }
    (*head) = newnode;
    cout<<"Pushed "<<newdata<<"\n";
}

//pop in place of delete;
void pop(Node** head){
    cout<<"Popped "<<(*head)->data<<"\n";
    if((*head) == NULL) return;
    Node* temp = (*head);
    (*head) = (*head)->next;
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