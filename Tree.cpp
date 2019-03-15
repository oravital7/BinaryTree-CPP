#include "Tree.hpp"

using namespace ariel;

Tree& Tree::insert(int i)
{
    if (r == NULL)
    {
        r = new Node(i);        
    }

    else if (contains(i))
        throw std::runtime_error("Duplicate number!");

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
                    current->setRight(new Node(i));
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
                    current->setLeft(new Node(i));
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
    
}

int Tree::size(){return capacity;}

bool Tree::contains(int i)
{
    Node *result = byInt(i);

    if(result == NULL) return false;
    return true;
}
int Tree::root() {return r->getData();}

int Tree::parent(int i) {
    if(r==NULL) throw std::runtime_error("empty tree");
    if(r->getData()== i) throw std::runtime_error("There is not parent for root!");
    if(!contains(i)) throw std::runtime_error("There is not i such that!!!");

    Node *current = r, *parent = r;
    int data,result;
    bool ok = false;
    while(current != NULL) {
        data = current->getData();

        if(i > data) {
            parent = current;
            current = current->getRight();
        }
        else if(i < data) {
            parent = current;
            current = current->getLeft();
        }
        else {
            result = parent->getData();
            break;
        }
    }
    return result;
}

int Tree::left(int i) {
    if(!contains(i)) throw std::runtime_error("There is not int suct that!!!");
    Node *result = byInt(i);
    if(result->getLeft() != NULL) return result->getData();
    else {
        throw std::runtime_error("There is not int suct that!!!");
    }
}

int Tree::right(int i) {
    if(!contains(i)) throw std::runtime_error("There is not int suct that!!!");
    Node *result = byInt(i);
    if(result->getRight() != NULL) return result->getData();
    else {
        throw std::runtime_error("There is not int suct that!!!");
    }
}

Node* Tree::byInt(int i) {
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

void Tree::print() {}
