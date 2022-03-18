#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    // Write your code here...
  }

  bool BinarySearchTree::Remove(int key) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::Clear() {
    // Write your code here...
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    // Write your code here...
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    // Write your code here...
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    return false;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    // Write your code here...
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    // Write your code here...
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return nullptr;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    // Write your code here...
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    // Write your code here...
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    return nullptr;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment