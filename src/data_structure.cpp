#include "data_structure.hpp"
#include <iostream>
#include "queue"
#include "stack"

using namespace std;
namespace itis {
  typedef Node *NodePtr;

  BinomialHeap::BinomialHeap() {
    this->head = nullptr;
  }

  BinomialHeap::BinomialHeap(Node *node) {
    this->head = node;
  }

  void BinomialHeap::mergeTrees(Node *newTree, Node *addedTree) {
    addedTree->parent = newTree;
    addedTree->sibling = newTree->child;
    newTree->child = addedTree;
    newTree->degree += 1;
  }

  void BinomialHeap::mergeHeaps(BinomialHeap *addedHeap) {
    Node *tempHeap = nullptr;

    if (this->head != nullptr && addedHeap->head != nullptr) {

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

        if ((newHeap->degree != next->degree)
            || (next->sibling != nullptr && newHeap->degree == next->sibling->degree)) {
          prev = newHeap;
          newHeap = next;

        } else {

          if (newHeap->data <= next->data) {

            newHeap->sibling = next->sibling;
            BinomialHeap::mergeTrees(newHeap, next);

          } else {

            if (prev == nullptr) {
              tempHeap = next;
            } else {
              prev->sibling =
                  next;
            }

            BinomialHeap::mergeTrees(next, newHeap);
            newHeap = next;
          }
        }

        next = newHeap->sibling;
      }
      setHead(
          tempHeap);
    }

    if (this->head == nullptr) {

      tempHeap = addedHeap->head;
      setHead(tempHeap);
    }
  }

  void BinomialHeap::setHead(Node *head1) {
    this->head = head1;
  }

  void BinomialHeap::insert(int data) {
    BinomialHeap *newHeap = new BinomialHeap();
    auto node = new Node(data, 0);
    newHeap->head = node;
    mergeHeaps(newHeap);
  }

  Node::~Node() {
    data = 0;
    degree = 0;
    parent = nullptr;
    child = nullptr;
    sibling = nullptr;
  }

  int BinomialHeap::deleteMinNode() {
    Node *prevNode = nullptr;
    Node *minNode = nullptr;
    Node *node = nullptr;
    Node *minNodeChild = nullptr;
    int minValue = INT_MAX;

    if (this->head != nullptr) {

      Node *minPrevNode = nullptr;
      minNode = this->head;
      node = (this->head)->sibling;
      prevNode = this->head;


      while (node != nullptr) {

        if (node->data <= minNode->data) {
          minNode = node;
          minPrevNode = prevNode;
        }
        prevNode = prevNode->sibling;
        node = node->sibling;
      }

      if (minPrevNode != nullptr) {
        minPrevNode->sibling = minNode->sibling;
      } else {
        this->head = minNode->sibling;
      }

      minNodeChild = minNode->child;
      node = minNodeChild;

      while (node != nullptr) {
        node->parent = minNode->parent;
        node = node->sibling;
      }

      minNode->sibling = nullptr;
      minNode->child = nullptr;
      minNode->parent = nullptr;
      minValue = minNode->data;
      delete minNode;
      BinomialHeap *heap1 = new BinomialHeap(minNodeChild);
      heap1->reverseHeap();
      mergeHeaps(heap1);
    }

    return minValue;
  }

  void BinomialHeap::reverseHeap() {
    stack<Node *> queue;
    while (this->head != nullptr) {
      queue.push(this->head);
      this->head = this->head->sibling;
      queue.top()->sibling = nullptr;
    }
    this->head = queue.top();
    Node *temp = queue.top();
    queue.pop();
    while (!queue.empty()) {
      this->head->sibling = queue.top();
      queue.pop();
      this->head = this->head->sibling;
    }
    this->head = temp;
  }

  void BinomialHeap::printHeap() {
    NodePtr currPtr = this->head;
    while (currPtr != nullptr) {
      cout << "Tree degree is " << currPtr->degree << endl;
      cout << pow(2, currPtr->degree) << " nodes in the tree" << endl;
      cout << "Here they are from left to right: " << endl;
      queue<NodePtr> queue;
      queue.push(currPtr);

      while (!queue.empty()) {
        NodePtr current = queue.front();
        queue.pop();
        cout << current->data << " ";

        if (current->child != nullptr) {
          NodePtr tempPtr = current->child;

          while (tempPtr != nullptr) {
            queue.push(tempPtr);
            tempPtr = tempPtr->sibling;
          }
        }
      }
      currPtr = currPtr->sibling;
      cout << endl << endl;
    }
  }


  BinomialHeap::~BinomialHeap() {
    NodePtr currPtr = this->head;
    vector<Node *> nodes;
    while (currPtr != nullptr) {
      queue<NodePtr> queue;
      queue.push(currPtr);
      while (!queue.empty()) {
        NodePtr current = queue.front();
        nodes.push_back(queue.front());
        queue.pop();

        if (current->child != nullptr) {
          NodePtr tempPtr = current->child;
          while (tempPtr != nullptr) {
            queue.push(tempPtr);
            tempPtr = tempPtr->sibling;
          }
        }
      }

      currPtr = currPtr->sibling;
    }
    for (int i = 0; i < nodes.size(); i++)
      delete nodes[i];
  }

}
