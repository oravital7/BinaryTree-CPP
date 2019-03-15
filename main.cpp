#include <iostream>
#include "Tree.hpp"

using namespace std;
int main() {
    ariel::Tree tree;
    tree.insert(3);
    
    cout << tree.root() << endl;
}