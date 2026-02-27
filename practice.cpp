#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** head_ref, int newdata){
    Node* newnode = new Node();
    newnode -> data = newdata;
    newnode -> next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = newnode;
        return;
    }
    
    Node* last = *head_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"NULL \n";
}

void deleteLast(Node** head_ref){
    if(*head_ref == NULL) return;
    if((*head_ref) -> next == NULL){
        delete *head_ref;
        //forgot this line, for some reason works without it as well ;)
        *head_ref = NULL;
        return;
    }
    Node* sec_last = *head_ref;
    while(sec_last->next->next != NULL){
        sec_last = sec_last->next;
    }
    
    delete (sec_last->next);
    sec_last->next = NULL;
    
}

int main(){
    Node* head = NULL;
    append(&head, 9);
    append(&head, 10);
    append(&head, 11);
    
    printList(head);
    
    deleteLast(&head);
    printList(head);
    return 0;
}