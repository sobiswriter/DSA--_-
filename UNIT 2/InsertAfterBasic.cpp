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
        *head_ref = newnode;
        return;
    }
    
    Node* last = *head_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
}


void insAft(Node* pervNode, int newdata){
    // insert after given node
    if(pervNode == NULL){
        cout<<"No prev node\n";
        return;
    }
    
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = pervNode->next;
    // set new->next to prev->next
    pervNode->next = newnode;
    // set prev->next to new
}


void deleteLast(Node** head_ref){
    if(*head_ref == NULL) return;
    if((*head_ref)->next == NULL){
        delete (*head_ref);
        *head_ref = NULL;
        return;
    }
    
    Node* sec_last = *head_ref;
    while((sec_last)->next->next != NULL){
        sec_last = sec_last->next;
    }
    delete (sec_last->next);
    sec_last->next = NULL;
    return;
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" => ";
        node = node->next;
    }
    cout<<"NULL \n";
}

int main(){
    Node* head = NULL;
    append(&head, 20);
    append(&head, 30);
    printList(head);
    insAft(head, 25); // it only adds after the first head element.
    printList(head);
    //here lets try putting after the sec element;
    insAft(head->next, 27);
    printList(head);
    // see now, that's definitely how ur supposed to use it, or u can make an element and use it as well
    //like sec = head->next->next see ;)
    deleteLast(&head);
    printList(head);
    deleteLast(&head);
    printList(head);
    deleteLast(&head);
    printList(head);
    return 0;
}