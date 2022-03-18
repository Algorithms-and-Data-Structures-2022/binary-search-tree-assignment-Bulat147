#pragma once

namespace assignment {

  struct Node {
    // ключ
    int key;

    // значение
    int value;

    // левый и правый узлы-потомки
    Node *left{nullptr};
    Node *right{nullptr};

    /**
     * Создание узла дерева с указанным ключом.
     * @param key - значение ключа
     * @param value - хранимые данные
     */
    Node(int key, int value) : key{key}, value{value} {}
  };

}  // namespace assignment