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

    Tree& insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();

    private:
    Node* byInt(int i);

};
}

