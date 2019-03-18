#include "Tree.hpp"

using namespace ariel;

// Insert a new data and finally increase capacity by 1
Tree &Tree::insert(int i)
{
    if (contains(i)) // Prevent duplicates data
        throw std::runtime_error("Duplicate number!");


    Node *node = new Node(i);

    if (r == NULL){ // if the root is null so it's now the new root
        r = node;
    }

    else // else, insert in the right place
    {
        Node *current = r;
        bool flag = true;
        int data;
        while (flag)
        {
            if (i > current->getData())
            {
                if (current->getRight() != NULL)
                {
                    current = current->getRight();
                }
                else
                {
                    current->setRight(node);
                    flag = false;
                }
            }
            else
            {
                if (current->getLeft() != NULL)
                {
                    current = current->getLeft();
                }
                else
                {
                    current->setLeft(node);
                    flag = false;
                }
            }
        }
    }
    capacity++;
    return *this;
}

// Remove element by data
void Tree::remove(int i)
{
    if (!contains(i) || r == NULL)
        throw std::runtime_error("There is not i such that!!!");


    if (r->getData() == i) // Case 1, root contain the data.
    {
        if(r->getRight()==NULL && r->getLeft()== NULL) { // No children
            delete r;
            r=NULL;
        }
        else if(r->getRight()!=NULL && r->getLeft()== NULL) { // Right child
            Node *temp = r->getRight();
            delete r;
            r = temp;
        }
        else if(r->getRight()==NULL && r->getLeft()!= NULL) { // Left child
            Node *temp = r->getLeft();
            delete r;
            r = temp;
        }
        else { // Root has 2 children
            Node *max = maxNode(r->getLeft()); // Search on left tree max data value
            int maxData = max->getData();
            remove(maxData); // Remove the max data that we found
            r->setData(maxData); // Set root to be the max data
            capacity++; // Just because we remove "twice"
        }
    }

    else // Case 2, it's a node not a root
    {
        Node *target = byInt(i);
        Node *par = byInt(parent(i));
        bool right;
        if (par->getRight()->getData() == i) // Detrmine parent of data is on the right or left side child
            right = true;
        else
            right = false;

        if (target->getRight() == NULL && target->getLeft() == NULL) // No children
        {
            setVertex(par, NULL, right); // Parent point to null
            delete target;
        }
        else if (target->getRight() == NULL && target->getLeft() != NULL) // Left child
        {
            setVertex(par, target->getLeft(), right);
            delete target;
        }
        else if (target->getRight() != NULL && target->getLeft() == NULL) // Righht child
        {
            setVertex(par, target->getRight(), right);
            delete target;
        }
        else // Parent has 2 children
        {
            Node *max = maxNode(target->getLeft());
            int maxData = max->getData();
            remove(maxData);
            target->setData(maxData);
            capacity++;
        }
    }

    capacity--;
}
// Return size of the tree (number of nodes - data)
int Tree::size() { return capacity; }

// Check if data is in the tree
bool Tree::contains(int i)
{
    Node *result = byInt(i);

    if (result == NULL)
        return false;

    return true;
}
// Return root data if exsist
int Tree::root() { 
    if(r != NULL) return r->getData(); 

    throw std::runtime_error("There is not root!");
}
// Return parent of data
int Tree::parent(int i)
{
    if (r == NULL)
        throw std::runtime_error("empty tree");
    if (r->getData() == i)
        throw std::runtime_error("There is not parent for root!");
    if (!contains(i))
        throw std::runtime_error("There is not i such that!!!");

    Node *current = r, *parent = r;
    int data, result;
    bool ok = false;
    while (current != NULL)
    {
        data = current->getData();

        if (i > data)
        {
            parent = current;
            current = current->getRight();
        }
        else if (i < data)
        {
            parent = current;
            current = current->getLeft();
        }
        else
        {
            result = parent->getData();
            break;
        }
    }
    return result;
}
// Return left child
int Tree::left(int i)
{
    if (!contains(i))
        throw std::runtime_error("There is not int suct that!!!");
    Node *result = byInt(i);
    if (result->getLeft() != NULL)
        return result->getLeft()->getData();
    else
    {
        throw std::runtime_error("There is not int suct that!!!");
    }
}
// Return right child
int Tree::right(int i)
{
    if (!contains(i))
        throw std::runtime_error("There is not int suct that!!!");
    Node *result = byInt(i);
    if (result->getRight() != NULL)
        return result->getRight()->getData();
    else
    {
        throw std::runtime_error("There is not int suct that!!!");
    }
}
// return the node Class by data
Node *Tree::byInt(int i)
{
    Node *current = r;
    while (current != NULL)
    {
        if (i > current->getData())
        {
            current = current->getRight();
        }
        else if (i < current->getData())
        {
            current = current->getLeft();
        }
        else
        {
            return current;
        }
    }
    return NULL;
}
// Print PreOrder tree contains
void Tree::print()
{
    print(r);
}
void Tree::print(Node *root)
{
    if (root != NULL)
    {
        std::cout << root->getData() << " ";
        print(root->getLeft());
        print(root->getRight());
    }
}
// Search for the max data from the target node
Node* Tree::maxNode(Node *root)
{
    while (root->getRight() != NULL)
    {
        root = root->getRight();
    }
    return root;
}
// Set node to point to other node or NULL
void Tree::setVertex(Node *node, Node *set, bool right)
{
    if (right)
    {
        node->setRight(set);
    }
    else
    {
        node->setLeft(set);
    }
}
// Destroy the tree just for destructor and prevent memory leaks
void Tree::destroyTree(Node *root) {
    if(root != NULL) {
        destroyTree(root->getLeft());
        destroyTree(root->getRight());
        delete root;
    }
}