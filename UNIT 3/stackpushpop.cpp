#include <iostream>
using namespace std;

int stack[5];
int top = -1;

void push(int x){
    if (top == 4){
        cout<<"Stack Overflow\n";
    } else {
        stack[++top] = x;
        cout<<"Pushed "<< x <<"\n";
    }
}

void pop(){
    if (top == -1){
        cout<<"Stack Underflow\n";
    } else {
        cout<<"Popped "<<stack[top--]<<" \n";
    }
}

void printStack(){
    if (top==-1){
        cout<<"Stack's empty\n";
    } else {
        cout<<"Stack: ";
        for(int i=top; i>=0; i--) cout<<stack[i]<<" ";
        //didn't knew using paranthesis over here actaully had some meaning cool -_-
        cout<<"\n";
    }
}
//sry but I need the commit
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