#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// insert into circular linked list
void insertCLL(Node** head, int val) {
    Node* newNode = new Node();
    // create new node
    newNode->data = val;
    
    if (*head == NULL) {
        // if empty, set head and next to itself
        *head = newNode;
        newNode->next = *head;
        return;
    }
    
    Node* temp = *head;
    // find last node
    while (temp->next != *head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    // connect last to new
    newNode->next = *head;
    // new to head
}

// delete from circular linked list
void deleteCLL(Node** head, int key) {
    if (*head == NULL) return;
    // if empty, return
    
    Node *curr = *head, *prev = NULL;
    
    while (curr->data != key) {
        // find the node
        if (curr->next == *head) {
            cout << "Not found\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    if (curr->next == *head && prev == NULL) {
        // only one node
        *head = NULL;
        delete curr;
        return;
    }
    
    if (curr == *head) {
        // deleting head
        prev = *head;
        while (prev->next != *head) prev = prev->next;
        *head = curr->next;
        prev->next = *head;
        delete curr;
    } 
    else {
        // middle or end
        prev->next = curr->next;
        delete curr;
    }
}

// print circular linked list
void displayCLL(Node* head) {
    if (head == NULL) {
        cout << "Empty\n";
        return;
    }
    Node* temp = head;
    do {
        // use do-while for circular
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    cout << "\n";
}

int main() {
    Node* head = NULL;
    
    insertCLL(&head, 10);
    insertCLL(&head, 20);
    insertCLL(&head, 30);
    displayCLL(head); // 10 ~O~ 20 ~O~ 30 ~O~ (Loops back to 10)
    
    deleteCLL(&head, 20); // Delete a middle guy
    displayCLL(head);     // 10 ~O~ 30 ~O~ (Loops back to 10)
    
    deleteCLL(&head, 10); // Delete the head
    displayCLL(head);     // 30 ~O~ (Loops back to 30)
    
    return 0;
}