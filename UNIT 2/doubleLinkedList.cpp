#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* perv; // prev pointer
    Node* next;
};

void insertF(Node** head_ref, int newdata){
    // insert at front for double linked list
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->perv = NULL;
    newnode->next = (*head_ref);
    
    if((*head_ref) != NULL){
        // if head exists, set its prev to new
        (*head_ref)->perv = newnode;
    }
    (*head_ref) = newnode;
    // set head to new
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" -_- ";
        node = node->next;
    }
    cout<<"NULL";
}

int main(){
    Node* head = NULL;
    insertF(&head, 10);
    insertF(&head, 20);
    insertF(&head, 30);
    printList(head);
    return 0;
}
