#include <iostream>
// #include <vector> // I had to learn this in case of BST n stuff, it's prefered to use std::vector
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (key == root->data) return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    cout << "Please input da Arrey >_<\n";
    int n;
    cout << "Please the size first: ";
    cin >> n;

    // vector<int> arr(n); // This is where I had to use it -_-, still works tho +_+
    int arr[n];
    cout << "\nNow the array please: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Range-based loop now works perfectly with vector
    for (int x : arr) {
        root = insert(root, x);
    }

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    int key = 55;
    if (search(root, key)) {
        cout << "\nFound it: " << key << endl;
    } else {
        cout << "\nCouldn't find it, sry ;_;" << endl;
    }
    //Can finally move on ig ^_^
    return 0;
}