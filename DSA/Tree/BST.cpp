#include <iostream>
using namespace std;

class Node {
    private:
      int key;
      Node* left;
      Node* right;    
      Node(int item) {
          key = item;
          left = NULL;
          right = NULL;
      }
  friend class Tree;
};

class Tree{
  Node* root;

  public:
    Node* insertNode(Node* node, int key);
    Node* searchKey(Node* node, int key);
};


Node* Tree::insertNode(Node* root, int key) {

    if (root == NULL) 
        return new Node(key);    

    if (root->key == key) // * KEY ALREADY THERE
        return root;

    if (root->key < key) // * Given KEY is GREATER than the current Node's VALUE
        root->right = insertNode(root->right, key);
    
    else // * Given KEY is SMALLER than the current Node's VALUE
        root->left = insertNode(root->left, key);

    return root;
}

Node* Tree::searchKey(Node* root, int key) {
  
    if (root == NULL || root->key == key)
        return root;

    // * Key GREATER than current node's val
    if (root->key < key)
        return searchKey(root->right, key);

    // * Key smaller than current node's val
    else 
        return searchKey(root->left, key);
}