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

    explicit Node(int data, int degree) {
      this->data = data;
      this->degree = degree;
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

    static void linkBinomialTrees(Node *newTree, Node *addedTree);
    void createSampleHeap1();
    void createSampleHeap2();
    void createSampleHeap3();
    void printHeap();
    Node * getHead();
    int deleteMin();
    void reverse();
    void setHead(Node * head);
    void merge(BinomialHeap *addedHeap);
    void insert(int data);
    ~BinomialHeap();

  };

}