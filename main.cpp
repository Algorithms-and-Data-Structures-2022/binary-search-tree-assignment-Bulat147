#include <iostream>  // cout, cin

#include "assignment/binary_search_tree.hpp"  // BinarySearchTree

using namespace std;
using namespace assignment;

int main(int argc, char** argv) {

  /*
   *                8
   *        3               10
   *    1     6         x      14
   * x   x  4   7     x   x  13   x
   *
   * x - это nullptr
   */

  BinarySearchTree tree;

  tree.Insert(8, 1);
  tree.Insert(3, 2);
  tree.Insert(10, 3);
  tree.Insert(1, 4);
  tree.Insert(6, 5);
  tree.Insert(4, 6);
  tree.Insert(7, 7);
  tree.Insert(14, 8);
  tree.Insert(13, 9);

  cout << "Write your code here ...\n";

  return 0;
}
