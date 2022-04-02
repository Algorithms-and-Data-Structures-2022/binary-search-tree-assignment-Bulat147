#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    Node* new_node = new Node(key, value);
    if (BinarySearchTree::IsEmpty() == true){
      root_ = new_node;
    }else {
      Node* iter_node = root_;
      bool flag = true;
      while (flag == true) {
        if (key == iter_node->key){
            iter_node->value = value;
            flag = false;
        }else if(key < iter_node->key){
            if (iter_node->left == nullptr){
              iter_node->left = new_node;
              flag = false;
            }else {
              iter_node = iter_node->left;
            }
        }else if(key > iter_node->key){
          if (iter_node->right == nullptr){
            iter_node->right = new_node;
            flag = false;
          }else {
            iter_node = iter_node->right;
          }
      }
    }
  }
  }

  bool BinarySearchTree::Remove(int key) {
    if (root_ == nullptr) {
      return false;
    }
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
      if (root_ != nullptr) {
        clear(root_);
        root_ = nullptr;
      }
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* iter_node = root_;
    while (iter_node != nullptr) {
      if (key == iter_node->key){
        return iter_node->value;
      }else if(key < iter_node->key){
        if (iter_node->left == nullptr){
          return std::nullopt;
        }else {
          iter_node = iter_node->left;
        }
      }else if(key > iter_node->key){
        if (iter_node->right == nullptr){
          return std::nullopt;
        }else {
          iter_node = iter_node->right;
        }
      }
    }
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    if (Find(key) != std::nullopt){
      return true;
    }
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    if (root_ == nullptr){
      return true;
    }
    return false;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (IsEmpty() == false){
      Node* iter_node = root_;
      while (iter_node != nullptr) {
        if (iter_node->left != nullptr) {
          iter_node = iter_node->left;
        }else{
          return iter_node->value;
        }
      }
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (IsEmpty() == false){
      Node* iter_node = root_;
      while (iter_node != nullptr) {
        if (iter_node->right != nullptr) {
          iter_node = iter_node->right;
        }else{
          return iter_node->value;
        }
      }
    }
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    Node* new_node = new Node(key, value);
    if (node == nullptr){
      node = new_node;
    }else {
      if (key == node->key){
        node->value = value;
      }else if(key < node->key){
        if (node->left == nullptr){
          node->left = new_node;
        }else {
          insert(key, value, node->left);
        }
      }else if(key > node->key){
        if (node->right == nullptr){
          node->right = new_node;
        }else {
          insert(key, value, node->right);
        }
      }

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

    /*if (node == nullptr){
      return false;
    }
    Node* iter_nd = node;
    while (iter_nd != nullptr){
      if (iter_nd->key == key){
        if(iter_nd->right == nullptr and iter_nd->left != nullptr){
          iter_nd->key = iter_nd->left->key;
          iter_nd->value = iter_nd->left->value;
          Node* next = iter_nd->left;
          if (iter_nd->left->right == nullptr and iter_nd->left->left == nullptr){
            delete iter_nd->left;
            iter_nd->left = nullptr;
            return true;
          }
          remove(iter_nd->key, next);
        }
        if(iter_nd->right != nullptr and iter_nd->left == nullptr){
          iter_nd->key = iter_nd->right->key;
          iter_nd->value = iter_nd->right->value;
          Node* next = iter_nd->right;
          if (iter_nd->right->right == nullptr and iter_nd->right->left == nullptr){
            delete iter_nd->right;
            iter_nd->right = nullptr;
            return true;
          }
          remove(iter_nd->key, next);
        }
        if(iter_nd->right != nullptr and iter_nd->left != nullptr){
          Node* minim = find_min(iter_nd->right);
          iter_nd->key = minim->key;
          iter_nd->value = minim->value;
          if (iter_nd->right->right == nullptr and iter_nd->right->left == nullptr
              and iter_nd->right->key == minim->key){
            delete iter_nd->right;
            iter_nd->right = nullptr;
            return true;
          }else {
            remove(minim->key, iter_nd->right);
          }
        }
        return true;
      }
      else if(key < iter_nd->key){
        if (iter_nd->left == nullptr){
          return false;
        }
        if (iter_nd->left->right == nullptr and iter_nd->left->left == nullptr
            and iter_nd->left->key == key){
          delete iter_nd->left;
          iter_nd->left = nullptr;
          return true;
        }
        iter_nd = iter_nd->left;
      }
      else if(key > iter_nd->key){
        if (iter_nd->right == nullptr){
          return false;
        }
        if (iter_nd->right->right == nullptr and iter_nd->right->left == nullptr
            and iter_nd->right->key == key){
          delete iter_nd->right;
          iter_nd->right = nullptr;
          return true;
        }
        iter_nd = iter_nd->right;
      }
    }
    return false;*/
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr){
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    if (node->key == key){
      return node;
    }else if(key < node->key){
      return find(key, node->left);
    }else if(key > node->key){
      return find(key, node->right);
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    if (node->left == nullptr){
      return node;
    }else{
      find_min(node->left);
    }
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    if (node->right == nullptr){
      return node;
    }else{
      find_min(node->right);
    }
  }

}  // namespace assignment