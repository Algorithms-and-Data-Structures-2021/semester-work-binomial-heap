#pragma once


namespace itis {

  struct Node {
    int data;
    int degree;
    Node *parent;
    Node *child;
    Node *sibling;

    explicit Node() {
      this->data = 0;
      this->degree = 0;
      this->parent = nullptr;
      this->child = nullptr;
      this->sibling = nullptr;
    }

    Node(Node *node, int data, int degree) {
      node->data = data;
      node->degree = degree;
      node->parent = nullptr;
      node->child = nullptr;
      node->sibling = nullptr;
    }

  };


  struct BinomialHeap {
   public:
    Node *head;

    BinomialHeap();
    BinomialHeap(Node *node);

    static void linkBinomialTrees(Node *x, Node * y);
    Node * findMinimum();
    void createSampleHeap1();
    void createSampleHeap2();
    void createSampleHeap3();
    void insert(int data);
    void printHeap();
    Node * getHead();
    void setHead(Node * head);
    void merge(BinomialHeap *h1);
    Node * deleteMin();
    ~BinomialHeap();

  };

}