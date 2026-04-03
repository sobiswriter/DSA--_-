#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data){
    // append to list
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while(last->next != NULL){
        last=last->next;
    }
    last->next = new_node;
}

void deleteLast(Node** head_ref){
    // delete last node
    if(*head_ref == NULL) return;
    if((*head_ref) -> next == NULL){
        // only one node
        delete *head_ref;
        *head_ref = NULL;
        return;
    }
    Node* sec_last = *head_ref;
    // find second last
    while(sec_last->next->next != NULL){
        sec_last = sec_last->next;
    }
    delete (sec_last->next);
    sec_last->next = NULL;
}

//3. Print stuff uising pl func, n* node yk
void printList(Node* node){
    //3.1 while node is not null, print n->d and move to next n=n->n
    while(node != NULL){
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"NULL";
}

//4.Main func;
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