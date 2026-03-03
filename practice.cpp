#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** h_ref, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode-> next = NULL;
    
    if(*h_ref == NULL){
        *h_ref=newnode;
        return;
    }
    Node* last = *h_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
}

void insertAftValue(Node* prev, int tv, int nv){
    Node* current = prev;
    while(current != NULL && current->data != tv){
        current=current->next;
    }
    
    if(current != NULL){
        Node* newnode = new Node();
        newnode->data = nv;
        newnode->next = current->next;
        current->next = newnode;
    } else {
        cout<<"we couldn't find her\n";
    }
}

void deleteAftValue(Node** prev, int tv){
    Node* current = *prev;
    while(current != NULL && current->data != tv){
        current=current->next;
    }
    
    if(current != NULL && current->next != NULL){
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    } else {
        cout<<"couldn't find her geez\n";
    }
    
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<"NULL\n";
}

int main(){
    Node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printList(head);
    insertAftValue(head, 20, 25);
    printList(head);
    deleteAftValue(&head, 20);
    printList(head);
    return 0;
}