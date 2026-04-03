#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node** hr, int nd){
    Node* nn = new Node();
    nn->data = nd;
    nn->next = NULL;
    
    if(*hr == NULL){
        *hr = nn;
        return;
    }
    
    Node* l = *hr;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = nn;
}

void dL(Node** hr){
    if(*hr == NULL) return;
    if((*hr)->next == NULL){
        delete *hr;
        *hr = NULL;
        return;
    }
    Node* sL = *hr;
    while(sL->next->next != NULL){
        sL = sL->next;
    }
    delete (sL->next);
    sL->next = NULL;
}



void insertAft(Node* Perv, int nd){
    if(Perv == NULL){
        cout<<"Perv head doesn't exist";
    }
    
    Node* nn = new Node();
    nn->data = nd;
    nn->next = Perv->next;
    Perv->next = nn;
}

void insertAftValue(Node* head, int tv, int nd){
    // insert after target value
    Node* current = head;
    // find node with tv
    while(current != NULL && current->data != tv){
        current = current->next;
    }
    
    if(current != NULL){
        // if found
        Node* newnode = new Node();
        newnode->data = nd;
        newnode->next = current->next;
        current->next = newnode;
    } else {
        cout<<"Not found\n";
    }
}

void pL(Node* node){
    while(node != NULL){
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"VOId\n";
}

int main(){
    Node* h = NULL;
    append(&h, 10);
    append(&h, 20);
    append(&h, 30);
    pL(h);
    insertAft(h->next, 22);
    pL(h);
    insertAftValue(h, 22, 25);
    pL(h);
    dL(&h);
    pL(h);
    
    return 0;
    
}
