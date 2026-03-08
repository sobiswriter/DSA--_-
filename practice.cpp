#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* perv;
    Node* next;
};

void insertF(Node** head, Node** tale, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = (*head);
    newnode->perv = NULL;
    
    if((*head) != NULL){
        (*head)->perv = newnode;
    } else {
        (*tale) = newnode;
    }
    (*head) = newnode;
}

void insertB(Node** head, Node** tale, int newdata){
    Node* newnode = new Node();
    newnode->data = newdata;
    newnode->next = NULL;
    newnode->perv = (*tale);
    
    if((*tale) != NULL){
        (*tale)->next = newnode;
    } else {
        (*head) = newnode;
    }
    (*tale) = newnode;
}

void DelByVal(Node** head, Node** tale, int del){
    Node* current = *head;
    
    while(current != NULL && current->data != del){
        current=current->next;
    }
    
    if(current == *head){
        *head = current->next;
    }
    
    if(current->next == NULL){
        *tale = current->perv;
    }
    
    if(current->next != NULL){
        current->perv->next = current->next;
    }
    
    if(current->perv != NULL){
        current->next->perv = current->perv;
    }
    
    delete current;
}


// void insertB(Node** head, Node** tale, int newdata){
//     Node* newnode = new Node();
//     newnode->data = newdata;
//     newnode->next = NULL;
//     newnode->perv = (*tale);
    
//     if((*tale) != NULL){
//         (*tale)->next = newnode;
//     } else {
//         (*head) = newnode;
//     } 
//     (*tale) = newnode;
// }

// void insertF(Node** head, Node** tale, int newdata){
//     Node* newnode = new Node();
//     newnode->data = newdata;
//     newnode->next = (*head);
//     newnode->perv = NULL;
    
//     if((*head) != NULL){
//         (*head)->perv = newnode;
//     } else {
//         (*tale)= newnode;
//     }
//     (*head) =  newnode;
// }

// void DelByVal(Node** head, Node** tale, int del){
//     Node* current = (*head);
//     while(current != NULL && current->data != del){
//         current=current->next;
//     }
    
//     if(current->next == NULL){
//         *tale = current->perv;
//     }
    
//     if(current == NULL){
//         cout<<"can't find her";
//         return;
//     }
    
//     if(*head == current){
//         *head = current->next;
//     }
    
//     if(current->next != NULL){
//         current->perv->next = current->next;
//     }
    
//     if(current->perv != NULL){
//         current->next->perv = current->perv;
//     }
    
//     delete current;
// }


void printList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" -> ";
        node=node->next;
    }
    cout<<"Hola\n";
}

int main(){
    Node* head = NULL;
    Node* tale = NULL;
    insertF(&head, &tale, 10);
    insertF(&head, &tale, 20);
    insertB(&head, &tale, 30);
    insertB(&head, &tale, 40);
    printList(head);
    DelByVal(&head, &tale, 10);
    printList(head);
    return 0;
}














