
#include "data_structure.hpp"
#include <iostream>
using namespace std;
#include "queue"
namespace itis {
  typedef Node *NodePtr;

  BinomialHeap::BinomialHeap() {
    this->head = nullptr;
  }

  BinomialHeap::BinomialHeap(Node *node) {
    this->head = node;
  }
  //Соединить два биномиальных дерева одинаковой степени
  void linkBinomialTrees(NodePtr x, NodePtr y) {
    y->parent = x;
    y->sibling = x->child;
    x->child = y;
    x->degree += 1;
  }

  void BinomialHeap::merge(BinomialHeap *heap2) {
    if (this->head == nullptr) {
      return;
    } else if (heap2->head == nullptr) {
      this->head = heap2->head;
    }
    auto *h = new BinomialHeap;
    NodePtr node1 = this->head;
    NodePtr node2 = heap2->head;

    while ((node1 != nullptr) && (node2 != nullptr)) {
      if (node1->degree <= node2->degree) {
        h->head = node1;
        node1 = node1->sibling;

      } else {
        h->head = node2;
        node2 = node2->sibling;
      }
    }

    while (node1 != nullptr) {
      h->head = node1;
      node1 = node1->sibling;
    }

    while (node2 != nullptr) {
      h->head = node2;
      node2 = node2->sibling;
    }
    this->head = h->head;
  }

  void BinomialHeap::printHeap() {
    NodePtr currPtr = this->head;
    while (currPtr != nullptr) {
      cout << "B" << currPtr->degree << endl;
      cout << "There are " << pow(2, currPtr->degree) << " nodes in this tree" << endl;
      cout << "The level order traversal is" << endl;
      queue<NodePtr> q;
      q.push(currPtr);
      while (!q.empty()) {
        NodePtr p = q.front();
        q.pop();
        cout << p->data << " ";

        if (p->child != nullptr) {
          NodePtr tempPtr = p->child;
          while (tempPtr != nullptr) {
            q.push(tempPtr);
            tempPtr = tempPtr->sibling;
          }
        }
      }
      currPtr = currPtr->sibling;
      cout << endl << endl;
    }
  }

}  // namespace itis