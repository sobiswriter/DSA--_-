#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* perv;
    Node* next;
};

//THis is ur versitility at peak func ;)

void insertF(Node** head, Node** tale, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->perv = NULL;
    newnode->next = (*head);
    
    if((*head) != NULL){
        (*head)->perv = newnode;
    } else {
        *tale = newnode;
    }
    (*head) = newnode;
}

void insertB(Node** head, Node** tale, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = NULL;
    newnode->perv = (*tale);
    
    if(*tale != NULL){
        (*tale)->next = newnode;
    } else {
        *head = newnode;
    }
    (*tale) = newnode;
}

void delByValDDL(Node** head, Node** tale, int del){
    Node* current = *head;
    
    while(current != NULL && current->data != del){
        current = current->next;
    }
    
    if(current == NULL){
        cout<<"Aeo she aint dere gurl ;D\n";
        return;
    }
    
    if(current->next == NULL){
        *tale = current->perv;
    }
    
    if(*head == current){
        *head = current->next;
    }
    
    if(current->next != NULL){
        current->next->perv = current->perv;
    }
    
    if(current->perv != NULL){
        current->perv->next = current->next;
    }
    
    delete current;
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" T_T ";
        node = node->next;
    }
    cout<<"Hello\n";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertF(&head, &tail, 10);
    insertF(&head, &tail, 20);
    insertF(&head, &tail, 30);
    printList(head);
    insertB(&head, &tail, 40);
    insertB(&head, &tail, 50);
    printList(head);
    delByValDDL(&head, 10);
    printList(head);
    return 0;
}

