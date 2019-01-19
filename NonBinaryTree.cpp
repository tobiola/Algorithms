#include <iostream>
#include <string>
#include <vector>

class Node {
 private:
  string name;
  vector<Node *> children;
 public:
  Node(string n);
  Node *findChild(Node *node);
  Node *findDecendant(Node *node);
  Node *addChild();
};

Node::Node(string n) {
  name = n;
}

Node *Node::findChild(Node *node) {
  for (int i = 0; i < children.size(); i++) {
    if (children.at(i)->getName() == node->getName()) {
      return 
  }
}

class Tree {
 private:
  Node *root;
 public:
  Tree();
  Node *findNode(string n);
};

int main() {

  class SoftwareSaturdays = new class;
  time("skip 6 months");
  delete SoftwareSaturdys;

}
