/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"
#include <ctime>  

int numInTree[20];

bool checkIn(int x, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (numInTree[i] == x)
      return true;
  }
  return false;
}

int main()
{
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree myTree;
  myTree.insert(6).insert(4).insert(8).insert(5);


    // Random check tree
  ariel::Tree randomTree;

  int i = 0, randNum;
  srand((unsigned)time(0)); 

  while (i < 20)
  {
    
    randNum = rand() % 100;
    if (!checkIn(randNum, i))
    {
      randomTree.insert(randNum);
      numInTree[i] = randNum;
      i++;
    }
  }

  

  badkan::TestCase tc("Binary tree");
  tc
      .CHECK_EQUAL(emptytree.size(), 0)
      .CHECK_OK(emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_EQUAL(emptytree.contains(5), true)
      .CHECK_OK(emptytree.remove(5))
      .CHECK_THROWS(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size(), 0)

      .CHECK_EQUAL(threetree.size(), 3)
      .CHECK_EQUAL(threetree.root(), 5)
      .CHECK_EQUAL(threetree.parent(3), 5)
      .CHECK_EQUAL(threetree.parent(7), 5)
      .CHECK_EQUAL(threetree.left(5), 3)
      .CHECK_EQUAL(threetree.right(5), 7)
      .CHECK_THROWS(threetree.insert(3))
      .CHECK_OK(threetree.print())

      // My tests addition:

      .CHECK_THROWS(myTree.left(4))
      .CHECK_EQUAL(myTree.right(4), 5)
      .CHECK_OK(myTree.insert(2))
      .CHECK_OK(myTree.remove(4))
      .CHECK_EQUAL(myTree.size(), 4)
      .CHECK_EQUAL(myTree.parent(2), myTree.root())
      .CHECK_EQUAL(myTree.right(2), 5)
      .CHECK_OK(myTree.insert(4))
      .CHECK_OK(myTree.remove(6))
      .CHECK_EQUAL(myTree.root(), 5)
      .CHECK_EQUAL(myTree.right(2), 4)
      .CHECK_THROWS(myTree.remove(20))
      .CHECK_EQUAL(myTree.contains(4), true)
      .CHECK_EQUAL(myTree.contains(20), false)
      .CHECK_EQUAL(myTree.left(myTree.root()), 2)
      .CHECK_EQUAL(myTree.right(myTree.root()), 8)
      .CHECK_THROWS(myTree.insert(8))
      .CHECK_EQUAL(myTree.contains(2), true)
      .CHECK_THROWS(myTree.insert(2))
      .CHECK_OK(myTree.remove(2))
      .CHECK_EQUAL(myTree.contains(2), false)
      .CHECK_OK(myTree.insert(2))
      .CHECK_EQUAL(myTree.contains(2), true)

      .CHECK_EQUAL(randomTree.size(),20)
      .CHECK_EQUAL(randomTree.contains(numInTree[0]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[3]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[5]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[6]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[7]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[8]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[9]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[10]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[18]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[19]),true)
      .CHECK_EQUAL(randomTree.contains(numInTree[11]),true)

      .CHECK_OK(randomTree.remove(numInTree[0]))
      .CHECK_THROWS(randomTree.remove(numInTree[0]))
      .CHECK_EQUAL(randomTree.size(),19)
      .CHECK_OK(randomTree.remove(numInTree[2]))
      .CHECK_EQUAL(randomTree.size(),18)
      


      .print();





cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}