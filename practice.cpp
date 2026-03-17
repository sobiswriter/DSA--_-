#include <iostream>
using namespace std;

int que[5];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == 4){
        cout<<"Que is full\n";
    } else {
        if(front == -1) front = 0;
        que[++rear] = x;
        cout<<"Qued "<<x<<"\n";
    }
}

void dequeue(){
    if(rear == -1){
        cout<<"It's an empty que\n";
    } else {
        cout<<"Dequed "<<que[front++]<<"\n";
    }
}

void printQueue(){
    if(rear == -1 || front > rear){
        cout<<"Empty again\n";
    } else {
        cout<<"QueL: ";
        for(int i = front; i<=rear; i++){
            cout<<que[i]<<" ";
        }
        cout<<"\n";
    }
}

// void enqueue(int x){
//     if (rear == 4){
//         cout<<"Quw is full\n";
//     } else {
//         if (front = 0) front = 1;
//         que[++rear] = x;
//         cout<<"Enqued "<<x<<"\n";
//     }
// }

// void dequeue(){
//     if(rear == -1){
//         cout<<"QW is empty\n";
//     } else {
//         cout<<"Dequed "<<que[front++]<<"\n";
//     }
// }

// void printQueue(){
//     if(rear == -1 || front > rear){
//         cout<<"The QW is empty yr\n";
//     } else {
//         cout<<"Que: ";
//         for(int i = front; i<=rear; i++){
//             cout<<que[i]<<" ";
//         }
//         cout<<"\n";
//     }
// }

int main(){
    dequeue();
    enqueue(10);
    enqueue(15);
    enqueue(20);
    printQueue();
    enqueue(56);
    enqueue(57);
    enqueue(88);
    printQueue();
    dequeue();
    printQueue();
    return 0;
}