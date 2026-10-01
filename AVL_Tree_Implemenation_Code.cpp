#include <iostream>
#include <vector>
using namespace std;

// Node of the AVL Tree
class Node{
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int x){
        key = x;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

// Return height of a node
int getHeight(Node* N){
    if(N == nullptr)
        return -1;

    return N->height;
}

// Update height using heights of left and right subtrees
void updateHeight(Node* root){
    if(root == nullptr)
        return;

    root->height = 1 + max(
        getHeight(root->left),
        getHeight(root->right)
    );
}

// Calculate Balance Factor
// BF = Height(Left) - Height(Right)
int getBalance(Node* N){
    if(N == nullptr)
        return 0;

    return getHeight(N->left) - getHeight(N->right);
}

// Find the node with minimum value
// Move continuously to the left
Node* minValueNode(Node* N){
    Node* curr = N;

    while(curr->left != nullptr)
        curr = curr->left;

    return curr;
}

// Find the node with maximum value
// Move continuously to the right
Node* maxValueNode(Node* N){
    Node* curr = N;

    while(curr->right != nullptr)
        curr = curr->right;

    return curr;
}

// Left Rotation
Node* LLRotate(Node* Z){
    Node* Y = Z->right;
    Node* T2 = Y->left;

    Y->left = Z;
    Z->right = T2;

    // Update lower node first
    updateHeight(Z);
    updateHeight(Y);

    return Y;
}

// Right Rotation
Node* RRRotate(Node* Z){
    Node* Y = Z->left;
    Node* T2 = Y->right;

    Z->left = T2;
    Y->right = Z;

    // Update lower node first
    updateHeight(Z);
    updateHeight(Y);

    return Y;
}

// Left-Right Rotation
Node* LRRotate(Node* Z){
    // First left rotate the left subtree
    Z->left = LLRotate(Z->left);

    // Then right rotate Z
    return RRRotate(Z);
}

// Right-Left Rotation
Node* RLRotate(Node* Z){
    // First right rotate the right subtree
    Z->right = RRRotate(Z->right);

    // Then left rotate Z
    return LLRotate(Z);
}

// Insert a key into the AVL Tree
Node* insert(Node* node, int key){

    // Normal BST insertion
    if(node == nullptr)
        return new Node(key);

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
        return node;    // Duplicate keys not allowed

    // Update height after insertion
    updateHeight(node);

    // Check balance factor
    int balance = getBalance(node);

    // Left-Right case
    if(balance > 1 && key > node->left->key)
        node = LRRotate(node);

    // Left-Left case
    if(balance > 1 && key < node->left->key)
        node = RRRotate(node);

    // Right-Right case
    if(balance < -1 && key > node->right->key)
        node = LLRotate(node);

    // Right-Left case
    if(balance < -1 && key < node->right->key)
        node = RLRotate(node);

    return node;
}

// Delete a key from the AVL Tree
Node* deleteNode(Node* root, int key){

    // Key not found
    if(root == nullptr)
        return nullptr;

    // Search for the node to delete
    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);

    // Node found
    else{

        // Node has zero or one child
        if(root->left == nullptr || root->right == nullptr){

            Node* temp = root->left ? root->left : root->right;

            // No child
            if(temp == nullptr){
                temp = root;
                root = nullptr;
            }

            // One child
            else{
                *root = *temp;
            }

            delete temp;
        }

        // Node has two children
        else{

            // Find inorder predecessor
            Node* temp = maxValueNode(root->left);

            // Copy predecessor's key
            root->key = temp->key;

            // Delete the predecessor
            root->left = deleteNode(root->left, temp->key);
        }
    }

    // If the tree became empty
    if(root == nullptr)
        return nullptr;

    // Update height after deletion
    updateHeight(root);

    // Check balance factor
    int balance = getBalance(root);

    // Left-Left case
    if(balance > 1 && getBalance(root->left) >= 0)
        root = RRRotate(root);

    // Left-Right case
    if(balance > 1 && getBalance(root->left) < 0)
        root = LRRotate(root);

    // Right-Left case
    if(balance < -1 && getBalance(root->right) > 0)
        root = RLRotate(root);

    // Right-Right case
    if(balance < -1 && getBalance(root->right) <= 0)
        root = LLRotate(root);

    return root;
}

// Preorder: Root -> Left -> Right
void PreOrder(Node* root){
    if(root != nullptr){
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// Inorder: Left -> Root -> Right
void InOrder(Node* root){
    if(root != nullptr){
        InOrder(root->left);
        cout << root->key << " ";
        InOrder(root->right);
    }
}

// Postorder: Left -> Right -> Root
void PostOrder(Node* root){
    if(root != nullptr){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> v(n);

    // Read the keys
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    Node* root = nullptr;

    // Insert all keys
    for(int i = 0; i < n; i++){
        root = insert(root, v[i]);
    }

    // Print tree after insertion
    InOrder(root);

    // Delete all keys
    for(int i = 0; i < n; i++){
        root = deleteNode(root, v[i]);
    }

    // Print tree after deletion
    InOrder(root);

    return 0;
}