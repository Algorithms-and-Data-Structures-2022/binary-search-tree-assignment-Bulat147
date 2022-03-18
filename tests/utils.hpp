#pragma once

#include <vector>
#include <unordered_set>
#include <algorithm>  // generate, shuffle
#include <random>     // mt19937, uniform_int_distribution

#include <queue>
#include <ostream>
#include <string>

#include "assignment/node.hpp"  // Node

using assignment::Node;

namespace utils {

  inline void tree_as_steam(std::ostream &os, Node *node) {

    if (node == nullptr) {
      return;
    }

    std::queue<Node *> nodes;
    nodes.push(node);

    while (!nodes.empty()) {

      auto *curr_node = nodes.front();
      nodes.pop();

      os << curr_node->key << ' ';

      if (curr_node->left != nullptr) {
        nodes.push(curr_node->left);
      }

      if (curr_node->right != nullptr) {
        nodes.push(curr_node->right);
      }
    }
  }

  inline std::string tree_as_str(Node *node) {
    std::stringstream ss;
    tree_as_steam(ss, node);
    return ss.str();
  }

  inline std::vector<int> rand_array(int length, int start, int end, bool unique = false) {
    if (length == 0) {
      return {};
    }

    auto engine = std::mt19937(std::random_device{}());
    auto dist = std::uniform_int_distribution<>(start, end);

    auto arr = std::vector<int>(length);
    auto unique_arr = std::unordered_set<int>(length);

    if (unique) {
      while (unique_arr.size() < length) {
        const int elem = dist(engine);

        if (unique_arr.count(elem) == 0) {
          unique_arr.insert(elem);
        }
      }

      arr.assign(unique_arr.cbegin(), unique_arr.cend());

    } else {
      std::generate(arr.begin(), arr.end(), [&dist, &engine]() { return dist(engine); });
    }

    std::shuffle(arr.begin(), arr.end(), engine);
    return arr;
  }

}  // namespace utils