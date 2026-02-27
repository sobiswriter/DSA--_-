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

//5. This is the delete last node func, with headref;
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