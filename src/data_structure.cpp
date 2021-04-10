
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
  void BinomialHeap::linkBinomialTrees(Node *newTree, Node *addedTree) {
    addedTree->parent = newTree;
    addedTree->sibling = newTree->child;
    newTree->child = addedTree;
    newTree->degree += 1;
  }

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

      while(node1 != nullptr && node2 != nullptr) {
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

        while(node1 != nullptr) {
          newHeap->sibling = node1;
          node1 = node1->sibling;
          newHeap = newHeap->sibling;
        }
      }

      if (node2 != nullptr) {

        while(node2 != nullptr) {
          newHeap->sibling = node2;
          node2 = node2->sibling;
          newHeap = newHeap->sibling;
        }
      }

      newHeap = tempHeap;
      NodePtr prev = nullptr;
      NodePtr next = newHeap->sibling;

      while (next != nullptr) {

        if ((newHeap->degree != next->degree )|| (next->sibling != nullptr && newHeap->degree == next->sibling->degree)) {
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


  BinomialHeap::~BinomialHeap(){
    delete head;
  }

  void BinomialHeap::setHead(Node *head1) {
    this->head = head1;
  };

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




  // create sample heap (given in figure Fig 10 (a))
  void  BinomialHeap::createSampleHeap2() {
    // B0
    NodePtr node1 = new Node( 5, 0);
    this->head = node1;

    // B2
    auto node2 = new Node( 6, 2);
    auto node3 = new Node( 12, 1);
    auto node4 = new Node(34, 0);
    auto node5 = new Node(33, 0);
    node2->child = node3;
    node3->parent = node2;
    node4->parent = node2;
    node3->child = node5;
    node3->sibling = node4;
    node5->parent = node3;

    // link B0 and B1
    node1->sibling = node2;

    // B3
    auto node6 = new Node(1, 3);
    auto node7 = new Node(2, 2);
    auto node8 = new Node(12, 1);
    auto node9 = new Node(6, 0);
    auto node10 = new Node(4, 1);
    auto node11 = new Node(13, 0);
    auto node12 = new Node( 18, 0);
    auto node13 = new Node( 7, 0);
    node6->child = node7;
    node7->parent = node6;
    node8->parent = node6;
    node7->parent = node6;
    node7->child = node10;
    node7->sibling = node8;
    node8->child = node12;
    node8->sibling = node9;
    node10->parent = node7;
    node11->parent = node7;
    node12->parent = node8;
    node10->child = node13;
    node10->sibling = node11;
    node13->parent = node10;

    // link B1 and B3
    node2->sibling = node6;
  }

  void  BinomialHeap::createSampleHeap3() {
    // B1
    auto node1 = new Node( 29, 1);
    auto node2 = new Node( 33, 0);
    node1->child = node2;
    node2->parent = node1;
    this->head = node1;

    // B2
    auto node3 = new Node( 21, 2);
    auto node4 = new Node( 23, 1);
    auto node5 = new Node(78, 0);
    auto node6 = new Node( 50, 0);
    node3->child = node4;
    node4->parent = node3;
    node5->parent = node3;
    node4->child = node6;
    node4->sibling = node5;
    node6->parent = node4;

    // link B1 and B2
    node1->sibling = node3;

  }



  Node::~Node() {
    data = 0;
    degree = 0;
    parent = nullptr;
    child = nullptr;
    sibling = nullptr;
  }
}// namespace itis