#include "data_structure.hpp"
#include <iostream>
#include "queue"

using namespace std;
namespace itis {
  typedef Node *NodePtr;

  BinomialHeap::BinomialHeap() {
    this->head = nullptr;
  }

  BinomialHeap::BinomialHeap(Node *node) {
    this->head = node;
  }
  //Соединить два биномиальных дерева одинаковой степени
  void BinomialHeap::linkBinomialTrees(Node *newTree, Node *addedTree) {
    addedTree->parent = newTree;
    addedTree->sibling = newTree->child;
    newTree->child = addedTree;
    newTree->degree += 1;
  }

  //соединить 2 кучи
  void BinomialHeap::merge(BinomialHeap *addedHeap) {
    NodePtr node1 = this->head;
    NodePtr node2 = addedHeap->head;
    NodePtr newHeap = nullptr;
    NodePtr tempHeap = nullptr;

    if (node1->degree <= node2->degree) {
      newHeap = node1;
      node1 = node1->sibling;
    } else {
      newHeap = node2;
      node2 = node2->sibling;
    }

    tempHeap = newHeap;

    while (node1 != nullptr && node2 != nullptr) {
      if (node1->degree <= node2->degree) {
        newHeap->sibling = node1;
        node1 = node1->sibling;
      } else {
        newHeap->sibling = node2;
        node2 = node2->sibling;
      }

      newHeap = newHeap->sibling;
    }

    if (node1 != nullptr) {

      while (node1 != nullptr) {
        newHeap->sibling = node1;
        node1 = node1->sibling;
        newHeap = newHeap->sibling;
      }
    }

    if (node2 != nullptr) {

      while (node2 != nullptr) {
        newHeap->sibling = node2;
        node2 = node2->sibling;
        newHeap = newHeap->sibling;
      }
    }

    newHeap = tempHeap;
    NodePtr prev = nullptr;
    NodePtr next = newHeap->sibling;

    while (next != nullptr) {

      if ((newHeap->degree != next->degree) || (next->sibling != nullptr && newHeap->degree == next->sibling->degree)) {
        prev = newHeap;
        newHeap = next;
      } else {

        if (newHeap->data <= next->data) {
          newHeap->sibling = next->sibling;
          BinomialHeap::linkBinomialTrees(newHeap, next);
        } else {
          if (prev == nullptr) {
            tempHeap = next;
          } else {
            prev->sibling = next;
          }

          BinomialHeap::linkBinomialTrees(next, newHeap);
          newHeap = next;
        }
      }

      next = newHeap->sibling;
    }

    setHead(tempHeap);
  }

  BinomialHeap::~BinomialHeap() {
    Node *temp = head;
    if (temp == nullptr) {
    }
    else {
      queue<Node*> q;
      q.push(temp);

      while (temp->sibling != nullptr) {
        temp = temp->sibling;
        q.push(temp);
      }
      while (!q.empty()) {
        temp = q.front();
        q.pop();
        Node *old = temp;
        if (temp != nullptr) {

          if (temp->child != nullptr) {
            temp = temp->child;
            q.push(nullptr);
            q.push(temp);
            while (temp->sibling != nullptr) {
              temp = temp->sibling;
              q.push(temp);
            }
          }
        }
        old = nullptr;
      }
    }
  }

  void BinomialHeap::setHead(Node *head1) {
    this->head = head1;
  };

  Node::~Node() {
    data = 0;
    degree = 0;
    parent = nullptr;
    child = nullptr;
    sibling = nullptr;
  }
}  // namespace itis