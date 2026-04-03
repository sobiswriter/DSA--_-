#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void push(int x){
    // push to stack
    if (top == 4){
        cout<<"Stack Overflow\n";
    } else {
        stack[++top] = x;
        // increment top and add
        cout<<"Pushed "<< x <<"\n";
    }
}

void pop(){
    // pop from stack
    if (top == -1){
        cout<<"Stack Underflow\n";
    } else {
        cout<<"Popped "<<stack[top--]<<" \n";
        // get top and decrement
    }
}

void printStack(){
    // print stack from top to bottom
    if (top==-1){
        cout<<"Stack empty\n";
    } else {
        cout<<"Stack: ";
        for(int i=top; i>=0; i--) cout<<stack[i]<<" ";
        cout<<"\n";
    }
}
int main(){
    pop();
    push(10);
    push(20);
    printStack();
    pop();
    printStack();
    push(30);
    push(40);
    push(50);
    push(60);
    printStack();
    push(70);
    printStack();
    return 0;
}