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
  //Соединить два биномиальных дерева одинаковой степени
  void BinomialHeap::linkBinomialTrees(Node *newTree, Node *addedTree) {
    addedTree->parent = newTree;
    addedTree->sibling = newTree->child;
    newTree->child = addedTree;
    newTree->degree += 1;
  }

  void BinomialHeap::merge(BinomialHeap *addedHeap) {
    Node *tempHeap = nullptr;

    if (this->head != nullptr && addedHeap->head != nullptr) {

      NodePtr node1 = this->head;
      NodePtr node2 = addedHeap->head;
      NodePtr newHeap = nullptr;
      NodePtr tempHeap = nullptr;

      if (node1->degree <= node2->degree) {  //выбираем корень
        newHeap = node1;
        node1 = node1->sibling;
      } else {
        newHeap = node2;
        node2 = node2->sibling;
      }

      tempHeap = newHeap;  //запоминаем корень

      while (node1 != nullptr && node2 != nullptr) {  //прикрепляем вершины по очереди
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

      newHeap = tempHeap;  //кидаем указатель

      NodePtr prev = nullptr;
      NodePtr next = newHeap->sibling;
      //
      while (next != nullptr) {
        //если 1!=2 или 1==2==3 (ниже то же самое, по условиям)
        //если 2 первых дерева неравны по длине или если есть 3 дерево и 1 дерево с 3 деревом равны по длине
        //так как 2 ситуации с самого начала быть не может, то мы мёрджаем в итоге 2 и 3 дерево, так как если 1==2==3, то 1 100% меньше по значению, чем 2 и 3, потому что мы присоединили к нему раньше
        if ((newHeap->degree != next->degree)
            || (next->sibling != nullptr && newHeap->degree == next->sibling->degree)) {
          prev = newHeap;  //пред деревео - 1
          newHeap = next;  //текущее - 2

        } else {

          //если значение в 1 дереве меньше чем значение во 2 дереве
          if (newHeap->data <= next->data) {

            newHeap->sibling = next->sibling;                //2 дерево убираем в детей
            BinomialHeap::linkBinomialTrees(newHeap, next);  //присоединяем 2 дерево к 1

          } else {  //если значение в 1 больше чем во 2

            if (prev == nullptr) {  //если дерево хед, то 2 дерево теперь хед
              tempHeap = next;
            } else {
              prev->sibling =
                  next;  //если дерево не хед, то у дерева, идущего до 1, сиблингом делаем 2, чтобы выкинуть 1 из деревьев и присоединить
            }

            BinomialHeap::linkBinomialTrees(next, newHeap);  //ко 2 присоединяем 1
            newHeap = next;                                  //2 дерево кидаем в хипу
          }
        }

        next = newHeap->sibling;  //переставляем некст на следующее дерево
      }
      setHead(
          tempHeap);  //устанавливаем новую голову (если ко 2 присоединили 1 и хед пропал), если ничего не делали, то хед остаётся тот же
      //вообще, можно поменять на this->head=tempHeap;
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
    merge(newHeap);
  }

  Node::~Node() {
    cout << "node deleted " << data << endl;
    data = 0;
    degree = 0;
    parent = nullptr;
    child = nullptr;
    sibling = nullptr;
  }

  int BinomialHeap::deleteMin() {
    Node *prevNode = nullptr;
    Node *minNode = nullptr;
    Node *node = nullptr;
    Node *minNodeСhild = nullptr;
    int minValue = INT_MAX;

    if (this->head != nullptr) {

      Node *minPrevNode = nullptr;   //предыдущее дерево минимального дерева
      minNode = this->head;          //мин дерево
      node = (this->head)->sibling;  //текущее дерево
      prevNode = this->head;         //предыдущ дерево
      /*
         * Найти мин дерево и его предыд дерево
         */
      while (node != nullptr) {

        if (node->data < minNode->data) {
          minNode = node;
          minPrevNode = prevNode;
        }
        prevNode = prevNode->sibling;
        node = node->sibling;
      }

      //выкидываем мин дерево из кучи
      //Если предыд узел мин узла есть
      if (minPrevNode != nullptr) {
        minPrevNode->sibling = minNode->sibling;  //следующий для предыдМин = след для минимального
      } else {                                    //иначе
        this->head = minNode->sibling;  //хед = след для минимального
      }

      // Делаем у всех детей мин корня родителем null
      minNodeСhild = minNode->child;
      node = minNodeСhild;

      while (node != nullptr) {
        node->parent = minNode->parent;
        node = node->sibling;
      }
      /*
         * Удаляем мин корень
         */
      minNode->sibling = nullptr;
      minNode->child = nullptr;
      minNode->parent = nullptr;
      minValue = minNode->degree;
      delete minNode;
      /*
         * Объединить 2 кучи
         */
      BinomialHeap *heap1 = new BinomialHeap(minNodeСhild);
      heap1->reverse();
      merge(heap1);
    }

    return minValue;
  }

  void BinomialHeap::reverse() {
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

  BinomialHeap::~BinomialHeap() {
    NodePtr currPtr = this->head;
    vector<Node *> nodes;
    while (currPtr != nullptr) {
      queue<NodePtr> q;
      q.push(currPtr);
      while (!q.empty()) {
        NodePtr p = q.front();
        nodes.push_back(q.front());
        q.pop();

        if (p->child != nullptr) {
          NodePtr tempPtr = p->child;
          while (tempPtr != nullptr) {
            q.push(tempPtr);
            tempPtr = tempPtr->sibling;
          }
        }
      }

      currPtr = currPtr->sibling;
    }
    for (int i = 0; i < nodes.size(); i++)
      delete nodes[i];
  }

  // create sample heap (given in figure Fig 10 (a))
  void BinomialHeap::createSampleHeap2() {
    // B0
    NodePtr node1 = new Node(5, 0);
    this->head = node1;

    // B2
    auto node2 = new Node(6, 2);
    auto node3 = new Node(12, 1);
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
    auto node12 = new Node(18, 0);
    auto node13 = new Node(7, 0);
    node6->child = node7;
    node7->parent = node6;
    node8->parent = node6;
    node9->parent = node6;
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

  void BinomialHeap::createSampleHeap3() {
    // B1
    auto node1 = new Node(29, 1);
    auto node2 = new Node(33, 0);
    node1->child = node2;
    node2->parent = node1;
    this->head = node1;

    // B2
    auto node3 = new Node(21, 2);
    auto node4 = new Node(23, 1);
    auto node5 = new Node(78, 0);
    auto node6 = new Node(50, 0);
    node3->child = node4;
    node4->parent = node3;
    node5->parent = node3;
    node4->child = node6;
    node4->sibling = node5;
    node6->parent = node4;

    // link B1 and B2
    node1->sibling = node3;
  }

}  // namespace itis