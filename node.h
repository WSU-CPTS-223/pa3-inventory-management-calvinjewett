#ifndef NODE_H
#define NODE_H

#include "product.h"

template <typename Key, typename Value>
class Node {
public:
    Key key;
    Value data;       
    Node<Key, Value>* left;
    Node<Key, Value>* right;
    int height;

    Node(const Key& k, const Value& info)
        : key(k), data(info), left(nullptr), right(nullptr), height(1) {}
};

#endif
