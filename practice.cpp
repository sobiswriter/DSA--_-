#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left=right=NULL;
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

bool search(Node* root, int key){
    if(root == NULL) return false;
    if(key == root->data) return true;
    
    if(key < root->data)
        return search(root->left, key);
    else;
        return search(root->right, key);
}


void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    
    int n;
    cout<<"Hello >_< Input size of ur array below:- \nSize: ";
    cin>>n;
    int arr[n];
    cout<<"Now input arrary with "<<n<<" elements plz: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"\nThks ^_^, I presure this is the array u inputed: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    for(int x: arr){
        root = insert(root, x);
    }
    
    cout<<"Here is it's Inorder: ";
    inorder(root);
    cout<<"\nHere is it's Preorder: ";
    preorder(root);
    cout<<"\nHere is it's Postorder: ";
    postorder(root);
    
    cout<<"\n";
    
    int key = 30;
    if(search(root,key))
        cout<<"Key found: "<<key;
    else
        cout<<"Sry couldn't find it";
        
    return 0;
}













