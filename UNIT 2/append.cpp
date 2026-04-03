#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data){
    // append to linked list, takes head ref and new data
    Node* new_node = new Node();
    // create new node
    new_node->data = new_data;
    new_node->next = NULL;
    // set data and next to null
    if(*head_ref == NULL){
        // if list empty, set head to new node
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    // start from head
    while(last->next != NULL){
        // traverse to last node
        last = last->next;
    }
    last->next = new_node;
    // set last->next to new node
}

void printList(Node* node) {
    while(node != NULL){
        //u can change here from data to next and it will literally give u addresses.
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"NULL";
}

int main(){
    Node* head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    
    cout<<"Here is ur Node: ";
    printList(head);
    
    return 0;
}