#include "Tree.hpp"

using namespace ariel;

Tree &Tree::insert(int i)
{
    if (contains(i))
        throw std::runtime_error("Duplicate number!");


    Node *node = new Node(i);

    if (r == NULL){
        r = node;
    }

    else
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

void Tree::remove(int i)
{
    if (!contains(i) || r == NULL)
        throw std::runtime_error("There is not i such that!!!");


    if (r->getData() == i)
    {
        if(r->getRight()==NULL && r->getLeft()== NULL) {
            delete r;
            r=NULL;
        }
        else if(r->getRight()!=NULL && r->getLeft()== NULL) {
            Node *temp = r->getRight();
            delete r;
            r = temp;
        }
        else if(r->getRight()==NULL && r->getLeft()!= NULL) {
            Node *temp = r->getLeft();
            delete r;
            r = temp;
        }
        else {
            Node *max = maxNode(r->getLeft());
            int maxData = max->getData();
            remove(maxData);
            r->setData(maxData);
            capacity++;
        }
    }

    else
    {
        Node *target = byInt(i);
        Node *par = byInt(parent(i));
        bool right;
        if (par->getRight()->getData() == i)
            right = true;
        else
            right = false;

        if (target->getRight() == NULL && target->getLeft() == NULL)
        {
            setVertex(par, NULL, right);
            delete target;
        }
        else if (target->getRight() == NULL && target->getLeft() != NULL)
        {
            setVertex(par, target->getLeft(), right);
            delete target;
        }
        else if (target->getRight() != NULL && target->getLeft() == NULL)
        {
            setVertex(par, target->getRight(), right);
            delete target;
        }
        else
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

int Tree::size() { return capacity; }

bool Tree::contains(int i)
{
    Node *result = byInt(i);

    if (result == NULL)
        return false;

    return true;
}
int Tree::root() { return r->getData(); }

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

Node* Tree::maxNode(Node *root)
{
    while (root->getRight() != NULL)
    {
        root = root->getRight();
    }
    return root;
}

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

void Tree::destroyTree(Node *root) {
    if(root != NULL) {
        destroyTree(root->getLeft());
        destroyTree(root->getRight());
        delete root;
    }
}
