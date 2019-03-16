#include <iostream>

class Node {
    private:
    int data;
    Node* right, *left;

    public:
    Node(int i) {
        data = i;
        right=left=NULL;
    }

    Node* getRight() {
        return right;
    }

    Node* getLeft() {
        return left;
    }

    int getData() {
        return data;
    }
    
    void setRight(Node* node) {
        right = node;
    }

    void setLeft(Node* node) {
        left = node;
    }

    void setData(int i) {
        data = i;
    }

};

namespace ariel {

class Tree {
    private:
    Node *r;

    int capacity;

    public:
    Tree()  {
        capacity=0;
        r = NULL;
    }

    ~Tree() {
        destroyTree(r);
    }

    Tree& insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    void print(Node *root);

    private:
    Node* byInt(int i);
    Node* maxNode(Node *root);
    void setVertex(Node *node,Node *set, bool right);
    void destroyTree(Node *root);

};
}

