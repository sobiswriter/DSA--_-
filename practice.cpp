#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);
    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

//transversal
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//delete
Node* finMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key){
    if(root == NULL) return NULL;
    if(key < root->data){
        root->left = delNode(root->left, key);
    } else if (key > root->data){
        root->right = delNode(root->right, key);
    } else {
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        } else if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = finMin(root->right);
            root->data =  temp->data;
            root->right = delNode(root->right, temp->data);
        }
    }
    return root;
    
    
}

int main(){
    Node* root = NULL;
    int arr[5] = {12, 19, 10, 5, 20};
    
    for(int x: arr){
        root = insert(root, x);
        //thsi si the last thime ti shoudl ahppen ehnce I'll specially write it down, no jot it doan twoice
    }
    for (int i: arr){
        root = insert(root, i);
    }
    for (int j: arr){
        root = insert(root, j);
    }
    for (int k: arr){
        root =  insert(root, k);
    }
    
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\n";
    
    root = delNode(root, 5);
    root = delNode(root, 5);
    root = delNode(root, 5);
    root = delNode(root, 5);
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\n";
    
    return 0;
}