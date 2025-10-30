#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "node.h"
#include <iostream>
#include <algorithm>

using namespace std;


template <typename Key, typename Value>
class avl_map {
private:
    Node<Key, Value>* root; 



    //Gets the height (height is public in Node)
    int height(Node<Key, Value>* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    //Gets the balance factor of a Node
    int balanceFactor(Node<Key, Value>* node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    //Right rotation for a given tree/subtree
    Node<Key, Value>* rightRotate(Node<Key, Value>* y)
    {
        Node<Key, Value>* x = y->left;
        Node<Key, Value>* T2 = x->right;

        //Rotate
        x->right = y;
        y->left = T2;

        //Update the height of each node
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        //Return the new root of the subtree
        return x;
    }

    //Left rotation for a given tree/subtree
    Node<Key, Value>* leftRotate(Node<Key, Value>* x)
    {
        Node<Key, Value>* y = x->right;
        Node<Key, Value>* T2 = y->left;

        y->left = x;
        x->right = T2;

        //Update the height of each node
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        //Return the new root of the subtree
        return y;
    }

    //function to insert a new node into the tree
    Node<Key, Value>* insert(Node<Key, Value>* root, Node<Key, Value>* node)
    {
        
        //Perform the normal BST insertion
        if (root == nullptr)
            return node;

        if (node->key < root->key)
            root->left = insert(root->left, node);
        else if (node->key > root->key)
            root->right = insert(root->right, node);
        else
        return root; //Duplicate keys not allowed, do nothing

        //Update the height of this node
        root->height = 1 + max(height(root->left), height(root->right));

        //Get the balance factor of this node
        int balance = balanceFactor(root);


        //If the tree/subtree is now unbalanced: 

        //LL case
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        //LR case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //RR case
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        //RL case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    //delete a node given the root of the tree and a key to delete
    Node<Key, Value>* deleteNode(Node<Key, Value>* root, Key key)
    {
        // Perform standard BST delete
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);

        else {
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node<Key, Value>* temp = root->left ? root->left : root->right;

            // Case 1: No child
            if (temp == nullptr) {
                delete root;
                root = nullptr;
            }
            // Case 2: One child
            else {
                Node<Key, Value>* oldRoot = root;
                root = temp;
                delete oldRoot;
            }
        }
        // Node with two children
        else {
            Node<Key, Value>* temp = leftmost(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

        if (root == nullptr)
            return root;

        //Update height of the current node
        root->height = 1
                       + max(height(root->left),
                             height(root->right));

        //Get the balance factor of this node
        int balance = balanceFactor(root);


        // If the node is unbalanced, the same 4 cases: 

        // Left Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    //in-order traversal of the whole tree, prints the keys
    void inorder(Node<Key, Value>* root) const
    {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " "; //just prints every key
            inorder(root->right);
        }
    }

    //search function
    bool search(Node<Key, Value>* root, Key key) const
    {
        if (root == nullptr)
            return false;
        if (root->key == key)
            return true;
        if (key < root->key)
            return search(root->left, key);
        return search(root->right, key);
    }

    //finds the leftmost node in a tree
    Node<Key, Value>* leftmost(Node<Key, Value>* node) const {
        while (node && node->left)
            node = node->left;
        return node;
    }

    //finds the next-largest node in the tree, aka the successor
    Node<Key, Value>* findSuccessor(Node<Key, Value>* root, Node<Key, Value>* node) const {
        if (!node) return nullptr;
        if (node->right)
            return leftmost(node->right);
        Node<Key, Value>* succ = nullptr;
        Node<Key, Value>* curr = root;
        while (curr) {
            if (node->key < curr->key) {
                succ = curr;
                curr = curr->left;
            } else if (node->key > curr->key) {
                curr = curr->right;
            } else break;
        }
        return succ;
    }



public:
    class iterator {
    private:
        Node<Key, Value>* current;
        Node<Key, Value>* root; //need root for ++

        Node<Key, Value>* leftmost(Node<Key, Value>* node) const {
            while (node && node->left)
                node = node->left;
            return node;
        }

        //find the successor node
        Node<Key, Value>* findSuccessor(Node<Key, Value>* root, Node<Key, Value>* node) const {
            if (!node) return nullptr;

            if (node->right)
                return leftmost(node->right);

            Node<Key, Value>* succ = nullptr;
            Node<Key, Value>* curr = root;

            while (curr) {
                if (node->key < curr->key) {
                    succ = curr;          //possible successor
                    curr = curr->left;    //keep going left
                } else if (node->key > curr->key) {
                    curr = curr->right;
                } else {
                    break;
                }
            }
            return succ; //return the successor node
        }

    public:
        iterator(Node<Key, Value>* node = nullptr, Node<Key, Value>* rootNode = nullptr)
            : current(node), root(rootNode) {}

        bool operator==(const iterator& other) const { return current == other.current; }
        bool operator!=(const iterator& other) const { return current != other.current; }

        Node<Key, Value>* operator->() const { return current; }

        pair<const Key&, Value&> operator*() const {
            return { current->key, current->data };
        }

        //++ operation
        iterator& operator++() {
            current = findSuccessor(root, current);
            return *this;
        }
    };

iterator begin() const {
        Node<Key, Value>* node = root;
        if (!node) return iterator(nullptr, root);
        while (node->left)
            node = node->left;
        return iterator(node, root);
    }

    iterator end() const {
        return iterator(nullptr, root);
    }

    iterator find(const Key& key) const {
        Node<Key, Value>* curr = root;
        while (curr) {
            if (key == curr->key)
                return iterator(curr, root);
            else if (key < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return end(); //unsuccessful search, not found
    }

    avl_map() : root(nullptr) {}
    ~avl_map() { clear(root); }

    //(public) insert a node into the tree
    void insert(Node<Key, Value>* node) { this->root = insert(this->root, node); }

    //insert into the tree using the Key and Value directly
    void insert(const Key& key, const Value& value) {
    Node<Key, Value>* node = new Node<Key, Value>(key, value);
    root = insert(root, node);
}

    //remove a node from the tree based on its key
    void remove(const Key& key) { root = deleteNode(root, key); }

    //search for a key in the tree
    bool search(Key key) const { return this->search(this->root, key); }

    //Print the whole tree in order using inorder(root)
    void printInorder() const
    {
        inorder(root);
        cout << endl;
    }

    Node<Key, Value>* getRoot() const { return root; }

private:
    void clear(Node<Key, Value>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
};

#endif
