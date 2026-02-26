#include <iostream>
using namespace std;

//1. struct a node, it's just new data and * next;
struct Node{
    int data;
    Node* next;
};

//2. the append func: with headref & data
void append(Node** head_ref, int new_data){
    //2.1 make a newnode & point it to data(no need for int tho);
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL; //point to next node i.e. Null;
    
    //2.2 if head is Null, make it newnode;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    //2.3 Make a last node & refer it to head;
    Node* last = *head_ref;
    
    //2.3 while nextnode is not Null, move to next node until NULL;
    while(last->next != NULL){
        last=last->next;
    }
    last->next = new_node;

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
    append(&head, 10);
    append(&head, 20);
    append(&head, 40);
    
    printList(head);
    return 0;
}

// void append(Node** head_ref, int new_node){
//     int Node* new_node = new Node();
//     new_node->data = new_data;
//     new_node->next = NULL;
//     if(*head_ref == NULL){
//         *head_ref = new_node;
//         return;
//     }
//     Node* last = head_ref;
//     while(last->next != NULL){
//         last= lat->next;
//     }
//     last->next = new_node;
// }


// void append(Node** head_ref, int new_data){
//     Node* new_node = new Node();
//     new_node->data = new_data;
//     new_node->next = NULL;
    
//     if(*head_ref == NULL){
//         *head_ref = new_node;
//         return;
//     }
    
//     Node* last = head_ref;
//     while(last->next != NULL){
//         last = last->next;
//     }
//     last->next = new_node;
// }