#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return false;
    }
    remove(key, root_);
    return true;
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return std::nullopt;
    }
    return found_node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr) {
      return false;
    }
    return true;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* curr_node = root_;
    while (curr_node->left != nullptr) {
      curr_node = curr_node->left;
    }
    return curr_node->key;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* found_node = find_max(root_);
    return found_node->key;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node != nullptr) {
      if (key < node->key) {
        return insert(key, value, node->left);
      }
      if (key > node->key) {
        return insert(key, value, node->right);
      }
    }
    else {
      Node* newNode = new Node(key, value);
      node = newNode;
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr){
      return node;
    }
    if (key < node->key){
      remove(key, node->left);
    }
    else if (key > node->key) {
      remove(key, node->right);
    }else if (node->left != nullptr && node->right != nullptr){
      node->key = find_min(node->right)->key;
      remove(node->key, node->right);}
    else{
      if (node->left != nullptr){
        node = node->left;}
      else if (node->right != nullptr){
        node = node->right;}
      else{
        node = nullptr;}}
    return node;
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->key == key) {
      return node;
    }
    if (key < node->key) {
      return find(key, node->left);
    }
    if (key > node->key) {
      return find(key, node->right);
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }

}  // namespace assignment