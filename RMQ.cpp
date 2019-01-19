#include <map>
#include <iostream>

using namespace std;

typedef struct node {
  int value;
  int index;
  struct node *left;
  struct node *right;
} node;

class RMQ {
 public:
  RMQ();
  RMQ(int *values, int size);
  ~RMQ();
  int getMin(int start, int end);
  void printTree();
  void insert(int value);

 private:
  int size;
  node *root;
  // map<int, int> indexes;
  void insertNode(node *new_node, node **cur);
  void destroyTree(node *leaf);
  void printTree(node *leaf);

};

RMQ::RMQ() {
  size = 0;
  root = NULL;
}

RMQ::RMQ(int values[10], int size) {

  size = 0;
  root = NULL;

  for (int i = 0; i < size; i++) {
    insert(values[i]);
  }

}

int RMQ::getMin(int start, int end) {

  node *cur = root;

  while (cur) {

    if ((cur->index >= start) && (cur->index <= end)) {
      return cur->value;
    }
    else  {
      cur = cur->index < start ? cur->right : cur->left;
    }
  }
  cerr << "value not found" << endl;
  return -1;
}

RMQ::~RMQ() {
  destroyTree(root);
}

void RMQ::destroyTree(node *leaf) {

  if (!leaf) {
    return;
  }

  destroyTree(leaf->left);
  destroyTree(leaf->right);
  delete leaf;

}

void RMQ::insert(int value) {

  node *new_node = new node;
  new_node->value = value;
  new_node->index = size++;
  new_node->left = NULL;
  new_node->right = NULL;

  insertNode(new_node, &root); 

}

void RMQ::insertNode(node *new_node, node **cur) {

  if (!(*cur)) {
    *cur = new_node;
  }
  else if (new_node->value < (*cur)->value) {
    new_node->left = *cur;
    *cur = new_node;
  }
  else {
    insertNode(new_node, &((*cur)->right));
  }

}

void RMQ::printTree() {

  printTree(root);

}

void RMQ::printTree(node *leaf) {

  if (!leaf) {
    return;
  }

  printTree(leaf->left);
  cout << leaf->value << endl;
  printTree(leaf->right);
        
};

int main() {

  int size = 10;
  int array[10] = { 5, 2, 6, 4, 23, 34, 11, 8, 7, 24};

  RMQ *algo = new RMQ();

  for (int i = 0; i < 10; i++) {
    algo->insert(array[i]);
  }

  cout << algo->getMin(4, 9) << endl;

  delete algo;

}
