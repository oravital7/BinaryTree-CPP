#include "Tree.hpp"

using namespace ariel;

void Tree::insert(int i)
{
    if (contains(i))
        throw std::runtime_error("Duplicate number!");

    if (r == NULL)
    {
        r = new Node(i);
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
}

void Tree::remove(int i)
{
}

int Tree::size()
{
    return capacity;
}
bool Tree::contains(int i)
{
    Node *current = r;
    bool result = false;
    while (!result && current != NULL)
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
            result = true;
        }
    }
    return result;
}
int Tree::root() {}
int Tree::parent(int i) {}
int Tree::left(int i) {}
int Tree::right(int i) {}
void Tree::print() {}
