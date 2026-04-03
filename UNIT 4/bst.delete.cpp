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
    else
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


Node* findMin(Node* root) {
    // find min in subtree (leftmost)
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    // delete node from BST
    if (root == NULL) return NULL;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
        // go left
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
        // go right
    }
    else {
        // found, handle cases
        if (root->left == NULL && root->right == NULL) {
            // no child
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            // one child: right
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            // one child: left
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            // two children
            Node* temp = findMin(root->right);
            // find min in right
            root->data = temp->data;
            // replace
            root->right = deleteNode(root->right, temp->data);
            // delete min
        }
    }
    return root;
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
    
    root = deleteNode(root, 5);
    cout<<"\nAfter deletein:-\n";
    
    cout<<"Here is it's Inorder: ";
    inorder(root);
    cout<<"\nHere is it's Preorder: ";
    preorder(root);
    cout<<"\nHere is it's Postorder: ";
    postorder(root);
        
    return 0;
}

