#include <iostream>
using namespace std;

int q[5];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == 4) cout << "Queue is Full!\n";
    else {
        if (front == -1) front = 0;
        q[++rear] = x;
        cout << "Enqueued " << x << "\n";
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        cout<<"No one's left\n";
    } else {
        cout<<"Sending "<<q[front++]<<" out\n";
    }
}

void printQueue(){
    if(front == -1 || front > rear){
        cout<<"No one to print ;_;";
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