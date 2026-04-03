#include <iostream>
using namespace std;

int q[5];
int front = -1;
int rear = -1;

void enqueue(int x) {
    // enqueue, add to rear
    if (rear == 4) cout << "Queue is Full!\n";
    else {
        if (front == -1) front = 0;
        // if first element, set front
        q[++rear] = x;
        // add to rear
        cout << "Enqueued " << x << "\n";
    }
}

void dequeue(){
    // dequeue, remove from front
    if(front == -1 || front > rear){
        cout<<"Queue empty\n";
    } else {
        cout<<"Dequeued "<<q[front++]<<"\n";
    }
}

void printQueue(){
    // print queue
    if(front == -1 || front > rear){
        cout<<"Queue empty\n";
    } else {
        cout<<"Queue: ";
        for(int i = front; i <= rear; i++){
            cout<<q[i]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    enqueue(10);
    enqueue(15);
    enqueue(20);
    printQueue();
    dequeue();
    printQueue();
    return 0;
}