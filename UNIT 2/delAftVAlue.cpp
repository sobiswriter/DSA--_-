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
// Let's try
void delAftValue(Node** head, int tv){
    Node* h = *head;
    while(h != NULL && h->data != tv){
        h = h->next;
    }
    //cout<<"Found it: "<<h->data<<"\n";
    if(h != NULL && h->next != NULL){ //making sure we don't it works even if the target value is the last node.
    Node* temp = h->next;
    h->next = temp->next;
    
    delete temp;
    } else {
        cout<<"Couldn't find her, or she's the last carriage bruh ;_; \n";
    }

    //say u wanna delete everything after value tho, simple >_<
    // delete (h->next);
    // h->next = NULL;
}
//BOOM we got it all by ourself heheh, take that Niva ;)

void insertAft(Node* Perv, int nd){
    if(Perv == NULL){
        cout<<"Perv head doesn't exist";
        return;
    }
    
    Node* nn = new Node();
    nn->data = nd;
    nn->next = Perv->next;
    Perv->next = nn;
}

//insertAV uses the current head, a target int value & the newVAlue as well to work
void insertAftValue(Node* head, int tv, int nd){
    Node* current = head;
    //Just go through it, ain't that tuff ;)
    while(current != NULL && current->data != tv){
        current = current->next;
    }
    
    if(current != NULL){
        Node* newnode = new Node();
        newnode->data = nd;
        newnode->next = current->next;
        current->next = newnode;
    } else {
        cout<<"Sorry couldn't find the girl ;_;\n";
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
    delAftValue(&h, 20); //Just enter the prev value u wanna delete hehe
    pL(h);
    dL(&h);
    pL(h);
    
    return 0;
    
}
