#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** head_ref, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref=newnode;
        return;
    }
    
    Node* last = *head_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
}

void deleteLast(Node** head_ref){
    if(*head_ref == NULL) return;
    if((*head_ref)->next == NULL){
        delete *head_ref;
        //just this line
        *head_ref = NULL;
        return;
    }
    
    Node* sec_las = *head_ref;
    while(sec_las->next->next != NULL){
        sec_las = sec_las->next;
    }
    //same as ahead brother;
    delete (sec_las->next);
    sec_las->next = NULL;
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"NULL";
}

int main(){
    Node* head = NULL;
    append(&head, 10);
    append(&head, 35);
    append(&head, 50);
    printList(head);
    deleteLast(&head);
    printList(head);
    return 0;
}

// void deleteLast(Node** head_ref){
//     if(*head_ref == NULL) return;
//     if((*head_ref)->next == NULL){
//         delete *head_ref;
//         *head_ref = NULL;
//         return;
//     }
//     Node* sec_las = *head_ref;
//     while((sec_las)->next->next != NULL){
//         sec_las = sec_las->next;
//     }
//     delete (sec_las->next);
//     sec_las->next = NULL;
// }