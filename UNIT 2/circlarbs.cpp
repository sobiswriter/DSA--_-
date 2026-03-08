#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 1. ADD TO THE CAROUSEL
void insertCLL(Node** head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    
    // If the carousel is empty, start it!
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // It points to ITSELF! The loop begins.
        return;
    }
    
    // Walk to the last carriage
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    
    // Connect the new carriage
    temp->next = newNode;
    newNode->next = *head; // Make sure the new last carriage points to the head
}

// 2. SURGICAL DELETE FROM THE CAROUSEL
void deleteCLL(Node** head, int key) {
    if (*head == NULL) return;
    
    Node *curr = *head, *prev = NULL;
    
    // Find the carriage
    while (curr->data != key) {
        if (curr->next == *head) {
            cout << "She ain't in the carousel, girly! ;_;\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    // Scenario A: It's the ONLY carriage left
    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        delete curr;
        return;
    }
    
    // Scenario B: We are deleting the HEAD
    if (curr == *head) {
        prev = *head;
        // We have to walk all the way around to tell the last carriage about the new head!
        while (prev->next != *head) prev = prev->next;
        *head = curr->next;
        prev->next = *head;
        delete curr;
    } 
    // Scenario C: Deleting from the middle or end
    else {
        prev->next = curr->next;
        delete curr;
    }
}

// 3. PRINT THE CAROUSEL (The do-while magic)
void displayCLL(Node* head) {
    if (head == NULL) {
        cout << "Carousel is empty!\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ~O~ ";
        temp = temp->next;
    } while (temp != head);
    
    cout << "(Loops back to " << head->data << ")\n";
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