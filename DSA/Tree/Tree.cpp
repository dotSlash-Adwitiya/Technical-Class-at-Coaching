#include<bits/stdc++.h>
using namespace std;

class Node {
  private : 
    Node* left;
    int data;
    Node* right;
    Node(int data) {
      this->left = NULL;
      this->data = data;
      this->right = NULL;
    }
  friend class Tree;
};

class Tree {
  public :
    Node* createTree();
    void inOrder(Node* root);
    void preOrder(Node* root);
    void postOrder(Node* root);

    int height(Node* root);
};

Node* Tree::createTree() {
    cout << "Enter data (-1 for no NULL): ";
    int rootData;
    cin >> rootData;

    // * Base case: if the input is -1, no node should be created
    if (rootData == -1) {
        return nullptr;
    }

    // * Create the root node with the input data
    Node* rootNode = new Node(rootData);

    // * Recursively create the left subtree
    cout << "Enter Left Child for " << rootData << ": ";
    rootNode->left = createTree();

    // * Recursively create the right subtree
    cout << "Enter Right Child for " << rootData << ": ";
    rootNode->right = createTree();

    return rootNode;
}

// * preOrder Traversal
// * ROOT-left-right
void Tree::preOrder(Node* root) {
  if(root == NULL) return;

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// * Inorder Traversal
// * left-ROOT-right
void Tree::inOrder(Node* root){
  if(!root) return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// * postOrder Traversal
// * left-right-ROOT
void Tree::postOrder(Node* root){
  if(!root) return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}


int main()
{
  Tree t;
  Node* root = t.createTree();

  cout << "PreOrder: ";
  t.preOrder(root);
  cout << endl;
  cout << "InOrder: ";
  t.inOrder(root);
  cout << endl;
  cout << "PostOrder: ";
  t.postOrder(root);
  cout << endl;

  return 0;
}