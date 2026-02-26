#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** head_ref, int new_data){
    //Make a node;
    Node* new_node = new Node();
    new_node->data = new_data;
    //also next node is null
    new_node->next = NULL;
    //if no nodes, new node is head;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    //Start at head walk to the end;
    Node* last = *head_ref;
    while(last->next != NULL){
        last = last->next; //move to last
    }
    last->next = new_node; //perhaps we're adding shit from behind;
    
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