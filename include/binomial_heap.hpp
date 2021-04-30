#pragma once

namespace itis {

  struct Node {
    int data;
    int degree;
    Node *parent;
    Node *child;
    Node *sibling;

    Node() {
      this->data = 0;
      this->degree = 0;
      this->parent = nullptr;
      this->child = nullptr;
      this->sibling = nullptr;
    }

    explicit Node(int newData, int newDegree) {
      this->data = newData;
      this->degree = newDegree;
      this->parent = nullptr;
      this->child = nullptr;
      this->sibling = nullptr;
    }

    ~Node();
  };

  struct BinomialHeap {
   public:
    Node *head;

    BinomialHeap();
    explicit BinomialHeap(Node *node);

    static void mergeTrees(Node *newTree, Node *addedTree);
    void printHeap();
    Node *getHead();
    int deleteMinNode();
    void reverseHeap();
    void setHead(Node *head);
    void mergeHeaps(BinomialHeap *addedHeap);
    void insert(int data);
    ~BinomialHeap();
  };

}  // namespace itis
