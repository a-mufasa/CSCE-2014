#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    
    Node* left;
    
    Node* right;
};

Node* search(Node* t, int key, Node * & parent)
{
    if (t == NULL){
        return NULL;
    }
    if(key == t->data){
        return t;
    }
    else if (key < t -> data){
        parent = t;
        return search(t->left, key, parent);
    }
    else if (key > t->data){
        parent = t;
        return search(t->right, key, parent);
    }
}
Node* insert(Node* t, int key)
{
    Node* parent = NULL;
    
    if (t == NULL){
        t = new Node();
        t -> data = key;
        t -> left = NULL;
        t -> right = NULL;
        return t;
    }
    
    if (search(t, key, parent) == NULL){
        if (key < parent -> data){
            parent -> left = new Node();
            parent -> left -> data = key;
            parent -> left -> left = NULL;
            parent -> left -> right = NULL;
            
            return t;
        }
        if (key > parent -> data){
            parent -> right = new Node();
            parent -> right -> data = key;
            parent -> right -> right = NULL;
            parent -> right -> left = NULL;
            
            return t;
        }
    }
    else{
        return t;
    }
}
void inorder(Node* t)
{
    if (t == NULL) {
        return;
    }
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}


int main()
{
    Node* parent = NULL;

    Node* btree = NULL; //initialize
    btree = insert(btree, 11);
    btree = insert(btree, 10);
    btree = insert(btree, 20);
    btree = insert(btree, 20);
    btree = insert(btree, 15);
    btree = insert(btree, 9);
    btree = insert(btree, 13);

    inorder(btree);
    cout << endl;
    cout << search(btree, 10, parent) << endl;
    
    cout << endl; //---------------------------------
    
    Node* a = NULL; //initialize
    a = insert(a, 12);
    a = insert(a, 11);
    a = insert(a, 6);
    a = insert(a, 19);
    a = insert(a, 4);
    a = insert(a, 21); 
    a = insert(a, 13);
    a = insert(a, 14);
    a = insert(a, 12); 
    a = insert(a, 102);
    a = insert(a, 68);
    a = insert(a, 101);
    a = insert(a, 369);

    inorder(a);
    cout << endl;
    cout << search(a, 999, parent) << endl;

    return 0;
}

